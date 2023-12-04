#ifndef SVECTOR_CPP  // Include guard to prevent multiple inclusions
#define SVECTOR_CPP

#include "svector.h"
#include <vector>
#include <concepts>
#include <stdexcept> 

using namespace std;

template <typename T,typename U >
requires RuVector<T> && ScalerValue<U>
void svector::sVax(std::vector <T>& InpVector,std::vector <T>& OutVector, U& a,size_t start,size_t end){

    if(InpVector.size()==OutVector.size()){
 
            for(int i=start; i< end;i++){
                OutVector[i] = a*InpVector[i];
            }
    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

};

template <typename T>
requires RuVector<T>
void svector::sVelemul (std::vector<T>& InpVector1,std::vector<T>& InpVector2,std::vector<T>& OutVector,size_t start,size_t end){

    if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){
 
            for(int i=0; i< InpVector1.size();i++){
                OutVector[i] = InpVector1[i]*InpVector2[i];
            }
    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

};

template <typename T>
requires RuVector<T>
auto svector::sVcheckelem(std::vector<T>& InpVector1,T ele){
            
            for(auto i:InpVector1){
                if (i==ele){
                    std::cout<<ele<<endl;
                    return 0;
                }
            }

            return 1;
};


template <typename T>
requires RuVector<T>
void svector::sVelediv(std::vector<T>& InpVector1,std::vector<T>& InpVector2,std::vector<T>& OutVector){
    if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){

            T ele = 0;
            if (sVcheckelem(InpVector2,ele)){
                for(int i=0; i< InpVector1.size();i++){
                    OutVector[i] = InpVector1[i]/InpVector2[i];
                }
            }
            else{
                throw std::invalid_argument("Dividing vector contains 0");
            }
    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

};




template <typename T,typename U>
requires RuVector<T> && ScalerValue<U>
void svector::sVaxpby(std::vector <T>& InpVector1,std::vector <T>& InpVector2,std::vector<T>& OutVector,U a,U b,size_t start,size_t end){

    if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){

            for(int i=0; i< InpVector1.size();i++){
                OutVector[i] = a*InpVector1[i] + b*InpVector2[i];
            }
    }

};

template <typename T>
requires RuVector<T>
void svector::sVdot (std::vector<T>& InpVector1,std::vector<T>& InpVector2,T& value,size_t start,size_t end){

    if((InpVector1.size()==InpVector2.size())){
        value = 0;
        for(int i=0;i<InpVector1.size();i++){
            value+= InpVector1[i]*InpVector2[i];
        }
    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

};

template <typename T>
requires RuVector<T>
void svector::sVnorm (std::vector<T>& InpVector1,std::vector<T>& InpVector2,T& norm,size_t start,size_t end){

    if((InpVector1.size()==InpVector2.size())){
        norm = 0;
        for(int i=0;i<InpVector1.size();i++){
            norm+= InpVector1[i]*InpVector1[i];
        }
        norm = pow(norm,0.5);
    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

};

template <typename T>
requires RuVector<T>
void svector::display(std::vector<T>& InpVector){

    for(auto i:InpVector ){
        cout << i << " " ;
    }
    cout << endl;
}

#endif

