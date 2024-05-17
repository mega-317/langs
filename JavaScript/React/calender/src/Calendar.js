import FullCalendar from "@fullcalendar/react";
import dayGridPlugin from '@fullcalendar/daygrid';
import interactionPlugin from "@fullcalendar/interaction";
import { useState } from "react";

export default function MyCalender() {

    let [event, setEvent] = useState(
        [
            {title : '과제1', date : '2024-05-19',},
            {title : '과제2', date : '2024-05-11',}
        ]
    )
    
    console.log(event)

    return (
        <FullCalendar 
            defaultView="dayGridMonth"
            plugins={[ dayGridPlugin, interactionPlugin]}
            dateClick={(info)=>{
                let copy = [...event];
                copy.push(
                    {title : '일정', date : info.dateStr}
                )
                setEvent(copy);
            }}
            events={event}
        />
    )
}