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
X y Y o determinar si los rectangulos intersectan.

Representacion de un rectangulo 
Donde x1, y1 son las coordenadas de la esquina inferior izquierda (bottom left) 
y x2, y2 son las coordenadas de la esquina superior derecha (top right)
```
struct Rect {
	int x1, y1, x2, y2;
	int area() { return (y2 - y1) * (x2 - x1); }
	void input(){ cin>>x1>>y1>>x2>>y2; }
};
```

### Largo, Ancho y Area de un rectangulo
Largo es la longitud de los lados verticales y el ancho la longitud de los lados horizontales

Largo = try - bly

Ancho = trx - blx

Area = largo * ancho

### Comprobar si dos rectangulos se intersectan
Dados dos rectangulos a y b solo hay 2 casos que no pueden intersectarse, recordando (tr = top right), (bl = bottom left) 

[ tr<sub>a<sub>y</sub></sub> <= bl<sub>b<sub>y</sub></sub> ] o [ bl<sub>a<sub>y</sub></sub> >= tr<sub>b<sub>y</sub></sub> ]

[ bl<sub>a<sub>x</sub></sub> >= tr<sub>b<sub>x</sub></sub> ] o [ tr<sub>a<sub>x</sub></sub> <= bl<sub>b<sub>x</sub></sub> ]

En todos los demas casos los rectangulos se intersectan

Implementacion
```
bool intersect(Rect a, Rect b) {
	// No comparten Area comun
	if (a.x1 >= b.x2 || a.x2 <= b.x1 || a.y1 >= b.y2 || a.y2 <= b.y1) {
		return false;
	}
	return true;
}
```

### Encontrar el area de una interseccion entre 2 rectangulos
Supondremos que la forma resultante de la intersección de dos rectángulos es también un rectángulo

Primero encontraremos el largo y ancho del rectangulo intersectado 

Largo = min(tr<sub>a<sub>y</sub></sub> , tr<sub>b<sub>y</sub></sub>) - max(bl<sub>a<sub>y</sub></sub> , bl<sub>b<sub>y</sub></sub>)

Ancho = min(tr<sub>a<sub>x</sub></sub> , tr<sub>b<sub>x</sub></sub>) - max(bl<sub>a<sub>x</sub></sub> , bl<sub>b<sub>x</sub></sub>)

Si alguno de estos valores largo o ancho es negativo no se intersectan. si son cero los rectangulos se intersectan en un solo punto. Se multiplica largo por ancho para saber el area comun

Implementacion
```
int intersectArea(Rect a, Rect b) {
	int xOverlap = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
	int yOverlap = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
	return xOverlap * yOverlap;
}
```

## Vector
Es un segmento de línea (por lo tanto, tiene dos puntos finales y longitud/magnitud) con una dirección.

## Circulo
Un círculo centrado en las coordenadas (a, b) con radio r es el conjunto de todos los puntos 
(x, y) tal que (x - a)² + (y - b)² = r².