import { useState, useEffect } from "react";
import AddEvent from "./AddEvent";

export default function EventInfo({info, event, setEvent}) {

  // 일정 추가하기를 선택해야 일정 추가 창이 뜨도록
  let [newEvent, setNewEvent] = useState(0);

  // 일정이 비었는지 확인하는 변수
  let [empty, setEmpty] = useState(0);

  // 일정 수정을 위한 state
  let [editName, setEditName] = useState('');
  let [editTime, setEditTime] = useState('');

  // 사용자가 일정을 수정 중인지 확인한느 변수
  let [isEdit, setIsEdit] = useState(0);

  // 멤버 수정을 위해 멤버 목록 복사
  let [member, setMember] = useState([]);

  // 멤버 이름, 전화번호를 수정하기 위한 변수
  let [memberName, setMemberName] = useState('');
  let [memberPhone, setMemberPhone] = useState('');

  // 사용자가 멤버를 수정하는지 확인하는 변수
  let [editMember, setEditMember] = useState(0);

  // 사용자가 다른 날짜를 선택했는지 확인
  let [confirm, setConfirm] = useState('');

  useEffect(() => {
    // 특정 날짜에 일정이 있는지 확인
    let hasEvent = event.some(e => e.date === info);
    if (hasEvent) {
      setEmpty(1);
    } else {
      setEmpty(0);
    }
  }, [info, event]);

  return (
    <div>
      <p>{info}</p>
      {
        event.map((a,i)=>{
          if (a.date == info) {
            return (
              <div className="singleEvent">

                {/* 일정의 제목 출력 */}
                <p>{a.title}</p>

                {/* 일정을 시작할 시간 출력 */}
                <p>{a.time}</p>

                {/* 일정 장소 출력 */}
                <p>{a.place}</p>

                {   
                  // 멤버 목록 출력
                  a.member.map((k, i)=>{
                    return (
                      <div className="memberCard">
                        <p>{k.name} {k.phone}</p>
                      </div>
                    )
                  })
                }

                {
                  a.edit == 1 ? 
                  <div>
                    <p>일정 수정하기</p>

                    {/* 일정 이름 수정하기 */}
                    <input type="text" value={editName} placeholder="제목" onChange={(e)=>{
                      setEditName(e.target.value);
                    }}></input>

                    {/* 일정 시간 수정하기 */}
                    <input type="time" value={editTime} onChange={(e)=>{
                      setEditTime(e.target.value);
                    }}></input>

                    {/* 멤버 목록 수정하기 */}
                    {
                      a.member.map((b,j)=>{
                        return (

                          <div>
                            {
                              // 멤버 목록과 수정 삭제 버튼 출력
                              editMember == 0 ? 
                                <p>{b.name} {b.phone} 
                                  <span>
                                    {/* 멤버 이름, 전화번호 수정하기 */}
                                    {/* <button onClick={()=>{
                                      setEditMember(1);
                                    }}>수정</button> */}

                                    {/* 멤버 삭제하기 */}
                                    <button onClick={()=>{
                                      let memCopy = [...a.member];
                                      console.log("인원: ", memCopy);
                                      memCopy.splice(i, 1);
                                      setMember(memCopy);
                                      a.member.splice(i, 1)
                                      console.log(member);
                                    }}>삭제</button>
                                  </span>
                                </p>
                              : null
                            }

                            {
                              // 멤버 수정 버튼을 클릭할 경우
                              editMember == 1 ?
                                <div>
                                  {/* 멤버 이름 수정 */}
                                  <input type="text" placeholder={b.name} onChange={(e)=>{
                                    setMemberName(e.target.value);
                                  }}>
                                  </input>

                                  {/* 멤버 전화번호 수정 */}
                                  <input placeholder={b.phone} onChange={(e)=>{
                                    setMemberPhone(e.target.value);
                                  }}></input>
                                </div>
                              : null
                            }
                          </div>
                        )
                      })
                    }

                    {/* 수정사항을 저장하는 버튼 */}
                    <button onClick={()=>{
                      let copy1 = [...event];
                      copy1[i].title = editName;
                      copy1[i].time = editTime;
                      copy1[i].edit = 0;
                      setEvent(copy1);
                      setEditName('');
                      setIsEdit(0);
                    }}>수정사항 저장하기</button>

                    <button onClick={()=>{
                      setIsEdit(0);
                      let copy1 = [...event];
                      copy1[i].edit = 0;
                      setEvent(copy1);
                    }}>수정 취소</button>
                  </div> : null
                }

                {/* 일정을 수정하는 버튼 */}
                {
                  isEdit == 0 ?
                    <button onClick={()=>{
                      let copy = [...event];
                      copy[i].edit = 1;
                      setEditName(a.title);
                      setEvent(copy);
                      setIsEdit(1);
                    }}>수정</button> : null
                }

                

                {/* 일정을 삭제하는 버튼 */}
                <button onClick={()=>{
                  let copy = [...event];
                  copy.splice(i, 1);
                  setEvent(copy);
                }}>삭제</button>
              </div>
            )
          }
        })
      }

      {
        // 일정이 없을 경우
        empty == 0 ? 
        <div>
            <p>일정이 없습니다</p>
        </div> : null
      }

      {
        newEvent == 0 ?
        <button onClick={()=>{
            setNewEvent(1);
            setEmpty(1);
            setConfirm(info);
        }}>추가</button> :
        null
      }

      {
        newEvent == 1 ? <AddEvent 
        info={info} event={event} setEvent={setEvent} setNewEvent={setNewEvent} setEmpty={setEmpty} confirm={confirm}
        /> : null
      }
    </div>
  )
}