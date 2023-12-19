package tp1.control.commands;

import tp1.control.ExecutionResult;
import tp1.exceptions.CommandParseException;
import tp1.logic.Game;
import tp1.logic.GameModel;

/**
 * Represents a user action in the game.
 *
 */
public abstract class Command {
	protected String commandName;
	public Command(String commandName){
		this.commandName=commandName;
		String[] commandInfoWords = commandName.split(" ");
	}

	  protected abstract String getName();
	  protected abstract String getShortcut();
	  protected abstract String getDetails();
	  protected abstract String getHelp();
	  
	  /**
		 * Execute the command.
		 * 
		 * @param game Where to execute the command.
		 * 
		 * @return {@code ExecutionResult} representing if command was successful and if board must be printed
		 */

	  public abstract ExecutionResult execute(GameModel game);
	  public abstract Command parse(String[] parameter) throws CommandParseException;
	  protected boolean matchCommandName(String name) {
		    return getShortcut().equalsIgnoreCase(name) || 
		        getName().equalsIgnoreCase(name);
	  }
	  
	  public String helpText(){
	    return getDetails() + " : " + getHelp() + "\n";
	  }


	  //esto no se que tiene que hacer
}
