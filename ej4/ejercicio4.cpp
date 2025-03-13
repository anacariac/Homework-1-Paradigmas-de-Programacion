#include <iostream>
using namespace std;

bool compare(const char* s1, const char* s2){
    if(*s1 == '\0' && *s2 == '\0'){
        return true; 
    }
    else if(*s1 != *s2){
        return false;
    }
    return compare(s1 + 1, s2 + 1);
}

int main(){
    cout<< compare("hola", "hoLa")<<endl;
    return 0;
}
