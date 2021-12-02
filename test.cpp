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
#include <sstream>
#include "sorts.h"
#include "bst.h"
#include "lists.h"

using namespace std;


void menuSA(){
    cout<<"Elige una opcion: "<<"\n";

    cout<<"1. Mostrar el archivo sin ordenar."<<"\n";
    cout<<"2. Mostrar el archivo ordenado."<<"\n";
    cout<<"3. Consulta informacion de un juego."<<"\n";
    cout<<"4. Arboles."<<"\n";
    cout<<"5. Salir."<<"\n";
}
void menuLI(){
    cout<<"Elige una opcion: "<<"\n";

    cout<<"1. Carga el archivo."<<"\n";
    cout<<"2. Agregar nombre a la lista."<<"\n";
    cout<<"3. Borrar nombre de la lista."<<"\n";
    cout<<"4. Ve la lista."<<"\n";
    cout<<"5. Salir."<<"\n";
}

void SA(){
    int opcion = 0;
    while(opcion>-1 && opcion<6){
        menuSA();
        string buffer;
        string temporary;
        vector <pair <string, int> >  patVecName;
        vector <pair <int, string> >  patVecHour;
        pair <string, int> patPairName;
        pair <int, string> patPairHour;
        int plength;
        string pCharacters;

        ifstream file ("steam.csv");
        cin>>opcion;
        if(opcion ==1){

            while(file.good()){

                getline(file, buffer,',');
                stringstream str_reader(buffer);
                str_reader >> pCharacters;


                getline(file, buffer);
                stringstream int_reader(buffer);
                int_reader >> plength;


                patPairName = make_pair (pCharacters,plength);
                cout << "Game name: " << pCharacters <<"---> Play time: "<< plength << " hours."<<endl <<endl;

            }
            file.close();
        }

        else if(opcion == 2){
            int tarde;
            cout<<"1-Ordena por nombre ///// 2-Ordena por horas"<<endl;
            cin>>tarde;
            if(tarde ==1){
                Sorts <pair<string,int>> sorts;
                while(file.good()){
                    getline(file, buffer,',');
                    stringstream str_reader(buffer);
                    str_reader >> pCharacters;


                    getline(file, buffer);
                    stringstream int_reader(buffer);
                    int_reader >> plength;


                    patPairName = make_pair (pCharacters,plength);
                    patVecName.push_back(patPairName);
                }
                sorts.ordenaMerge(patVecName);
                for(int i=0; i<patVecName.size(); i++){
                    cout << "Game name: " << patVecName[i].first <<"---> Play time: "<< patVecName[i].second << " hours."<<endl <<endl;
                }
                ofstream file;
                file.open("NameThenHour.txt");
                for (int i=0; i<patVecName.size(); i++){
                    file<<"Game name: " << patVecName[i].first <<"---> Play time: "<< patVecName[i].second << " hours."<<endl<<endl;
                }
                file.close();
            }
            else if(tarde == 2){
                Sorts <pair<int,string>> sorts;
                while(file.good()){
                    getline(file, buffer,',');
                    stringstream str_reader(buffer);
                    str_reader >> pCharacters;


                    getline(file, buffer);
                    stringstream int_reader(buffer);
                    int_reader >> plength;


                    patPairHour = make_pair (plength,pCharacters);
                    patVecHour.push_back(patPairHour);
                }
                sorts.ordenaMerge(patVecHour);
                for(int i=0; i<patVecHour.size(); i++){
                    cout << "Play time: " << patVecHour[i].first <<" hours. ---> Game name: "<< patVecHour[i].second <<endl <<endl;
                }
                ofstream file;
                file.open("HourThenName.txt");
                for (int i=0; i<patVecHour.size(); i++){
                    file<<"Play time: " << patVecHour[i].first <<" hours. ---> Game name: "<< patVecHour[i].second <<endl <<endl;
                }
                file.close();
            }
            else{
                cout<<"Opcion Invalida \n\n";
            }
        }

        else if(opcion == 3){
            string fusca;
            cout<<"Escribe nombre de juego que desees buscar informacion"<<endl;
            cin>>fusca;
            Sorts <pair<string,int>> sorts;
            while(file.good()){
                getline(file, buffer,',');
                stringstream str_reader(buffer);
                str_reader >> pCharacters;


                getline(file, buffer);
                stringstream int_reader(buffer);
                int_reader >> plength;


                patPairName = make_pair (pCharacters,plength);
                patVecName.push_back(patPairName);
                for(int i=0; i<patVecName.size(); i++){
                    if(fusca == patVecName[i].first){
                        cout << "Game name: " << patVecName[i].first <<"---> Play time: "<< patVecName[i].second << " hours."<<endl;
                        return;
                    }
                }
            }
        }

        else if(opcion == 4){

            BST<int>bst;
            while(file.good()){
                    getline(file, buffer,',');
                    stringstream str_reader(buffer);
                    str_reader >> pCharacters;


                    getline(file, buffer);
                    stringstream int_reader(buffer);
                    int_reader >> plength;


                    patPairHour = make_pair (plength,pCharacters);
                    bst.add(patPairHour.first);
                }
            cout<<"PreOrder"<<endl;cout<<"InOrder"<<endl;cout<<"PostOrder"<<endl;cout<<"LevelByLevel"<<endl;
            cout<<bst.visit();
        }

        else if(opcion == 5){
            cout<<"bye \n\n";
            return;
        }

        else{
            cout<<"Opcion Invalida \n\n";
        }
        }

}

void LI(){
    int opcion = 0;
    List<string>v;
    string str, ListData;
    ifstream file ("Steam.csv");
    while(opcion>-1 && opcion<9){
        menuLI();
        cin>>opcion;
        if(opcion ==1){
            while(getline(file,ListData)){
                if(ListData.size() > 0){
                    v.insertion(ListData);
                }
            }
        file.close();
        }
        else if(opcion == 2){
            cout<<"Agrega nombre \n\n";
            cin.ignore();
            getline(cin,ListData);
            v.insertion(ListData);
        }
        else if(opcion == 3){
            cout<<"Agrega nombre para eliminar \n\n";
            cin.ignore();
            getline(cin,ListData);
            v.deleteAt(ListData);
        }
        else if(opcion == 4){
            v.show();
            cout<<"\n";
        }
        else if(opcion == 5){
            cout<<"bye \n\n";
            return;
        }
        else{
            cout<<"Opcion Invalida \n\n";
        }
        }
}

int main(){
    int opcion = 0;
    while(opcion>-1 && opcion<6){
        cout << "Elija lo que desee revisar" <<endl;
        cout << "1. Sorts y Arboles" <<endl;
        cout << "2. Linked Lists" << endl;
        cout << "3. Salir" << endl;
        cin >> opcion;
        if(opcion == 1){
            SA();
        }
        else if(opcion == 2){
            LI();
        }
        else if(opcion == 3){
            cout << "Bye" <<endl;
            return 0;
        }
        else{
            return 0;
        }
    }
}
