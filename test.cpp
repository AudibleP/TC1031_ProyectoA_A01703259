/*
Este proyecto en un futuro jalara la biblioteca de steam
del usuario y ordenara dependiendo de lo que le pides.
Para esta entrega se ordena atraves de un merge sort los
nombres de los juegos en orden alfabetico.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

#include "sorts.h"

using namespace std;


void menu(){
    cout<<"Elige una opcion: "<<"\n";

    cout<<"1. Mostrar el archivo sin ordenar."<<"\n";
    cout<<"2. Mostrar el archivo ordenado."<<"\n";
    cout<<"3. Salir."<<"\n";
}

int main(){
    int opcion = 0;
    while(opcion>-1 && opcion<6){
        menu();

        ifstream file ("Steam.csv");
        cin>>opcion;
        if(opcion ==1){
            string name, hour;
            while(file.good()){
                getline(file, name, ',');
                getline(file, hour, '\n');
                cout << "Name: "<<name<<'\n';
                cout << "Time Played: "<<hour<<" Hours"<<'\n'<<"\n";
            }
        file.close();
        }

        else if(opcion == 2){
            Sorts <string> sorts;

            vector<string>v;
            string str;
            while(file >> str){
                v.push_back(str);
            }
            sorts.ordenaMerge(v);
            copy (v.begin(),v.end(),ostream_iterator<string>(cout,"\n\n"));
            cout << v.size();
        }

        else if(opcion == 3){
            cout<<"bye \n\n";
            return 0;
        }

        else{
            cout<<"Opcion Invalida \n\n";
        }
        }

}
