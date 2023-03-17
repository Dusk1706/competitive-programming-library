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



