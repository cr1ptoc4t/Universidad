<!-- TOC start -->
- [Assignment 2 - Part I: Space Invaders Refactored](#práctica-2---parte-i-space-invaders-refactored)
	- [Introduction](#introducción)
	- [Refactoring the solution of the previous assignment](#refactorización-de-la-solución-de-la-práctica-anterior)
		- [*Command* Pattern](#patrón-command)
		- [Inheritance and polymorphism](#herencia-y-polimorfismo)
		- [Game Object Container](#contenedor-de-objetos-del-juego)
		- [Interfaces for `Game`](#interfaces-de-game)
		- [Interfaces for `GameObject`](#interfaces-de-gameobject)
	- [Testing](#pruebas)
<!-- TOC end -->
<!-- TOC --><a name="práctica-2-parte-i-space-invaders-refactored"></a>
# Assignment 2 - Part I: Space Invaders Refactored
 
**Objectives:** Inheritance, polymorphism, abstract classes, and interfaces.

**Frequently asked questions**: As usual (and normal), if you have doubts, we will compile them in this [Frequently Asked Questions document](../faq.md). To find out about the latest changes, [you can check the history of the document](https://github.com/informaticaucm-TPI/2324-SpaceInvaders-SOLUCION/commits/main/enunciados/faq.md).

<!-- TOC --><a name="introducción"></a>
## Introduction

This assignment consists, fundamentally, of applying the mechanisms offered by OOP to improve the code developed so far in Assignment 1. In particular, we will include the following improvements:

- In *Part I* of Assignment 2 we will refactor[^1] the code from [Assignment 1](../practica1/assignment1.md), thus preparing it for *Part II*. At the end of the refactoring, the assignment must pass the same tests that were passed in Assignment 1.

 - We will modify part of the controller, distributing its functionality among a set of classes, better structured, in order to facilitate subsequent extensions.

 - We're going to make use of inheritance to rearrange in-game items. As we've seen, there's a lot of repeated code in the different types of objects. Therefore, we are creating a class hierarchy that allows us to extend the functionality of the game more easily.
   
 - Inheritance will also allow us to redefine how we store game state information. In the previous assignment, since we didn't use inheritance, we had to have a list for each set of objects. However, in this version of the assignment, we will be able to use a single data structure to store all game objects.

- In *Part II*, once the assignment has been refactored, we will add new objects and new commands to the game, in a safe, orderly and reliable way, thanks to the new code structure.

[^1]: Refactoring is changing the structure of the code without changing its functionality. The aim is to improve the code. 

The above changes will be carried out progressively. The main goal is to extend the assignment in a robust way, preserving functionality in every step we take, and seeking to modify as little code as possible when we extend it.

<!-- TOC --><a name="refactorización-de-la-solución-de-la-práctica-anterior"></a>
## Refactoring the solution from the previous assignment

<!-- TOC --><a name="patrón-command"></a>
### *Command* Pattern

In the previous assignment, the user could perform several actions: move, shoot, call for help, etc. The technical goal is to be able to add new actions without having to modify code outside the new action. To this end, let's introduce the *Command* [^2] design pattern, which is especially suitable for this type of situation. The general idea is to encapsulate each user action in its own class. Each action will correspond to a command, so that the behaviour of one command will be completely isolated from the rest.

[^2]: The one we will use is a variant of the *Command design pattern*, one of the twenty-three software patterns presented in the foundational software patterns book "Design Patterns: Elements of Reusable Object-Oriented Software" first published in 1994. The general idea of the *Command pattern* is to encapsulate each command in its own class.

The following entities will be involved in the *Command* pattern, which we will explain in several steps, as we go deeper into the details:

- The `Command` class is an abstract class that encapsulates the common functionality of all concrete commands.
- The `NoParamsCommand` class is an abstract class that inherits from `Command` and serves as the basis for all commands that have no parameters, such as `none`, `reset` or `help`.
- The specific commands correspond to the user's actions: `MoveCommand`, `HelpCommand`, `ExitCommand`, ... 
- Each action will have its own class and each command will have three basic methods:
  - `protected boolean matchCommand(String)` checks whether an action entered by keyboard corresponds to that of the command.
  - `public Command parse(String[])` instantiates the command, given the user-provided parameters.
  - `public ExecutionResult execute(Game)` executes the action of the command, modifying the game.  

- The `Controller` class contains much less code then in the previous assignment since a large part of its functionality is now delegated to the specific command classes, as explained below.

In the previous assignment, in order to know which command was executed, **the Game loop**, implemented using the controller's `run()` method, which contained a `switch` (or a sequence of nested `if`) whose options corresponded to the different commands.

In the new version, the driver's `run()` method will look something like this. Your code doesn't have to be exactly the same, but the important thing is that you see that it resembles this proposal.

```java
while (!game.isFinished()) {

  String[] userWords = prompt();
  Command command = CommandGenerator.parse(userWords);

  if (command != null) { 
	
	ExecutionResult result = command.execute(game);

    if (result.success()) { 
    	if (result.draw()) 
			printGame();
    }
	else
    	System.out.println(result.errorMessage());
	} 
	else 
		System.out.format(Messages.UNKNOWN_COMMAND);
}  
```

While the game is not over, in the loop we read an action from the console, parse it syntactically to get the associated command, execute the command and, if the execution is successful and the state of the game has changed, we draw it. Otherwise, we show an error.

In the loop above, the key moment corresponds to the line of code:

```java
	Command command = CommandGenerator.parse(userWords);
```

The controller only handles abstract commands, so it doesn't know which particular command will be executed, or what exactly the command will do. This is the key mechanism that will make it easier for us to add new specific commands.

The `parse(String[])` method is a static method of the `CommandGenerator` class, responsible for finding the specific command associated with the user's input. To do this, the `CommandGenerator` class maintains a `AVAILABLE_COMMANDS` list cof available commands. This method traverses the list of commands to
determine, by calling the `parse(String[])` method of each command which one the user input corresponds to. When it finds it, it processes the possible parameters, instantiates that same type of command, and returns it to the controller.

The skeleton of the `CommandGenerator` code is as follows:

```java
public class CommandGenerator {

	private static final List<Command> AVAILABLE_COMMANDS = Arrays.asList(
		new MoveCommand(),
		new ListCommand(),
		new ResetCommand(),
		new HelpCommand(),
		// ...
	);
}
```

The `AVAILABLE_COMMANDS` attribute is used in the following `CommandGenerator` methods:

- The method
	```java 
	public static Command parse(String[] commandWords)
	```
	invokes the `parse` method of each `Command subclass, as explained above. 

- The method
	```java
	public static String commandHelp()
	```
	has a similar structure to the previous method, but it invokes the `helpText()` method of each subclass of `Command`. In turn, it is invoked by the `execute` method of the `HelpCommand` class.

After receiving a `Command` object from the `parse` method, the controller will simply ask the *game* as a parameter to execute the corresponding action.

All concrete commands have a series of information associated with them, such as the `name`, `shortcut`, `detail`, etc. For example, the specific command `HelpCommand` has the following code:

```java
public class HelpCommand extends NoParamsCommand {
	@Override
	protected String getName() {
		return Messages.COMMAND_HELP_NAME;
	}
	
	@Override
	protected String getShortcut() {
		return Messages.COMMAND_HELP_SHORTCUT;
	}
	
	@Override
	public String getDetails() {
		return Messages.COMMAND_HELP_DETAILS;
	}

  // ...
}
```

<!-- Abstract methods can not be static. Those methods must be declared in the Command class -->

As already stated, the specific command classes inherit from the `Command` class. The `Command` class must implement as abstract, so it's the concrete commands that implement its functionality:

- The `execute` method performs the action on the *game* and returns a value of type `ExecutionResult`, which represents the result of the execution of the command: whether it was successful or not, the error message in case it is necessary, and if necessary to redraw the state of the game. `ExecutionResult` is a record class ([Java Record](https://www.geeksforgeeks.org/what-are-java-records-and-how-to-use-them-alongside-constructors-and-methods/)) that allows us to return multiple values as a result of a method (as if it were a tuple or C/C++ struct-style dataset).

- The `parse(String[])` method returns an instance of the particular command. Like every command processes its own parameters, this method will either return this or create a new instance of the same class. In the event that the arguments entered by the user are invalid for the command, the `parse(String[])` method will return `null`.

The `NoParamsCommand` abstract class, which it inherits from `Command` class, is used to represent all commands that do not need parameters, such as ***help*** or ***reset*** and from which commands such as `HelpCommand` or `ResetCommand`. This class can implement the `parse` method because all those commands *parse* the same: just check that the user has only entered a word that matches the name or abbreviation of the command, in this case can be returned `this`. Obviously, the implementation of `execute` must be postponed to the specific commands, so the `NoParamsCommand` class must be abstract. 

Also note that for commands with parameters, it would not be correct for their `parse` method to return `this`, but it is necessary to return a new command of the corresponding type. 

<!-- TOC --><a name="herencia-y-polimorfismo"></a>
### Inheritance y polymorphism

One of the most frustrating and error-prone parts of the first assignment has been having to replicate code in in-game items and item lists. We are going to solve this discomfort by using the mechanism par excellence of object-oriented programming: **inheritance**. 

With the `Command` pattern, we wanted to be able to introduce new commands without having to change the controller code. Similarly, we want to be able to add new game items without having to modify the rest of the code. The key to this is that `Game` doesn't handle specific objects, but rather handles objects of an abstract entity that we're going to call `GameObject`. The rest of the in-game items will be inherited from this entity. Since all the elements of the game are going to be `GameObject`, they will share most of the attributes and methods, and each of the specific game objects will be in charge of implementing its own behaviour.

All `GameObject` objects have a position in the game, a life, auxiliary methods to manipulate that position and that life, and a series of methods that we call during each cycle of the game, such as, for example, when they need to do something of their own with that object at a specific moment in its life-cycle:

- `computerAction()` y `automaticMove()` These are called at each iteration of the game loop.
- `onDelete()`: It is called when the item exits the game, just before it disappears.
- `isAlive()`: indicates whether or not this element has any lives left, returning true if it does and false if it does not. In this case, it must be removed from the game.

It is common for simple objects to have some of these methods empty or with trivial functionality. For instance, in `UCMShip`, which does not move automatically, the implementation of the `automaticMove` method will be empty.

`GameObject` will be the base class in the class hierarchy of in-game objects:

- The `GameObject` abstract class will have the corresponding attributes and methods for controlling the position on the board and a reference to the `Game` class.
- From `GameObject` they will inherit `Ship` and `Weapon` classes. `Ship` will represent the ships in the game, while `Weapon` will represent objects that deal damage.
- The `EnemyShip` class, a subclass of `Ship`, will represent enemy ships, including the UFO. Among other elements, this class will have to manage the movement of the ships and the points that are obtained when destroyed by the player.
- Similarly, the `UCMShip` class will also be a subclass of the `Ship` class and will represent the ship the player controls.
- The `AlienShip` class, a subclass of `EnemyShip` class, will represent the ships in the game that move with a group behaviour, i.e. all in the same direction. Your movement will follow the same rules that were defined in Assignment 1.
- The `RegularAlien` and `DestroyerAlien` classes will inherit from the `AlienShip` class, implementing its behaviour.
- From the `Weapon` class, it will inherit `EnemyWeapon` and `UCMWeapon`.
- Finally, the `Bomb` and `UCMLaser` classes will inherit, respectively, from `EnemyWeapon` and `UCMWeapon` classes, both of them are subclasses of the `Weapon` class. They represent the shots fired by the `DestroyerAlien` and `UCMShip` ships, respectively.
- The `Shockwave` class will also inherit from the `UCMWeapon` class. Even if it doesn't move and has a different way of attacking as well, we can consider it as a weapon. If, later on, we had other *power-ups* we could refine the class hierarchy to have weapons with different behaviours.

t is important to note that the previous version of the assignment was designed with the structure of this second assignment in mind so that refactoring would be easier. In particular, most of the game logic was already distributed in the game elements themselves, and the `Game` was relieved of this task.

<!-- TOC --><a name="contenedor-de-objetos-del-juego"></a>
### Game Object Container

Now that we've got all the objects on the board to belong to (some subclass of) the `GameObject` class, it would also be a good idea to simplify by refactoring the code related to lists. In this assignment, we will use a class called `GameObjectContainer` which will be in charge of managing the list of elements of type `GameObject`. 

The `GameObjectContainer` encapsulates the data structure used to store the objects representing elements of the game (hereinafter we will refer to the unique instance of this class as the container) as well as the methods for updating them, deleting them, etc. It will include enemy ships, fired guns, and also the `UCMShip` itself. For the store itself, we can use any type of collection (and since it is encapsulated, we can change to another type of collection any time we want without affecting the rest of the code); for simplicity, we propose to use the `ArrayList` of `GameObject` class, typed using the `List` interface, declared as follows:

```java
public class GameObjectContainer {

	private List<GameObject> gameObjects;

	public GameObjectContainer() {
		gameObjects = new ArrayList<>();
	}
	//...
}
```

n the container we will handle abstractions of the objects, so we cannot (and should not!) distinguish who is who.

<!-- UCMShip forma parte del contenedor para que los ataques a UCMShip se puedan meter en el saco general de ataques entre objetos -->

Finally, it is very important that the details of the `GameObjectContainer` class implementation are private. This allows us to change the implementation (the collection type) without having to modify code in the rest of the assignment.

<!-- TOC --><a name="interfaces-de-game"></a>
### `Game` Interfaces

In Assignment 1, the `Game` class was used from three different contexts, corresponding to the three types of `Game` references that were maintained elsewhere in the code:

- In the `Controller` class, a reference to `Game` is maintained in order to be able to send the user's instructions to the game (now through the execute(Game) method of the commands). In this context, methods such as `move(Move move)`, `shootLaser()` or `reset()` are used.

- In the `GamePrinter` class, it also maintains a reference to `Game` to request the data that is due show. Methods such as `getCycle()`, `getRemainingAliens()` or `positionToString(int, int)` are used.

- From the game objects, a reference to `Game` is also maintained, in this case to communicate to the game what has to do with attacks or the inclusion of new objects (for example, to add a bomb from `DestroyerAlien`). Methods such as `addObject(GameObject)` or `receivePoints(int). These methods are often called *callbacks*.

Even if there is such a classification of methods in `Game`, there is nothing to prohibit `GameObject` from invoking `reset`, for example, or from invoking `addObject` from `GamePrinter` to add a bomb or laser. After all, these are all public `Game` methods and can be used from any object that has a reference to `Game`.

To solve this problem, we can use interfaces. First, we will create a distinct interface for each of these three contexts. Each interface will provide a ***partial view*** of `Game` with just a few of its methods. Specifically, let's define `GameModel` for `Controller`, `GameStatus` for `GamePrinter`, and `GameWorld` for `GameObject`.

For example:

```java
public interface GameModel {

	public boolean move(Move move);
	public boolean shootLaser();
	public void reset();
	// ...
}
```

Once the interfaces are defined, we'll have `Game` implement them:

```java
public class Game implements GameModel, GameStatus, GameWorld {

	// ... 

	private GameObjectContainer container;
	private UCMShip player;
	// ...

	public Game (Level level, long seed){
		this.seed = seed;
		this.level = level;
		initGame();
	}
		
	private void initGame () {	
		rand = new Random(seed);
		doExit = false;
		currentCycle = 0;
		
		alienManager = new AlienManager(this, level);
		container = alienManager.initialize();
		player = new UCMShip(this, new Position(DIM_X / 2, DIM_Y - 1));
		container.add(player);
	}

	// GameModel Methods
	// ...
	// GameWorld Methods
	// ...
	// GameStatus Methods
	// ...
	// Other methods
	// ...
}
```

Finally, in each of the contexts in which `Game` was used, we replaced the type of the reference with the corresponding interface. For example, in `Controller` we will have a reference to a `GameModel`. Similarly, we've replaced the type of the `Command` `execute` parameter so that it supports a `GameModel` and not a `Game`:

```java
public abstract ExecutionResult execute(GameModel game);
```

<!-- TOC --><a name="interfaces-de-gameobject"></a>
### `GameObject` interfaces

We are going to use another interface to encapsulate the methods related to the *attacks*. The `GameObject` class implements the `GameItem` interface. The idea is that every object in the game should have the ability to attack or be attacked. Therefore, we have to implement the possibility of receiving an attack from each of the projectiles.

```java
public interface GameItem {
	public boolean performAttack(GameItem other);
	public boolean receiveAttack(EnemyWeapon weapon);
	public boolean receiveAttack(UCMWeapon weapon);
	....
}
```
Notice that the `receiveAttack` method is overloaded. Implementations of these methods will be included in the implementation of `GameObject` (or its subclasses). The `DestroyerAlien` don't do harm, but what they do is drop bombs, which are the ones that really do damage. If a game object can attack, it will have to overwrite the method and implement the logic of its attack.

Similarly, all items can take damage from another item. By default, they don't receive it. But, for example, aliens and bombs do take damage from the laser, and the player and the laser do take attacks from the
pumps.

<!-- TOC --><a name="pruebas"></a>
## Testing

Recall that the functionality of the refactored code should be exactly the same as that of the original code, for which reason, the refactored code should pass exactly the same black-box (i.e. functional) system-level tests as the original code.

This allows us to set up the structure to easily add new commands and game objects in *Part II* of this assignment.

To simplify the testing procedure, we are going to slightly "misuse" the [JUnit](https://junit.org/) support provided by Eclipse. JUnit is a widely-used unit-testing framework for Java applications. You will surely see and use JUnit, or similar, in other subjects of your degree.

Together with the template for the solution of the assignment, we include the  `tp1.Tests` class which contains JUnit tests, one for each of the test cases of the previous assignment.

Before trying to execute the JUnit tests, you will need to add the JUnit libraries
to your project by choosing *Project > Properties* on the Eclipse menu and then selecting *Java Build Path* and finally the *Libraries* tab. Next, click on the **Add Library...** button.

![](./imgs/00-ProjectProjerties.jpg)

In the new window, choose *JUnit* and click on the *Finish* button.

![](./imgs/01-AddJUnit.jpg)

On returning to the project properties window, click on the button *Apply and Close*.

Now that you have included the JUnit libraries, if you click with the right button on the file `Tests.java` and then choose *Run As*, there should now be a new option available called **JUnit Test**.

![](./imgs/02-RunAsJUnitTest.jpg)

On choosing the JUnit Test option, Eclipse opens a window which allows us to choose which of the tests we want to execute and to then visualise the result of their exeuction. Note that the JUnit test-execution results simply tell us which of the tests passed and which failed where, in our case, a test fails if there is any difference between the output of the program and the expected output. To obtain more information about the failed tests in order to understand *why* a test failed, you will need to use the test procedure of the previous assignment. 

<!-- ![Fallo JUnit](./imgs/03-JUnitFailed.jpg) -->
<figure>
  <img src="./imgs/03-JUnitFailed.jpg"
     alt="Failed JUnit">
  <figcaption>JUnit Test Fail</figcaption>
</figure>

<!-- ![Todas las pruebas JUnit tienen éxito](./imgs/04-JUnitPass.jpg) -->
<figure>
  <img src="./imgs/04-JUnitPass.jpg"
     alt="Successful JUnit">
  <figcaption>All JUnit test are successful</figcaption>
</figure>
