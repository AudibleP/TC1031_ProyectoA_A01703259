/*
Este proyecto en un futuro jalara la biblioteca de steam
del usuario y ordenara dependiendo de lo que le pides.
Para esta entrega se ordena atraves de un merge sort los
nombres de los juegos en orden alfabetico.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>
#include <string>

#include "sorts.h"
#include "lists.h"

using namespace std;


void menu(){
    cout<<"Elige una opcion: "<<"\n";

    cout<<"1. Carga el archivo."<<"\n";
    cout<<"2. Mostrar el archivo ordenado."<<"\n";
    cout<<"3. Agregar nombre a la lista."<<"\n";
    cout<<"4. Borrar nombre de la lista."<<"\n";
    cout<<"5. Ve la lista."<<"\n";
    cout<<"6. Salir."<<"\n";
}

int main(){
    int opcion = 0;
    List<string>v;
    string str, ListData;
    ifstream file ("Steam.csv");
    while(opcion>-1 && opcion<9){
        menu();
        cin>>opcion;
        if(opcion ==1){
            //string name, hour;
            while(getline(file,ListData)){
                if(ListData.size() > 0){
                    v.insertion(ListData);
                }
            }
            //while(file.good()){
                /*getline(file, name, ',');
                getline(file, hour, '\n');
                cout << "Name: "<<name<<'\n';
                cout << "Time Played: "<<hour<<" Hours"<<'\n'<<"\n";
            }*/
        file.close();
        }

        else if(opcion == 2){
            Sorts <string> sorts;
            cout<<"Benji pls fix me\n";

            while(file >> str){
                v.insertion(str);
                v.toString();
            }
            //sorts.ordenaMerge(v);
            //copy (v.begin(),v.end(),ostream_iterator<string>(cout,"\n\n"));
            //cout << v.size();
        }

        else if(opcion == 3){
            cout<<"Agrega nombre \n\n";
            cin.ignore();
            getline(cin,ListData);
            v.insertion(ListData);
        }
        else if(opcion == 4){
            cout<<"Agrega nombre para eliminar \n\n";
            cin.ignore();
            getline(cin,ListData);
            v.deleteAt(ListData);
        }
        else if(opcion == 5){
            v.show();
            cout<<"\n";
        }
        else if(opcion == 6){
            cout<<"bye \n\n";
            return 0;
        }

        else{
            cout<<"Opcion Invalida \n\n";
        }
        }

}
