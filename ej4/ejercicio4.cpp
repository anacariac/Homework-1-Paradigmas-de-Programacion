#include <iostream>
#include <fstream>
#include <chrono>
#include "ejercicio4.hpp"
using namespace std::chrono;

bool compare(string s1, string s2){
    if(s1.size() == 0 && s2.size() == 0){ //si estan vacios los dos es verdadero
        return true; 
    }
    else if(s1[0] != s2[0]){
        return false;
    }
    return compare(s1.substr(1), s2.substr(1)); //llama a la funcion con un substring eliminando el primer elemento
}

bool compare(const char* s1, const char* s2){
    if(*s1 == '\0' && *s2 == '\0'){ //si estan vacios los dos es verdadero
        return true; 
    }
    else if(*s1 != *s2){
        return false;
    }
    return compare(s1 + 1, s2 + 1);//llama a la funcion moviendo el puntero al siguiente caracter
}

constexpr bool compare_constexpr(const char* s1, const char* s2){
    if(*s1 == '\0' && *s2 == '\0'){
        return true; 
    }
    else if(*s1 != *s2){
        return false;
    }
    return compare(s1 + 1, s2 + 1);// devuelve un constexpr
}

void finalTime(string s1, string s2){
    auto startTime = high_resolution_clock::now(); 
    bool result = compare(s1, s2);
    cout<< "\nResultado de comparación: "<< boolalpha<< result <<endl; 
    auto endTime = high_resolution_clock::now();
    auto elapsedTime = duration_cast<nanoseconds>(endTime - startTime);
    cout<<"Duracion: "<<elapsedTime.count() <<" ns\n"<< endl; // diferencia de tiempo inicial menos tiempo final expresado en nanosegundos
}

void finalTime(const char* s1,const char* s2,bool expr){
    auto startTime = high_resolution_clock::now();
    bool result;
    if(expr){ //si se quiere utilizar la funcion que ejecuta en tiempo de compilación
       result = compare_constexpr(s1, s2); 
    }else result = compare(s1, s2);
    cout<< "\nResultado de comparación: "<< boolalpha<< result <<endl;
    auto endTime = high_resolution_clock::now();
    auto elapsedTime = duration_cast<nanoseconds>(endTime - startTime);
    cout<<"Duracion: "<<elapsedTime.count()<<" ns\n"<< endl;
}


int main(){
    ifstream File("archivoprueba.txt");  //archivo con oraciones de prueba
    if(!File){
        cerr<<"Error al abrir el archivo"<<endl;
        return 1;
    }
    string s1,s2;

    while(getline(File,s1) && getline(File,s2)){
        cout<<"\n====================================="<<endl;
        cout<<s1<<" vs. \n"<<s2<<endl;
        cout << "\n--- Comparación con std::string ---"<<endl;
        finalTime(s1, s2);

        cout << "\n--- Comparación con char* ---"<<endl;
        finalTime(s1.c_str(), s2.c_str());   
        cout<<"====================================="<<endl;
    } 
    File.close();
    constexpr const char* sc1 = "Hola!";
    constexpr const char* sc2 = "Hola!";

    cout<<"\n---Comparación Tiempo de Ejecución y Tiempo de Compilación---"<<endl;
    cout << "\n--- Comparación Tiempo de Compilación ---"<<endl;
    finalTime(sc2, sc2, true); 
    cout << "\n--- Comparación Tiempo de Ejecución ---"<<endl;
    finalTime(sc1, sc2);

    cout<<"\nFin de los test!"<<endl;
    
    return 0;
}
