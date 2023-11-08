package tp1.view;

import static tp1.util.MyStringUtils.repeat;
import tp1.logic.Game;
import tp1.logic.GameStatus;
import tp1.util.MyStringUtils;

public class BoardPrinter extends GamePrinter {
	
	private static final String SPACE = " ";

	private static final String CELL_BORDER_CHAR = "─";

	private static final String VERTICAL_DELIMITER = "|";

	private static final String NEW_LINE = System.lineSeparator();

	private static final int CELL_SIZE = 6;

	private static final String CELL_BORDER = repeat(CELL_BORDER_CHAR, CELL_SIZE+1);

	private static final String ROW_BORDER = SPACE + repeat(CELL_BORDER, Game.DIM_X) + NEW_LINE;
	
	
	public BoardPrinter(GameStatus game) {
		super(game);
	}
		
	/**
	 * Builds a string that represent the game status
	 * 
	 * @return the string that represents the game status.
	 */
	protected String getInfo() {
		StringBuilder buffer = new StringBuilder();
		/* @formatter:off */
		buffer
		.append(Messages.NUMBER_OF_CYCLES).append(SPACE).append(game.getCycle()).append(NEW_LINE)
		.append(game.stateToString())
		.append(Messages.REMAINING_ALIENS).append(SPACE).append(game.getRemainingAliens()).append(NEW_LINE);
		/* @formatter:on */
		return buffer.toString();
	}

	@Override
	public String toString() {
		
		StringBuilder str = new StringBuilder();
	
		// Game Status
		str.append(getInfo());

		// Paint game board
		str.append(ROW_BORDER);

		for (int row = 0; row < Game.DIM_Y; row++) {
			str.append(VERTICAL_DELIMITER);
			for (int col = 0; col < Game.DIM_X; col++) {
				str.append(MyStringUtils.center(game.positionToString(col, row), CELL_SIZE));
				str.append(VERTICAL_DELIMITER);
			}
			str.append(NEW_LINE);
			str.append(ROW_BORDER);
		}

		return str.toString();
	}

	public String endMessage() {
		StringBuilder sb = new StringBuilder();
		
		if (this.game.playerWin()) sb.append(Messages.PLAYER_WINS);
		else if (this.game.aliensWin()) sb.append(Messages.ALIENS_WIN);
		else sb.append(Messages.PLAYER_QUITS);
		
		return sb.toString();
	}
}

