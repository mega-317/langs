import React, { useEffect, useState } from 'react';
// import { Map, MapMarker, CustomOverlayMap } from 'react-kakao-maps-sdk';

const { kakao } = window;

export default function KakaoMap({ searchPlace, setPlace }) {

  let [placeName, setPlaceName] = useState('장소 이름');
  let [placeList, setPlaceList] = useState([]);

  useEffect(()=>{

    var infowindow = new kakao.maps.InfoWindow({ zIndex: 1 })
    const container = document.getElementById('myMap')

    const options = {
      center: new kakao.maps.LatLng(33.450701, 126.570667),
      level: 3,
    }

    const place = new kakao.maps.services.Places();
    const map = new kakao.maps.Map(container, options)
    place.keywordSearch(searchPlace, placeSearchCB)

    function placeSearchCB(data, status, pagination) {
      if (status === kakao.maps.services.Status.OK) {
        let bounds = new kakao.maps.LatLngBounds();

        // 검색을 통해 장소 이름 목록 출력하기
        // for (let i=0; i<data.length; i++) {
        //   let copy = [...placeList];  
        //   copy.push(data[i].place_name);
        //   setPlaceList(copy);
        // }
        for (let i=0; i<data.length; i++) {
          displayMarker(data[i]);
          bounds.extend(new kakao.maps.LatLng(data[i].y, data[i].x));
        }

        map.setBounds(bounds);
      }
    }

    function displayMarker(place) {
      let marker = new kakao.maps.Marker({
        map : map,
        position : new kakao.maps.LatLng(place.y, place.x),
      })

      kakao.maps.event.addListener(marker, 'click', function() {
        infowindow.setContent('<div style="padding:5px;font-size:12px;">' + place.place_name + '</div>')
        infowindow.open(map, marker)
        setPlaceName(place.place_name);
        setPlace(place.place_name);
      })
    }
  }, [searchPlace])

  return (
    <div>
      <div 
        id='myMap'
        style={{
          width : '200px',
          height : '200px',
        }}>
      </div>
      <p>{placeName}</p>
      {/* {
        placeList.map((a,i)=>{
          return (
            <div>
              <ul>
                <li>{a}</li>
              </ul>
            </div>
          )
        })
      } */}
    </div>  
  )
}