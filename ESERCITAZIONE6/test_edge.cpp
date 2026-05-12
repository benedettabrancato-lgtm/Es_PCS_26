#include "unidirected_edge.hpp"
#include <iostream> 
using namespace std;

int main(){
    //Creo gli archi
    unidirected_edge<int>arco1(3,5);
    unidirected_edge<int>arco2(5,3);
    unidirected_edge<int>arco3(1,7);
    unidirected_edge<int>arco4(6,8);

    //Verifico se l'arco viene stampato come: numero minore, maggiore
    cout<<"Arco 1 (3,5): " <<arco1 << endl; //Stampare(3,5)
    cout<<"Arco 2 (5,3):" <<arco2 << endl; //Deve essere ruotato: mi deve stampare (3,5)

    //Testo l'operatore di uguaglianza 
    if (arco1 == arco2) {
        cout << "L'operatore di uguaglianza funziona correttamente: arco1 e arco2 sono uguali."<<endl;
    }
    else {
        cout<<"ERRORE, dovrebbero essere uguali"<<endl;
    }

    //Testo l'operatore <
    cout << "Verifico ordinamento tra archi diversi: " << endl;
    cout<< "Arco 3: "<<arco1<< endl; //Deve stampare (3,5)
    cout <<"Arco 4: " <<arco4<< endl;

    //Confronto arco3 e arco1
    if (arco3<arco1) {
        cout <<arco3<<"precede" << arco1<< "perchè (1<3)"<< endl;
    }
    else {
        cout <<"L'arco 3" << arco3<< "precede" << arco1<<endl;
    }

    //Confronto tra arco2 e arco4
    if (arco2<arco4) {
        cout << "L'arco" << arco2 << "è minore di " << arco4 << "perchè (3 < 6)" << endl;
    }
    else {
        cout <<"L'arco" << arco4 << "è minore di " << arco2 << endl;
    }

    return 0;

}