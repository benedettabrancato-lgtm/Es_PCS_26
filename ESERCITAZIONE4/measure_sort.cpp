#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "sorts.hpp"  //Contiene template bubble_sort ...
#include "timecounter.h" //Misura tempi
#include "randfiller.h" //Riempimento casuale vettori

using namespace std;

int main(){
    vector<int> sizes = {4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};

    randfiller rf;
    timecounter tc; 

    cout << left << setw(10)<< "N" //Formattazione: Parto da sinistra e conto gli spazi per ordinare 
         << setw(15) << "Bubble"
         << setw(15) << "selection"
         << setw(15) << "Insertion"
         << setw(15) << "std::sort" << endl;
    cout <<string(70, '-') << endl; 


    for (int n : sizes) {
        vector<int> base_vec(n); //ciclo sul vettore e genero un altro vettore della dimensione n che, ogni volta viene iterata 
        rf.fill(base_vec, -1000, 1000);

        cout << left << setw(10) <<n; 

    
    //Faccio una copia del vettore per ogni test che devo fare
        auto v1 = base_vec;
        auto v2 = base_vec;
        auto v3 = base_vec;
        auto v4 = base_vec;

    // BUBBLE SORT
        tc.tic();
        bubble_sort(v1);
        double time_bubble = tc.toc();

    // INSERTION SORT
        tc.tic();
        insertion_sort(v2);
        double time_insertion = tc.toc();

    //SELECTION SORT
        tc.tic();
        selection_sort(v3);
        double time_selection = tc.toc();

    //SORT
        tc.tic();
        sort(v4.begin(), v4.end());
        double time = tc.toc();

    //STAMPO I RISULTATI 

        cout <<left<<setw(10)
        <<setw(15)<< time_bubble
        <<setw(15)<< time_insertion
        <<setw(15)<< time_selection
        <<setw(15)<< time << endl;
        }
        return 0;

    }