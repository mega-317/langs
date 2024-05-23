import { useState } from "react";

export default function AddMember({setMemberList, memberList, setAddMember}){

  // 멤버 이름을 저장할 변수
  let [memberName, setMemberName] = useState('');

  // 멤버 전화번호를 저장할 변수
  let [memberPhone, setMemberPhone] = useState('');

  return (
    <div>
      {/* 멤버 이름 입력 */}
      <input value={memberName} placeholder="같이 할 사람" onChange={(e)=>{
          setMemberName(e.target.value);
      }}></input>
      
      <br></br>

      {/* 멤버 전화 번호 입력 */}
      <input value={memberPhone} placeholder="전화번호" onChange={(e)=>{
          setMemberPhone(e.target.value);
      }}></input>

      {/* 멤버 추가 버튼 */}
      <button onClick={()=>{
        let copy = [...memberList];
        let member = {};
        member = { name : memberName, phone : memberPhone};
        copy.push(member);
        setMemberList(copy);
        setMemberName('');
        setMemberPhone('');
      }}>등록</button>

      {/* 멤버 추가 취소 버튼 */}
      <button onClick={()=>{
        setAddMember(0);
      }}>취소</button>
    </div>
  )
}