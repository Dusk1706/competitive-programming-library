# Combinatoria 
## Variacion
La variación es una muestra ordenada de r elementos que se pueden tomar de un conjunto de n elementos. La 
fórmula para calcular las variaciones de tamaño r en un conjunto con n elementos es la siguiente:

## Combinaciones
Es una muestra no ordenada de r elementos que se pueden tomar de un conjunto de n elementos. Es parecido a las variaciones, con la diferencia de que aquí el orden no importa.
Hay dos maneras de calcular esto, con el triángulo de pascal (como veremos más adelante) o directamente con la fórmula.

## Multiconjuntos
Un multiconjunto es un conjunto donde un elemento puede aparecer más de una vez. Se denotan y tienen las mismas propiedades y operaciones que los conjuntos. También existe un sub multiconjunto, que es como el subconjunto.

## Permutaciones con repetición
Son las posibles ordenaciones de los elementos de un multiconjunto.
![](https://github.com/Dusk1706/Estructuras-de-datos-y-Algoritmos/blob/main/Imagenes/PermutacionesConRepeticion.png)
La fórmula básicamente explica que la cantidad de permutaciones con repetición es igual a la cantidad de datos en el multiconjunto factorial entre el producto de las factoriales de la cantidad que se repite cada elemento del multiconjunto.

## Variaciones con repetición
Son posibles muestras ordenadas de r elementos, no necesariamente distintos, que se pueden extraer de un conjunto de n elementos. Cuando se trabaja con variaciones con repetición, normalmente se habla de que existe una cantidad infinita de repeticiones de los elementos
![](https://github.com/Dusk1706/Estructuras-de-datos-y-Algoritmos/blob/main/Imagenes/VariacionesConRepeticion.png)
La fórmula dice que la cantidad de variaciones con repetición es igual a la cantidad de elementos del multiconjunto elevado a la cantidad de elementos de la muestra.

## Combinaciones con repetición
Son posibles muestras no ordenadas de r elementos, no necesariamente distintos, que se pueden extraer de un conjunto de n elementos. Cuando se trabaja con combinaciones con repetición, normalmente se habla de que existe una cantidad infinita de repeticiones de los elementos.
![](https://github.com/Dusk1706/Estructuras-de-datos-y-Algoritmos/blob/main/Imagenes/CombinacionesConRepeticion.png)
La fórmula para sacar la cantidad de las combinaciones repetidas es la misma que de la combinatoria normal, con la diferencia de que, en vez de n, utilizaremos n + r – 1.


