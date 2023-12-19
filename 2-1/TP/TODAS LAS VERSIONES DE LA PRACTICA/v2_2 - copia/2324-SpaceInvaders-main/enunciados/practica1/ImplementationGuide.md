# Assignment 1 - Space Invaders: Implementation Guide

This document is intended to help you with the implementation of assignment 1. If you find it unhelpful, you may disregard it.

## Structure

You have been given a template with the following packages and files:

+ `tp1`
    - _`Main`_
+ `tp1.view`
    - _`GamePrinter`_
	- _`Messages`_
+ `tp1.control`
    - `Controller`
+ `tp1.utils`
    - _`MyStringUtils`_
+ `tp1.logic`
    - `AlienManager`
	- `Game`
	- `Level`
	- `Move`
	- `Position`
+ `tp1.logic.gameobjects`
    - `RegularAlien`
	- `UCMLaser`
	- `Ufo`
+ `tp1.logic.lists`
    - `RegularAlienList`

As you will see, within each package, there are several files. The files in italics are fully implemented and you should not change their code. The rest, on the other hand, are partially implemented and you can (and should) add more methods and attributes to their classes. Additionally, you can also create more classes and packages if you consider necessary.

The provided code follows something similar to the _Model-View-Controller_ (MVC) pattern.

+ The **View** corresponds to the `view` package. This is where the classes in charge of displaying the game. In our case, it is a simple console view. This is handled by `GamePrinter`, which receives an instance of `Game` and converts it to `String` to display the game state on the console. We could have several views and even, in the future, it could be changed by adding, for example, colours, just as you did in FP2, but don't waste too much time with it.

+ The **Controller** corresponds to the `control` package. There is the class in charge of managing the "life cycle" of the game: while the game is not finished, it requests user commands, transfers them to the game and calls the view. This is a simple controller, which is limited to reading the commands that the user types through the console, instead of capturing keystrokes or other alternatives. This is where the game lifecycle is implemented, without delving into the game's logic.

+ The **Model** corresponds to the `logic` package, where the game's logic is located, that is, the rules of the game and the management of all game objects. The main class of this package is `Game`. In order to carry out its task, the game receives the corresponding command from the controller. Among the game commands there are orders to execute a ship movement, shoot, activate the superpower *shockwave* or do nothing (`none`). As you can see, everything related to the game is implemented in the model: number of cycles, score, ships, if there is a winner, if it has finished, etc.

Once we have seen the structure of the assignment, we realize that there is a lot of work ahead, and we consider...

| **Where to start?** |
| :---: |


## Task Breakdown

In large projects, it is best to break them down into small milestones or mini-projects that are working, with extensions added later. Furthermore, it is convenient to divide these mini-projects into small steps whose functionality can be tested. In this regard, we propose the following mini-projects with the respective steps:

### [A] Our ship, a shot from it, and a regular alien spaceship

1. If the template does not compile, add the essential code to make it compile. For example, if a method that is not yet implemented, should return an object, you can temporarily write `return null`. And execute it!

2. In the `main` method, provide the necessary parameters and, if needed, change the return value of a method to ensure that the **empty board** is displayed.

3. Add the ship `UCMShip` and make sure it is displayed.

4. Make the ship move (first commands: `[m]ove` and `[n]one`).

5. Add the ship's shooting, `UCMLaser`, make it visible and make it move on its own (`[s]hoot` command).

6. Add a regular alien spaceship, `RegularAlien`, make it appear on the board, and make it move automatically.

    - ***Movement***: Notice that it first moves in a fixed direction to the left. If it reaches the side edge, it changes direction downwards for a single movement, while the next movement will be to the right. If it moves down, it is because it was on an edge, so it has to change direction again towards the opposite edge.
    - ***Implementation***: A simple way to implement it is to consider that the alien has a movement direction (left or right) and a boolean value that indicates whether it has to respect the direction of movement or go down. This boolean only needs to be changed if, after moving, it has reached the edge. In this case, not only will it need to indicate that it has to move downward in the next movement, but it will also have to change the direction to the opposite one. In the movement in which you move downwards, it will only be necessary to change the boolean again, as the next movement must follow the stored direction.
        
7. Make the shooting kill the alien spaceship.

8. Make the game end by winning, losing, or executing **exit** (`[e]xit` command).

9. Review small details (number of cycles, score, other commands,...) that you may have ignored during the previous stages and check how the overall functionality of the assignment (commands `[h]elp`, `[l]ist` and `[r]eset`).

|***Make sure everything works as expected!***|
| :---: |

### [B] Our ship, one of its shots, and many regular alien spaceships

1. Include the alien spaceship in the `RegularAlienList` list. Check that it can be killed, that the game still ends, etc.
        
2. Include two alien spaceships in the list and implement the `AlienManager` so that the ships' movements occur at the same time and so that any ship reaching the edge changes the overall direction of movement. You can think of the `AlienManager` as the **mother ship** to which all alien spaceships must consult their movement direction.

    - ***Implementation***: Now you will have to take part of the movements that you implemented in `RegularAlien` to the `AlienManager` (**mother ship**). Each `RegularAlien` must inform the **mother ship** if it dies or reaches the edge, and it must also ask the **mother ship**, before moving, in which direction it should move. The **mother ship** knows how many requests it has received and, until it receives the request for the movement direction of all the ships it controls, it cannot change the general direction of their movement, because all of them must move in sync. Therefore, now the **mother ship** must store whether any ship, in the current step, has informed it that it had reached the edge, so that it can then change the `boolean` that indicated whether it had to respect the direction or move downward. Note that when all the ships have communicated, it is when they make the direction changes that were previously done in `RegularAlien`, so that in the next movement they all move in sync.

3. Generalize the list and allow several alien spaceships to be included.

4. Implement the appropriate initializer for the list so that, depending on the difficulty, the corresponding alien spaceships are created.

### [C] Our ship, one of its shots, many regular and destroyers alien spaceships

1. Add a single destroyer ship and implement the `Bomb` class.

2. Generalize to be able to have many destroyer alien ships.

### [D] Our ship, one of its shots, many regular and destroyers alien spaceships and a UFO
   
1. Add `Ufo`. Make it *killable* with the laser. (For your tests, you could leave only the UFO.)

2. Add the superpower and allow the user able to use the "shock[W]ave" command.

|***Congrats! It looks like you're done!***|
| :---: |
| Perform the tests we provide you.|