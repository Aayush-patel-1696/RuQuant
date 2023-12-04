

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

   
   
    svector s;
    vector<double> arr = {1.0,2.0,3.0,4.0,5.0};
    vector<double> arr2(arr.size(),0.0);
    double a = 2;
    s.sVax(arr,arr2,a);

    //  vector<double> arr3(arr.size(),0);
    // svector::sVelemul(arr,arr2,arr3);

    s.display(arr);
    s.display(arr2);
    // display(arr3);
}
