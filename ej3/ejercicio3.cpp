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

    push_front(my_list.get(), 10);
    push_front(my_list.get(), 20);
    push_back(my_list.get(), 30);
    push_back(my_list.get(), 40);
    insert(my_list.get(), 25, 2);  

    cout << "Lista después de insertar elementos: ";
    print_list(my_list.get());  

    erase(my_list.get(), 2);
    cout << "Lista después de borrar el nodo en posición 2: ";
    print_list(my_list.get());  // Debería mostrar: 20->10->30->40->NULL

    // Borrar el primer nodo
    erase(my_list.get(), 0);
    cout << "Lista después de borrar el primer nodo: ";
    print_list(my_list.get());  // Debería mostrar: 10->30->40->NULL

    // Insertar en la última posición (pos > cant)
    insert(my_list.get(), 50, 10);  // La lista tiene 3 elementos, por lo que se debe insertar al final
    cout << "Lista después de insertar 50 al final: ";
    print_list(my_list.get());  // Debería mostrar: 10->30->40->50->NULL

    // Borrar el último nodo
    erase(my_list.get(), 3);
    cout << "Lista después de borrar el último nodo: ";
    print_list(my_list.get());  // Debería mostrar: 10->30->40->NULL

    return 0;
}