/* Sequatial Vector Operations header files


following operations will be created


1) tVaxpy = alpha*x + y 
both inplace and return manner
2) tVaxsy =alpha*x + y 
2) tVdot = x*y
only return manner
3) tVnrm = x
only return manner
4) tVelemul = x*y 
both inplace and return manner
5) tVelediv = x/y
both inplace and return manner
6) tVax



*/
#include<iostream>
#include <concepts>
#include <vector>
#include <cmath>

using namespace std;

#ifndef SVECTOR_H  // Include guard to prevent multiple inclusions
#define SEVECTOR_H

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
        void sVax(vector <T>& InpVector,vector <T>& OutVector, T a); // scalar multiplication: a*x

        template <typename T>
        requires RuVector<T>
        void sVelemul (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector); // vector multiplication: z = x*y

        template <typename T>
        requires RuVector<T>
        auto sVcheckelem(vector<T>& InpVector1,T ele)        // check if element present in vector

        template <typename T>
        requires RuVector<T>
        void sVelediv (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector)  //vector division: z = x/y

        template <typename T>
        requires RuVector<T>
        void sVaxpby(vector <T>& InpVector1,vector <T>& InpVector2,vector<T>& OutVector,T a,T b) // two vector addition with scalar multiplication: z = a*x + b*y

        template <typename T>
        requires RuVector<T>
        void sVdot (vector<T>& InpVector1,vector<T>& InpVector2,T& value) // dot product of two vectors = a.b

        template <typename T,typename U>
        requires RuVector<T> &&  ScalerValue<U>
        void sVnorm (vector<T>& InpVector1,vector<T>& InpVector2,U& norm) // norm of the vector = sqrt(sum(x_i^2))

        template <typename T>
        requires RuVector<T>
        void display(vector<T> &InpVector) // Display the vector
};
#endif