import 'bootstrap/dist/css/bootstrap.min.css';
import './App.css';
import { Button, Navbar, Container, Nav, NavDropdown} from 'react-bootstrap';

function App() {
  return (
    <div className="App">
      <Navbar bg="light" data-bs-theme="light">
        <Container>
          <Navbar.Brand href="#home">ShoeShop</Navbar.Brand>
          <Nav className="me-auto">
            <Nav.Link href="#home">Home</Nav.Link>
            <Nav.Link href="#cart">Cart</Nav.Link>
          </Nav>
        </Container>
      </Navbar>

      <div className='main-bg'>
        
      </div>
    </div>
  );
}

export default App;
