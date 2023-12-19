<!-- TOC start -->
- [Práctica 2 - Parte I: Space Invaders Refactored](#práctica-2---parte-i-space-invaders-refactored)
	- [Introducción](#introducción)
	- [Refactorización de la solución de la práctica anterior](#refactorización-de-la-solución-de-la-práctica-anterior)
		- [Patrón *Command*](#patrón-command)
		- [Herencia y polimorfismo](#herencia-y-polimorfismo)
		- [Contenedor de objetos del juego](#contenedor-de-objetos-del-juego)
		- [Interfaces de `Game`](#interfaces-de-game)
		- [Interfaces de `GameObject`](#interfaces-de-gameobject)
	- [Pruebas](#pruebas)
<!-- TOC end -->
<!-- TOC --><a name="práctica-2-parte-i-space-invaders-refactored"></a>
# Práctica 2 - Parte I: Space Invaders Refactored
 
**Objetivos:** Herencia, polimorfismo, clases abstractas e interfaces.

**Preguntas frecuentes**: Como es habitual (y normal), que tengáis dudas, las iremos recopilando en este [documento de preguntas frecuentes](../faq.md). Para saber los últimos cambios que se han introducido [puedes consultar la historia del documento](https://github.com/informaticaucm-TPI/2324-SpaceInvaders/commits/main/enunciados/faq.md).

<!-- TOC --><a name="introducción"></a>
## Introducción

Esta práctica consiste, fundamentalmente, en aplicar los mecanismos que ofrece la POO para mejorar el código desarrollado hasta ahora en la Práctica 1. En particular, incluiremos las siguientes mejoras:

- En la *Parte I* de la Práctica 2 refactorizaremos[^1] el código de la [Práctica 1](../practica1/practica1.md), preparándolo así para la *Parte II*. Al finalizar la refactorización, la práctica debe pasar los mismos test que se pasaron en la Práctica 1.

  - Modificaremos parte del controlador, distribuyendo su funcionalidad entre un conjunto de clases, mejor estructuradas, de cara a facilitar las extensiones posteriores.

  - Vamos a hacer uso de la herencia para reorganizar los objetos del juego. Como hemos visto, hay mucho código repetido en los distintos tipos de objetos. Por ello, vamos a crear una jerarquía de clases que nos permita extender más fácilmente la funcionalidad del juego.
      
  - La herencia también nos va a permitir redefinir cómo almacenamos la información del estado del juego. En la práctica anterior, al no usar herencia, debíamos tener una lista para cada conjunto de objetos. Sin embargo, en esta versión de la práctica, podremos usar una sola estructura de datos para almacenar todos los objetos de juego.

- En la *Parte II*, una vez refactorizada la práctica, añadiremos nuevos objetos y nuevos comandos al juego, de una forma segura, ordenada y fiable, gracias a la nueva estructura del código.

[^1]: Refactorizar consiste en cambiar la estructura del código sin cambiar su funcionalidad. Lo que se suele buscar con ello es mejorar el código. 

Los anteriores cambios se llevarán a cabo de forma progresiva. El objetivo principal es extender la práctica de una manera robusta, preservando la funcionalidad en cada paso que demos, buscando modificar la menor cantidad de código posible cuando la ampliemos.

<!-- TOC --><a name="refactorización-de-la-solución-de-la-práctica-anterior"></a>
## Refactorización de la solución de la práctica anterior

<!-- TOC --><a name="patrón-command"></a>
### Patrón *Command*

En la práctica anterior, el usuario podía realizar varias acciones: mover, disparar, pedir ayuda, etc. El objetivo técnico es poder añadir nuevas acciones sin tener que modificar código ajeno a la nueva acción. Para ello, vamos a introducir el patrón de diseño *Command*[^2], que es especialmente adecuado para este tipo de situaciones. La idea general es encapsular cada acción del usuario en su propia clase. Cada acción se corresponderá con un comando, de tal manera que el comportamiento de un comando quedará completamente aislado del resto. 

[^2]: Lo que vamos a ver en esta sección no es el patrón *Command* de manera rigurosa, sino una adaptación de éste a las necesidades de la práctica.

En el patrón *Command* van a intervenir las siguientes entidades, las cuales iremos explicando en varios pasos, a medida que vayamos profundizando en los detalles:

- La clase `Command` es una clase abstracta que encapsula la funcionalidad común de todos los comandos concretos.
- La clase `NoParamsCommand` es una clase abstracta que hereda de `Command` y que sirve de base para todos los comandos que no tienen parámetros, como `none`, `reset` o `help`.
- Los comandos concretos se corresponden con las acciones del usuario: `MoveCommand`, `HelpCommand`, `ExitCommand`... 
- Cada acción va a tener su propia clase y cada comando tendrá tres métodos básicos:
    - `protected boolean matchCommand(String)` comprueba si una acción introducida por teclado se corresponde con la del comando.
    - `public Command parse(String[])` crea una instancia del comando, dados los parámetros proporcionados por el usuario.
    - `public ExecutionResult execute(Game)` ejecuta la acción del comando, modificando el juego.   

- La clase `Controller`, correspondiente al controlador, va a quedar muy reducida pues, como veremos más adelante, su funcionalidad quedará delegada en los comandos concretos.

En la práctica anterior, para saber qué comando se ejecutaba, el **bucle de Juego**, implementado mediante el método `run()` del controlador, contenía un `switch` (o una serie de `if` anidados) cuyas opciones se correspondían con los diferentes comandos.

En la nueva versión, el método `run()` del controlador va a tener, más o menos, el siguiente aspecto. Tu código no tiene que ser exactamente igual, pero lo importante es que veas que se asemeja a esta propuesta.

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

Mientras que la partida no finalice, en el bucle leemos una acción de la consola, la analizamos sintácticamente para obtener el comando asociado, ejecutamos el comando y, si la ejecución es satisfactoria y ha cambiado el estado del juego, lo dibujamos. En otro caso, mostramos un error.

En el bucle anterior, el momento clave se corresponde con la línea de código:

```java
Command command = CommandGenerator.parse(userWords);
```

El controlador solo maneja comandos abstractos, por lo que no sabe qué comando concreto se ejecutará, ni qué hará exactamente el comando. Este es el mecanismo clave que nos facilitará la tarea de añadir nuevos comandos concretos.

El método `parse(String[])` es un método estático de la clase `CommandGenerator`, encargado de encontrar el comando concreto asociado a la entrada del usuario. Para ello, la clase `CommandGenerator` mantiene una lista `AVAILABLE_COMMANDS` con los comandos disponibles. Este método recorre la lista de comandos para determinar, llamando al método `parse(String[])` de cada comando, con cuál se corresponde la entrada del usuario. Cuando lo encuentra, procesa los posibles parámetros, crea una instancia de ese mismo tipo de comando y lo devuelve al controlador.

El esqueleto del código de `CommandGenerator` es:
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

El atributo `AVAILABLE_COMMANDS` se usa en los siguientes métodos de `CommandGenerator`:

- El método
	```java 
	public static Command parse(String[] commandWords)
	```
	invoca el método `parse` de cada subclase de `Command`, tal y como se ha explicado anteriormente.

- El método
	```java
	public static String commandHelp()
	```
	tiene una estructura similar al método anterior, pero invoca el método `helpText()` de cada subclase de `Command`. A su vez, es invocado por el método `execute` de la clase `HelpCommand`.

Después de recibir un `Command`, el controlador simplemente lo ejecutará usando *game* como parámetro.

Todos los comandos tienen una serie de información asociada, como el nombre, atajo, detalle, etc. Por ejemplo, el comando concreto `HelpCommand` cuenta con los siguientes métodos:

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

<!-- Los métodos abstractos no pueden ser estáticos. Esos métodos estarán declarados en Command  -->

Como hemos indicado anteriormente, todos los comandos heredan de la clase `Command`. La clase `Command` es abstracta, por lo que son los comandos concretos los que implementan su funcionalidad:

- El método `execute` realiza la acción sobre *game*  y devuelve un valor de tipo `ExecutionResult`, que representa el resultado de la ejecución del comando: si ha tenido éxito o no, el mensaje de error por si fuera necesario, y si procede volver a dibujar el estado del juego. `ExecutionResult` es una clase registro ([Java Record](https://www.geeksforgeeks.org/what-are-java-records-and-how-to-use-them-alongside-constructors-and-methods/)) que nos permite devolver múltiples valores como resultado de un método (como si fuera una tupla o conjunto de datos del estilo de los `struct` de C/C++).

- El método `parse(String[])` devuelve una instancia del comando concreto. Como cada comando procesa sus propios parámetros, este método devolverá `this` o creará una nueva instancia de la misma clase. En el caso de que los argumentos introducidos por el usuario no sean válidos para el comando, el método `parse(String[])` devolverá `null`.

La clase abstracta `NoParamsCommand`, que hereda de `Command`, sirve para representar a todos los comandos que no necesitan parámetros, como ***help*** o ***reset***, y de la que heredarán, por lo tanto, comandos como `HelpCommand` o `ResetCommand`. Esta clase puede implementar el método `parse` porque todos esos comandos se *parsean* igual: basta comprobar que el usuario solamente ha introducido una palabra que coincide con el nombre o la abreviatura del comando, en cuyo caso se puede devolver `this`. Obviamente, la implementación de `execute` se tiene que posponer a los comandos concretos, de modo que la clase `NoParamsCommand` tiene que ser abstracta. 

Fíjate también que para los comandos con parámetros no sería correcto que su método `parse` devuelva `this`, sino que es necesario devolver un nuevo comando del tipo correspondiente.

<!-- TOC --><a name="herencia-y-polimorfismo"></a>
### Herencia y polimorfismo

Una de las partes más frustrantes y propensa a errores de la primera práctica ha sido tener que replicar código en los objetos del juego y en las listas de objetos. Esta incomodidad la vamos a resolver utilizando el mecanismo por antonomasia de la programación orientada a objetos: la **herencia**. 

Con el patrón `Command` hemos buscado poder introducir nuevos comandos sin tener que cambiar el código del controlador. Análogamente, queremos poder añadir nuevos objetos de juego sin tener que modificar el resto del código. La clave para ello es que `Game` no maneje objetos específicos, sino que maneje objetos de una entidad abstracta que vamos a llamar `GameObject`. El resto de objetos del juego heredarán de esta entidad. Como todos los elementos del juego van a ser `GameObject`, compartirán la mayoría de atributos y métodos, y cada uno de los objetos de juego concretos será el encargado de implementar su propio comportamiento. 

Todos los `GameObject` tienen una posición en el juego, una vida, métodos auxiliares para manipular esa posición y esa vida, y una serie de métodos que llamamos durante cada ciclo del juego como, por ejemplo, cuando necesitan hacer algo propio de ese objeto en un momento concreto de su ciclo de vida:

- `computerAction()` y `automaticMove()`: se llaman en cada iteración del bucle de juego.
- `onDelete()`: se llama cuando el objeto sale del juego, justo antes de desaparecer.
- `isAlive()`: es verdadero si el objeto sigue vivo, o falso si hay que eliminarlo del juego.

Es normal que en objetos sencillos haya algunos de estos métodos vacíos o con funcionalidad trivial. Por ejemplo, en `UCMShip`, que no se mueve de forma automática, la implementación del método `automaticMove` será vacía.

`GameObject` será la clase base en la jerarquía de clases de los objetos del juego:

- La clase abstracta `GameObject` tendrá los atributos y métodos básicos para controlar la posición en el tablero y una referencia a la clase `Game`.
- De `GameObject` heredarán las clases `Ship` y `Weapon`. `Ship` representará a las naves del juego, mientras que `Weapon` representará a los objetos que causan daño.
- La clase `EnemyShip`, subclase de `Ship`, representará a las naves enemigas, incluyendo el ovni. Entre otros elementos, esta clase deberá gestionar el movimiento de las naves y los puntos que se obtienen al ser destruidas por el jugador.
- De forma similar, la clase `UCMShip` también será subclase de `Ship` y representará a la nave que controla el jugador.
- La clase `AlienShip`, subclase de `EnemyShip`, representará a las naves del juego que se mueven con un comportamiento grupal, es decir, todas en la misma dirección. Su movimiento seguirá las mismas reglas que fueron definidas en la Práctica 1. 
- Las clases `RegularAlien` y `DestroyerAlien` heredarán de `AlienShip`, implementando su comportamiento.
- De la clase `Weapon` heredarán `EnemyWeapon` y `UCMWeapon`.
- Finalmente, las clases `Bomb` y `UCMLaser` heredarán, respectivamente, de `EnemyWeapon` y `UCMWeapon`, ambas subclases de `Weapon`. Representan los disparos realizados por las naves `DestroyerAlien` y `UCMShip`, respectivamente.
- La clase `Shockwave` también heredará de `UCMWeapon`. Aunque no se mueva y tenga una forma de atacar diferente también, lo podemos considerar como un arma. Si, más adelante, tuviéramos otros *power-ups* podríamos refinar la jerarquía de clases para tener armas con diferentes comportamientos.

Es importante remarcar que la versión anterior de la práctica se diseñó pensando en la estructura que tendría esta segunda práctica, de modo que la refactorización resultase más sencilla. En particular, la mayor parte de la lógica de juego estaba ya distribuida en los propios elementos del juego, quedando la clase `Game` liberada de esta tarea. 

<!-- TOC --><a name="contenedor-de-objetos-del-juego"></a>
### Contenedor de objetos del juego

Ahora que hemos conseguido que todos los objetos presentes en el tablero pertenezcan a (alguna subclase de) la clase `GameObject`, podemos ocuparnos de refactorizar el código de las listas. En esta práctica utilizaremos una clase llamada `GameObjectContainer` que será la encargada de gestionar la lista de elementos de tipo `GameObject`. 

El `GameObjectContainer` es el almacén de objetos del juego, que llamaremos **contenedor**. En él estarán todas las naves enemigas, las armas disparadas y también la propia `UCMShip`. El contenedor será el encargado de actualizarlos, borrarlos, etc. Para implementar este almacén podemos utilizar cualquier tipo de colección. Nosotros, por simplicidad, vamos a usar un `ArrayList` de `GameObject`:

```java
public class GameObjectContainer {

	private List<GameObject> gameObjects;

	public GameObjectContainer() {
		gameObjects = new ArrayList<>();
	}
    //...
}
```

En el contenedor manejaremos abstracciones de los objetos, por lo que no podemos (¡ni debemos!) distinguir quién es quién.

<!-- UCMShip forma parte del contenedor para que los ataques a UCMShip se puedan meter en el saco general de ataques entre objetos -->

Por último, es muy importante que los detalles de la implementación del `GameObjectContainer` sean privados. Eso permite cambiar la implementación (el tipo de colección) sin tener que modificar código en el resto de la práctica. 

<!-- TOC --><a name="interfaces-de-game"></a>
### Interfaces de `Game`

En la Práctica 1, la clase `Game` se utilizaba desde tres contextos diferentes, correspondientes a los tres tipos de referencias de `Game` que se mantenían en otros puntos del código:

- En `Controller` se mantiene una referencia a `Game` para poder enviar al juego las instrucciones del usuario (ahora a través del método `execute(Game)` de los comandos). En este contexto, se usan métodos como `move(Move move)`, `shootLaser()` o `reset()`.  

- En `GamePrinter` también se mantiene una referencia a `Game` para solicitar los datos que se deben mostrar. Se utilizan métodos como `getCycle()`, `getRemainingAliens()` o `positionToString(int, int)`.

- Desde los objetos del juego también se mantiene una referencia a `Game`, en este caso para comunicarle al juego aquello que tiene que ver con los ataques o la inclusión de nuevos objetos (por ejemplo, para añadir una bomba desde `DestroyerAlien`). Se usan métodos como `addObject(GameObject)` o `receivePoints(int)`. A menudo, a estos métodos se les llama  *callbacks* (acciones de retorno). 

Aunque exista esa clasificación de métodos en `Game`, nada prohíbe que, por ejemplo, un `GameObject` invoque a `reset`, o que desde `GamePrinter` se invoque, por ejemplo, a `addObject` para añadir una bomba o un láser. Al fin y al cabo, todos ellos son métodos públicos de `Game` y pueden utilizarse desde cualquier objeto que tenga una referencia a `Game`.

Para resolver este problema podemos usar interfaces. En primer lugar, vamos a crear una interfaz distinta para cada uno de estos tres contextos. Cada interfaz va a proporcionar una ***vista parcial*** de `Game` con solo algunos de sus métodos.
En concreto, vamos a definir `GameModel` para `Controller`, `GameStatus` para `GamePrinter` y `GameWorld` para `GameObject`.

Por ejemplo:

```java
public interface GameModel {

	public boolean move(Move move);
	public boolean shootLaser();
	public void reset();
	// ...
}
```

Una vez definidos los interfaces, haremos que `Game` los implemente:

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

	// Métodos de GameModel
	// ...
	// Métodos de GameWorld
	// ...
	// Métodos de GameStatus
	// ...
	// Otros métodos
	// ...
}
```

Por último, en cada uno de los contextos en los que se usaba `Game` reemplazamos el tipo de la referencia por el interfaz correspondiente. Por ejemplo, en `Controller` tendremos una referencia a un `GameModel`. Del mismo modo, reemplazamos el tipo del parámetro de `execute` de `Command` para que admita un `GameModel` y no un `Game`:

```java
public abstract ExecutionResult execute(GameModel game);
```

<!-- TOC --><a name="interfaces-de-gameobject"></a>
### Interfaces de `GameObject`

Vamos a usar otra interfaz para encapsular los métodos relacionados con los *ataques*. La clase `GameObject` implementa el interfaz `GameItem`. La idea es que todos los objetos del juego deben tener la posibilidad de atacar o ser atacados. Por ello, tenemos que implementar la posibilidad de recibir un ataque por parte de cada uno de los proyectiles. 

```java
public interface GameItem {
    public boolean performAttack(GameItem other);
    public boolean receiveAttack(EnemyWeapon weapon);
    public boolean receiveAttack(UCMWeapon weapon);
	....
}
```

Fíjate en que el método `receiveAttack` está sobrecargado.
En la implementación de `GameObject` (o en sus subclases) se incluirán las implementaciones de estos métodos. Los `DestroyerAlien` no hacen daño, sino que lo que hacen es lanzar bombas, que son las que realmente hacen daño. Si un objeto de juego puede atacar, tendrá que sobrescribir el método e implementar la lógica de su ataque.

De igual manera, todos los objetos pueden recibir daño de otro objeto. Por defecto, no lo reciben. Pero, por ejemplo, los aliens y las bombas sí reciben daño del láser, y el jugador y el láser sí reciben ataques de las bombas.

<!-- TOC --><a name="pruebas"></a>
## Pruebas

Recuerda que, una vez terminada la refactorización, la práctica debe funcionar exactamente igual que en la versión anterior y debe pasar los mismos test, aunque en la implementación tendremos muchas más clases. 

Así conseguimos dejar preparada la estructura para añadir fácilmente nuevos comandos y objetos de juego en la *Parte II* de esta práctica.

Para simplificar las pruebas, vamos a «abusar» del soporte de [JUnit](https://junit.org/) dentro de Eclipse, lo cual facilitará nuestras pruebas de comparación de la salida de nuestro programa. JUnit es un *framework* para la realización de pruebas automatizadas al código Java de tu aplicación. Seguramente verás y utilizarás JUnit, o análogo, en otras asignaturas de la carrera.

Como parte de la plantilla de la práctica, se incluye la clase `tp1.Tests`, la cual es una clase de pruebas JUnit. Esta clase contiene una prueba para cada uno de los casos de prueba de la Práctica 1.

Antes de poder ejecutar las pruebas que incluye, tenemos que añadir JUnit a nuestro proyecto. Para ello, tenemos que ir a las propiedades del proyecto *Project > Properties*, seleccionar *Java Build Path* e ir a la pestaña *Libraries*. Allí, con *Classpath* seleccionado (no *ModulePath*), pulsamos en el botón *Add Library...*

![](./imgs/00-ProjectProjerties.jpg)

En la nueva ventana seleccionamos *JUnit* y pulsamos en el botón *Finish* 

![](./imgs/01-AddJUnit.jpg)

Al volver a la ventana de las propiedades del proyecto, pulsamos en el botón *Apply and Close*.

Si lo hemos configurado correctamente, al pulsar con el botón derecho del ratón sobre el fichero `Tests.java` e ir al menú *Run As*, debería aparecer la opción *JUnit Test*.

![](./imgs/02-RunAsJUnitTest.jpg)

Si ejecutamos las pruebas, Eclipse mostrará una vista en la que podremos ver el resultado de las pruebas y lanzar las que hayan fallado de manera individualizada o todas a la vez. **Recuerda** que utilizamos las pruebas JUnit simplemente para comparar la salida de tu programa con la salida esperada. Si quieres ver los detalles en el caso de que no se produzca concordancia, tendrás que aplicar el mismo procedimiento que en la Práctica 1.

<!-- ![Fallo JUnit](./imgs/03-JUnitFailed.jpg) -->
<figure>
    <img src="./imgs/03-JUnitFailed.jpg"
         alt="Fallo JUnit">
    <figcaption>Fallan las pruebas JUnit</figcaption>
</figure>

<!-- ![Todas las pruebas JUnit tienen éxito](./imgs/04-JUnitPass.jpg) -->
<figure>
    <img src="./imgs/04-JUnitPass.jpg"
         alt="Éxito JUnit">
    <figcaption>Todas las pruebas JUnit tienen éxito</figcaption>
</figure>

