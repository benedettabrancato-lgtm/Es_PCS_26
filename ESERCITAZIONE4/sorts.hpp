#include <iostream>
#include <vector>
#include <algorithm>

//insertion_sort
template <typename T>
void insertion_sort(std::vector <T> & vec)
{
    int n = vec.size();
    for(int j = 1; j < n; j++){
        T key = vec[j] ;
        int i = j - 1;
        while (i >= 0 && vec[i] > key){
            vec[i+1] = vec[i];
            i = i-1;
        }
        vec[i+1] = key;
    }
}

//selection_sort
template <typename T>
void selection_sort(std::vector <T>& vec)
{
    int n = vec.size();
    for(int i = 0; i <= n-1 ; i++){
        int minimo = i;
        for ( int j = i + 1; j <n; j++){
            if (vec[j]<vec[minimo]) {
                minimo = j;
            }
        }
        std::swap(vec[i], vec[minimo]);
    }
}

//bubble sort
template <typename T>
void bubble_sort(std::vector <T>& vec)
{
    int n = vec.size();

    for (int i = 0; i <= n-1; i++){
        for (int j = n-1; j > i ; j--) {
            if (vec[j] < vec[j-1])  {
                (std::swap(vec[j],vec[j-1]));
            }
        }
    }
}

//is_sorted()
template <typename T>
bool is_sorted(std::vector<T> & vec)
{
    if(vec.size()<2){
        return true; //In caso di vettore vuoto, questo è già ordinato per def.
    }
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        if(vec[i] > vec[i +1]) {
            return false; 
        }
    }
    return true;
}

