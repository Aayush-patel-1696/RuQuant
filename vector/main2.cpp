#include "svector.h"
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

   
   
    svector<double> s;
    vector<double> arr = {1.0,2.0,3.0,4.0,5.0};
    vector<double> arr2(arr.size(),0.0);
    s.sVax(arr,arr2,2.0);

    //  vector<double> arr3(arr.size(),0);
    // svector::sVelemul(arr,arr2,arr3);

    // display(arr);
    // display(arr2);
    // display(arr3);
}

