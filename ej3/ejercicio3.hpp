#include <memory>
using namespace std;

shared_ptr<node> create_node(int value);

shared_ptr<list> create_list();

void push_front(list* list, int value);

shared_ptr<node>* find_prev(list* list, size_t pos);

void push_back(list*list, int value);

void insert(list* list, int value, size_t pos);

void erase(list* list, size_t pos);

void print_list(list* list);
