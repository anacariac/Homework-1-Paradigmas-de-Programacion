#include <iostream>
#include <fstream>
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

void finalTime(string s1, string s2){
    auto startTime = high_resolution_clock::now();
    bool result = compare(s1, s2);
    cout<< "\nResultado de comparación: "<< boolalpha<< result <<endl;
    auto endTime = high_resolution_clock::now();
    auto elapsedTime = duration_cast<nanoseconds>(endTime - startTime);
    cout<<"Duracion: "<<elapsedTime.count() <<" ns\n"<< endl;
}

void finalTime(char* s1, char* s2){
    auto startTime = high_resolution_clock::now();
    bool result = compare(s1, s2);
    cout<< "\nResultado de comparación: "<< boolalpha<< result <<endl;
    auto endTime = high_resolution_clock::now();
    auto elapsedTime = duration_cast<nanoseconds>(endTime - startTime);
    cout<<"Duracion: "<<elapsedTime.count()<<" ns\n"<< endl;
}


int main(){
    ifstream File("archivoprueba.txt");
    if(!File){
        cerr<<"Error al abrir el archivo"<<endl;
        return 1;
    }
    string s1,s2;

    while(getline(File,s1) && getline(File,s2)){
        cout<<"====================================="<<endl;
        cout<<s1<<" vs " <<s2<<endl;
        cout << "\n--- Comparación con std::string ---";
        finalTime(s1, s2);

        cout << "--- Comparación con char* ---";
        finalTime(s1.c_str(), s2.c_str());   
    } 
    cout<<"\nFin de los test!"<<endl;
    File.close();
    return 0;
}
