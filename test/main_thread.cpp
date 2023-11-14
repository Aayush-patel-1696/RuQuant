#include<iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono>

using namespace std;

static int num_threads = 4;
template < typename T>
concept RuVector = requires (T a,T b){
    a*b;
    a+b;
} && (is_arithmetic_v<T>) && (! same_as<T, char>) ;

template < typename U>
concept ScalerValue = requires (U a,U b){
    a*b;
    a+b;
} && (is_arithmetic_v<U>) && (! same_as<U, char>);

template <typename T,typename U >
requires RuVector<T> && ScalerValue<U> 
void sVax(vector <T>& InpVector,vector <T>& OutVector, U a,int start,int end){

    if(InpVector.size()==OutVector.size()){
           
            for(int i= start; i< end;i++){
                OutVector[i] = a*InpVector[i];
            }
    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

}




template <typename T,typename U >
requires RuVector<T> && ScalerValue<U> 
void tVax(vector <T>& InpVector,vector <T>& OutVector, U a){

    if(InpVector.size()==OutVector.size()){
 
            size_t chunk_size = InpVector.size() / num_threads;

            // Create a vector to store thread objects
            thread tarray[num_threads];

            // Launch threads to perform vector scalar multiplication on different chunks
            for (int i = 0; i < num_threads; ++i) {
                size_t start = i * chunk_size;
                size_t end = (i == num_threads - 1) ? InpVector.size() : (i + 1) * chunk_size;
                tarray[i] = thread(sVax<T,U>, ref(InpVector),ref(OutVector), a, start, end);
            }

            // Join the threads to wait for them to complete
            for(int i=0;i<num_threads;i++){
            if(tarray[i].joinable())
                tarray[i].join();
            }


    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

}

template <typename T>
requires RuVector<T>
void sVelemul (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector,size_t start ,size_t end){

    if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){
 
            for(int i=start; i< end;i++){
                OutVector[i] = InpVector1[i]*InpVector2[i];
            }
    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

}

template <typename T>
requires RuVector<T>
void tVelemul (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector){

    if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){

         size_t chunk_size = InpVector1.size() / num_threads;

        // Create a vector to store thread objects
        thread tarray[num_threads];

        // Launch threads to perform vector scalar multiplication on different chunks
        for (int i = 0; i < num_threads; ++i) {
            size_t start = i * chunk_size;
            size_t end = (i == num_threads - 1) ? InpVector1.size() : (i + 1) * chunk_size;
            tarray[i] = thread(sVelemul<T>, ref(InpVector1),ref(InpVector2),ref(OutVector), start, end);
        }

        // Join the threads to wait for them to complete
        for(int i=0;i<num_threads;i++){
        if(tarray[i].joinable())
            tarray[i].join();
        }
    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

}

template <typename T,typename U >
requires RuVector<T> && ScalerValue<U> 
void sVaxpby(vector <T>& InpVector1,vector <T>& InpVector2,vector<T>& OutVector,U a,U b,size_t start,size_t end){

    if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){

            for(int i=start; i< end;i++){
                OutVector[i] = a*InpVector1[i] + b*InpVector2[i];
            }
    }

}

template <typename T,typename U>
requires RuVector<T> && ScalerValue<U> 
void tVaxpby(vector <T>& InpVector1,vector <T>& InpVector2,vector<T>& OutVector,U a,U b){

    if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){

        size_t chunk_size = InpVector1.size() / num_threads;

        // Create a vector to store thread objects
        thread tarray[num_threads];

        // Launch threads to perform vector scalar multiplication on different chunks
        for (int i = 0; i < num_threads; ++i) {
            size_t start = i * chunk_size;
            size_t end = (i == num_threads - 1) ? InpVector1.size() : (i + 1) * chunk_size;
            tarray[i] = thread(sVaxpby<T,U>, ref(InpVector1),ref(InpVector2),ref(OutVector),a,b,start, end);
        }

        // Join the threads to wait for them to complete
        for(int i=0;i<num_threads;i++){
        if(tarray[i].joinable())
            tarray[i].join();
        }
    }

}

template <typename T>
requires RuVector<T>
void sVdot (vector<T>& InpVector1,vector<T>& InpVector2,T& value,size_t start,size_t end){

    if((InpVector1.size()==InpVector2.size())){
        value = 0;
        for(int i=start;i<end;i++){
            value += InpVector1[i]*InpVector2[i];
        }
    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

}

template <typename T>
requires RuVector<T>
void tVdot (vector<T>& InpVector1,vector<T>& InpVector2,T& value){

    if((InpVector1.size()==InpVector2.size())){

        size_t chunk_size = InpVector1.size() / num_threads;

        // Create a vector to store thread objects
        thread tarray[num_threads];

        vector<T> valuearray(num_threads,0);
        // Launch threads to perform vector scalar multiplication on different chunks
        for (int i = 0; i < num_threads; ++i) {
            size_t start = i * chunk_size;
            size_t end = (i == num_threads - 1) ? InpVector1.size() : (i + 1) * chunk_size;
            tarray[i] = thread(sVdot<T>, ref(InpVector1),ref(InpVector2),ref(valuearray[i]),start, end);
        }

        for(int i=0;i<num_threads;i++){
            value += valuearray[i];
        }

        // Join the threads to wait for them to complete
        for(int i=0;i<num_threads;i++){
        if(tarray[i].joinable())
            tarray[i].join();
        }

    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }
}

// template <typename T,typename U>
// requires RuVector<T> &&  ScalerValue<U>
// void sVnorm (vector<T>& InpVector1,U& norm){
//     norm = 0;
//     for(int i=0;i<InpVector1.size();i++){
//         norm += InpVector1[i]*InpVector1[i];
//     }
// }

template <typename T,typename U>
requires RuVector<T> &&  ScalerValue<U>
void tVnorm(vector<T>& InpVector1,U& norm){

    size_t chunk_size = InpVector1.size() / num_threads;

    // Create a vector to store thread objects
    thread tarray[num_threads];

    vector<T> normarray(num_threads,0);
    // Launch threads to perform vector scalar multiplication on different chunks
    for (int i = 0; i < num_threads; ++i) {
        size_t start = i * chunk_size;
        size_t end = (i == num_threads - 1) ? InpVector1.size() : (i + 1) * chunk_size;
        tarray[i] = thread(sVdot<T>, ref(InpVector1),ref(InpVector1),ref(normarray[i]),start, end);
    }

    // Join the threads to wait for them to complete
    for(int i=0;i<num_threads;i++){
    if(tarray[i].joinable())
        tarray[i].join();
    }
    for(int i=0;i<num_threads;i++){
        norm += normarray[i];
    }
    norm = pow(norm,0.5);

}

template <typename T>
requires RuVector<T>
void display(vector<T>& InpVector){

    for(auto i:InpVector ){
        cout << i << " " ;
    }
    cout << endl;
}





int main(){


    vector<double> arr = {1,2,3,4,5,8,9,10,11,12};
    vector<double> arr2(arr.size(),0);
    vector<double> arr3(arr.size(),0);
    tVax(arr,arr2,2);
    tVaxpby(arr,arr2,arr3,2,3);
    
    // tVelemul(arr,arr2,arr3);

    display(arr);
    display(arr2);
    double norm=0;
    tVnorm(arr,norm);
    cout<<norm<<endl;

    return 0;

}

//g++-10 -std=c++2a main_thread.cpp -o out -lpthread

