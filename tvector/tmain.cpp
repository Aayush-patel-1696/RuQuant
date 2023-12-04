#include "tvector.h"
#include <vector>
#include <chrono>

using namespace std;

using namespace std::chrono;


int main(){

    tvector t;
    svector s;

    vector<double> arr;
    size_t N = 7000000;
    for(int i=1;i<N+1;i++){
        arr.push_back(i);
    }

    cout <<"Hi" << endl;
    vector<double> arr2(arr.size(),0);
    vector<double> arr3(arr.size(),0);
    int b=2;

    auto tstartTime = high_resolution_clock::now();

    t.tVax(arr,arr2,b);

    auto tstopTime = high_resolution_clock::now();

    auto tduration = duration_cast<microseconds>(tstopTime-tstartTime);

    cout << "Time to compute using multithreading " << tduration.count()/1000000.0 << endl;

    auto startTime = high_resolution_clock::now();

    s.sVax(arr,arr3,b,0,arr.size());

    auto stopTime = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stopTime-startTime);

    cout << "Time to compute using sequential " << duration.count()/1000000.0 << endl;

    // tVaxpby(arr,arr2,arr3,2,3);
    
    // // tVelemul(arr,arr2,arr3);

    // t.display(arr);
    // t.display(arr2);
    // double norm=0;
    // tVnorm(arr,norm);
    // cout<<norm<<endl;

    return 0;

}


 //g++-10 -std=c++2a -c ssimple.cpp -o ssimple.o -pthread
 //g++-10 -std=c++2a -c smain.cpp -o smain.o -pthread
 // g++-10 -std=c++2a  ssimple.o smain.o -o stemplate_example -pthread

 //g++-10 -std=c++2a tvector.cpp svector.cpp tmain.cpp -o out -pthread