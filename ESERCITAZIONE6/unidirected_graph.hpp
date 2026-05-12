#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <optional>
#include "unidirected_edge.hpp"

template <typename T>
class unidirected_graph {
    std::set<T> nodi;
    std::vector<unidirected_edge<T>> archi; //archi è il nome del vettore che contiene tutti gli oggetto di tipo unidirected_edge
    std::map<T, std::set<T>> lista_adiacenza;
       
public:
    unidirected_graph() = default; //Creo il grafo partendo da zero, inizializzando i contenitori come vuoti
    unidirected_graph(const unidirected_graph& other) = default; //costruttore di copia: copia il contenuto del vettore archi e della mappa lista_adiacenza

    //Implemento il metodo neighbours
    //Cerco i vicini tramite i nodi
    std::set<T> neighbours(const T& nodo) const{
        auto indice_nodo = lista_adiacenza.find(nodo); //cerco il nodo nella mappa
        if(indice_nodo==lista_adiacenza.end()){
            return std::set<T>();
        }
        return lista_adiacenza.at(nodo);
    }


    //metodo add edge() che permetta di aggiungere un arco al grafo:
    //Ricevo un arco, se l'arco già esiste non faccio nulla; altrimenti lo aggiugno 
    void add_edge(const unidirected_edge<T> & arco) {
        //se arco esiste, non fare nulla
        for(size_t i = 0; i<archi.size();i++){
            if(archi[i] == arco){
                return;
            }
        }
        //aggiugno arco al vettore
        archi.push_back(arco);

        //Aggiorno il set di nodi
        nodi.insert(arco.from());
        nodi.insert(arco.to());

        //Modifico lista adiacenza quando aggiungo un arco
        lista_adiacenza[arco.from()].insert(arco.to());
        lista_adiacenza[arco.to()].insert(arco.from());
    }

    //Un metodo all edges() che restituisce tutti gli archi
    std::vector<unidirected_edge<T>> all_edges() const{
            return archi;
    }

    //Un metodo all nodes() che restituisce tutti gli nodi
    std::set<T> all_nodes() const{
            return nodi;
    }

    // Un metodo edge_number() che, dato un arco, ne restituisce la sua numerazione all’interno del grafo
    std::optional<int> edge_number(const unidirected_edge<T>& arco) const{
        //Itero su tutti gli archi presenti nel vettore 
        for(size_t i = 0; i< archi.size(); i ++){
            if (archi[i]==arco) {
                return int(i);
            }
        }
    //Se il ciclo finisce senza trovare nulla, l'arco non è nel grafo: restituisco il "vuoto" 
        return std::nullopt;
    }

    //Un metodo edge_at() che, dato un numero d’arco, restituisce il corrispondente oggetto arco all’interno del grafo
    unidirected_edge<T> edge_at(int numero) const{
        //Restituisce direttamente l'arco alla posizone 'numero'
            return archi.at(numero);
            }

    // L’operatore operator-(), che permette di calcolare la differenza tra due grafi: dati G e G′, 
    //la differenza G −G′ è data dagli archi presenti in G e non presenti in G′.
    unidirected_graph<T> operator-(const unidirected_graph<T>& other) const{
        unidirected_graph<T> grafo_finale;

        //Recupero archi di G 
        auto archi_G = all_edges();

        //Recupero archi di G' 
        auto archi_G_barrato = other.all_edges();

        //Scorro archi di G
        for(const auto& arco_G: archi_G){
            bool trovato = false;

            //Controllo se arco_mio è in archi_G_barrato, se è in archi_G_barrato, non fare niente
            for(const auto& arco_altro: archi_G_barrato){
                if (arco_G == arco_altro) {
                    trovato = true;
                    break;
                }
            }
            if(!trovato){
                grafo_finale.add_edge(arco_G);
            }
        }
        return grafo_finale;
    }
};