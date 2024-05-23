import { useState } from "react"
import KakaoMap from "./KakaoMap";

export default function AddLocation({setAddLocation, setLocation}){

  let [locationName, setLocationName] = useState('');
  let [place, setPlace] = useState('');

  return (
    <div>
      <form>
        {/* 장소 이름 입력하기 */}
        <input type="text" value={locationName} placeholder="장소 이름" onChange={(e)=>{
          setLocationName(e.target.value);
        }}></input>

        <KakaoMap searchPlace={locationName} setPlace={setPlace}/>
      </form>

      <button onClick={()=>{
        setLocation(place);
        setAddLocation(0);
      }}>확인</button>

      <button onClick={()=>{
        setAddLocation(0);
      }}>취소</button>
    </div>
  )
}