#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

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
    string s1,s2;
    cout << "Ingrese la primer palabra a comparar: "<< endl;
    cin >> s1;
    cout << "Ingrese la segunda palabra a comparar: "<<endl;
    cin >> s2;

    auto startTime = high_resolution_clock::now();

    cout<< compare(s1.c_str(), s2.c_str())<<endl;

    auto endTime = high_resolution_clock::now();
    auto elapsedTime = duration_cast<nanoseconds>(endTime - startTime);

    cout<<"A compare() le tomo: "<< elapsedTime.count() << " nanosegundos"<< endl;
    return 0;
}
