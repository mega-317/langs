import { useState } from 'react';
import AddMember from './AddMember';
import AddLocation from './AddLocation';

export default function AddEvent({info, event, setEvent, setNewEvent, confirm}){

  // 일정 이름을 저장할 변수
  let [eventName, setEventName] = useState('');

  // 일정 시간을 저장할 변수
  let [eventTime, setEventTime] = useState('');

  // 멤버를 추가할지 여부를 확인하는 변수
  let [addMember, setAddMember] = useState(0);

  // 장소를 추가할지 여부를 확인하는 변수
  let [addLocation, setAddLocation] = useState(0);

  // 인원 정보를 담는 배열
  let [memberList, setMemberList] = useState([]);

  // 장소 정보를 담는 배열
  let [location, setLocation] = useState('');

  // 사용자가 다른 날짜를 선택하면 일정 추가 창 끄기
  if (confirm != info) {
      setNewEvent(0);
  }

  return(
      <div className="card">
          <p>일정 추가</p>

          {/* 일정 이름 추가 */}
          <input value={eventName} placeholder="제목" onChange={(e)=>{
              setEventName(e.target.value);
          }}></input><br></br>

          {/* 일정 시간 추가 */}
          <input type="time" onChange={(e)=>{
              console.log("time " + e.target.value);
              setEventTime(e.target.value);
          }}></input><br></br>

          {
            // 멤버 목록 출력
            memberList.map((a,i)=>{
                return (
                    <div>
                        <p>{a.name} {a.phone}</p>
                    </div>
                )
            })
          }

          {/* 멤버 추가 창*/}
          {
              addMember == 1 ? 
              <AddMember 
                setMemberList={setMemberList} memberList={memberList} setAddMember={setAddMember}
              /> : null
          }

          {/* 일정 멤버 추가 버튼*/}
          {
            addMember == 0 ? <button onClick={()=>{setAddMember(1);}}>같이 할 사람</button> : null
          }
          <br></br>

          {
            addLocation == 1 ?
            <AddLocation setAddLocation={setAddLocation} setLocation={setLocation}/> : null
          }

          {
            addLocation == 0 ? <p>{location}</p> : null
          }

          {/* 장소 추가 버튼 */}
          <button onClick={()=>{
            setAddLocation(1);
          }}>약속 장소</button>
          <br></br>

          {/* 일정 추가하기 */}
          <button onClick={()=>{
              let copy = [...event];
              let newEvent = {};
              newEvent = { title : eventName, date : info, time : eventTime, member : memberList, place : location};
              copy.push(newEvent);
              setEvent(copy);
              setEventName('');
              setNewEvent(0);
          }}>추가</button>

          {/* 일정 추가 취소하기 */}
          <button onClick={()=>{
              setNewEvent(0);
          }}>취소</button>
      </div>
  )
}