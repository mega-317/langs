import { useState } from 'react';
import './App.css';

function App() {

  let [글제목, 글제목수정] = useState([
    '남자 코트 추천', 
    '강남 우동 맛집',
    '파이썬 독학'
  ]);

  let [따봉, 따봉수정] = useState([0, 0, 0]);

  let [modal, setModal] = useState(false);

  let [modalNum, setModalNum] = useState(0);

  return (
    <div>
      <div className='black-nav'>
        <h4>ReactBlog</h4>
      </div>

      {
        글제목.map((a, i)=>{
          return (
            <div className='list'>
              <h4 onClick={()=>{
                setModal(!modal);
                setModalNum(i);
              }}>
                {글제목[i]}
                <span onClick={()=>{
                  let copy = [...따봉]
                  copy[i]++;
                  따봉수정(copy);
                }}>
                  👍
                </span>
                {따봉[i]}
              </h4>
              <p>4월 27일 발행</p>
            </div>
          )
        })
      }

      {
        modal ? <Modal 
        글제목={글제목} 
        index={modalNum}
        글제목수정={글제목수정}
        color={'skyblue'}/> : null
      }
    </div>
  )
}

function Modal(props) {
  return (
    <div className='modal' style={{background : props.color}}>
      <h4>{props.글제목[props.index]}</h4>
      <p>날짜</p>
      <p>내용</p>
      <button onClick={()=>{
        let array = props.글제목;
        let copy = [...array];
        copy[0] = '여자 코트 추천';
        props.글제목수정(copy);
      }}>글수정</button>
    </div>
  )
}

export default App;
