# Strings
## Cifrar / Codificar / Decodificar / Descifrar
Este tipo de problemas se basan en que las comunicaciones digitales privadas sean seguras. Es decir que sus mensajes (cadenas) solo pueden ser leídos por el destinatario. 
Existen muchos sistemas de cifrado con este propósito y una gran parte de estos (Habitualmente los más sencillos) terminan convirtiéndose en un problemas ad hoc en concursos de programación, (Este tipo de problemas pueden ser divididos en 2 categorías los fáciles y los difíciles)
Para este tipo de problemas puede ser útil tener conocimientos sobre seguridad informática y criptografía.
Para poder resolver estos problemas es necesario entender el método de codificación o decodificación, que se describe en el problema, fuera de eso es solo implementarlo como se indica. 
## Análisis sintáctico de la entrada
Este tipo de problema van desde lo más sencillo, que se pueden resolver con un procesador iterativo, hasta los más complejos, los cuales necesitan del uso de métodos recursivos o la clase String/Pattern de Java

## String / Pattern de Java
### matches ( String regex )
El método se usa para determinar con mayor precisión si la cadena dada coincide con una expresión regular o no como cada vez que este método se llama en sí mismo como coincidencias, o ser coincidencias donde pasamos dos argumentos que son nuestra cadena y expresión regular, El trabajo y la producción siguen siendo los mismos.

Existen múltiples variantes, tres variantes del método matches() :
### Variante 1 : 
Este método indica si esta cadena coincide o no con la expresión regular dada (Retorna true or false). Una llamada de este método de la forma str.matches(regex) produce exactamente el mismo resultado que la expresión Pattern.matches(regex, str).
(.*) Indica si hay algo antes o después dependiendo en qué parte del regex se coloque. Por lo que busca si el regex forma parte de la cadena.

public class GFG {
    public static void main(String args[]){
       // Declaring and initializing a string
   	String Str = new String("Welcome to geeksforgeeks");
      System.out.print(
            "Does String contains regex (.*)geeks(.*) ? : ");
      // Testing if regex is present or not
      System.out.println(Str.matches("(.*)geeks(.*)"));
	//This show true
      System.out.print(
       	"Does String contains regex geeks ? : ");
      // Testing if regex is present or not
      System.out.println(Str.matches("geeks"));
	//This show false
    }
}

### Variante 2 y 3 : 
Este método tiene dos variantes que se pueden usar para probar si dos regiones de cadena son iguales, las cuales se diferencian en el hecho de que la variante 2 contempla si las letras son minusculas o mayusculas por lo que hace distinción entre estas a diferencia de la variante 3 que considera igual mayusculas y minusculas.

// Variante 2
public class GFG {
  public static void main(String args[]){
	String Str1= new String("Welcome to geeksforgeeks");
	String Str2 = new String("geeks");
	/* Tests whether GEEKS starts in geeksforgeeks starting
from pos 11 and compares 5 characters of GEEKS */
	System.out.print("Checking if GEEKS is in geeksforgeeks(
 case sensitive ) : ");
	System.out.println(Str1.regionMatches(11, Str2, 0, 5));
	//This show false
	}
}
// Variante 3
public class GFG {
   public static void main(String args[]) {
      String Str = new String("Welcome to geeksforgeeks");
      String Str2 = new String("GEeKs");
      /* Tests whether GEEKS starts in geeksforgeeks starting
 	from pos 11 and from 0 ( i.e starting in GEEKS) and
ignores case and compares 5 characters of GEEKS */
      System.out.print("Checking if GEEKS is in geeksforgeeks(
case insensitive ) : " );
   	System.out.println(Str.regionMatches(true,11,Str2, 0,5));
	/*El parámetro true indica si tomamos minúsculas y 
Mayúsculas como iguales*/
   }
}

### replaceAll( String regex, String replacement )
Este método reemplaza todas las coincidencias regex de una cadena por por la cadena indicada como replacement.
Ejemplos : 
El primer ejemplo cambia las coincidencias java por scala
String str = "how to do in java !! a java blog !!";
Assertions.assertEquals("how to do in scala !! a scala blog !!", str.replaceAll("java", "scala"));
		En este caso quitamos los espacios
		String blog = "how to do in java";
Assertions.assertEquals("howtodoinjava",
blog.replaceAll("\\s", ""));
En este caso añadimos un espacio entre cada caracter
String str = "JavaTpoint";
System.out.printf(str.replaceAll(“”, “ ”));

## Formato de salida 
Normalmente son problemas de calentamiento o para gastar tiempo. Para este tipo de problemas es recomendable practicar tus capacidades de programación, resolviendo este tipo de problemas lo más rápido posible, para tener una menor penalización de tiempo, fuera de ello para resolver el problema sólo has lo que se pide no hay mucha ciencia.

## Comparacion de cadenas
Estos problemas, se deben comparar cadenas según varios criterios. Esta es similar a la de los problemas de coincidencia de cadenas (Se definirá más adelante este tipo de problemas), para resolver este tipo de problemas regularmente se utilizarán funciones relacionadas con el strcmp en C / C++, el compare de C++ o el compareTo de Java.

