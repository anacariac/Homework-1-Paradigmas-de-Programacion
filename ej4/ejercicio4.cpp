#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool compare(string s1, string s2){
    if(s1.empty() && s2.empty()){
        return true; 
    }
    else if(s1[0] != s2[0]){
        return false;
    }
    return compare(s1.substr(1), s2.substr(1));
}

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
    string s1,s2; //CAMBIAR
    cout << "Ingrese la primer palabra a comparar: "<< endl;
    cin >> s1;
    cout << "Ingrese la segunda palabra a comparar: "<<endl;
    cin >> s2;

    auto startTime1 = high_resolution_clock::now();

    cout<< compare(s1, s2)<<endl;

    auto endTime1 = high_resolution_clock::now();
    auto elapsedTime1 = duration_cast<nanoseconds>(endTime1 - startTime1);

    cout<<"A compare() utilizando <string> tardó: "<< elapsedTime1.count() << " nanosegundos"<< endl;

    auto startTime = high_resolution_clock::now();

    cout<< compare(s1.c_str(), s2.c_str())<<endl;

    auto endTime = high_resolution_clock::now();
    auto elapsedTime = duration_cast<nanoseconds>(endTime - startTime);
    cout<<"A compare() utilizando *char tardó: "<< elapsedTime.count() << " nanosegundos"<< endl;

    return 0;
}
