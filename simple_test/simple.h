

#ifndef SIMPLE_H  // Include guard to prevent multiple inclusions
#define SIMPLE_H

#include<iostream>
#include <concepts>
#include <vector>
#include <cmath>

using namespace std;

template < typename T>
concept RuVector = requires (T a,T b){
    a*b;
    a+b;
} && (is_arithmetic_v<T>) && (! same_as<T, char>) ;

template < typename U>
concept ScalerValue = requires (U a,U b){
    a*b;
    a+b;
} && (is_arithmetic_v<U>) && (! same_as<U, char>) ;


class svector{

    public:


        template <typename T,typename U >
        requires RuVector<T> && ScalerValue<U>
        void sVax(vector <T>& InpVector,vector <T>& OutVector, U& a,size_t start,size_t end); // scalar multiplication: a*x

        template <typename T>
        requires RuVector<T>
        void sVelemul (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector,size_t start,size_t end); // vector multiplication: z = x*y

        template <typename T>
        requires RuVector<T>
        auto sVcheckelem(vector<T>& InpVector1,T ele);        // check if element present in vector

        template <typename T>
        requires RuVector<T>
        void sVelediv (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector,size_t start,size_t end);  //vector division: z = x/y

        template <typename T,typename U>
        requires RuVector<T> && ScalerValue<U>
        void sVaxpby(vector <T>& InpVector1,vector <T>& InpVector2,vector<T>& OutVector,U a,U b,size_t start,size_t end); 

        template <typename T>
        requires RuVector<T> 
        void sVdot (vector<T>& InpVector1,vector<T>& InpVector2,T& value,size_t start,size_t end); // dot product of two vectors = a.b

        template <typename T>
        requires RuVector<T> 
        void sVnorm (vector<T>& InpVector1,vector<T>& InpVector2,T& norm,size_t start,size_t end); // norm of the vector = sqrt(sum(x_i^2))

        template <typename T>
        requires RuVector<T>
        void display(vector<T> &InpVector); // Display the vector

};

#include "simple.cpp" // Include the implementation file
#endif