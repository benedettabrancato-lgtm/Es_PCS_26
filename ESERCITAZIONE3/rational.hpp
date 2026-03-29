#include <iostream>
#include <concepts>
#pragma once
#include <numeric>
using namespace std;

template<typename I> requires std::integral<I> //per ogni I t.c. I è un intero
class rational{ 
    I num_; 
    I den_;

//Semplificazione
    void semplificazione() {
        if (den_==0) return; //se ho Inf o Nan non procedere con la semplificazione 

        I comune = std::gcd(num_,den_); //MCD incluso nella libreria 'numeric'

        num_ = num_/comune;
        den_ = den_/comune;

        if (den_<0){
            num_ = -num_;
            den_ = -den_;
        }
    }
public:
    /*Costruttore di default*/
    rational() 
        : num_(I{0}),den_(I{1})  
    {}
    
    /*Costruttore user-defined */ 
    rational(const I& pnum, const I& pden) 
        :num_(pnum), den_(pden)
    {
        if (den_ == 0 && num_ != 0) 
            num_ = 1;  // valore sentinella per Inf 
        else if (num_ == 0 && den_ == 0) {
            num_= 0;
            den_= 0; //valori sentinella per NaN
        }
        semplificazione();
    }
        
    /*Restituiscono i valori di x e y*/ 
    I num() const{return num_;}
    I den() const{return den_;}
        
    /*Implementazione dell'operatore +=*/
    rational& operator+=(const rational& other) {
        //caso Inf 
        if ((den_ == 0 && num_ == 1) || (other.num_ ==1 && other.den_ == 0)){ // '||' = or
            num_=1;
            den_=0;
        }

        //caso NaN
        else if ((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)){
            num_ = 0;
            den_ = 0;
        }

        //caso Inf - Inf = NaN
        else if ((den_==0 && num_==1) || (other.num_ == 1 && other.den_ == 0)){
            num_=0;
            den_=0;
        }
        // caso semplice 
        else {
            num_ = (num_*other.den_)+(other.num_*den_);
            den_=(den_*other.den_);
        }
        semplificazione();
        return *this;
    }
    /*Implementazione dell'operatore +*/
    // Qui non modifico num_ e den_, ma creo nuova variabile
    rational operator+(const rational& other) const { 
        rational ret=*this;
        ret +=other;
        return ret; 
    } 

    /*Implementazione dell'operatore -=*/
    rational& operator-=(const rational& other) {
        //tratto Inf 
        if ((den_ == 0 && num_ == 1) || (other.num_ ==1 && other.den_ == 0)){
            num_=1;
            den_=0;
        }
        //NaN
        else if ((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)){
            num_ = 0;
            den_ = 0;
        }
        // caso semplice 
        else {
            num_ = (num_*other.den_)-(other.num_*den_);
            den_=(den_*other.den_);
        }
        semplificazione();
        return *this;
    }

    /*Implementazione dell'operatore -*/
    // Qui non modifico num_ e den_, ma creo nuova variabile
    rational operator-(const rational& other) const { 
        rational ret=*this;
        ret -=other;
        return ret; 
    } 

    /*Implementazione dell'operatore  *= */
    rational& operator*=(const rational& other) {
        //tratto Inf 
        if ((den_ == 0 && num_ == 1) || (other.num_ ==1 && other.den_ == 0)){
            num_=1;
            den_=0;
        }
        //NaN
        else if ((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)){
            num_ = 0;
            den_ = 0;
        }
        //Caso inf * numero
        else if ((den_==0 && num_==1) && (other.num_ != 1 && other.den_ != 0)){
            num_ = 1;
            den_=0;
        }
        // caso semplice 
        else {
            num_ = (num_*other.num_);
            den_=(den_*other.den_);
        }
        semplificazione();
        return *this;
    }

    /*Implementazione dell'operatore * */
    // Qui non modifico num_ e den_, ma creo nuova variabile
    rational operator*(const rational& other) const { 
        rational ret=*this;
        ret *=other;
        return ret; 
    } 

    /*Implementazione dell'operatore /= */
    rational& operator/=(const rational& other) {
        //tratto Inf 
        if ((den_ == 0 && num_ == 1) && (other.num_ == 1 && other.den_ == 0)){
            num_=0;
            den_=0;
            //Inf/Inf f.indeterminata
        }
        else if ((den_==0 && num_==0)&& (other.den_ == 0 && other.num_ == 0)){
            num_=0;
            den_=0;
            //caso 0/0 forma indeterminata(NaN)
        }
        else if ((den_==0 && num_==1)&&(other.num_!=1 && other.num_!=0 && other.den_ != 0)) {
            num_=1;
            den_=0;
            // caso inf/num=inf
        }
        else if ((num_!=1 && num_!=0 && den_ != 0)&&(other.den_==0 && other.num_==0)){
            num_=1;
            den_=0;
            //caso num/zero=inf
        }
        //Caso 'semplice o normale'
        else { //caso semplice o normale
            num_=(num_*other.den_);
            den_=(den_*other.num_);
        }
        semplificazione();
        return *this;
    }

    /*Implementazione dell'operatore / */
    // Qui non modifico num_ e den_, ma creo nuova variabile
    rational operator/(const rational& other) const { 
        rational ret=*this;
        ret /=other;
        return ret; 
    } 
};

//Definisco l'operatore stampa
template <typename I>
std::ostream& 
operator<<(std::ostream& os, const rational<I>& r)
{
    os << r.num() <<"/" << r.den();
    return os;
}