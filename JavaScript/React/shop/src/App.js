import 'bootstrap/dist/css/bootstrap.min.css';
import './App.css';
import { Navbar, Container, Nav } from 'react-bootstrap';
import { useState } from 'react';
import data from './data.js';
import { Route, Routes, Link, useNavigate, Outlet } from 'react-router-dom';
import Detail from './routes/Detail.js';
import axios from 'axios';

function App() {

  let [shoes, setShoes] = useState(data);
  let navigate = useNavigate();
  console.log(shoes);

  return (
    <div className="App">

      <Navbar bg="light" data-bs-theme="light">
        <Container>
          <Navbar.Brand href="/">ShoeShop</Navbar.Brand>
          <Nav className="me-auto">
            <Nav.Link onClick={()=>{ navigate('/')}}>Home</Nav.Link>
            <Nav.Link onClick={()=>{ navigate('/detail')}}>Detail</Nav.Link>
          </Nav>
        </Container>
      </Navbar>

      <Routes>
        <Route path="/" element={
          <>
            <div className='main-bg'></div>
            <div className='container'>
              <div className='row'>
                {
                  shoes.map((a, i)=>{
                    return (
                      <Card shoes={a} index={i+1}/>
                    )  
                  })
                }
              </div>
            </div>
            <button onClick={()=>{
              axios.get('https://codingapple1.github.io/shop/data2.json')
              .then((result)=>{ 
                console.log(result.data)
                let copy = [...shoes, ...result.data];
                setShoes(copy);
              })
              .catch(()=>{
                console.log('실패함 ㅅㄱ')
              })
            }}>버튼</button>
          </>
        }/>
        
        <Route path="/detail/:id" element={ <Detail shoes={shoes} />}/>
        <Route path="/about" element={ <About /> }>
          <Route path="member" element={ <div>멤버임</div> } />
          <Route path="location" element={ <div>위치정보임</div> } />
        </Route>
        <Route path="*" element={ <div>404 error</div> } />
      </Routes>

    </div>
  );
}

function About(){
  return (
    <div>
      <h4>회사정보임</h4>
      <Outlet></Outlet>
    </div>
  )
}

function Card(props){
  return (
    <div className='col-md-4'>
      <img src={`https://codingapple1.github.io/shop/shoes${props.index}.jpg`} width="80%"/>
      <h4>{props.shoes.title}</h4>
      <p>{props.shoes.price}</p>
    </div>
  )
}

export default App;
