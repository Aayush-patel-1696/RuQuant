#include "ssimple.h"
#include <vector>

using namespace std;


int main(){

    tvector t;
    vector<double> arr = {1,2,3,4,5,8,9,10,11,12};
    vector<double> arr2(arr.size(),0);
    vector<double> arr3(arr.size(),0);
    int b=2;
    t.tVax(arr,arr2,b);
    // tVaxpby(arr,arr2,arr3,2,3);
    
    // // tVelemul(arr,arr2,arr3);

    t.display(arr);
    t.display(arr2);
    // double norm=0;
    // tVnorm(arr,norm);
    // cout<<norm<<endl;

    return 0;

}


 //g++-10 -std=c++2a -c ssimple.cpp -o ssimple.o -pthread
 //g++-10 -std=c++2a -c smain.cpp -o smain.o -pthread
 // g++-10 -std=c++2a  ssimple.o smain.o -o stemplate_example -pthread