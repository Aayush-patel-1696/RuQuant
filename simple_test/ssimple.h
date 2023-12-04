

#ifndef SSIMPLE_H  // Include guard to prevent multiple inclusions
#define SSIMPLE_H

#include <iostream>
#include <concepts>
#include <vector>
#include <cmath>
#include "simple.h"

using namespace std;

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


class tvector :public svector{

    public:

        // tvector{};

        // tvector(size_t num_threads);

        // {
        //     this->num_threads = num_threads;
        // }

        // template <typename T,typename U >
        // requires RuVector<T> && ScalerValue<U>
        // void sVax(vector <T>& InpVector,vector <T>& OutVector, U a,size_t start,size_t end); 

        template <typename T,typename U >
        requires RuVector<T> && ScalerValue<U> 
        void tVax(vector <T>& InpVector,vector <T>& OutVector, U& a) ;// scalar multiplication: a*x

        // template <typename T>
        // requires RuVector<T>
        // void tVelemul (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector) // vector multiplication: z = x*y

        // template <typename T>
        // requires RuVector<T>
        // auto sVcheckelem(vector<T>& InpVector1,T ele);        // check if element present in vector

        // template <typename T>
        // requires RuVector<T>
        // void sVelediv (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector,size_t start,size_t end);  //vector division: z = x/y

        // template <typename T,typename U>
        // requires RuVector<T> && ScalerValue<U> 
        // void tVaxpby(vector <T>& InpVector1,vector <T>& InpVector2,vector<T>& OutVector,U a,U b); 

        // template <typename T>
        // requires RuVector<T>
        // void tVdot (vector<T>& InpVector1,vector<T>& InpVector2,T& value); // dot product of two vectors = a.b

        // template <typename T,typename U>
        // requires RuVector<T> &&  ScalerValue<U>
        // void tVnorm(vector<T>& InpVector1,U& norm); // norm of the vector = sqrt(sum(x_i^2))

        template <typename T>
        requires RuVector<T>
        void display(vector<T> &InpVector); // Display the vector

    private:
        size_t num_threads = 4;


};

#include "ssimple.cpp" // Include the implementation file
#endif