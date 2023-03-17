# Geometria

## Punto
Tratamos de evitar operaciones de punto flotante (es decir, divisiones, raíces cuadradas y cualquier otra operación que pueda producir errores numéricos) y trabajar con enteros precisos siempre que sea posible (es decir, sumas, restas y multiplicaciones).

Si necesitamos trabajar con puntos flotantes
- Para comparar 2 numeros de punto flotante se debe hacer de esta manera: fabs(a-b) < EPS, 
donde EPS es un número pequeño como 1e-9 (es decir, 10⁹ o 0.000000001) en lugar de a == b.
- Verificar si un número de punto flotante X es mayor que 0.0 utilizando x > -EPS (similarmente, para verificar si x ≤ 0.0, usamos x < EPS).
- Utilizar el tipo de datos double por defecto en lugar del tipo de float.
- Aplazar las operaciónes de punto flotante lo más tarde posible para reducir el efecto de errores acumulativos.
- Reducir la cantidad de operaciones de punto flotante tanto como sea posible, por ejemplo, en lugar de calcular a/b/c (dos divisiones de punto flotante), calculamos a/(b * c) (sólo una división de punto flotante).