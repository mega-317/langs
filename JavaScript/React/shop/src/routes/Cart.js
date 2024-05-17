import { Table } from "react-bootstrap";
import { useSelector } from "react-redux";

export default function Cart() {

    let state = useSelector((state)=> state )
    console.log(state.cart)

    return (
        <div>
            <Table>
                <thead>
                    <tr>
                        <th>#</th>
                        <th>상품명</th>
                        <th>수량</th>
                        <th>변경하기</th>
                    </tr>
                </thead>
                {
                    state.cart.map((a, i)=>{
                        return (
                            <tbody>
                                <tr>
                                    <td>{i+1}</td>
                                    <td>{a.name}</td>
                                    <td>{a.count}</td>
                                    <td>변경하기</td>
                                </tr>
                            </tbody>
                        )
                    })
                }
            </Table>
        </div>
    )
}