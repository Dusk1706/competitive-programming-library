# Geometria

## Formulas
Pendiente: m = (Y2-Y1)/(X2-X1)

## Puntos
Tratamos de evitar operaciones de punto flotante (es decir, divisiones, raíces cuadradas y cualquier otra operación que pueda producir errores numéricos) y trabajar con enteros precisos siempre que sea posible (es decir, sumas, restas y multiplicaciones).

Si necesitamos trabajar con puntos flotantes
- Para comparar 2 numeros de punto flotante se debe hacer de esta manera: fabs(a-b) < EPS, 
donde EPS es un número pequeño como 1e-9 (es decir, 10⁹ o 0.000000001) en lugar de a == b.
- Verificar si un número de punto flotante X es mayor que 0.0 utilizando x > -EPS (similarmente, para verificar si x ≤ 0.0, usamos x < EPS).
- Utilizar el tipo de datos double por defecto en lugar del tipo de float.
- Aplazar las operaciónes de punto flotante lo más tarde posible para reducir el efecto de errores acumulativos.
- Reducir la cantidad de operaciones de punto flotante tanto como sea posible, por ejemplo, en lugar de calcular a/b/c (dos divisiones de punto flotante), calculamos a/(b * c) (sólo una división de punto flotante).

### Formulas de Puntos
Pendiente a partir de un punto positivo: m = Y/X 

### Producto Cruz
El producto cruz nos da el doble del area de un triangulo formado por dos puntos y tambien permite determinar la orientacion relativa de un punto respecto a una línea 

Formula: (X1)(Y2) - (X2)(Y1)

Dados los Puntos (A, B, C) restamos las coordenadas de A a los puntos B y C para conocer la
posicion relativa y de la linea en el plano luego hacemos producto cruz (B X C)

Si el producto cruz da positivo quiere decir que el punto C esta de lado izquierdo desde A hacia B, si da negativo esta de lado derecho y si es cero esta en la misma linea osea son colineales
![](https://github.com/Dusk1706/Estructuras-de-datos-y-Algoritmos/blob/main/Imagenes/OrientacionProductoCruz.png)

### Sweep Line 
Muchos problemas geometricos pueden ser resueltos usando la tecnica Sweep Line. La idea
al usar esta tecnica es representar una instancia del problema como un conjunto de eventos
que corresponden a puntos en el plano.
Los eventos son procesados en orden ascendiente de acuerdo a las coordenadas X o Y.

## Lineas
Las líneas son un conjunto de puntos (x, y) en el plano que cumplen una ecuación de la forma
ax + by + c = 0, donde al menos uno de los valores de a y b es distinto de cero. Los valores de a y b determinan la dirección de la línea, mientras que c determina su posición.

### Interseccion de 2 segmentos de linea
Interseccion: Es el punto donde ambos segmentos se cruzan o se encuentran.
Consideraciones para 

### Segmento de linea
Es una línea con dos puntos finales que tiene una longitud finita.

## Rectangulo
Representaremos los rectangulos con 2 puntos la esquina superior derecha (top right = tr) 
y esquina inferior izquierda (bottom left = bl) 
Algunas formulas que involucran el area de dos o mas rectangulos basados en sus coordenadas
X y Y o determinar si los rectangulos intersectan

### Area de un rectangulo
Formula del area de un solo rectangulo largo por ancho
Largo es la longitud de los lados verticales y el ancho la longitud de los lados horizontales
largo = try - bly
ancho = trx - blx
area = largo * ancho

Implementacion 
```
long long area(int bl_x, int bl_y, int tr_x, int tr_y) {
	long long length = tr_y - bl_y;
	long long width = tr_x - bl_x;
	return length * width;
}
```
### Comprobar si dos rectangulos se intersectan
Dados dos rectangulos a y b solo hay 2 casos que no pueden intersectarse, recordando (tr = top right), (bl = bottom left) 

[ tr<sub>a<sub>y</sub></sub> <= bl<sub>b<sub>y</sub></sub> ] o [ bl<sub>a<sub>y</sub></sub> >= tr<sub>b<sub>y</sub></sub> ]

[ bl<sub>a<sub>x</sub></sub> >= tr<sub>b<sub>x</sub></sub> ] o [ tr<sub>a<sub>x</sub></sub> <= bl<sub>b<sub>x</sub></sub> ]

En todos los demas casos los rectangulos se intersectan

Implementacion
```
bool intersect(vector<int> s1, vector<int> s2) {
	int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
	int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

	// No comparten Area comun
	if (bl_a_x >= tr_b_x || tr_a_x <= bl_b_x || bl_a_y >= tr_b_y ||
	    tr_a_y <= bl_b_y) {
		return false;
	} else {
		return true;
	}
}
```

## Vector
Es un segmento de línea (por lo tanto, tiene dos puntos finales y longitud/magnitud) con una dirección.

## Circulo
Un círculo centrado en las coordenadas (a, b) con radio r es el conjunto de todos los puntos 
(x, y) tal que (x - a)² + (y - b)² = r².