#include <iostream>
#include <string>
#include <fstream>
using namespace std;
enum class Level { DEBUG, INFO, WARNING, ERROR, CRITICAL};

string convertLevel(Level severity){
    switch(severity){
        case Level :: DEBUG: return "[DEBUG]";
        case Level :: INFO: return "[INFO]";
        case Level :: WARNING: return "[WARNING]";
        case Level :: ERROR: return "[ERROR]";
        case Level :: CRITICAL: return "[CRITICAL]";
    }
    return "[UNKNOWN]";
}

void logMessage(const string message, Level severity){
    ofstream File("logfile.txt", ios::app);
    if(!File){
        cerr <<"Error no se pudo abrir el archivo"<<endl;
    } 
    File << convertLevel(severity) << " <" <<message<< ">"<<endl;
    File.close();
    return;
}

void logMessage(const string message, const string file, int line){
    ofstream File("logfile.txt", ios::app);
    if(!File){
        cerr <<"Error no se pudo abrir el archivo"<<endl;
    } 
    File << "<" <<message<< ">"<<" FILE: "<<file<<" LINE:"<<line<<endl;
    File.close();
    return;
}

void logMessage(const string message, const string user){
    ofstream File("logfile.txt", ios::app);
    if(!File){
        cerr <<"Error no se pudo abrir el archivo"<<endl;
    } 
    File << "[SECURITY]"<< " <" <<message<< ">"<<" -> Usuario: "<<user<<endl;
    File.close();
    return;
}


int main(int argc, char* argv[]){
    logMessage("error",Level::DEBUG);
    logMessage("error",Level::INFO);
    logMessage("error",Level::WARNING);
    logMessage("No such directory compilation terminated.",Level::ERROR);
    logMessage("error",Level::CRITICAL);
    logMessage("No such directory compilation terminated.", "main.cpp", 12);
    logMessage("Access Granted","myusername");
    logMessage("Access Denied","myusername");

    try{
        if(argc == 2){
            throw runtime_error("Runtime Error");
        }
    }catch(const runtime_error& e){
        logMessage(string("Error en ejecución: ") + e.what(), Level::ERROR);
        cout<<"Runtime Error"<<endl;
        return 1;
    }

    cout<<"Fin del programa!"<<endl;
    
    return 0;
}
