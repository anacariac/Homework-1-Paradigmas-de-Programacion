## Homework-1-Paradigmas-de-Programacion
##  **Ejercicio 1 - Matriz Cuadrada y Recorrido Decreciente**
###  **Descripción**
Este ejercicio genera una **matriz cuadrada `n x n`**, la llena con valores secuenciales (`1, 2, 3, ..., n*n`) y la imprime en **orden decreciente** de índices.

###  **Implementación**
- `creatematrix(n)`: Crea y llena la matriz con valores secuenciales.
- `printmatrix(M, n)`: Imprime los valores de la matriz en orden decreciente.
- `main()`: Pide al usuario un tamaño `n`, genera la matriz y la imprime.

###  **Ejemplo de Ejecución**


---

##  **Ejercicio 2 - Sistema de Logs**
###  **Descripción**
Este ejercicio implementa un **sistema de logs** que registra eventos en un archivo `logfile.txt` con diferentes niveles de severidad.

###  **Implementación**
- `convertLevel(Level severity)`: Convierte un nivel de severidad a su representación en texto (`[DEBUG]`, `[INFO]`, etc.).
- `logMessage(message, severity)`: Guarda un mensaje en el log con su nivel de severidad.
- `logMessage(message, file, line)`: Guarda un mensaje con información del archivo y línea.
- `logMessage(message, user)`: Guarda un mensaje de seguridad con el nombre de usuario.
- `main()`: Genera eventos de prueba y los registra en el log.

###  **Ejemplo de Salida en `logfile.txt`**


---

##  **Ejercicio 3 - Lista Enlazada con `shared_ptr`**
###  **Descripción**
Implementación de una **lista enlazada dinámica** en C++ utilizando **smart pointers `shared_ptr`**.

###  **Implementación**
- `create_list()`: Crea una lista vacía.
- `create_node(value)`: Crea un nuevo nodo con un valor dado.
- `push_front(list, value)`: Inserta un nodo al frente de la lista.
- `push_back(list, value)`: Inserta un nodo al final de la lista.
- `insert(list, value, pos)`: Inserta un nodo en una posición específica.
- `erase(list, pos)`: Elimina un nodo de una posición dada.
- `print_list(list)`: Imprime la lista enlazada.

###  **Ejemplo de Ejecución**



---

##  **Ejercicio 4 - Comparación de Cadenas y Tiempo de Ejecución**
###  **Descripción**
Este ejercicio compara dos cadenas de texto utilizando **tres métodos distintos** y mide el tiempo de ejecución de cada uno:
1. **`std::string`** (más sencillo pero menos eficiente).
2. **`char*`** (más rápido al evitar la sobrecarga de `std::string`).
3. **`constexpr char*`** (se evalúa en **tiempo de compilación** para mejorar el rendimiento).

###  **Implementación**
- `compare(string s1, string s2)`: Compara dos cadenas usando `std::string`.
- `compare(const char* s1, const char* s2)`: Compara dos cadenas usando punteros a `char`.
- `compare_constexpr(const char* s1, const char* s2)`: Compara dos cadenas usando `constexpr char*`.
- `finalTime()`: Mide el tiempo de ejecución de cada método.

###  **¿Por qué `char*` es más rápido que `std::string`?**
- `std::string` maneja la memoria internamente, lo que agrega **sobrecarga**.
- `char*` evita la asignación dinámica de memoria, lo que lo hace **más rápido en operaciones simples**.

###  **¿Por qué `constexpr char*` es aún más rápido?**
- Un `constexpr` se evalúa en **tiempo de compilación**, eliminando completamente la ejecución en **runtime**.
- Si la comparación es **determinista**, el compilador optimiza la función para que se ejecute en `O(1)`.

---

