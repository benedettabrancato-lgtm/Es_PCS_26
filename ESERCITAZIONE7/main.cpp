#include <iostream> 
#include "unidirected_graph.hpp"
#include "graph_visit.hpp"
using namespace std;

int main(){
    unidirected_graph<int> grafo;

    //Nodo 1
    grafo.add_edge(unidirected_edge<int>(1,2));
    grafo.add_edge(unidirected_edge<int>(1,3));
    grafo.add_edge(unidirected_edge<int>(1,4));
    grafo.add_edge(unidirected_edge<int>(1,6));
    
    //Nodo 2
    grafo.add_edge(unidirected_edge<int>(2,7));
    grafo.add_edge(unidirected_edge<int>(2,5));
    grafo.add_edge(unidirected_edge<int>(2,4));

    //Nodo 3
    grafo.add_edge(unidirected_edge<int>(3,6));
    
    //Nodo 4
    grafo.add_edge(unidirected_edge<int>(4,6));
    grafo.add_edge(unidirected_edge<int>(4,7));
    
    //Nodo 5
    grafo.add_edge(unidirected_edge<int>(5,7));
    
    //Nodo 6
    grafo.add_edge(unidirected_edge<int>(6,7));
    grafo.add_edge(unidirected_edge<int>(6,8));
    
    //Nodo 7
    grafo.add_edge(unidirected_edge<int>(7,9));
    
    //Nodo 8
    grafo.add_edge(unidirected_edge<int>(8,9));


    fifo<int> coda;
    unidirected_graph<int>grafo_finale1 = graph_visit(grafo,1,coda);
    salva_dot(grafo_finale1, "test_grafo_bfs.dot");

    lifo<int> pila;
    unidirected_graph<int>grafo_finale2 = graph_visit(grafo,1,pila);
    salva_dot(grafo_finale2, "test_grafo_dfs.dot");

    unidirected_graph<int>grafo_finale3 = recursive_dfs(grafo,1);
    salva_dot(grafo_finale3, "test_grafo_recursive_dfs.dot");

    unidirected_graph<int>grafo_finale4 = dijkstra(grafo,1,coda);
    salva_dot(grafo_finale4, "test_grafo_dijkstra.dot");

    return 0; 
}