#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include "unidirected_graph.hpp"
#include <set>
#include <limits>
#include <fstream>
#include <string>
#pragma once

using namespace std;

template <typename T>
class fifo{
private:
    queue<T> coda;
public:
    void put(const T& value){ //Inserisce un elemento in fondo alla coda
        coda.push(value);
    }

    T get() {
        T testa = coda.front(); //Recupero il primo elemento 
        coda.pop(); //rimuovo per estrarlo elemento in testa alla coda
        return testa;
    }

    bool empty() const{
        return coda.empty() ;
    }
};

template<typename T>
class lifo {
private:
    stack<T> pila;
public:
    void put(const T& value){
        pila.push(value);
    }

    T get() {
        T testa = pila.top();
        pila.pop();
        return testa;
    }

    bool empty() const{
        return pila.empty();
    }
};

template<typename T, typename C>
unidirected_graph<T> graph_visit(const unidirected_graph<T>& grafo, int nodo_sorgente, C& container){
    
    unidirected_graph<T> grafo_finale; 
    map<T, bool> reached; //Registro dei nodi già visitati

    //Inserico la sorgente nel contenitore e nel grafo finale 
    reached[nodo_sorgente] = true;
    container.put(nodo_sorgente);

    while (!container.empty()) {
        T u = container.get(); //Estraggo il prossimo nodo da esplorare
        
        //Guardo i vicini di u nel grafo originale 
        for (T v: grafo.neighbours(u)){
            if (!reached[v]) {
                    reached[v] = true;
                    container.put(v); //Metto il vicino di u nel container Cgrafo.add_node(v); //Aggiungo nodo v all'albero 
                    grafo_finale.add_edge(unidirected_edge<T>(u,v)); //aggiungo arco che va da u a v                    }
            }
        }
    }   
return grafo_finale; 
}


//recursive_dfs
template<typename T>
void dfs_helper(const unidirected_graph<T>& grafo, T u, map<T, bool>& reached, unidirected_graph<T>& grafo_finale){
    reached[u] = true; 
    for(T v: grafo.neighbours(u)){
        if (!reached[v]) {
            grafo_finale.add_edge(unidirected_edge<T>(u, v));
            dfs_helper(grafo, v, reached, grafo_finale);
        }
    }
}

template<typename T>
unidirected_graph<T> recursive_dfs(const unidirected_graph<T>& grafo, int nodo_sorgente){
    unidirected_graph<T> grafo_finale;
    map<T,bool > reached;

    dfs_helper(grafo, nodo_sorgente, reached, grafo_finale);
    
    return grafo_finale;
}

//Algoritmo di Dijkstra senza pesi
template<typename T, typename C>
unidirected_graph<T> dijkstra(const unidirected_graph<T>& grafo, int nodo_sorgente, C& container){
    unidirected_graph<T> grafo_finale;
    //Recupero tutti i nodi
    auto nodi = grafo.all_nodes();
    const int INF = numeric_limits<int>::max();
    map<T, int> distanza; //Salvo le distanze per capire quanto è lontano ogni nodo 
    map<T,T> predecessore; 

    for(T nodo: nodi){
        distanza[nodo] = INF;
        predecessore[nodo] = -1;
    }

    //Inizializzazione
    predecessore[nodo_sorgente] = nodo_sorgente;
    distanza[nodo_sorgente] = 0; 
    container.put(nodo_sorgente);

    while(!container.empty()){
        T u = container.get(); //Estraggo dal container

        for (T v: grafo.neighbours(u)) {
            if(distanza[v]> distanza[u]+1) {
                distanza[v] = distanza[u] + 1;
                predecessore[v] = u; 
                container.put(v); //Metto il vicino nel contenitore
                } 
            }
        }

    //Costruzione grafo finale dopo aver calcolato tutti i risultati
    for(T nodo: nodi){
        if(distanza[nodo]!= INF && nodo!=nodo_sorgente){
            grafo_finale.add_edge(unidirected_edge<T>(predecessore[nodo],nodo));
        }
    }
    return grafo_finale;
}

template <typename T>
void salva_dot(const unidirected_graph<T>& grafo, const string& nome_file){
    ofstream out(nome_file); //Apro il file in scrittura

    if(!out.is_open()) {
        return; //Controllo se il file è pronto 
    }

    out << "graph G { " <<endl; //Intestazione del file DOT

    //Per ogni nodo u, esploro i vicini v

    for(auto const& e: grafo.all_edges()){
        //Scrivo nel file la riga dell'arco
        //ES: "A" -> "B"
        out << " " << e.from() << " -- " << e.to() << ";" << endl;
        }

    out << "}" << endl; //Chiudo il file
    out.close();
}

