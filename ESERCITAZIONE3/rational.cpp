#include <iostream>
#include "rational.hpp"
using namespace std;

int main(void) {
    rational<int> r1(200,2);
    rational<int> r2(150,-5);
    rational<int> r[4];

    r[0] = r1+r2;
    r[1] = r1-r2;
    r[2] = r1*r2;
    r[3]= r1/r2;

// Per Inf e NaN
    for (int i =0 ;i<4; i++){
        if (r[i].num()==1 && r[i].den()==0){
            cout<<"Il risultato finale è Inf"<<"\n";
        }
    else if (r[i].num()==0 && r[i].den()==0){
        cout <<"Il risultato finale è NaN"<<"\n";
    }
    else if (r[i].num()==1 && r[i].den()!=0){
        cout <<0<< "\n";
    }
    else if (r[i].den()==1){
        cout <<r[i].num()<<"\n";
    }
    else{
        cout <<r[i].num()<< "/" << r[i].den() <<"\n";
    }
};

return 0;
}
