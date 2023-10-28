# Assignment 1: Space Invaders

**Deadline: 31st of October 2023, 9:00 hrs**
 
**Objectives:** Introduction to object orientation and to Java; use of arrays and enumerations; string handling with the `String` class; input-output on the console.

**Frequently Asked Questions**: As usual (and normal), you may have questions, we will compile them in this [frequently asked questions document](../faq_en.md). To know the latest changes that have been introduced, you can consult [the history of the document](https://github.com/informaticaucm-TPI/2324-SpaceInvaders-SOLUCION/commits/main/enunciados/faq_en.md).

<!-- TOC start -->
  * [Copy Detection](#control-de-copias)
- [1. Description of the assignment](#1-descripción-de-la-práctica)
  * [1.1 Introduction](#11-introducción)
  * [1.2. Details about the assignment](#12-detalles-sobre-la-práctica)
  * [1.3. Game objects](#13-objetos-del-juego)
- [2. Game organization](#2-organización-del-juego)
  * [2.1 Draw](#21-draw)
  * [2.2 User actions](#22-user-actions)
  * [2.3 Computer actions](#23-computer-actions)
  * [2.4 Automatic moves](#24-automatic-moves)
- [3. Implementation ](#3-implementación)
- [4. Submission of the assignment](#4-entrega-de-la-práctica)
- [5. Testing](#5-pruebas)
<!-- TOC end -->

<!-- TOC --><a name="control-de-copias"></a>
## Copy Detection

For each of the TP assignments, all the submissions from all the different TP groups will be checked using anti-plagiarism software, firstly by comparing them all pairwise and secondly, by searching to see if any of their code is copied from other sources on the Internet. 

Any plagiarism detected will be reported to the _Comité de Actuación ante Copias_ which, after interviewing the student or students in question, will decide whether further action is appropriate, and if so, will propose one of the following sanctions:


- A grade of zero for the TP-course exam session (*convocatoria*) to which the assignment belongs.
- A grade of zero for all the TP-course exam sessions (*convocatorias) for that year.
- Opening of disciplinary proceedings (*apertura de un expediente académico*) with the relevant university authority (*Inspección de Servicios*).

<!-- TOC --><a name="1-descripción-de-la-práctica"></a>
# 1. Description of the assignment

<!-- TOC --><a name="11-introducción"></a>
## 1.1 Introduction

Space Invaders was one of the early games associated with the *shoot 'em up* or *space shooter* genre. It is currently considered one of the most influential and important video games in history. The objective of the game is to control a spaceship to destroy the alien ships that appear in space by shooting a laser. There are many clones and modern versions of the game that have introduced new features, such as types of weapons, shields and superpowers.

![Snapshot of the classical version of videogame (Source: www.smithsonianmag.com)](imgs/Bitmap/Pr1/screenshot1.png)

For this assignment, we will use elements from the classic game as well as some new features introduced in more modern versions. In the original game, the action takes place in real-time, meaning that enemies act continuously regardless of the player's actions. However, in our case, the game will be turn-based, where the player can take one action pin each game cycle, causing the game to pause until the player indicates their action. The ships will then update to perform their corresponding movements or actions.

![Snapshot of a modern version](imgs/Bitmap/Pr1/screenshot2.jpg)

If you have not played or are not familiar with the game, we recommend you to play it before developing the assignment. There is a free version, available through the browser via this link: https://www.minijuegos.com/juego/space-invaders.

During this term, we will progressively develop our own version of the game. We will start with a simplified version, and we will improve its implementation to easily increase its complexity. In the first assignment, we aim to implement the game using the console.


<!-- TOC --><a name="12-detalles-sobre-la-práctica"></a>
## 1.2. Details of the assignment

In our first assignment, we will consider that the game consists of a **9 x 8** board (9 colummns by 8 rows). The top-left cell is (0, 0), and the bottom-right cell is (8, 7). Each cell can be occupied by an alien spaceship, UCMShip (the user-controlled ship), a *UFO*, UCMShip's laser, or a bomb launched by an alien spaceship. Cells that are not occupied will be considered empty cells. To distinguish between the shots from both types of ships, from now on, we will use the term *laser* to refer to the shot fired by UCMShip and *bomb* for the shot fired by the alien spaceships.

The alien spaceships will move in groups, meaning that they will all perform the same movement in the same cycle. Initially, the ships will move to the left at a speed relative to the selected difficulty level. When one of the spaceships reaches the edge of the board, all the ships will move down by one cell. In the next cycle, the ships will begin moving horizontally towards the opposite edge, just like in the original game.

If an alien ship manages to reach the row where UCMShip is located, or UCMShip runs out of damage points, the player will have lost the game. Instead, the player will win when they has destroyed all the alien spaceships, that is, if during the **Update**, there are no alien ships left on the board.

In this assignment we will only consider two types of alien spaceships: *common ship* and *destroyer ship*.

In each game cycle, the following actions are performed sequentially:

1. ***Draw.*** The board is painted and the game information is displayed.

2. ***User command.*** The user can take an action such as moving laterally or firing a shot. The user can choose to do nothing during a cycle and let time pass. They can also execute commands that do not update the game, such as requesting a list of available commands.

3. ***Update***. The game is updated. The game update is done in two stages:
    - ***Computer action.*** The computer first performs the actions it determines need to be performed at the beginning of the update. In this version of the assignment, you can decide whether a *destroyer* ship fires a shot, or whether a *UFO* (see more details below) appears on the first row of the board.
    - ***Automatic moves.*** Objects on the board are moved according to their state and the state of the game. While they move, it is necessary to check if their movement has triggered an attack.

<!-- TOC --><a name="13-objetos-del-juego"></a>
## 1.3. Game objects

In this section we describe the type of objects that appear in the game and their behaviour.

### UCMShip Spaceship

***Behaviour***: It moves horizontally and fires shots. Initially, it is placed in cell (4,7).

***Resistance***: 3 points of damage.

***Shooting***: It fires a laser. There cannot be more than one laser on the board. The laser will move vertically until it reaches an alien spaceship, a bomb, a UFO, or reaches the end of the board, at which point a new one can be fired. When the player initiates the shot, the laser will have the same coordinates as UCMShip at the time of the action. However, its trajectory will be updated in the *update* action of the same cycle.

***Damage***: The standard behaviour of the shot causes one point of damage to the impacted ship.

### Regular Alien Spaceship (*regular alien*)

***Behaviour***: It moves horizontally. When an alien spaceship reaches the edge of the board, all the ships will move down by one cell, and their lateral movement will be towards the opposite edge, just as it happens in the original game. Vertical movement will occur in the cycle following their arrival at the board's edge, regardless of the speed established by the game's difficulty.

***Resistance***: 2 points of damage.

***Shooting***: This spaceship does not fire.

***Damage***: 5 points when destroyed.

### Destroyer Alien Spaceship (*destroyer alien*)

***Behaviour***: The movement is the same as the regular spaceship.

***Resistance***: 1 point of damage.

***Shooting***: Drop a bomb. The bomb's movement is vertical in the direction where UCMShip is located.

***Damage***: 1 point of damage.

***Points***: 10 points when destroyed.

### UFO (*ufo*)

***Behaviour***: It initially appears in cell (8,0), which is the upper-right corner. It moves horizontally one cell per cycle until it reaches the edge of the board or is destroyed by a UCMShip laser. If it is hit by a shot from UCMShip, it will provide the player with a superpower called *shockWave*. The *shockWave* does not stack: if the player already has one and hits a *UFO*, they will have only one active *shockWave* and not two. Once it has moved through the cells in its initial row, the *UFO* is removed from the board.

***Resistance***: 1 point of damage.

***Shooting***: This spaceship does not fire.

***Points***: 25 points when destroyed.

<!-- TOC --><a name="2-organización-del-juego"></a>
# 2. Game Organization

Next, we describe what happens in each part of the game cycle.

<!-- TOC --><a name="21-draw"></a>
## 2.1 Draw

In each cycle, the current state of the board will be displayed, along with the player's remaining damage points (*life*), the game cycle in which we are (initially 0), the accumulated score, the number of alien spaceships currently on screen, and whether or not we have a *shockWave*.

Each ship on the board displays its remaining life in square brackets. The user's laser is represented by the characters **'oo'** (without quotes), and the projectiles from the alien ships are represented by **'*'** (without quotes). We will also display the game's **prompt** to request the user's next action.

The board is displayed through the console interface using ASCII characters, as shown in the following example:

```
Number of cycles: 9
Life: 3
Points: 15
ShockWave: OFF
Remaining aliens: 10

──────────────────────────────────────────────────────────────── 
|      |      |      |      |      |      | U[1] |      |      |
──────────────────────────────────────────────────────────────── 
|      |      |      |      |      |      |      |      |      |
──────────────────────────────────────────────────────────────── 
|      |      |      | R[2] | R[2] | R[2] | R[2] |      |      |
──────────────────────────────────────────────────────────────── 
|      |      |      | R[2] | R[2] | R[2] | R[2] |      |      |
──────────────────────────────────────────────────────────────── 
|      |      |      |      | D[1] | D[1] |      |      |      |
──────────────────────────────────────────────────────────────── 
|      |      |      |  *   |      |      |      |      |      |
──────────────────────────────────────────────────────────────── 
|      |      |      |      |  oo  |      |      |      |      |
──────────────────────────────────────────────────────────────── 
|      |      |      |      | ^__^ |      |      |      |      |
──────────────────────────────────────────────────────────────── 

Command > 
```


<!-- TOC --><a name="22-user-actions"></a>
## 2.2 User actions

The user will be asked what they want to do, and they can respond with one of the following options:

- `move <left|lleft|right|rright>`: This command is used to move UCMShip. It accepts an argument indicating the direction and the number of cells for the movement: `left` (one cell to the left), `right` (one cell to the right), `lleft` (two cells to the left), or `rright` (two cells to the right).

- `shoot`: The UCMShip fires a shot if it can, which means if there is no laser already on the board.

- `shockwave`: The UCMShip launches a wave that causes one point of damage to all alien spaceships on the board. This action takes place in the same cycle in which the command is executed.

- `list`: It will display the name of the current ships, their points, damage, and resistance. In this version, it will be shown as follows:

```
Command > list
[U]CM Ship:  Harm: 1 - Shield: 3
[R]egular Alien: Points: 5 - Harm: 0 - Shield: 2
[D]estroyer Alien: Points: 10 - Harm: 1 - Shield: 1 
U[f]o: Points: 25 - Harm: 0 - Shield: 1
```

- `help`: This command prompts the application to display help on how to use the commands. One line will be displayed for each command. Each line has the name of the command followed by ':' and a brief description of what the command does.

```
Command > help
[m]ove <left|lleft|right|rright>: Moves UCM-Ship to the indicated direction.
[s]hoot: UCM-Ship launches a laser.
shock[W]ave: UCM-Ship releases a shock wave.
[l]ist: Prints the list of available ships.
[r]eset: Starts a new game.
[h]elp: Prints this help message.
[e]xit: Terminates the program.
[n]one: Skips one cycle.
```

- `reset`: This command allows you to restart the game, returning the game to the initial configuration.

- `exit`: This command allows you to exit the application, previously displaying the *Game Over* message.

- `none`: The user does not take any action.

**Notes on commands:**

- The application must allow commands written in lowercase, uppercase, or a mix of both.

- The application must allow the use of the first letter of the command (or the one indicated in square brackets, if that letter is already used) instead of the full command `[M]ove`, `[S]hoot`, `shock[W] ave`, `[L]ist`, `[R]eset`, `[H]elp`, `[E]xit`, `[N]one`.
  
- If the command is empty, it is identified as `none` and the game proceeds to the next game cycle.
 
- If the command is misspelled, does not exist, or cannot be executed, the application will display an error message.

- In the event that the user executes a command that does not change the game state, or an incorrect command, the board should not be redrawn.

<!-- TOC --><a name="23-computer-actions"></a>
## 2.3 Computer actions

In this first assignment the computer will have pseudo-random behaviour. One of the input parameters will be the difficulty level. We will define three levels: **EASY**, **HARD** and **INSANE**. Each level will determine:

- The number of *regular* spaceships that appear at the beginning of the game.
- The number of *destroyer* spaceships that appear at the beginning of game.
- The firing rate of *destroyer* spaceships. Frequency determines the probability of a ship dropping a bomb. Thus, if the frequency is 0.2, a ship will have a 20% probability of launching a bomb in a cycle, although since it is a probability, they may come out more widely -- or less -- depending on the randomness. It is important to note that there cannot be two bombs dropped by the same ship on the screen.
- The speed of the alien spaceships. This parameter determines the number of cycles that must pass for the ships to move **one cell**.
- The probability of a *UFO* appearing. Similarly, this parameter indicates the probability that the program will generate a *UFO*. When this happens, the *UFO* will be placed in cell (8, 0) and will advance one cell per cycle, regardless of the difficulty set. As with shooting, there can only be one *UFO* on the screen.

| Level   | Regular ships | Destroyer ships | Firing rate | Speed | UFO
| :---:   | :---:            | :---:      |  :---: |  :---: |  :---: 
|`EASY`   | 4 (in 1 row)                | 2        | 0.1 | 3 | 0.5
|`HARD`   | 8 (in 2 rows)               | 2        | 0.3 | 2 | 0.2
|`INSANE` | 8 (in 2 rows)               | 4        | 0.5 | 1 | 0.1

To control the random behaviour of the game, and to be able to repeat the same execution several times, we will use a **seed**. This optional value provides control over the behaviour of the program, which will allow us to replicate exactly the same execution.

In each cycle the program must decide if each *destroyer* ship launches a bomb (if possible) or if the *UFO* appears on the screen (if there is not one currently on the board).

It would be interesting if you tried different values for the number of spaceships and speed to find those combinations that are more enjoyable and playable.

<!-- TOC --><a name="24-automatic-moves"></a>
## 2.4 Automatic moves

In each cycle, the movements of the game objects occur, which can lead to attacks, and whose order is as follows:

- The position of the alien ships is updated.

- Advance in the trajectory of the existing bombs on the screen. Each bomb will move vertically -- from the ship dropping the bomb to the back row -- one cell each cycle.

   - If a bomb from an alien ship hits UCMShip, UCMShip suffers a decrease of one point of damage and the bomb is destroyed.

   - If UCMShip reaches 0 damage points, the following `String` will be used to represent that the ship is destroyed: `!xx!`.

   - If a bomb hits UCMShip's laser, both bomb and laser are destroyed.

- If the UFO is on the screen, its position is updated.

- Advance in the trajectory of the laser fired by UCMShip. The laser will move vertically -- from the last row to the first -- one cell each cycle. If a laser does not exist at the time **Update** is performed, this action will be ignored.

   - If the laser launched by UCMShip hits a bomb on an alien ship, both are removed from the board.

   - If UCMShip's laser hits an alien ship, the impacted ship suffers a decrease of one point of damage and the laser is destroyed.

   - If an alien ship reaches 0 damage points, it disappears from the board.

The game will end if one of the following scenarios occurs during the **Update** action:

1. All alien spaceships are destroyed.
2. One of the alien spaceships reaches the row where UCMShip is located.
3. UCMShip's resistance reaches 0 points of damage.

When the game ends, the winner must be shown: **'Player wins'** or **'Aliens win'**.

### Initial placement of the ships

- In the `EASY` level the ships will be placed in rows of 4, starting with row 1 and column 2. The *destroyer* ships are centred with respect to the *common* ships, as in the example below.

- In the `HARD` level another row of *common* ships must appear in row 2 of the board, so that the *destroyer* ships appear in row 3.

- In the `INSANE` level, two rows of *common* ships appear -- in rows 1 and 2 -- so that the four *destroyer* ships appear in row 3.

```
Number of cycles: 0
Life: 3
Points: 0
shockWave: OFF
Remaining aliens: 6

──────────────────────────────────────────────────────────────── 
|      |      |      |      |      |      |      |      |      |
──────────────────────────────────────────────────────────────── 
|      |      | R[2] | R[2] | R[2] | R[2] |      |      |      |
──────────────────────────────────────────────────────────────── 
|      |      |      | D[1] | D[1] |      |      |      |      |
──────────────────────────────────────────────────────────────── 
|      |      |      |      |      |      |      |      |      |
──────────────────────────────────────────────────────────────── 
|      |      |      |      |      |      |      |      |      |
──────────────────────────────────────────────────────────────── 
|      |      |      |      |      |      |      |      |      |
──────────────────────────────────────────────────────────────── 
|      |      |      |      |      |      |      |      |      |
──────────────────────────────────────────────────────────────── 
|      |      |      |      | ^__^ |      |      |      |      |
────────────────────────────────────────────────────────────────
```

UCMShip initially appears centred on the board.


### Application parameters

The program must accept one mandatory and one optional parameter via command line.

   - The first, called **level**, is the game level and is mandatory.

   - The second, called **seed**, contains the value of the seed used for the pseudo-random behaviour of the game and is optional.

![Execution options](imgs/Bitmap/Pr1/args.png)

<!-- TOC --><a name="3-detalles-de-implementación"></a>
# 3. Implementation

The proposed implementation for the first assignment may not be the best, since it does not make use of **inheritance** and **polymorphism**, two fundamental tools in object-oriented programming. Later on, we will explore ways to improve it by using the tools provided by object-oriented programming.

To implement the first version, we will need to copy and paste a lot of code, which is often considered a bad programming practice. Code duplication implies that it will be poorly maintainable and *testable*. There is a well-known programming principle called **DRY (Don't Repeat Yourself)**. According to this principle, no information should be duplicated, because duplication increases the complexity of future changes and evolution, can hinder clarity, and may lead to possible inconsistencies.

In the next assignment we will learn how to refactor the code to avoid repetitions.

To launch the application the `tp1.Main` class will be executed, therefore, it is recommended that all classes developed in this assignment be in the `tp1` package (or its subpackages).

### Game objects

To represent each of the types of elements that can appear on the board, which we will call game objects, you will need at least the following classes:

- `UCMShip`, `RegularAlien`, `DestroyerAlien`, `Ufo`: These classes encapsulate the behaviour of the game's ships. They have private attributes, such as their position `(column, row)`, their life, etc.

  All of these ships have `getSymbol()` methods, which return the symbol with which it appears on the board, and the `getDescription()` method, which returns its description as it appears when executing the `list` command.
  For example, for regular aliens those methods return `R` and `[R]egular Alien`, respectively. The first method will be used as a helper by `toString()` and the second by the `getInfo()` method, which returns the entire line shown by `list`.
  
- `UCMLaser`, `Bomb`: These classes represent the weapons that can appear in this version of the assignment, the laser fired by `UCMShip` and the bombs launched by the destroyer ships, respectively. They also need private attributes for their position, their *life*, the direction of their movement, and so on. Additionally, `Bomb` will need to store a reference to the destroyer ship that launched it.

- `ShockWave`: class that represents the *shock wave* that the player can launch on the board.

Both ships and weapons maintain a reference to `Game` (see below). This way, these classes can *communicate* with the `Game` class using its public methods. Among others, they need basic methods to know if they are alive, to know what their position is, if they are inside the board, to move following a given movement (`Move`), to receive damage, and so on.

#### Program actions

To implement the actions decided by the program (for example, a bomb being fired by a destroyer spaceship), the game objects will implement the method:

```java
    public void computerAction() {...}
```

For example, in the case of the `DestroyerAlien` class, this method must decide whether to fire a bomb. In this case, it will be necessary to note it in an attribute so that in the next movement, the bomb is created and added to the board.

#### Automatic movement

Objects that move automatically will implement a method like:

```java
    public void automaticMove() {...}
```
in this method, the change in the object's position will be implemented depending on its state and the game's state.

In the case of weapons, after the movement, it will generally be necessary to check whether the movement has produced an attack. The way to do this is through the `game` reference that we mentioned we would be maintained:

```java
    game.performAttack(this);
```

The game will be responsible for delivering this attack to each of the game objects that can receive it (in this example, laser and player).

#### Implementation of attacks

Weapons will have methods to implement their attack on other objects. For example, to implement the laser attack on the regular ships we will have a method in the `UCMLaser` class like:

```java
    public boolean performAttack(RegularAlien alien) {...}
```
Similarly, to implement the attack on a destroyer ship we will have a method in the class like:

```java
    public boolean performAttack(DestroyerAlien alien) {...}
```

Notice that we are using method overloading here. These methods first check that both the attacker and attacked are alive and share a position, and if so, they launch the attack. The effect of the attack on the attacker will be implemented directly in these methods. For example, the laser "dies" upon hitting an alien. However, the effect that the attack has on the attacked should be implemented not in the attacking class, but in the attacked class. To do this, we will need the objects to implement methods for receiving an attack from a weapon. For example, to implement the damage a regular alien ship receives from a laser, the `RegularAlien` class will implement a method like:

```java
    public boolean receiveAttack(UCMLaser weapon) {...}
```

In this case the implementation of `receiveAttack` will be limited to decreasing lives according to the damage exerted by `weapon`.


#### Removal of game objects

Game object will include a method like:

```java
    public void onDelete() {...}
```

which will be invoked when it is detected that the object has died, meaning it has zero lives, before the object is permanently removed from its container (see below).

This method will be responsible for carrying out those actions necessary at the time of object's removal. For example, alien ships will notify `AlienManager` of their elimination, so that it will update its counter of ships remaining on the board. Bombs will notify the ship that launched them that they have died, allowing the ship to launch a bomb again.

### Containers for game objects

On the board there is a UCMship and, at most, one laser and one UFO. However, there may be multiple regular alien ships, multiple destroyer ships, and multiple bombs. Therefore, we need classes that represent *containers* of these game objects.

You must implement the classes `RegularShipList`, `DestroyerShipList` and `BombList`, which contain **lists** of the respective **enemy** elements of the game, as well as auxiliary methods for their management. These lists will all be implemented using an array (large enough) and a counter. Additionally, the containers will be responsible for carrying the game's requests to each of their objects.

### Initialization and movement of alien spaceships

The `AlienManager` class has the function of managing, on one hand, the initialization of the board, that is, the initial positions of the alien spaceships and, on the other hand, of managing their synchronized movement. It has an attribute of the `Game` class and other attributes to track the situation of the *squadron* of ships (for example, to know how many alien spaceships are left, if the group of spaceships is at the edge of the board or if they have reached the bottom row of the board).

For initialization, the `AlienManager` class has methods like:

```java
    RegularAlienList initializeRegularAliens() {...}
    DestroyerAlienList initializeDestroyerAliens() {...}
```

### The model: the `Game` class

The `Game` class encapsulates the game's logic. There will be a single instance of `Game` in the program. Contains one instance of `RegularShipList`, one instance of `DestroyerShipList`, and one instance of `BombList`, among other object instances. It also has an `AlienManager` attribute, the cycle counter and the player's score. Finally, it also has a `Random rand` attribute to generate random values.

  It has, among others, the `update` method that updates the state of all the elements of the game. Its implementation will consist of performing the *computer actions* first and then the automatic movements (in the order specified above).


### Classes for control and visualization

- `Controller`: class to control the game's execution, asking the user what they want to do and updating the game according based on their input. The `Controller` class needs at least two private attributes:

```java
  private Game game;
  private Scanner in;
```

The `in` object is used to read user commands from the console.

The `Controller` class implements the public `public void run()` method that controls the main game cycle. Specifically, while the game is not finished, it requests commands from the user and executes them.

- `GamePrinter`:  it receives the `game` and has a `toString` method that is used to display the game as we saw earlier.

### Other classes

- `Level`: is an enumerated class that encapsulates the three game levels.

- `Move`: Enumeration to represent the different movements that game objects can make.

- `Position`: Immutable class to represent a position on the board, i.e., to encapsulate a column and a row.

- `Main`: It is the class that contains the `main` method of the application. In this case, the `main` method reads the values of the application's parameters, creates a new game (object of the `Game` class), creates a controller (object of the `Controller` class) with that game, and invokes the controller's `run` method.

### Notes on the implementation

- During the execution of the application only one object of the `Controller` class will be created. The same applies to the `Game` class, which represents the current game session and there can only be one active.

- Along with the assignment, we will provide you with some code templates for certain parts of the code.

- In the annex you will find some traces of the execution; The output of the assignment must match the examples.

The rest of the specific information to implement this assignment will be explained by the lecturer during the different theory and laboratory classes. In these classes, you will be informed about which aspects of the implementation are considered mandatory to accept the assignment as correct and which aspects are left to the discretion of the students.


<!-- TOC --><a name="4-entrega-de-la-práctica"></a>
# 4. Submission of the assignment

The assignment must be submitted using the virtual campus delivery mechanism, no later than the **date and time indicated in the virtual campus task**.

The file must contain at least the following content [^1]:

- Folder `src` with the code of all the assignment classes.
- File `alumnos.txt` where the name of the group members will be indicated.

Remember that `.class` should not be included.

> **Note**: Remember that you can use the `File > Export` option to help you generate the .zip.

[^1]: You can also optionally include the Eclipse project information files.

<!-- TOC --><a name="5-pruebas"></a>
# 5. Tests

Along with the assignment instructions, you will have a folder with traces of the program. You will find two files with the following nomenclature:

- `00-easy_25-input.txt`: it is the input of test case `0` with level `easy` and seed `25`.
- `00-easy_25-expected.txt`: is the expected output for the previous input.

In Eclipse, to use an input file and redirect the output to an output file, you must configure redirection in the `Common` tab of the `Run Configurations` window, as shown in the following figure.

![Input and output redirection](imgs/Bitmap/Pr1/runConfigurationsCommon.png)

There are many free programs to visually compare files. For example, Eclipse already has a built-in tool to compare files that you can launch by selecting two files, right-clicking and in the pop-up menu selecting `Compare With > Each other`.

![How to compare to files in Eclipse](imgs/Bitmap/Pr1/Eclipse_Compare_EachOther.png)

A new window will appear where the differences between the files will be clearly highlighted.

Be very careful with **the order of instructions** in the `update` because it can significantly affect the output.

Of course, our output may have some errors, so if you detect any inconsistencies, please let us know so we can correct them.

During the correction of assignments <!-- we will give you new ones --> we will use other test files to ensure that your implementations generalize correctly, so be sure to test not only the cases we provide you, but also other possible executions.