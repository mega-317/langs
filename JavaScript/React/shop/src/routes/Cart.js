import { Table } from "react-bootstrap";

export default function Cart() {

    

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
                <tbody>
                    <tr>
                        <td>1</td>
                        <td>상품명</td>
                        <td>수량</td>
                        <td>변경하기</td>
                    </tr>
                </tbody>
            </Table>
        </div>
    )
}