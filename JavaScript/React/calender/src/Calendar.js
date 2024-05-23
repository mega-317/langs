import FullCalendar from "@fullcalendar/react";
import dayGridPlugin from '@fullcalendar/daygrid';
import interactionPlugin from "@fullcalendar/interaction";
import { useState, useEffect } from "react";
import EventInfo from "./component/EventInfo.js";

export default function MyCalender() {

    let [event, setEvent] = useState(
        [
            {title : '과제1', date : '2024-05-19', time : '13:00', member : [
                { name : '김윤태', phone : '010-2222-2222', edit : 0 },
                { name : '홍길동', phone : '010-3333-3333', edit : 0 },
            ], 
            place : '충북대학교 중앙도서관',
            edit : 0},
            {title : '마라탕 먹기', date : '2024-05-19', time : '15:00', member : [], place : '', edit : 0},
            {title : '과제2', date : '2024-05-11', time : '15:00', member : [], place : '', edit : 0}
        ]
    );
    let [info, setInfo] = useState('');
    let [selectDate, setSelectDate] = useState(0);
    let [calendarKey, setCalendarKey] = useState(0);

    const timeOption = { hour: '2-digit', minute: '2-digit', hour12 : false };

    useEffect(() => {
        setCalendarKey(calendarKey + 1);
    }, [event]);
    
    console.log(event);

    return (
        <div className="mainPage">
            <FullCalendar 
                defaultView="dayGridMonth"
                plugins={[ dayGridPlugin, interactionPlugin]}

                // 날짜를 클릭하면 일정 목록과 일정 관리에 대한 부분이 뜨도록 함
                dateClick={(info)=>{
                    // 해당 날짜 출력
                    console.log('현재 날짜 ' + info.dateStr);
                    setInfo(info.dateStr);
                    setSelectDate(1);
                }}

                // 이벤트를 클릭해도 마찬가지로 일정 목록과 일정 관리가 뜨도록 함
                eventClick={(info)=>{
                    // 해당 날짜 출력
                    console.log('현재 날짜 ' + info.event.startStr);
                    console.log(info.event.start.toLocaleTimeString([], timeOption));
                    setInfo(info.event.startStr);
                    setSelectDate(1);
                }}
                events={event}
                key={calendarKey}
                dayMaxEventRows={2}
            />
            {
                selectDate == 1 ? 
                <div>
                    <EventInfo info={info} event={event} setEvent={setEvent}/>
                </div>
                : null
            }
        </div>
    )
}



