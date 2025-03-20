#include <memory>
using namespace std;

/*
Estructura de un nodo en una lista enlazada.
 */
struct node {
    int value; /**< Valor almacenado en el nodo */
    shared_ptr<node> next; /**< Puntero al siguiente nodo */
};

/*
Estructura de una lista enlazada.
 */
struct list {
    shared_ptr<node> head; /**< Puntero al primer nodo de la lista */
    size_t cant; /**< Cantidad de nodos en la lista */
};

/*
Crea una estructura de un nodo en una lista enlazada
int value
shared_ptr al siguiente nodo
retorna shared_ptr<node>
*/
shared_ptr<node> create_node(int value);

/*
Crea una estructura de una lista enlazada
size_t cant
shared_ptr al head
retorna shared_ptr<list>
*/
shared_ptr<list> create_list();

/*
 Inserta un nodo al inicio de la lista.
 list<list*> Puntero a la lista donde se insertará el nodo.
 value <int>Valor del nodo a insertar.
 */
void push_front(list* list, int value);

/*
Encuentra el nodo previo a una posición dada en la lista.
list<list*> Puntero a la lista.
pos<size_t> Posición del nodo cuyo predecesor se quiere encontrar.
retorna shared_ptr<node>* Puntero al puntero del nodo anterior o nullptr si no existe.
 */
shared_ptr<node>* find_prev(list* list, size_t pos);

/*
 Inserta un nodo al final de la lista.
 list<list*> Puntero a la lista donde se insertará el nodo.
 value <int>Valor del nodo a insertar.
 */
void push_back(list*list, int value);

/*
 Inserta un nodo en una posición dada de la lista.
 Si la posición es mas larga que la lista se la inserta al final
 list<list*> Puntero a la lista donde se insertará el nodo.
 value <int>Valor del nodo a insertar.
 pos<size_t> posicion donde se quiere insertar el nodo
 */
void insert(list* list, int value, size_t pos);

/*
 Elimina un nodo de una posición dada de la lista.
 Si la posición es mas larga que la lista se elimina el último nodo
 list<list*> Puntero a la lista donde se eliminará el nodo.
 pos<size_t> posicion del nodo que se quiere eliminar
 */
void erase(list* list, size_t pos);

/*
Imprime los valores de la lista enlazada.
list<list*> Puntero a la lista a imprimir.
 */
void print_list(list* list);
