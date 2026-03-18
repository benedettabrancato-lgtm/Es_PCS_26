#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{ 
  static const int N = 10;
  double arr[N] = {3.1, 5.0, 7.0, 9.4, 1.0,2.0, 4.0, 6.7, 8.9, 10.0 };

  // calcolo massimo e minimo 
  double massimo=arr[0];
  double minimo=arr[0];

  //Calcolo minimo e massimo attraverso funzione

  // for (int i=1; i<N; i++)
  //   {
  //     massimo = std::max(massimo,arr[i]);
  //     minimo = std::min(minimo,arr[i]);
  //   }

  //Calcolo massimo e minimo attraverso ciclo for
  for (int i = 0; i <N; i++)
  {
    if (arr[i]>= massimo)
    {
      massimo = arr[i];
    }
  }

  for (int i = 0; i <N; i++)
  {
    if (arr[i]<= minimo)
    {
      minimo = arr[i];
    }
  }
    std:: cout <<"Il massimo è il seguente: " << massimo << "\n";
    std:: cout <<"Il minimo è il seguente: " << minimo << "\n";

  // calcolo media 
  double somma = 0.0;
  for (int i= 0; i<N; i++)
  {
    somma = somma + arr[i];
  }
  double media = somma/N;
  std::cout <<"La media tra i seguenti numeri è: " << media << "\n";

  //calcolo la deviazione standard
  double diff_i_esima = 0.0;
  double somma_i_esima = 0.0;
  double quadrato = 0.0;
  
  for (int i = 0; i<N; i++)

  {
    diff_i_esima = arr[i]-media;
    quadrato = diff_i_esima*diff_i_esima;
    somma_i_esima = somma_i_esima + quadrato;
  }

  double rapporto = somma_i_esima /N;
  double dev_standard = sqrt(rapporto);
  std::cout <<"La deviazione standard tra i seguenti numeri è: " <<dev_standard<< "\n";

    return 0;
}