### strcmp de C / C++
#include <cstring>
int main() {
    char str1[] = "hola", str2[] = "adios";
    int resultado = strcmp(str1, str2);
    if (resultado < 0) {
        cout << "str1 es menor que str2" << std::endl;
    } else if (resultado > 0) {
        cout << "str1 es mayor que str2" << std::endl;
    } else {
        cout << "str1 es igual a str2" << std::endl;
    }
    return 0;
}

### compare de C++
#include <string>
int main() {
    string str1 = "hello";
    string str2 = "world";
    int result = str1.compare(str2);
    if (result == 0) {
        cout << "Las cadenas son iguales" << endl;
    } else if (result < 0) {
        cout << "La primera cadena es menor que la segunda" << endl;
    } else {
        cout << "La primera cadena es mayor que la segunda" << endl;
    }
    return 0;
}

### compareTo de Java : 
String str1 = "hola";
String str2 = "adiós";
int resultado = str1.compareTo(str2);
if (resultado < 0) {
    System.out.println("str1 es menor que str2");
} else if (resultado > 0) {
    System.out.println("str1 es mayor que str2");
} else {
    System.out.println("str1 es igual a str2");
}

## Coincidencia de cadenas
La coincidencia de cadenas (También llamada búsqueda), consiste encontrar el índice, o índices, de una (sub) Cadena (llamada texto T).
Por ejemplo, aunamos que tenemos T = ‘STEVEN EVENT’. Si P = ‘EVE’, la respuesta serán los índices 2 y 7 (contando desde 0). Si P = ‘EVENT’, la respuesta será 7. Si P = ‘EVENING’, no habrá respuesta (no se encontrará ninguna coincidencia y devolveremos -1 o NULL).

### Soluciones con bibliotecas
Para problemas en que las cadenas son cortas:
#include <bits/stdc++.h>
using namespace std;
int main (){
  string T = "STEVEN EVENT";
  string P = "EVE";


  auto found = T.find(P); // Se busca la primera coincidencia de P en T
  cout << found << endl; // found = 2
  found = T.find(P, found + 1); //Buscamos a partir de una posición dada.
  cout << found << endl; 
  found = T.find("EVENTI"); //En este caso no se encontrara
  if(found == string::npos){ //Comprobamos si se encontró la cadena
  	cout << "NULL" << endl;
  }
  else
  	cout << found << endl;
  return 0;
}

## Algoritmo de Knuth-Morris-Pratt (KMP)
Con el algoritmo de KMP podemos encontrar todas las apariciones de la subcadena P (Con longitud m) en una cadena (larga) T (de longitud n), si hay alguna aparición de P.
El algoritmo KMP lo dividimos en 2 partes, la primera el Preprocesar la cadena P, para crear una ‘tabla de reinicios’, en base a los patrones que vayamos encontrando por la cadena P.
Para el cálculo de la tabla de reinicios, buscamos patrones para tratar de reiniciar de una mejor posición que la inicial. Comenzamos poniendo la primera posición como -1 (Por que no hay ningún patrón antes). En el caso de que no haya patrón el valor en la tabla de reinicio será cero, si hay patrón, el valor de la tabla de reinicio será igual al valor de la posición de reinicio en la que comenzaremos en caso de un fallo.
La segunda parte consiste en buscar las coincidencias de P en T, utilizando un proceso similar al que utilizamos anteriormente para preprocesar P. En este caso avanzaremos los punteros de las cadenas mientras coincidan, y en el caso del fallo simplemente el puntero de nuestra cadena P se reinicia a la posición almacenada en la tabla de reinicios. Para saber si P ya se encontró el puntero deberá ser igual al largo de la cadena, en este caso la posición de la coincidencia es i - j (Siendo i el puntero de T y j el puntero de P), para continuar buscando la próxima coincidencia reiniciamos j (De acuerdo a nuestra tabla de reinicios).
La complejidad de este algoritmo es O(n + m)

### Implementación siguiente página.
#include <bits/stdc++.h>
#define MAX 100010
using namespace std;
string T, P;
int b[MAX], n, m; 
// b = tabla de reinicios // n = long. de T // m = long. de P 
void kmpPreprocess(){ // Llamar antes de kmpSearch()
    int i = 0, j = -1; b[0] = -1;  // Valores Iniciales
    while(i < m){ //Proceso previo de cadena patrón P
        while(j >= 0 && P[i] != P[j]) j = b[j]; //Diferente, reiniciar j
        i++; j++; // Si es igual avanzamos ambos punteros
        b[i] = j;
    }
}
void kmpSearch(){ //Similar a kmpPreprocess(), pero sobre T
    int i = 0, j = 0;   //Valores iniciales
    while(i < n){ //Buscar en la cadena T
        while(j >= 0 && T[i] != P[j]) j = b[j]; //Diferente, reiniciar j
        i++; j++; //Si es igual avanzamos ambos punteros
        if(j == m){
            cout << "P se encontró en el index " << i - j << "\n";
            j = b[j]; //Preparar j para la siguiente coincidencia
        }
    }
}






