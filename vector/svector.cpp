#include "svector.h"
#include <vector>
#include <stdexcept> 

using namespace std;

template <typename T,typename U >
requires RuVector<T> && ScalerValue<U> 
void svector<T>::sVax(vector <T>& InpVector,vector <T>& OutVector, U a){

    if(InpVector.size()==OutVector.size()){
 
            for(int i=0; i< InpVector.size();i++){
                OutVector[i] = a*InpVector[i];
            }
    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

}

template <typename T>
requires RuVector<T>
void svector::sVelemul (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector){

    if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){
 
            for(int i=0; i< InpVector1.size();i++){
                OutVector[i] = InpVector1[i]*InpVector2[i];
            }
    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

}

template <typename T>
requires RuVector<T>
auto svector::sVcheckelem(vector<T>& InpVector1,T ele){
            
            for(auto i:InpVector1){
                if (i==ele){
                    return 1;
                }
            }

            return 0;
        }

template <typename T>
requires RuVector<T>
void svector::sVelediv (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector){
    if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){


            if (sVcheckelem(InpVector2,0)){
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

}

template <typename T>
requires RuVector<T>
void svector::sVaxpby(vector <T>& InpVector1,vector <T>& InpVector2,vector<T>& OutVector,T a,T b){

    if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){

            for(int i=0; i< InpVector1.size();i++){
                OutVector[i] = a*InpVector1[i] + b*InpVector2[i];
            }
    }

}

template <typename T>
requires RuVector<T>
void svector::sVdot (vector<T>& InpVector1,vector<T>& InpVector2,T& value){

    if((InpVector1.size()==InpVector2.size())){
        value = 0;
        for(int i=0;i<InpVector1.size();i++){
            value+= InpVector1[i]*InpVector2[i];
        }
    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

}

template <typename T,typename U>
requires RuVector<T> &&  ScalerValue<U>
void svector::sVnorm (vector<T>& InpVector1,vector<T>& InpVector2,U& norm){

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

}

template <typename T>
requires RuVector<T>
void svector::display(vector<T> InpVector){

    for(auto i:InpVector ){
        cout << i << " " ;
    }
    cout << endl;
}