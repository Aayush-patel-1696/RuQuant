

#include "simple.h"
#include <vector>
#include <iostream>

using namespace std;


// template <typename T>
// requires RuVector<T>
// void display(vector<T> InpVector){

//     for(auto i:InpVector ){
//         cout << i << " " ;
//     }
//     cout << endl;
// }

int main(){

   
   
    svector s;
    vector<double> arr = {1.0,2.0,3.0,4.0,5.0};
    vector<double> arr2(arr.size(),0.0);
    vector<double> arr3(arr.size(),0.0);
    double a = 2;
    s.sVax(arr,arr2,a,0,arr.size());

    s.sVaxpby(arr,arr2,arr3,3,5,2,arr.size());

    //  vector<double> arr3(arr.size(),0);
    s.sVelemul(arr,arr2,arr3,2,arr.size());
    // s.display(arr);
    // s.display(arr2);
    // s.display(arr3);
    s.sVelediv(arr,arr2,arr3,2,arr.size());
    double value = 0;
    s.sVdot(arr3,arr2,value,2,arr.size());
    cout<<"dot product "<<value<<endl;

    double value1 = 0;
    s.sVnorm(arr3,arr2,value1,2,arr.size());
    cout<<"dot product "<<value1<<endl;

    s.display(arr);
    s.display(arr2);
    s.display(arr3);
}
