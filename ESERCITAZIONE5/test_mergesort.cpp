#include <iostream>
#include <concepts>
#include <random>
#include <vector>
#include <string>
#include "sorts.hpp"
#include "randfiller.h"

int main() {
    randfiller rf;
    std::vector<int> vec(100); //creo vettore vuoto di interi di dimensione 100 
    rf.fill(vec,100,8000); //riempo il vettore con 100 valori casuali compresi tra 100 e 800

    for (int i = 0; i<100; i++){ //itero sul vettore e ordino
        std::vector<int> casuali(vec[i]); //causali è un nuovo vettorela cui dimensione è vec[i]
        rf.fill(casuali,-500,500); //Riempo il vettore appena creato

        mergesort(casuali,0,casuali.size()-1);
        //verifico corretto funzionamento
        if(!is_sorted(casuali.begin(),casuali.end())){
            std::cerr<<"Il mergesort non ha ordinato correttamente il vettore\n";
            return EXIT_FAILURE;
        }
    }
    std::vector<std::string> stringa = {"Dave","Fill","Angel","Bob","Clark", "Erik","Adam","Robert","Jonathan", "Lis"};
    mergesort(stringa,0,stringa.size()-1);
    if (!is_sorted(stringa.begin(),stringa.end())){
            std::cerr<<"Il mergesort non ha ordinato correttamente il vettore di stringhe \n";
            return EXIT_FAILURE;
            
    }
    return EXIT_SUCCESS;
}