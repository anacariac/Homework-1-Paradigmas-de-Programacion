#include <string>
using namespace std;

/*
Compara dos oraciones con implementacion de recursividad, 
retorna un booleano
 s1<string> Primera cadena.
 s2 <string> Segunda cadena.
*/
bool compare(string s1, string s2);

/*
Compara dos oraciones con implementacion de recursividad, 
retorna un booleano
 s1<const char*> Primera cadena.
 s2 <const char*> Segunda cadena.
*/
bool compare(const char* s1, const char* s2);

/*
Compara dos oraciones con implementacion de recursividad, el programa corre en tiempo de compilación
retorna un booleano en consexpr
 s1<const char*> Primera cadena.
 s2 <const char*> Segunda cadena.
*/
constexpr bool compare_constexpr(const char* s1, const char* s2);

/*
 Mide el tiempo de ejecución de la comparación de cadenas utilizando string.
 s1<string> Primera cadena.
 s2 <string> Segunda cadena.
 Implementación de libreria <chrono>
 */
void finalTime(string s1, string s2);

/*
 Mide el tiempo de ejecución de la comparación de cadenas utilizando punteros a caracteres (char*).
 s1<const char*> Primera cadena.
 s2 <const char*> Segunda cadena.
 expr <bool>  Indica si se usa la versión constexpr, por default es false.
 */
void finalTime(const char* s1,const char* s2,bool expr = false);

