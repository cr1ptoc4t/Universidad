# Práctica 1 - Space Invaders: Guía de implementación

Este documento pretende ayudarte con la implementación de la práctica 1. Si no lo consideras útil, puedes ignorarlo.

## Estructura

Se os ha entregado una plantilla con los siguientes paquetes y ficheros:

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

Como verás, dentro de cada paquete hay varios ficheros. Los ficheros en cursiva se encuentran completamente implementados y no debes cambiar su código. El resto, en cambio, están parcialmente implementados y puedes (y debes) añadir más métodos y atributos a sus clases. Además, también puedes crear más clases y paquetes si lo consideras necesario.

El código entregado sigue algo parecido al patrón _Modelo-Vista-Controlador_ (MVC). 

+ La **Vista** se corresponde con el paquete `view`. Ahí se encuentran las clases encargadas de mostrar el juego. En nuestro caso, se trata de una simple vista por consola. Se encarga de ello `GamePrinter`, que recibe una instancia de `Game` y la convierte a `String` para mostrar el estado de juego en consola. Podríamos tener varias vistas e incluso, en un futuro, se podría cambiar añadiendo, por ejemplo, colores, tal y como hicisteis en FP2, pero no pierdas el tiempo con ello. 

+ El **Controlador** se corresponde con el paquete `control`. Ahí se encuentra la clase encargada de gestionar el "ciclo de vida" del juego: mientras que el juego no se acaba, solicita órdenes al usuario, las traslada al juego y llama a la vista. Estamos ante un controlador sencillo, que se limita a leer las órdenes que el usuario teclea por consola, en lugar de capturar pulsaciones de teclas u otras alternativas. Aquí es donde se implementa el ciclo de vida del juego, sin entrar en la lógica del juego.

+ El **Modelo** se corresponde con el paquete `logic`, donde se encuentra la lógica del juego, es decir, las reglas del juego y el manejo de todos los objetos del juego. La clase principal de este paquete es `Game`. Para poder realizar su tarea, el juego recibe del controlador la orden correspondiente. Entre los comandos del juego hay órdenes para ejecutar un movimiento de la nave, disparar, activar el superpoder *shockwave* o no realizar nada (`none`). Como puedes observar, en el modelo se implementa todo lo relativo al juego: número de ciclos, puntuación, naves, si hay ganador, si se ha terminado, etc.

Una vez vista la estructura de la práctica, nos damos cuenta de que hay mucho trabajo por delante y nos planteamos...

| **¿Por dónde empezar?** |
| :---: |


## División en tareas

En proyectos grandes lo mejor es plantearse hitos pequeños o mini-proyectos que vayan funcionando, a los que luego ir añadiendo extensiones. A su vez, es conveniente dividir estos mini-proyectos en pequeños pasos cuya funcionalidad se pueda probar. En este sentido, os planteamos los siguientes mini-proyectos con los siguientes pasos:

### [A] Nuestra nave, un disparo suyo y una nave alienígena común
	
1. Si la plantilla no compila, añade el código imprescindible para que compile. Por ejemplo, si un método aún no implementado tiene que devolver un objeto, escribe por el momento `return null`. ¡Y ejecútala!

2. Mete los parámetros del `main` y si es necesario cambia el valor devuelto por algún método para que se dibuje el **tablero vacío**.

3. Añade la nave `UCMShip` y haz que se dibuje.

4. Haz que se mueva la nave (primeros comandos: `[m]ove` y `[n]one`).

5. Añade el disparo de la nave, `UCMLaser`, haz que se vea y se mueva solo (comando `[s]hoot`).

6. Añade una nave alienígena común, `RegularAlien`, haz que se dibuje y que se mueva sola. 

    - ***Movimiento***: Fíjate que primero se mueve en una dirección fija hacia la izquierda. Si llega al borde lateral, cambia la dirección hacia abajo durante un solo movimiento, mientras que el próximo movimiento lo realizará hacia la derecha. Si se mueve hacia abajo es porque estaba en un borde, por lo que tiene que volver a cambiar la dirección hacia el borde contrario.
    - ***Implementación***: Una forma sencilla de implementarlo es considerar que el alien tiene una dirección de movimiento (izquierda o derecha) y un valor booleano que indica si tiene que respetar la dirección del movimiento o bajar. Este booleano solo es necesario cambiarlo si, después de moverse, ha llegado al borde. En este caso, no solo habrá que indicar que en el próximo movimiento tiene que bajar, sino que se tendrá que cambiar la dirección a la opuesta. En el movimiento en el que se mueva hacia abajo, solo será necesario volver a cambiar el booleano, ya que el movimiento siguiente deberá respetar el de la dirección almacenada.
        
7. Haz que el disparo mate a la nave alienígena.

8. Haz que el juego termine ganando, perdiendo o ejecutando **exit** (comando `[e]xit`).

9. Revisa pequeños detalles (número de ciclos, puntuación, resto de comandos,...) que has podido ignorar durante las etapas anteriores y comprueba el funcionamiento de la práctica general (comandos `[h]elp`, `[l]ist` y `[r]eset`).

|***¡Que todo funcione correctamente!***|
| :---: |

### [B] Nuestra nave, un disparo suyo y muchas naves alienígenas comunes

1. Mete la nave alienígena en la lista `RegularAlienList`. Comprueba que se puede matar, que el juego sigue terminando, etc.
        
2. Mete dos naves alienígenas en la lista e implementa el `AlienManager` para que los movimientos de las naves se produzcan a la vez y para que cualquiera que alcance el borde cambie la dirección del movimiento general de las naves. El `AlienManager` te lo puedes plantear como la **nave nodriza** a la que todas las naves alienígenas tienen que consultar su dirección de movimiento.

    - ***Implementación***: Ahora te tocará llevar parte de los movimientos que implementaste en `RegularAlien` al `AlienManager`(**nave nodriza**). Cada `RegularAlien` debe informar a la **nave nodriza** si muere o si llega al borde, y también deberá preguntarle, antes de moverse, en qué dirección debe moverse. La **nave nodriza** sabe cuántas peticiones ha recibido y, hasta que no reciba la petición de dirección de movimiento de todas las naves a las que controla, no podrá cambiar la dirección general del movimiento de estas, puesto que todas se deben mover acompasadas. Por lo tanto, ahora la **nave nodriza** tiene que almacenar si alguna nave, en el paso actual, le ha comunicado que había llegado al borde, para luego poder cambiar el `booleano` que indicaba si tenía que respetar la dirección o bajar. Fíjate que cuando todas las naves se han comunicado es cuando hace los cambios de dirección que antes se hacían en `RegularAlien`, para que en el siguiente movimiento todas se muevan acompasadas.

3. Generaliza la lista y permite meter varias naves alienígenas.

4. Implementa el inicializador adecuado de la lista para que, dependiendo de la dificultad, se creen las naves alienígenas que correspondan.

### [C] Nuestra nave, un disparo suyo, muchas naves alienígenas comunes y destructoras

1. Añade una única nave destructora e implementa la clase `Bomb`.

2. Generaliza para poder tener muchas naves alienígenas destructoras.

### [D] Nuestra nave, un disparo suyo, muchas naves alienígenas comunes y destructoras y un ovni
   
1. Añade `Ufo`. Haz que se le pueda matar con el láser. (Para tus pruebas, podrías dejar solo al ovni.)

2. Añade el superpoder y haz que el usuario pueda utilizar el comando "shock[W]ave".

|***¡Felicidades! ¡Parece que has terminado!***|
| :---: |
| Realiza las pruebas que te demos.|
