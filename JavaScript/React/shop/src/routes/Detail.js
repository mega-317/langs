import { useContext, useEffect, useState } from "react";
import { Nav } from "react-bootstrap";
import { useParams } from "react-router-dom";

import {Context1} from './../App.js';

function Detail(props) {

    let {재고} = useContext(Context1)

    useEffect(()=>{
        setTimeout(()=>{ setAlert(false) }, 2000);
    }, [])

    let [alert, setAlert] = useState(true);
    let [tab, setTab] = useState(0);

    let shoes = props.shoes;
    let {id} = useParams();
    let info = props.shoes.find((x)=>{
        return x.id == id
    })

    let [fade, setFade] = useState('');

    useEffect(()=>{
        setFade('end')
    })

    return (
        <div className={`container start ${fade}`}>
            {
                alert ? <div className="alert alert-warning">2초 이내 구매시 할인</div> : null
            }
            <div className="row">
                <div className="col-md-6">
                    <img src={`https://codingapple1.github.io/shop/shoes${info.id+1}.jpg`} width="100%" />
                </div>
                <div className="col-md-6 mt-4">
                    <h4 className="pt-5">{info.title}</h4>
                    <p>{info.content}</p>
                    <p>{info.price}</p>
                    <button className="btn btn-danger">주문하기</button> 
                </div>
            </div>

            <Nav variant="tabs" defaultActiveKey="link0">
                <Nav.Item>
                    <Nav.Link eventKey="link0" onClick={()=>{
                        setTab(0)
                    }}>버튼1</Nav.Link>
                </Nav.Item>
                <Nav.Item>
                    <Nav.Link eventKey="link1" onClick={()=>{
                        setTab(1)
                    }}>버튼2</Nav.Link>
                </Nav.Item>
                <Nav.Item>
                    <Nav.Link eventKey="link2" onClick={()=>{
                        setTab(2)
                    }}>버튼3</Nav.Link>
                </Nav.Item>
            </Nav>

            <Tab tab={tab} shoes={shoes}></Tab>

        </div>
    )
}

function Tab({tab, shoes}){

    let [fade, setFade] = useState('');

    useEffect(()=>{
        setTimeout(()=>{ setFade('end') }, 100)
        return ()=>{
            setFade('')
        }
    }, [tab])

    return <div className={`start ${fade}`}>
        {[<div>{shoes[0].title}</div>, <div>{shoes[1].title}</div>, <div>{shoes[2].title}</div>][tab]}
    </div> 
    
}

export default Detail;