// #include "tvector.h"
// #include <vector>
// #include <chrono>

// using namespace std;

// using namespace std::chrono;


// vector<double> intitalize_vector_1_n(size_t N){
//     vector<double> arr;
//     for(int i=1;i<N+1;i++){
//         arr.push_back(i);
//     }

//     return arr;

// }

// vector<double> intitalize_vector_0(size_t N){
//     vector<double> arr(N,0);
   

//     return arr;

// }





// int main(){

//     tvector t;
//     svector s;

//     size_t iter = 50;

//     vector<size_t> size_array = {1000,10000,1000000,5000000,10000000,20000000};

//     vector<double> tduration_arr;

//     // Code for two vectors
//     vector<double> arr;
//     vector<double> arr2;
//     vector<double> arr3;

//     double tduration;
//     for (auto i :size_array){

//         for (int j = 0;j<iter;j++){

//             arr = intitalize_vector_1_n(i);
//             arr2 = intitalize_vector_0(i);

//             arr3 = intitalize_vector_1_n(i);

//             int b =2;

//             double value=0;
//             auto tstartTime = high_resolution_clock::now();

//             //t.tVax(arr,arr2,b);                // Change the function 

//             // double value = 0;
//             // arr2 = intitalize_vector_1_n(i);
//             // t.tVnorm(arr,arr2,value);
            
//             //t.tVelemul(arr,arr3,arr2);

//             t.tVdot(arr,arr2,value);

//             auto tstopTime = high_resolution_clock::now();

//             auto temp_tduration = duration_cast<microseconds>(tstopTime-tstartTime);

//             tduration += temp_tduration.count()/1000000.0;

//         }

//         tduration = tduration/(static_cast<float> (iter));

//         tduration_arr.push_back(tduration);
        

//     }

//     // Code for two vectors
//     vector<double> sduration_arr;
//     double sduration;
//     for (auto i :size_array){

//         for (int j = 0;j<iter;j++){

//             arr = intitalize_vector_1_n(i);
//             arr2 = intitalize_vector_0(i);
//             arr3 = intitalize_vector_1_n(i);;

//             int b = 2;

//             double value = 0; 

//             auto sstartTime = high_resolution_clock::now();

//             //s.sVax(arr,arr2,b,0,arr.size());                // Change the function 

//             // double value = 0;
//             // arr2 = intitalize_vector_1_n(i);
//             // s.sVnorm(arr,arr2,value,0,arr.size());

//             // s.sVelemul(arr,arr3,arr2,0,arr.size());

//             s.sVdot(arr,arr2,value,0,arr.size());

//             auto sstopTime = high_resolution_clock::now();

//             auto temp_sduration = duration_cast<microseconds>(sstopTime-sstartTime);

//             sduration += temp_sduration.count()/1000000.0;

//         }

//         sduration = sduration/(static_cast<float> (iter));

//         sduration_arr.push_back(sduration);
        

//     }


//     for (int i =0;i< size_array.size();i++){
//         cout<< "For defined  Operation speedup gained for size array " << size_array[i] << " is "  << sduration_arr[i]/tduration_arr[i] << endl;

//     }


    
//     return 0;

// }


//  //g++-10 -std=c++2a -c ssimple.cpp -o ssimple.o -pthread
//  //g++-10 -std=c++2a -c smain.cpp -o smain.o -pthread
//  // g++-10 -std=c++2a  ssimple.o smain.o -o stemplate_example -pthread

//  //g++-10 -std=c++2a tvector.cpp svector.cpp tmain.cpp -o out -pthread


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


 //g++-10 -std=c++2a tvector.cpp svector.cpp tmain.cpp -o out -pthread