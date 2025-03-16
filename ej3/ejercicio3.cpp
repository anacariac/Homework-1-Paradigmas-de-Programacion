#include <iostream>
#include <memory>
using namespace std;

struct node{
    int value;
    unique_ptr<node> next;
};
struct list{
    unique_ptr<node> head;
    size_t cant;
};

unique_ptr<node> create_node(int value){
    unique_ptr<node> new_node = make_unique<node>();
    new_node ->value = value;
    new_node ->next = nullptr;
    return new_node;
}

unique_ptr<list> create_list(){
    unique_ptr<list> new_list = make_unique<list>();
    new_list ->head = nullptr;
    new_list ->cant = 0;
    return new_list;
}

void push_front(list* list, int value){
    unique_ptr<node> new_node = create_node(value);
    new_node->next = move(list->head);
    list->head = move(new_node);
    list->cant++;
}

void push_back(list*list, int value){
    unique_ptr<node> new_node = create_node(value);
    if(!(list->head)){
        list->head = move(new_node);
        list->cant++;
        return;
    }
    unique_ptr<node>* temp = &(list->head);
    while((*temp)->next){
        temp = &((*temp)->next);
    }
    (*temp)->next = move(new_node);
    list->cant++;
}

void insert(list* list, int value, size_t pos){
    if(pos==0){
        push_front(list, value);
        list->cant++;
        return;
    }
    if(pos>=(list->cant)){
        if(pos>(list->cant)){
            cout<<"Posición mayor al largo de la lista, se insertará en el útlimo lugar"<<endl;
        }
        push_back(list, value);
        list->cant++;
        return;
    }
    size_t count = 0;
    unique_ptr<node>* temp = &(list->head);
    while(count < pos -1){
        temp = &((*temp)->next);
        count++;
    }
    unique_ptr<node> new_node = create_node(value);
    new_node->next = move((*temp)->next);
    (*temp)->next = move(new_node);
    list->cant++;
}

void erase(list* list, size_t pos){
    if(!(list->cant)) return;
    if(pos==0){
        list->head = move(list->head->next);
        list->cant--;
        return;
    }
    size_t count = 0;
    unique_ptr<node>* temp = &(list->head);
    while((*temp)->next && count < pos - 1){
        temp = &((*temp)->next);
        count++;
    }

    if ((*temp)->next) {
        cout << "Posición mayor al largo de la lista, se eliminará el último elemento" << endl;
        (*temp)->next = nullptr;  // Eliminamos el último nodo
    } else {
        (*temp)->next = move((*temp)->next->next);  // Eliminamos el nodo en `pos`
    }
    
    list->cant--;  // Decrementamos el tamaño una sola vez
}

void print_list(list* list){
    unique_ptr<node>* temp = &(list->head);
    for (size_t i = 0; i < list->cant; i++){
        cout<<(*temp)->value<<"->";
        temp = &((*temp)->next);
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