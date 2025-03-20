#include <iostream>
#include <memory>
using namespace std;

struct node{
    int value;
    shared_ptr<node> next;
};
struct list{
    shared_ptr<node> head;
    size_t cant;
};

shared_ptr<node> create_node(int value){
    shared_ptr<node> new_node = make_shared<node>();
    new_node ->value = value;
    new_node ->next = nullptr;
    return new_node;
}

shared_ptr<list> create_list(){
    shared_ptr<list> new_list = make_shared<list>();
    new_list ->head = nullptr;
    new_list ->cant = 0;
    return new_list; //crea lista vacía
}

void push_front(list* list, int value){
    shared_ptr<node> new_node = create_node(value);
    new_node->next = (list->head); //el head de la lista ahora es el siguiente del nuevo nodo
    list->head = (new_node);
    list->cant++;
}

shared_ptr<node> find_prev(list* list, size_t pos){
    if (pos == 0 || list->cant == 0) return nullptr; // No hay anterior al primer nodo
    size_t count = 0;
    shared_ptr<node> temp = (list->head); 

    while ((temp)->next && count < pos - 1) {
        temp = ((temp)->next);
        count++;
    }
    return temp; // Retornamos el nodo anterior
}

void push_back(list*list, int value){
    shared_ptr<node> new_node = create_node(value);
    if(!(list->head)){// si la lista esta vacía
        list->head = (new_node);
        list->cant++;
        return;
    }
    shared_ptr<node> prev = find_prev(list,list->cant);//encuentro el previo
    (prev)->next = (new_node);
    list->cant++;
}

void insert(list* list, int value, size_t pos){
    if(pos==0){//si quiero insertarlo en el primer lugar
        push_front(list, value);
        return;
    }
    if(pos>=(list->cant)){
        if(pos>(list->cant)){
            cout<<"Posición mayor al largo de la lista, se insertará en el útlimo lugar"<<endl;
        }
        push_back(list, value);
        return;
    }
    shared_ptr<node> prev = find_prev(list,pos);//encuentro el previo
    shared_ptr<node> new_node = create_node(value);
    new_node->next = ((prev)->next);
    (prev)->next = (new_node);
    list->cant++;
}

void erase(list* list, size_t pos){
    if(!(list->cant)) return;
    if(pos==0){
        list->head = (list->head->next);
        list->cant--;
        return;
    }
    if(pos<= list->cant){
        shared_ptr<node> prev = find_prev(list,pos); //encuentro el previo
        (prev)->next = (prev)->next->next;
        list->cant--;
        return;
    }
    cout<<"Posición mayor al largo de la lista, se eliminará el útlimo elemento"<<endl;
    shared_ptr<node> prev = find_prev(list,list->cant);
    (prev)->next = nullptr;
    list->cant--;
    return;
}

void print_list(list* list){
    shared_ptr<node> temp = (list->head); 
    for (size_t i = 0; i < list->cant; i++){
        cout<<(temp)->value<<"->";
        temp = ((temp)->next);
    }
    cout<<"NULL\n"<<endl;
}

int main(){
    auto my_list = create_list();

    // Insertar en la cabeza y en la cola
    push_front(my_list.get(), 10);
    push_front(my_list.get(), 20);
    push_back(my_list.get(), 30);
    push_back(my_list.get(), 40);
    insert(my_list.get(), 25, 2);

    cout << "\nLista después de insertar elementos: ";
    print_list(my_list.get());  

    // Borrar en una posición intermedia
    erase(my_list.get(), 2);
    cout << "\nLista después de borrar el nodo en posición 2: ";
    print_list(my_list.get());  // Debería mostrar: 20->10->30->40->NULL

    // Borrar el primer nodo
    erase(my_list.get(), 0);
    cout << "\nLista después de borrar el primer nodo: ";
    print_list(my_list.get());  // Debería mostrar: 10->30->40->NULL

    // Insertar en la última posición (pos > cant)
    insert(my_list.get(), 50, 10);  
    cout << "\nLista después de insertar 50 al final: ";
    print_list(my_list.get());  // Debería mostrar: 10->30->40->50->NULL

    // Borrar el último nodo
    erase(my_list.get(), 3);
    cout << "\nLista después de borrar el último nodo: ";
    print_list(my_list.get());  // Debería mostrar: 10->30->40->NULL

    // 🔹 Insertar en la posición 1
    insert(my_list.get(), 15, 1);
    cout << "\nLista después de insertar 15 en posición 1: ";
    print_list(my_list.get());  // Debería mostrar: 10->15->30->40->NULL

    // 🔹 Insertar en la cabeza (posición 0)
    insert(my_list.get(), 5, 0);
    cout << "\nLista después de insertar 5 en la cabeza: ";
    print_list(my_list.get());  // Debería mostrar: 5->10->15->30->40->NULL

    // 🔹 Intentar eliminar un nodo fuera del rango (debería eliminar el último)
    erase(my_list.get(), 10);
    cout << "\nLista después de intentar borrar en pos > cant: ";
    print_list(my_list.get());  // Debería mostrar: 5->10->15->30->NULL

    // 🔹 Eliminar todos los nodos uno por uno
    erase(my_list.get(), 0);
    erase(my_list.get(), 0);
    erase(my_list.get(), 0);
    erase(my_list.get(), 0);
    
    cout << "\nLista después de eliminar todos los nodos: ";
    print_list(my_list.get());  // Debería mostrar: NULL

    // 🔹 Insertar nuevamente después de vaciar la lista
    push_front(my_list.get(), 100);
    push_front(my_list.get(), 200);
    cout << "\nLista después de insertar elementos en una lista vacía: ";
    print_list(my_list.get());  // Debería mostrar: 200->100->NULL

    return 0;
}