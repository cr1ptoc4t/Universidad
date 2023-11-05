package tp1.logic;

/**
 * Represents the allowed movements in the game
 *
 */
public enum Move {
	LEFT(-1,0), LLEFT(-2,0), RIGHT(1,0), RRIGHT(2,0), DOWN(0,1), UP(0,-1), NONE(0,0);
	
	private int x;
	private int y;
	
	private Move(int x, int y) {
		this.x=x;
		this.y=y;
	}
	
	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}


	//TODO fill your code
	
	public void setX (int x) {
		this.x=x;
	}
	
	public void setY(int y) {
		this.y=y;
	}
	
	public static Move stringAMov(String str) {
		
		Move ret= NONE;
		
		switch(str) {
		case "left":
			ret= LEFT;
			break;
		case "right":
			ret= RIGHT;
			break;
		case "lleft":
			ret= LLEFT;
			break;
		case "rright":
			ret= RRIGHT;
		}
		return ret;
	}

	public Move opuesto(){
		Move ret=LLEFT;
		switch (this){
			case UP:
				ret= DOWN;
				break;
			case DOWN:
				ret=UP;
				break;
			case LEFT:
				ret=RIGHT;
				break;
			case RIGHT:
				ret=LEFT;
				break;
			case LLEFT:
				ret=RRIGHT;
		}

		return ret;
	}
	
}
