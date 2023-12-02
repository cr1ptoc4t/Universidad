package tp1.control.commands;

public abstract class NoParamsCommand extends Command {


	public NoParamsCommand(String commandName) {
		super(commandName);
	}

	@Override
	public Command parse(String[] commandWords) {
		//TODO fill with your code

		Command command;
		//for (Command c: availableCommands) {

		//}
		//return command;

		//for(Command c : availableCommands){  //comands es la lista de comandos que tenemos
			//if(c.commandName(commandWords[0])){
			//	return c.parse(commandWords);
			//}

		//}
		//return new noParamsCommand("none");

		if(commandWords[0].equals(getName())||commandWords[0].equals(getShortcut())){
			command = new ShootCommand();
		} else{
			command=null;
		}



		return command;
	}


}
