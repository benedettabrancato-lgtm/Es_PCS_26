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

template <typename T>
void merge(std::vector <T> & A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    //creo un vettore temporaneo
    std::vector <T> L(n1+1);
    std::vector <T> R(n2+1);
    for (int i = 0; i< n1; i++) {
        L[i] = A[p + i];
    } 
    for (int j = 0; j< n2; j++) {
        R[j] = A[q + 1 + j];
    }

    //
    int i = 0;
    int j = 0;
    int k =p;

    while (i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j ++;
        }
        k++;
    }

// Copio gli elementi rimanenti di L
while (i < n1) {
    A[k] = L[i];
    i++;
    k++;
}

//Copio elementi rimasti di R
while (j < n2) {
    A[k] = R[j];
    j++;
    k++;
    }
}

template <typename T>
void mergesort(std::vector<T> & A, int p,int r)
{
    if (p<r){

        //Calcolo il punto medio
        int q = ((p+r)/2);
        mergesort (A,p,q);
        mergesort (A,q+1,r);
        merge (A,p,q,r);
    }
}

template <typename T>
int partition(std::vector <T> & A, int p, int r) 
{
    T x = A[r]; //x è un elemento del vettore che ha elementi di tipo T 
    int i = p - 1;
    for (int j = p; j <= r - 1; j ++){
        if (A[j]<= x){
            i = i + 1;
            std::swap (A[i],A[j]);
        }
    }
    std::swap(A[i+1],A[r]);
    return i + 1;
}
template <typename T>
void quicksort(std::vector <T> & A, int p, int r)
{
    if ( p <  r) {
        int q = partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
    return;
}

template <typename T>
void insertion_sort_hybrid(std::vector <T> & A, int p, int n)
{
    for(int i= p + 1; i < n; i++)
    {
        int val = A[i];
        int j = 1;
    while (j > p && A[j-1]>val)
        {
            A[j] = A[j-1];
        j-=1;
    }
    A[j] = val;
    }

}
template <typename T>
int partition_hybrid(std::vector <T> & A, int p, int r)
{
    int pivot = A[r];
    int j = p;

    for (int i = p; i < r; i ++)
    {
        if(A[i]<pivot)
        {
            int temp = A[i];
        A[i] = A[j];
        A[j]=temp;
        j += 1;
        }
    }

    int temp = A[j];
    A[j] = A[r];
    A[r] = temp;

return j; 
}

//Ottimizzo il Quicksort classico
template <typename T>
void hybrid_quick_sort(std::vector <T> & A, int p, int r)
{
    while (p < r)
    {
        if(r - p + 1 < 10)
        {
            insertion_sort_hybrid(A, p, r);
            break;
        }
        else{
            int pivot = partition(A,p,r);
            if (pivot-p < r - pivot)
            {
            hybrid_quick_sort(A,p, pivot - 1);
            p = pivot + 1;
            }
    else {
        hybrid_quick_sort(A,pivot + 1, r);
        r = pivot - 1;
        }
        }
    }
}
