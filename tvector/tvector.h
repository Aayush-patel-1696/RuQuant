#ifndef TVECTOR_H  // Include guard to prevent multiple inclusions
#define TVECTOR_H

#include <iostream>
#include <concepts>
#include <vector>
#include <cmath>
#include "svector.h"

using namespace std;

class tvector :public svector{

    public:

        template <typename T,typename U >
        requires RuVector<T> && ScalerValue<U> 
        void tVax(vector <T>& InpVector,vector <T>& OutVector, U& a) ;// scalar multiplication: a*x

        template <typename T>
        requires RuVector<T>
        void tVelemul (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector); 

        template <typename T,typename U>
        requires RuVector<T> && ScalerValue<U> 
        void tVaxpby(vector <T>& InpVector1,vector <T>& InpVector2,vector<T>& OutVector,U a,U b);

        template <typename T>
        requires RuVector<T>
        void tVdot (vector<T>& InpVector1,vector<T>& InpVector2,T& value);

        template <typename T,typename U>
        requires RuVector<T> &&  ScalerValue<U>
        void tVnorm(vector<T>& InpVector1,vector<T>& InpVector2,U& norm);

        template <typename T>
        requires RuVector<T>
        void display(vector<T> &InpVector); // Display the vector

    private:
        size_t num_threads = 6;


};

#include "tvector.cpp" // Include the implementation file
#endif