package practice;

public class Automobile extends Car {
	
	int seatNum;
	
	int getSeatNum() {
		return seatNum;
	}
	
	@Override
	void upSpeed(int value) {
		if (speed + value >= 300) 	
			speed = 300;
		else 
			speed = speed + (int)value;
		}
}
