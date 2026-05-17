#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class unidirected_edge {
    T nodo_from; 
    T nodo_to;
public:
    unidirected_edge(const T& n1, const T& n2)
    {
        nodo_from = min(n1,n2);
        nodo_to = max(n1,n2);
    }
//Implemento from e to 
    const T& from() const {return nodo_from; } //resitutisce nodo minore
    const T& to() const {return nodo_to; } //restituisce nodo maggiore

    bool operator==(const unidirected_edge& other) const{
    if(nodo_from == other.nodo_from && nodo_to == other.nodo_to){
        return true;
    }
    else{
        return false;
    }
    }

    bool operator<(const unidirected_edge& other) const{
    if(nodo_from < other.nodo_from){
        return true;
    }
    else if (nodo_from > other.nodo_from){
        return false;
    }
    else{
        if(nodo_to < other.nodo_to){
            return true;
        }
        else{
            return false;}
        }
        }
    };


template <typename T>
std::ostream& operator<<(std::ostream & output, const unidirected_edge<T>& e){
    output <<"(";
    output <<e.from();
    output <<"--";
    output <<e.to();
    output <<")";
    return output;
}



