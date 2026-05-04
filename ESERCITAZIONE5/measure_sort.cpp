#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "sorts.hpp"  //Contiene template bubble_sort ...
#include "timecounter.h" //Misura tempi
#include "randfiller.h" //Riempimento casuale vettori

using namespace std;

int main(){
    randfiller rf;
    timecounter tc; 

    cout << left << setw(10)<< "k" //Formattazione: Parto da sinistra e conto gli spazi per ordinare 
         << setw(15) << "Bubble"
         << setw(15) << "selection"
         << setw(15) << "Insertion"
         << setw(15) << "Quick"
         << setw(15) << "Merge"
         << setw(15) << "Hybrid"
         << setw(15) << "std::sort" << endl;
    cout <<string(70, '-') << endl; 


    //Creo un vettore di vettori per memorizzare 100 campioni di dimensione 'k'
    for (int k = 1; k <= 100; k+=5) {
        vector<vector<int>>base_vec(100,vector<int>(k));
    

    //Riempo i vettori 
        for(int i = 0; i < 100; i ++) {
            rf.fill(base_vec[i],-1000,1000);
        }
        cout << left << setw(10) <<k; 


    //Faccio una copia del vettore per ogni test che devo fare
        auto v1 = base_vec;
        auto v2 = base_vec;
        auto v3 = base_vec;
        auto v4 = base_vec;
        auto v5 = base_vec;
        auto v6 = base_vec;
        auto v7 = base_vec;

    // BUBBLE SORT
        double media_tb = 0; //Inizializzo 
        tc.tic();
        for(int j = 0; j < 100; j ++) {
            bubble_sort(v1[j]); //ordino il j-esimo vettore
        }
        media_tb = tc.toc()/100;

    // INSERTION SORT
        double media_ti = 0; 
        tc.tic();
        for (int j = 0; j < 100; j++) {
            insertion_sort(v2[j]);
        }
        media_ti = tc.toc()/100;

    //SELECTION SORT
        double media_ts = 0; 
        tc.tic();
        for (int j = 0; j < 100; j ++) { 
            selection_sort(v3[j]);
        }
        media_ts = tc.toc()/100;

    //MERGESORT
        double media_tm;
        tc.tic();
        for (int j = 0; j < 100; j ++){
            mergesort(v4[j], 0, k-1);
        }
        media_tm = tc.toc()/100;

    //QUICKSORT
        double media_tq = 0;
        tc.tic();
        for (int j = 0; j < 100; j ++){
            quicksort(v5[j], 0, k-1);
        }
        media_tq = tc.toc()/100;

    //SORT
        double media_tstd = 0; 
        tc.tic();
        for (int j = 0; j < 100; j ++){
            sort(v6[j].begin(), v6[j].end()); //ordin con sort ogni elemento del vettore di vettori 
        }
        media_tstd = tc.toc()/100;

    //HYBRID 
        double media_th = 0;
        tc.tic();
        for (int j = 0; j < 100; j++){
            hybrid_quick_sort(v7[j], 0, k-1);
        }
        media_th = tc.toc()/100;
        
    //STAMPO I RISULTATI 

        cout <<left<<setw(10)
        <<setw(15)<< media_tb
        <<setw(15)<< media_ti
        <<setw(15)<< media_ts
        <<setw(15)<< media_tm
        <<setw(15)<< media_tq
        <<setw(15)<<media_th
        <<setw(15)<< media_tstd << endl;
    }
        return 0;
}