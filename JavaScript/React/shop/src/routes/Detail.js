import { useEffect, useState } from "react";
import { useParams } from "react-router-dom";

function Detail(props) {

    let [notNum, setNotNum] = useState(false);
    let [input, setInput] = useState('');

    useEffect(()=>{
        setTimeout(()=>{ setAlert(false) }, 2000);

        if (isNaN(input) == true) {
            setNotNum(true);
        }

    }, [input])

    let [alert, setAlert] = useState(true);

    let {id} = useParams();
    let info = props.shoes.find((x)=>{
        return x.id == id
    })

    return (
        <div className="container">
            {
                alert ? <div className="alert alert-warning">2초 이내 구매시 할인</div> : null
            }
            <div className="row">
                <div className="col-md-6">
                    <img src={`https://codingapple1.github.io/shop/shoes${info.id+1}.jpg`} width="100%" />
                </div>
                <div className="col-md-6 mt-4">
                    {
                        notNum ? <div>숫자만 입력하세요!</div> : null
                    }
                    <input onChange={(e)=>{
                        console.log(e.target.value);
                        setInput(e.target.value);
                    }}></input>
                    <h4 className="pt-5">{info.title}</h4>
                    <p>{info.content}</p>
                    <p>{info.price}</p>
                    <button className="btn btn-danger">주문하기</button> 
                </div>
            </div>
        </div>
    )
}

export default Detail;