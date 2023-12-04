#ifndef TVECTOR_CPP  // Include guard to prevent multiple inclusions
#define TVECTOR_CPP

#include "tvector.h"
#include <vector>
#include <concepts>
#include <stdexcept> 
#include <thread>

using namespace std;


template <typename T,typename U >
requires RuVector<T> && ScalerValue<U> 
void tvector::tVax(std::vector <T>& InpVector,std::vector <T>& OutVector, U& a){

    if(InpVector.size()==OutVector.size()){
 
            size_t num_th = (tvector::num_threads);
            size_t chunk_size = InpVector.size() /num_th ;

            // Create a vector to store thread objects
            std::thread tarray[num_th];

            svector obj;

            // Launch threads to perform vector scalar multiplication on different chunks
            for (int i = 0; i < num_th; ++i) {
                size_t start = i * chunk_size;
                size_t end = (i == num_th - 1) ? InpVector.size() : (i + 1) * chunk_size;
                tarray[i] = std::thread(&svector::sVax<T,U>,&obj,std::ref(InpVector),std::ref(OutVector), std::ref(a), start, end);
            }

            // Join the threads to wait for them to complete
            for(int i=0;i<num_th;i++){
            if(tarray[i].joinable())
                tarray[i].join();
            }
    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

};

template <typename T>
requires RuVector<T>
void tvector::tVelemul (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector){

    if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){

        size_t num_th = (tvector::num_threads);
        size_t chunk_size = InpVector1.size() / num_th;

        // Create a vector to store thread objects
        thread tarray[num_th];

        svector obj;

        // Launch threads to perform vector scalar multiplication on different chunks
        for (int i = 0; i < num_th; ++i) {
            size_t start = i * chunk_size;
            size_t end = (i == num_th - 1) ? InpVector1.size() : (i + 1) * chunk_size;
            tarray[i] = thread(&svector::sVelemul<T>,&obj,ref(InpVector1),ref(InpVector2),ref(OutVector), start, end);
        }

        // Join the threads to wait for them to complete
        for(int i=0;i<num_th;i++){
        if(tarray[i].joinable())
            tarray[i].join();
        }
    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

};

template <typename T,typename U>
requires RuVector<T> && ScalerValue<U> 
void tvector::tVaxpby(vector <T>& InpVector1,vector <T>& InpVector2,vector<T>& OutVector,U a,U b){

    if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){

        size_t num_th = (tvector::num_threads);
        size_t chunk_size = InpVector1.size() / num_th;

        // Create a vector to store thread objects
        thread tarray[num_th];

        svector obj;

        // Launch threads to perform vector scalar multiplication on different chunks
        for (int i = 0; i < num_th; ++i) {
            size_t start = i * chunk_size;
            size_t end = (i == num_th - 1) ? InpVector1.size() : (i + 1) * chunk_size;
            tarray[i] = thread(&svector::sVaxpby<T,U>,&obj,ref(InpVector1),ref(InpVector2),ref(OutVector),a,b,start, end);
        }

        // Join the threads to wait for them to complete
        for(int i=0;i<num_th;i++){
        if(tarray[i].joinable())
            tarray[i].join();
        }
    }

}

template <typename T>
requires RuVector<T>
void tvector::tVdot (vector<T>& InpVector1,vector<T>& InpVector2,T& value){

    if((InpVector1.size()==InpVector2.size())){

        size_t num_th = (tvector::num_threads);

        size_t chunk_size = InpVector1.size() / num_th;

        // Create a vector to store thread objects
        thread tarray[num_th];

        svector obj;

        vector<T> valuearray(num_th,0);
        // Launch threads to perform vector scalar multiplication on different chunks
        for (int i = 0; i < num_th; ++i) {
            size_t start = i * chunk_size;
            size_t end = (i == num_th - 1) ? InpVector1.size() : (i + 1) * chunk_size;
            tarray[i] = thread(&svector::sVdot<T>, &obj, ref(InpVector1),ref(InpVector2),ref(valuearray[i]),start, end);
        }

        for(int i=0;i<num_th;i++){
            value += valuearray[i];
        }

        // Join the threads to wait for them to complete
        for(int i=0;i<num_th;i++){
        if(tarray[i].joinable())
            tarray[i].join();
        }

    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }
};

template <typename T,typename U>
requires RuVector<T> &&  ScalerValue<U>
void tvector::tVnorm(vector<T>& InpVector1,vector<T>& InpVector2,U& norm){

    size_t num_th = (tvector::num_threads);
    size_t chunk_size = InpVector1.size() / num_th;

    // Create a vector to store thread objects
    thread tarray[num_th];

    svector obj; 

    vector<T> normarray(num_th,0);
    // Launch threads to perform vector scalar multiplication on different chunks
    for (int i = 0; i < num_th; ++i) {
        size_t start = i * chunk_size;
        size_t end = (i == num_th - 1) ? InpVector1.size() : (i + 1) * chunk_size;
        tarray[i] = thread(&svector::sVdot<T>,&obj, ref(InpVector1),ref(InpVector2),ref(normarray[i]),start, end);
    }

    // Join the threads to wait for them to complete
    for(int i=0;i<num_th;i++){
    if(tarray[i].joinable())
        tarray[i].join();
    }
    for(int i=0;i<num_th;i++){
        norm += normarray[i];
    }
    norm = pow(norm,0.5);

};


template <typename T>
requires RuVector<T>
void tvector::display(std::vector<T>& InpVector){

    for(auto i:InpVector ){
        cout << i << " " ;
    }
    cout << endl;
}

#endif

