
// #include "simple.h"
// #include <iostream>

// template <typename T>
// SimpleTemplateClass<T>::SimpleTemplateClass(T value) : data(value) {}

// template <typename T>
// void SimpleTemplateClass<T>::display() {
//     std::cout << "Value: " << data << std::endl;
// }



// template < typename T>
// concept RuVector = requires (T a,T b){
//     a*b;
//     a+b;
// } && (is_arithmetic_v<T>) && (! same_as<T, char>) ;

// template < typename U>
// concept ScalerValue = requires (U a,U b){
//     a*b;
//     a+b;
// } && (is_arithmetic_v<U>) && (! same_as<U, char>) ;

#ifndef SSIMPLE_CPP  // Include guard to prevent multiple inclusions
#define SSIMPLE_CPP

#include "ssimple.h"
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

// template <typename T>
// requires RuVector<T>
// void svector::sVelemul (std::vector<T>& InpVector1,std::vector<T>& InpVector2,std::vector<T>& OutVector,size_t start,size_t end){

//     if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){
 
//             for(int i=start; i< end;i++){
//                 OutVector[i] = InpVector1[i]*InpVector2[i];
//             }
//     }

//     else{
//         throw std::invalid_argument("Input and output vector sizes must be the same.");
//     }

// };

// template <typename T>
// requires RuVector<T>
// auto svector::sVcheckelem(std::vector<T>& InpVector1,T ele){
            
//             for(auto i:InpVector1){
//                 if (i==ele){
//                     std::cout<<ele<<endl;
//                     return 0;
//                 }
//             }

//             return 1;
// };


// template <typename T>
// requires RuVector<T>
// void svector::sVelediv(std::vector<T>& InpVector1,std::vector<T>& InpVector2,std::vector<T>& OutVector,size_t start,size_t end){
//     if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){

//             T ele = 0;
//             if (sVcheckelem(InpVector2,ele)){
//                 for(int i=start; i< end;i++){
//                     OutVector[i] = InpVector1[i]/InpVector2[i];
//                 }
//             }
//             else{
//                 throw std::invalid_argument("Dividing vector contains 0");
//             }
//     }

//     else{
//         throw std::invalid_argument("Input and output vector sizes must be the same.");
//     }

// };




// template <typename T,typename U>
// requires RuVector<T> && ScalerValue<U>
// void svector::sVaxpby(std::vector <T>& InpVector1,std::vector <T>& InpVector2,std::vector<T>& OutVector,U a,U b,size_t start,size_t end){

//     if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){

//             for(int i=start; i< end;i++){
//                 OutVector[i] = a*InpVector1[i] + b*InpVector2[i];
//             }
//     }

// };

// template <typename T>
// requires RuVector<T>
// void svector::sVdot (std::vector<T>& InpVector1,std::vector<T>& InpVector2,T& value,size_t start,size_t end){

//     if((InpVector1.size()==InpVector2.size())){
//         value = 0;
//         for(int i=start; i< end;i++){
//             value+= InpVector1[i]*InpVector2[i];
//         }
//     }

//     else{
//         throw std::invalid_argument("Input and output vector sizes must be the same.");
//     }

// };

// template <typename T>
// requires RuVector<T>
// void svector::sVnorm (std::vector<T>& InpVector1,std::vector<T>& InpVector2,T& norm,size_t start,size_t end){

//     if((InpVector1.size()==InpVector2.size())){
//         norm = 0;
//         for(int i=start; i< end;i++){
//             norm+= InpVector1[i]*InpVector1[i];
//         }
//         norm = pow(norm,0.5);
//     }

//     else{
//         throw std::invalid_argument("Input and output vector sizes must be the same.");
//     }

// };

template <typename T>
requires RuVector<T>
void tvector::display(std::vector<T>& InpVector){

    for(auto i:InpVector ){
        cout << i << " " ;
    }
    cout << endl;
}

#endif

