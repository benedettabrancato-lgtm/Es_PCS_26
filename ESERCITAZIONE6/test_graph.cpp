#include <iostream>
#include <vector>
#include <optional>
#include <set>
#include "unidirected_graph.hpp"
using namespace std;

int main(){
    unidirected_graph<int> grafo;
    unidirected_edge<int> e1(1,2);
    unidirected_edge<int> e2(3,4);
    unidirected_edge<int> e3(1,5);

    grafo.add_edge(e1);
    grafo.add_edge(e2);

    //Testo l'esistenza di un arco (edge_number)
    optional<int> risultato = grafo.edge_number(e1); //Optional restituisce un contenitore 
    if (risultato.has_value()){ //has_value() resistuisce true se contenitore pieno, false altrimenti 
        cout<<"Arco trovato nella posizione: "<< risultato.value()<<endl; 
    }
    else{
        cout<<"ERRORE: arco non trovato"<<endl;
    }

    //Testo il metodo edge_at
    int indice_da_testare = 0;
    unidirected_edge<int> arco_recuperato = grafo.edge_at(indice_da_testare);
    if(arco_recuperato == e1){ //e1 è stato il primo arco aggiunto, quindi dovrebbe essere all'indice 0 
        cout <<"Test edge_at: Recuperato correttamente l'arco e1  alla posizone: " << indice_da_testare << endl;
    }
    else {
        cout << "ERRORE: edge_at alla posizione  " << indice_da_testare << " non ha restituisto e1! "<< endl; 
        }

    //testo la non esistenza di un arco nel grafo
    optional<int> risultato2= grafo.edge_number(e3);
    if(!risultato2.has_value()){
        cout<<"Arco non trovato nella posizione, non esiste nel grafo"<<endl;
    }
    else{
        cout<<"ERRORE: arco trovato (non è stato aggiunto al grafo,q uindi non dovrebbe esserci)"<< endl;
    }

    //Testo operator-
    unidirected_graph<int>grafo2;
    grafo2.add_edge(e1);
    unidirected_graph<int>differenza = grafo - grafo2;
    optional<int> controllo = differenza.edge_number(e1);
    if(!controllo.has_value()){
        cout<<"e1 non c'è più nel grafo differenza"<<endl;
    }
    else{
        cout<<"ERRORE: e1 ancora presente nel grafo differenza!";
    }
    optional<int>controllo2 = differenza.edge_number(e2);
    if(controllo2.has_value()){
        cout<<"e2 è rimasto correttamente nel grafo differenza"<<endl;
    }
    else{
        cout<<"ERRORE: e2 non è presente nel grafo differenza"<<endl;
    }

    //testo all_nodes
    grafo.add_edge(e3);
    set<int>nodi = grafo.all_nodes(); //Set di tutti i nodi
    //Verifico il numero di nodi (1,2,3,4,5)
    if (nodi.size()==5){
        cout<<"Il numero di nodi totali presenti nel grafo1 è corretto!"<<endl;
    }
    else{
        cout<<"ERRORE: Il numero di nodi totali non è corretto: attesi 5 nodi, trovati "<<nodi.size()<<endl;
    }
    cout<< "Archi totali presenti nel grafo: " << grafo.all_edges().size() << endl;

    //Testo neighbours
    set<int> vicini = grafo.neighbours(1);

    //Verifico se il numero di vicini del nodo 1 corrisponde a 2: (2 e 5)
    if (vicini.size() == 2) {
        cout<<"Il numero di vicini per il nodo 1 è corretto!" <<endl;
    }
    else {
        cout<<"ERRORE: il nodo 1 dovrebbe avere 2 vicini, ma ne risultano "<< vicini.size() << endl;
    }

    //Itero un ciclo per stampare i vicini
    cout<<"I vicini del nodo 1 sono: ";
    for (int n: vicini) {
        cout<< n <<" ";
    }
    cout << endl;

    return 0; 
}