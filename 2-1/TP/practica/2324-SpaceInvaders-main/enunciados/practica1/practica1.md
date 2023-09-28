# Práctica 1: Space Invaders

**Entrega: Semana del 30 de octubre**
 
**Objetivos:** Iniciación a la orientación a objetos y a Java; uso de arrays y enumerados; manipulación de cadenas con la clase `String`; entrada y salida por consola.

**Preguntas Frecuentes**: Como es habitual (y normal) que tengáis dudas, las iremos recopilando en este [documento de preguntas frecuentes](../faq.md). Para saber los últimos cambios que se han introducido [puedes consultar la historia del documento](https://github.com/informaticaucm-TPI/2324-SpaceInvaders/commits/main/enunciados/faq.md).

<!-- TOC start -->
  * [Control de copias](#control-de-copias)
- [1. Descripción de la práctica](#1-descripción-de-la-práctica)
  * [1.1 Introducción](#11-introducción)
  * [1.2. Detalles sobre la práctica](#12-detalles-sobre-la-práctica)
  * [1.3. Objetos del juego](#13-objetos-del-juego)
- [2. Organización del juego](#2-organización-del-juego)
  * [2.1 Draw](#21-draw)
  * [2.2 User actions](#22-user-actions)
  * [2.3 Computer actions](#23-computer-actions)
  * [2.4 Automatic moves](#24-automatic-moves)
- [3. Implementación ](#3-implementación)
- [4. Entrega de la práctica](#4-entrega-de-la-práctica)
- [5. Pruebas](#5-pruebas)
<!-- TOC end -->

<!-- TOC --><a name="control-de-copias"></a>
## Control de copias

Durante el curso se realizará control de copias de todas las prácticas, comparando las entregas de todos los grupos de TPI. Se considera copia la reproducción total o parcial de código de otros alumnos o cualquier código extraído de Internet o de cualquier otra fuente, salvo aquellas autorizadas explícitamente por el profesor. 

En caso de detección de copia, se informará al Comité de Actuación ante Copias que citará al alumno infractor y, si considera que es necesario sancionar al alumno, propondrá una de las tres siguientes medidas:


- Calificación con cero en la convocatoria de la asignatura a la que corresponde la prueba.
- Calificación con cero en todas las convocatorias del curso actual.
- Apertura de expediente académico ante la Inspección de Servicios de la Universidad.

<!-- TOC --><a name="1-descripción-de-la-práctica"></a>
# 1. Descripción de la práctica

<!-- TOC --><a name="11-introducción"></a>
## 1.1 Introducción

Space Invaders fue uno de los primeros juegos identificados con el género *matamarcianos* o *marcianitos*. Actualmente está considerado como uno de los videojuegos más influyentes e importantes de la historia. El objetivo del juego consiste en controlar una nave para destruir -- disparando un láser -- las naves alienígenas que aparecen en el espacio. Existen multitud de clones y versiones modernas del juego que han introducido novedades, como tipos de armas, escudos y superpoderes.

![Vista del juego en su versión clásica (Fuente: www.smithsonianmag.com)](imgs/Bitmap/Pr1/screenshot1.png)

Para esta práctica utilizaremos tanto elementos del juego clásico como algunas de las novedades introducidas en las versiones más modernas. En el juego original la acción se desarrolla en tiempo real, es decir, los enemigos actúan de forma continua, independientemente de las acciones que tome el jugador. Sin embargo, en nuestro caso el juego se desarrollará por turnos, en los que el jugador podrá realizar una acción en cada ciclo del juego, de forma que el juego permanece parado hasta que el jugador indica la acción. Seguidamente, las naves se actualizarán para realizar sus movimientos o acciones correspondientes.

![Vista del juego en su versión moderna](imgs/Bitmap/Pr1/screenshot2.jpg)

Si no has jugado, o no conoces el juego, te recomendamos que lo pruebes antes de desarrollar la práctica. Existe una versión gratuita, accesible a través del navegador a través de este enlace: https://www.minijuegos.com/juego/space-invaders.

Durante el cuatrimestre vamos a ir desarrollando progresivamente nuestra propia versión del juego. Empezaremos con una versión reducida, e iremos mejorando su implementación para poder incrementar fácilmente su complejidad. En la primera práctica tenemos como objetivo implementar el juego usando la consola. 


<!-- TOC --><a name="12-detalles-sobre-la-práctica"></a>
## 1.2. Detalles sobre la práctica

En nuestra primera práctica vamos a considerar que el juego consta de un tablero de **9 x 8** casillas (9 columnas por 8 filas). La casilla de arriba a la izquierda es la (0, 0) y la de abajo a la derecha la (8, 7).  Cada casilla puede estar ocupada por una nave alienígena, por UCMShip (la nave que controla el usuario), un *ovni*, el láser de UCMShip o una bomba lanzada por una nave alienígena. Las casillas que no estén ocupadas se considerarán casillas vacías. Para distinguir los disparos de ambas naves, de aquí en adelante utilizaremos el término *láser* para hacer referencia al disparo realizado por UCMShip y *bomba* al disparo realizado por las naves alienígenas.

Las naves alienígenas se moverán en grupo. Es decir, todas realizarán el mismo movimiento en el mismo ciclo. Inicialmente, las naves se desplazarán hacia la izquierda con la velocidad relativa al nivel de dificultad seleccionado. Cuando una de las naves llegue al borde del tablero, todas las naves se desplazarán una casilla hacia abajo. En el siguiente ciclo, las naves comenzarán a moverse horizontalmente en dirección al borde opuesto, tal y como ocurre en el juego original. 

Si una nave alienígena logra llegar a la fila en la que se encuentra UCMShip, o UCMShip se queda sin puntos de daño, el jugador habrá perdido la partida. En cambio, el jugador ganará cuando haya destruido todas las naves alienígenas, es decir, si durante el **Update**, no quedan naves alienígenas en el tablero.

En esta práctica solo consideraremos dos tipos de naves alienígenas: *nave común* y *nave destructora*. 

En cada ciclo del juego se realizan secuencialmente las siguientes acciones:

1. ***Draw.*** Se pinta el tablero y se muestra la información del juego.

2. ***User command.*** El usuario puede realizar una acción como, por ejemplo, moverse lateralmente o realizar un disparo. El usuario puede no hacer nada en un ciclo y dejar pasar el tiempo. También puede ejecutar comandos que no actualizan el juego, como solicitar el listado de comandos disponibles.

3. ***Update***. El juego se actualiza. La actualización del juego se hace en dos etapas:
    - ***Computer action.*** El ordenador realiza primero las acciones que decide que hay que realizar al comienzo del update. En esta versión de la práctica puede decidir si una nave *destructora* realiza un disparo, o si aparece un *ovni* (ver más adelante) en la primera fila del tablero.
    - ***Automatic moves.*** Se mueven los objetos que están en el tablero según su estado y el estado del juego. A la vez que se mueven es necesario comprobar si su movimiento ha causado un ataque.

<!-- TOC --><a name="13-objetos-del-juego"></a>
## 1.3. Objetos del juego

En esta sección describimos el tipo de objetos que aparecen en el juego y su  comportamiento.

### Nave UCMShip

***Comportamiento***: Se mueve horizontalmente y realiza disparos. Inicialmente se coloca en la casilla (4,7).

***Resistencia***: 3 puntos de daño.

***Disparo***: Lanza un láser. No puede haber más de un láser en el tablero. El láser avanzará verticalmente de forma que hasta que  no haya alcanzado una nave alienígena, una bomba, un ovni o haya llegado al final del tablero, no se podrá disparar uno nuevo. Si el jugador realiza el disparo, el láser tendrá, en el momento de realizar la acción, la misma coordenada que UCMShip. Sin embargo, su trayectoria se actualizará en la acción *update* del mismo ciclo.

***Daño***: El comportamiento estándar del disparo ocasiona un punto de daño en la nave impactada.

### Nave alienígena común (*regular alien*)

***Comportamiento***: Se desplaza horizontalmente. Cuando una nave alienígena llega al borde del tablero, todas las naves se desplazarán una casilla hacia abajo y su movimiento lateral se realizará hacia el borde opuesto, tal y como ocurre en el juego original. El desplazamiento vertical se realizará en el ciclo siguiente al de haber alcanzado el borde del tablero, independientemente de la velocidad establecida por la dificultad del juego.

***Resistencia***: 2 puntos de daño.

***Disparo***: Esta nave no realiza disparos.

***Puntos***: 5 puntos al ser destruida.

### Nave alienígena destructora (*destroyer alien*)

***Comportamiento***: El movimiento es el mismo que la nave común.

***Resistencia***: 1 punto de daño.

***Disparo***: Deja caer una bomba. El movimiento de la bomba es vertical en el sentido hacia donde se encuentra UCMShip.

***Daño***: 1 punto de daño.

***Puntos***: 10 puntos al ser destruida.

### Ovni (*ufo*)

***Comportamiento***: Inicialmente aparece en la casilla (8,0), es decir, en la esquina superior derecha. Se desplaza horizontalmente una casilla por cada ciclo, hasta alcanzar el borde del tablero, o ser destruido por un láser de UCMShip. Si es alcanzado por un disparo de UCMShip, proporcionará al jugador un superpoder  llamado *shockWave*. El *shockWave* no se acumula: si el jugador ya dispone de uno y alcanza a un *ovni*, tendrá un solo *shockWave* activo y no dos. Una vez recorridas las casillas de la fila en la que aparece, el *ovni* se elimina del tablero.

***Resistencia***: 1 punto de daño.

***Disparo***: Esta nave no realiza disparos.

***Puntos***: 25 puntos al ser destruido.

<!-- TOC --><a name="2-organización-del-juego"></a>
# 2. Organización del juego

A continuación, describimos lo que ocurre en cada parte del bucle del juego.

<!-- TOC --><a name="21-draw"></a>
## 2.1 Draw

En cada ciclo se pintará el estado actual del tablero, así como los puntos de daño (*life*) que le quedan al jugador, el ciclo de juego en el que nos encontramos (inicialmente 0), la puntuación acumulada, el número de naves alienígenas que quedan actualmente en pantalla y si disponemos o no de un *shockWave*.

Cada nave en el tablero muestra entre corchetes la vida que le queda. El láser del usuario se representa con los caracteres **'oo'** (sin comillas) y los proyectiles de las naves alienígenas con **'*'** (sin comillas). También mostraremos el **prompt** del juego para solicitar al usuario la siguiente acción.

El tablero se pintará por el interfaz consola utilizando caracteres ASCII, como muestra el siguiente ejemplo:

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

Se preguntará al usuario qué quiere hacer, a lo que podrá contestar una de las siguientes alternativas:

- `move <left|lleft|right|rright>`: Este comando se utiliza para desplazar a UCMShip. Acepta un argumento que indica la dirección y el número de casillas del desplazamiento: `left` (una casilla a la izquierda), `right` (una casilla a la derecha), `lleft` (dos casillas a la izquierda) o `rright` (dos casillas a la derecha).

- `shoot`: La nave UCMShip realiza un disparo si puede hacerlo, es decir, si no hay ya un láser en el tablero.

- `shockwave`: La nave UCMShip lanza una onda que causa un punto de daño a todas las naves alienígenas del tablero. Esta acción tiene lugar en el mismo ciclo en el que se ejecuta el comando.

- `list`: Mostrará el nombre de las naves actuales, puntos, daño y resistencia. En esta versión se mostrará así:

```
Command > list
[U]CM Ship:  Harm: 1 - Shield: 3
[R]egular Alien: Points: 5 - Harm: 0 - Shield: 2
[D]estroyer Alien: Points: 10 - Harm: 1 - Shield: 1 
U[f]o: Points: 25 - Harm: 0 - Shield: 1
```

- `help`: Este comando solicita a la aplicación que muestre la ayuda relativa a cómo utilizar los comandos. Se mostrará una línea por cada comando. Cada línea tiene el nombre del comando seguida por ':' y una breve descripción de lo que hace el comando. 

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

- `reset`: Este comando permite reiniciar la partida, llevando al juego a la configuración inicial.

- `exit`: Este comando permite salir de la aplicación, mostrando previamente el mensaje *Game Over*.

- `none`: El usuario no realiza ninguna acción.

**Observaciones sobre los comandos:**

- La aplicación debe permitir comandos escritos en minúsculas, mayúsculas o mezcla de ambas.
 
- La aplicación debe permitir el uso de la primera letra del comando (o la indicada entre corchetes, si esa letra ya se utiliza) en lugar del comando completo `[M]ove`, `[S]hoot`, `shock[W]ave`, `[L]ist`, `[R]eset`, `[H]elp`, `[E]xit`, `[N]one`.
  
- Si el comando es vacío se identifica como `none` y se avanza al siguiente ciclo de juego.
 
- Si el comando está mal escrito, no existe, o no se puede ejecutar, la aplicación mostrará un mensaje de error.

- En el caso de que el usuario ejecute un comando que no cambia el estado del juego, o un comando erróneo, el tablero no se debe repintar. 

<!-- TOC --><a name="23-computer-actions"></a>
## 2.3 Computer actions

En esta primera práctica el ordenador tendrá un comportamiento pseudoaleatorio. Uno de los parámetros de entrada será el nivel. Definiremos tres niveles: **EASY**, **HARD** e **INSANE**. Cada nivel determinará:

- El número de naves *comunes* que aparecen al inicio de la partida.
- El número de naves *destructoras* que aparecen al inicio de la partida.
- La frecuencia de disparo de las naves *destructoras*. La frecuencia determina la probabilidad de que una nave deje caer una bomba. Así pues, si la frecuencia es 0.2, una nave tendrá un 20% de probabilidad de lanzar una bomba en un ciclo, aunque al tratarse de una probabilidad pueden salir más espaciadas -- o menos --, en función de la aleatoriedad. Es importante remarcar que no puede haber en pantalla dos bombas lanzadas por la misma nave. 
- La velocidad de las naves alienígenas. Este parámetro determina el número de ciclos que deben transcurrir para que las naves se desplacen **una casilla**.
- La probabilidad de que aparezca un *ovni*. De forma similar, este parámetro indica la probabilidad de que el programa genere un *ovni*. Cuando esto ocurra, el *ovni* se situará en la casilla (8, 0) y avanzará una casilla por ciclo, independientemente de la dificultad establecida. Al igual que sucede con los disparos, solo puede haber un *ovni* en la pantalla.

| Nivel   | Naves comunes | Naves destructoras | Frec. disparo | Velocidad | Ovni
| :---:   | :---:            | :---:      |  :---: |  :---: |  :---: 
|`EASY`   | 4 (en 1 fila)                | 2        | 0.1 | 3 | 0.5
|`HARD`   | 8 (en 2 filas)               | 2        | 0.3 | 2 | 0.2
|`INSANE` | 8 (en 2 filas)               | 4        | 0.5 | 1 | 0.1

Para controlar el comportamiento aleatorio del juego, y poder repetir varias veces la misma ejecución, utilizaremos una semilla o **seed**, como se conoce en inglés. Este valor opcional proporciona un control del comportamiento del programa, lo que nos permitirá repetir exactamente una misma ejecución. 

En cada ciclo el programa deberá decidir si cada nave *destructora* lanza una bomba (si es posible) o si el *ovni* sale por pantalla (si no hay uno actualmente en el tablero).

Sería interesante que probaras otros valores de número de naves y velocidad para encontrar aquellas combinaciones que sean más divertidas y jugables.

<!-- TOC --><a name="24-automatic-moves"></a>
## 2.4 Automatic moves

En cada ciclo se producen los movimientos de los objetos del juego, que pueden dar lugar a ataques, y cuyo orden es el siguiente: 

- Se actualiza la posición de las naves alienígenas.

- Avance en la trayectoria de las bombas existentes en pantalla. Cada bomba se desplazará verticalmente -- desde la nave que lanza la bomba hacia la última fila -- una casilla en cada ciclo.

	- Si una bomba de una nave alienígena alcanza a UCMShip, UCMShip sufre un decremento de un punto de daño y la bomba es destruida.

  - Si UCMShip llega a 0 puntos de daño, se utilizará el siguiente `String` para representar que la nave está destruida: `!xx!`.

  - Si una bomba alcanza al láser de UCMShip, ambos, bomba y láser, son destruidos.

- Si el ovni está en la pantalla, se actualiza su posición.

- Avance en la trayectoria del láser lanzado por UCMShip. El láser se desplazará verticalmente -- desde la última fila hasta la primera -- una casilla en cada ciclo. Si no existe un láser en el momento de realizar **Update**, esta acción será ignorada.

	- Si el láser lanzado por UCMShip alcanza una bomba de una nave alienígena, ambos se eliminan del tablero.
	- Si el láser de UCMShip alcanza una nave alienígena, la nave impactada sufre un decremento de un punto de daño y el láser es destruido.
  - Si una nave alienígena llega a 0 puntos de daño, desaparece del tablero.

El juego finalizará si durante la acción **Update** se produce uno de los siguientes escenarios: 

1. Todas las naves alienígenas son destruidas
2. Una de las naves alienígenas alcanza la fila en la que se encuentra UCMShip
3. La resistencia de UCMShip llega a 0 puntos de daño

Cuando el juego termine se debe mostrar quién ha sido el ganador: **'Player wins'** o **'Aliens win'**.


### Colocación inicial de las naves

- En el nivel `EASY` las naves se colocarán en filas de 4, comenzando por la fila 1 y columna 2. Las naves *destructoras* están centradas con respecto a las naves *comunes*, como en el ejemplo de abajo.

-  En el nivel `HARD` debe aparecer otra fila de naves *comunes* en la fila 2 del tablero, de forma que las naves *destructoras* aparecen en la fila 3.

- En el nivel `INSANE`, aparecen dos filas de naves *comunes* -- en filas 1 y 2 -- de forma que las cuatro naves *destructoras* aparecen en la fila 3.


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

UCM-Ship aparece inicialmente centrado en el tablero.


### Parámetros de la aplicación

El programa debe aceptar un parámetro obligatorio y uno opcional por línea de comandos.

  -  El primero, llamado **level**, es el nivel de juego y es obligatorio.

  -  El segundo, llamado  **seed**, contiene el valor de la semilla usada para el comportamiento pseudoaleatorio del juego y es opcional. 

![Opciones de ejecución](imgs/Bitmap/Pr1/args.png)

<!-- TOC --><a name="3-detalles-de-implementación"></a>
# 3. Implementación

La implementación propuesta para la primera práctica no es la mejor, ya que no hace uso de **herencia** y **polimorfismo**, dos herramientas básicas de la programación orientada a objetos. Más adelante, veremos formas de mejorarla mediante el uso de las herramientas que nos brinda la programación orientada a objetos. 

Para implementar la primera versión tendremos que copiar y pegar mucho código y esto casi siempre es una mala práctica de programación. La duplicación de código implica que va a ser poco mantenible y *testeable*. Hay un principio de programación muy conocido llamado **DRY (Don't Repeat Yourself)** (**No te repitas**, en castellano). Según este principio, ninguna información debería estar duplicada, ya que la duplicación incrementa la dificultad de los cambios y evolución posterior, puede perjudicar la claridad y dar pie a posibles inconsistencias.

En la siguiente práctica veremos cómo refactorizar el código para evitar repeticiones.

Para lanzar la aplicación se ejecutará la clase `tp1.Main`,
por lo que se aconseja que todas las clases desarrolladas en la práctica estén en el paquete `tp1` (o subpaquetes suyos). 

### Objetos del juego

Para representar cada uno de los tipos de elementos que pueden aparecer en el tablero, a los que llamaremos objetos del juego, necesitarás, al menos, las siguientes clases:

- `UCMShip`, `RegularAlien`, `DestroyerAlien`, `Ufo`: estas  clases encapsulan el comportamiento de las naves del juego. Tienen atributos privados, como su posición `(columna, fila)`, su vida, etc. 

  Todas estas naves tienen métodos `getSymbol()`, que devuelven el símbolo con el que aparece en el tablero y el método `getDescription()`, que devuelven su descripción tal y como aparece al ejecutar el comando `list`. 
  Por ejemplo, para los aliens comunes esos métodos devuelven  `R` y `[R]egular Alien`, respectivamente.
  El primer método lo usará de modo auxiliar `toString()` y el segundo el método `getInfo()`, que devuelve la línea completa mostrada por `list`.
  
- `UCMLaser`, `Bomb`: estas clases representan las armas que pueden aparecer en esta versión de la práctica, el láser lanzado por `UCMShip` y las bombas lanzadas por las naves destructoras, respectivamente. También necesitan atributos privados para su posición, su *vida*, la dirección de su movimiento,... Además, `Bomb` necesitará guardar una referencia a la nave destructora que la lanzó.

- `ShockWave`: clase que representa la *shock wave* que puede lanzar el jugador sobre el tablero.

Tanto naves como armas mantienen una referencia a `Game` (ver más abajo).
De este modo, estas clases pueden *comunicarse* con la clase `Game` usando sus métodos públicos.
Entre otros, necesitan métodos básicos para saber si están vivos, para saber cuál es su posición, si están dentro del tablero, moverse siguiendo un movimiento (`Move`) dado,  para recibir daño...

#### Acciones del programa

Para implementar las acciones decididas por el programa (por ejemplo, el disparo de una bomba por parte de una nave destructora), los objetos del juego implementarán el método

```java
    public void computerAction() {...}
```


Por ejemplo, en el caso de la clase `DestroyerAlien` dicho método debe decidir si debe lanzar una bomba. En dicho caso, será necesario apuntarlo en un atributo para que en el próximo movimiento se cree la bomba y se añada al tablero. 

#### Movimiento automático

Los objetos que se muevan automáticamente implementarán un método

```java
    public void automaticMove() {...}
```
en el que se implementará el cambio de posición del objeto en función de su estado y del estado del juego. 

En el caso de las armas, tras el movimiento será en general necesario comprobar si el movimiento ha producido algún ataque. La forma de hacerlo es a través de la referencia `game` que hemos dicho que íbamos a mantener:

```java
    game.performAttack(this);
```

El juego se encargará de llevar este ataque a cada uno de los objetos del juego que pueden recibirlo (en este ejemplo, láser y jugador).


#### Implementación de los ataques

Las armas tendrán métodos para implementar su ataque al resto de objetos. Por ejemplo, para implementar el ataque del láser a las naves ordinarias tendremos en la clase `UCMLaser` un método

```java
    public boolean performAttack(RegularAlien alien) {...}
```

Análogamente, para implementar el ataque a una nave destructora tendremos en la clase un método

```java
    public boolean performAttack(DestroyerAlien alien) {...}
```

Fíjate en que estamos haciendo uso de la sobrecarga de métodos. Estos métodos primero comprueban que atacante y atacado están ambos vivos y comparten posición, en cuyo caso lanzan el ataque. El efecto del ataque sobre el atacante lo implementaremos directamente en estos métodos. Por ejemplo, el láser "muere" al alcanzar un alien. Sin embargo, el efecto que el ataque tiene sobre el atacado debería implementarse no en la clase atacante, sino en la clase atacada. Para ello, necesitaremos que los objetos implementen métodos para la recepción de un ataque por parte de un arma. Por ejemplo, para la implementación del daño que recibe una nave alienígena común por parte de un láser, la clase `RegularAlien` implementará un método

```java
    public boolean receiveAttack(UCMLaser weapon) {...}
```

En este caso la implementación de `receiveAttack` se limitará a decrementar las vidas según el daño ejercido por `weapon`.



#### Eliminación de objetos del juego

Los objetos de juego incluirán un método

```java
    public void onDelete() {...}
```

que será invocado cuando se detecte que el objeto ha muerto, es decir, que tiene cero vidas, antes de que el objeto sea eliminado definitivamente de su contenedor (ver más abajo). 

Dicho método se encargará de realizar aquellas acciones necesarias en el momento de la eliminación del objeto. Por ejemplo, las naves alienígenas notificarán su eliminación a `AlienManager`, para que este actualice su contador de las naves que quedan en el tablero. Las bombas notificarán a la nave que las lanzó que han muerto, de forma que la nave pueda volver a lanzar una bomba.

### Contenedores de objetos de juego 

En el tablero hay una UCMship y, a lo sumo, un láser y un ovni. Sin embargo, puede haber múltiples naves alienígenas ordinarias, múltiples naves destructores y múltiples bombas. Por ello, necesitamos clases que representen *contenedores* de estos objetos del juego.

Tienes que implementar las clases `RegularShipList`, `DestroyerShipList` y `BombList`, que contienen **listas** de los respectivos elementos **enemigos** del juego, así como métodos auxiliares para su gestión. Estas listas estarán todas implementadas mediante un array (suficientemente grande) y un contador. Además, los contenedores serán responsables de llevar las peticiones del juego a cada uno de sus objetos.

### Inicialización y movimiento de naves alienígenas

La clase `AlienManager` tiene la función de gestionar, por un lado, la inicialización del tablero, es decir, las posiciones iniciales de las naves alienígenas y, por otro lado, de gestionar su movimiento sincronizado. Tiene un atributo de la clase `Game` y otros atributos para conocer la situación del *escuadrón* de naves (por ejemplo, para saber cuántas naves alienígenas quedan, si el grupo de naves se encuentra en el borde del tablero o si han llegado a la fila inferior del tablero). 

Para la inicialización, la clase `AlienManager` cuenta con métodos

```java
    RegularAlienList initializeRegularAliens() {...}
    DestroyerAlienList initializeDestroyerAliens() {...}
```

### El modelo: la clase `Game`

La clase `Game` encapsula la lógica del juego. Habrá una única instancia de `Game` en el programa. Contiene una instancia de `RegularShipList`, una de `DestroyerShipList` y una de `BombList`, entre otras instancias de objetos. También tiene un atributo `AlienManager`, el contador de ciclos y la puntuación del jugador. Por último, tiene también un atributo `Random rand` para generar los valores aleatorios.

 Tiene, entre otros, el método `update` que actualiza el estado de todos los elementos del juego. Su implementación consistirá en realizar primero las *computer actions* y después los movimientos automáticos (en el orden especificado más arriba).

### Clases para el control y la visualización

- `Controller`: clase para controlar la ejecución del juego, preguntando al usuario qué quiere hacer y actualizando la partida de acuerdo a lo que éste indique. La clase `Controller` necesita, al menos, dos atributos privados:

```java
  private Game game;
  private Scanner in;
```

El objeto `in` sirve para leer de la consola las órdenes del usuario.

La clase `Controller` implementa el método público `public void run()` que controla el bucle principal del juego. Concretamente, mientras la partida
no esté finalizada, solicita órdenes al usuario y las ejecuta.

- `GamePrinter`: recibe el `game` y tiene un método `toString` que sirve para pintar el juego como veíamos anteriormente. 

### Otras clases

- `Level`: es una clase enumerada con la que se encapsulan los tres niveles de juego. 

- `Move`: enumerado para representar los distintos movimientos que pueden hacer los objetos del juego.

- `Position`: clase inmutable para representar una posición del tablero, es decir, para encapsular una columna y una fila.

- `Main`: Es la clase que contiene el método `main` de
la aplicación. En este caso, el método `main` lee los valores de los parámetros de la aplicación, crea una nueva partida (objeto de la clase `Game`), crea un controlador (objeto de la clase `Controller`) con dicha partida, e invoca al método `run` del controlador.

### Observaciones a la implementación

- Durante la ejecución de la aplicación solo se creará un objeto de la clase `Controller`. Lo mismo ocurre para la clase `Game`, que representa la partida en curso y solo puede haber una activa.

- Junto con la práctica, os proporcionaremos unas plantillas con partes del código.

- En el anexo encontrarás unas trazas de la ejecución; la salida de la práctica debe coincidir con los ejemplos.

El resto de información concreta para implementar la práctica será explicada por el profesor durante las distintas clases de teoría y laboratorio. En esas clases se indicará qué aspectos de la implementación se consideran obligatorios para poder aceptar la práctica como correcta y qué aspectos se dejan a la voluntad de los alumnos.


<!-- TOC --><a name="4-entrega-de-la-práctica"></a>
# 4. Entrega de la práctica

La práctica debe entregarse utilizando el mecanismo de entregas del campus virtual, no más tarde de la **fecha y hora indicada en la tarea del campus virtual**.

El fichero debe tener, al menos, el siguiente contenido [^1]:

- Directorio `src` con el código de todas las clases de la práctica.
- Fichero `alumnos.txt` donde se indicará el nombre de los componentes del grupo.

Recuerda que no se deben incluir los `.class`.

> **Nota**: Recuerda que puedes utilizar la opción `File > Export` para ayudarte a generar el .zip.

[^1]: Puedes incluir también opcionalmente los ficheros de información del proyecto de Eclipse

<!-- TOC --><a name="5-pruebas"></a>
# 5. Pruebas

Junto con las instrucciones de la práctica, tendrás una carpeta con trazas del programa. Encontrarás dos ficheros con la siguiente nomenclatura:

- `00-easy_25-input.txt`: es la entrada del caso de prueba `0` con nivel `easy` y semilla `25`.
- `00-easy_25-expected.txt`: es la salida esperada para la entrada anterior.

En Eclipse, para usar un fichero de entrada y volcar la salida en un fichero de salida, debes configurar la redirección en la pestaña `Common` de la ventana `Run Configurations`, tal y como se muestra en la siguiente figura.

![Redirección entrada y salida](imgs/Bitmap/Pr1/runConfigurationsCommon.png)

Hay multitud de programas gratuitos para comparar visualmente ficheros, por ejemplo Eclipse ya tiene integrada una herramienta para comparar archivos que puedes lanzar al seleccionar dos archivos, pulsar con el botón derecho y en el menú emergente seleccionar `Compare With > Each other`.

![Cómo comparar dos archivos en Eclipse](imgs/Bitmap/Pr1/Eclipse_Compare_EachOther.png)

Aparecerá una nueva ventana donde se mostrarán marcadas claramente las diferencias entre los archivos.

Ten mucho cuidado con **el orden las instrucciones** en el `update` porque puede cambiar la salida considerablemente.

Por supuesto, nuestra salida puede tener algún error, así que si detectas alguna inconsistencia por favor comunícanoslo para que lo corrijamos.

Durante la corrección de prácticas <!-- os daremos nuevos --> usaremos otros ficheros de prueba para asegurarnos de que vuestras prácticas se generalizan correctamente, así que asegúrate de probar no solo los casos que te damos, sino también otras posibles ejecuciones.
