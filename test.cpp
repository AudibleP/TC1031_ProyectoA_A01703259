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

using namespace std;


void menu(){
    cout<<"Elige una opcion: "<<"\n";

    cout<<"1. Mostrar el archivo sin ordenar."<<"\n";
    cout<<"2. Mostrar el archivo ordenado."<<"\n";
    cout<<"3. Arboles."<<"\n";
    cout<<"4. Salir."<<"\n";
}

int main(){
    int opcion = 0;
    while(opcion>-1 && opcion<6){
        menu();
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
            }
            else{
                cout<<"Opcion Invalida \n\n";
            }

        }

        else if(opcion == 3){

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

        else if(opcion == 4){
            cout<<"bye \n\n";
            return 0;
        }

        else{
            cout<<"Opcion Invalida \n\n";
        }
        }

}
