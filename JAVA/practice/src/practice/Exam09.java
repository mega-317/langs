package practice;

public class Exam09 {
	public static void main(String[] args) {
		Automobile auto = new Automobile();
		
		auto.upSpeed(270);
		auto.downSpeed(30);
		System.out.println("승용차의 속도는 " + auto.getSpeed() + "km 입니다");
	}
}
