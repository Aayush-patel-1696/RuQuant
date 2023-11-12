/*

following operations will be created


1) tVaxpy = alpha*x + y 
2) tVdot = x*y
only return manner
3) tVnrm = sqrt(x1^2+ x2^2 + x3^3)
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





// template <typename T>
// requires MyVector<T>
// void sVax (vector <T>& InpVector,T a){

//     int size = InpVector.size();
//     for(int i=0; i< size;i++){

//         InpVector[i] = a*InpVector[i];

//     }

 
// }

// template <typename T,typename U >
// requires MyVector<T> && MyVector2<U> 
// void sVax(vector <T>& InpVector,vector <T>& OutVector, U a ){

//     if(InpVector.size()==OutVector.size()){
 
//             for(int i=0; i< InpVector.size();i++){
//                 OutVector[i] = a*InpVector[i];
//             }
//     }

//     else{
//         /* Handle Error*/
//     }

// }

// template <typename T>
// requires MyVector<T>
// void sVelemul (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector){

//     if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){
 
//             for(int i=0; i< InpVector1.size();i++){
//                 OutVector[i] = InpVector1[i]*InpVector2[i];
//             }
//     }

//     else{
//         /* Handle Error*/
//     }

// }

// template <typename T>
// requires MyVector<T>
// auto sVcheckelem(vector<T>& InpVector1,T ele){
    
//      for(auto i:InpVector1){
//         if (i==ele){
//             return 1;
//         }
//      }

//      return 0;

// }

// template <typename T>
// requires MyVector<T>
// void sVelediv (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector){

//     if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){
 

//             if (sVcheckelem(InpVector2,0)){
//                 for(int i=0; i< InpVector1.size();i++){
//                     OutVector[i] = InpVector1[i]/InpVector2[i];
//                 }
//             }
//             else{
//                 /*handle Error*/
//             }
//     }

//     else{
//         /* Handle Error*/
//     }

// }


// template <typename T>
// requires MyVector<T>
// void sVaxpby(vector <T>& InpVector1,vector <T>& InpVector2,vector<T>& OutVector,T a,T b){

//      if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){
 
//             for(int i=0; i< InpVector1.size();i++){
//                 OutVector[i] = a*InpVector1[i] + b*InpVector2[i];
//             }
//     }

// }


// template <typename T>
// requires MyVector<T>
// void sVdot (vector<T>& InpVector1,vector<T>& InpVector2,T& value){

//     if((InpVector1.size()==InpVector2.size())){
//         value = 0;
//         for(int i=0;i<InpVector1.size();i++){
//             value+= InpVector1[i]*InpVector2[i];
//         }
//     }

//     else{
//         /* Handle Error*/
//     }

// }

// template <typename T,typename U>
// requires MyVector<T> &&  MyVector2<U>
// void sVnorm (vector<T>& InpVector1,vector<T>& InpVector2,U& norm){

//     if((InpVector1.size()==InpVector2.size())){
//         norm = 0;
//         for(int i=0;i<InpVector1.size();i++){
//             norm+= InpVector1[i]*InpVector1[i];
//         }
//         norm = pow(norm,0.5);
//     }

//     else{
//         /* Handle Error*/
//     }

// }


// template <typename T>
// requires MyVector<T>
// void display(vector<T> InpVector){

//     for(auto i:InpVector ){
//         cout << i << " " ;
//     }
//     cout << endl;
// }


template <typename T,typename U >
requires RuVector<T> && ScalerValue<U> 
void sVax(vector <T>& InpVector,vector <T>& OutVector, U a){

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
void sVelemul (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector){

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
auto sVcheckelem(vector<T>& InpVector1,T ele){
            
            for(auto i:InpVector1){
                if (i==ele){
                    return 1;
                }
            }

            return 0;
        }

template <typename T>
requires RuVector<T>
void sVelediv (vector<T>& InpVector1,vector<T>& InpVector2,vector<T>& OutVector){
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
void sVaxpby(vector <T>& InpVector1,vector <T>& InpVector2,vector<T>& OutVector,T a,T b){

    if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){

            for(int i=0; i< InpVector1.size();i++){
                OutVector[i] = a*InpVector1[i] + b*InpVector2[i];
            }
    }

}


template <typename T>
requires RuVector<T>
void sVdot (vector<T>& InpVector1,vector<T>& InpVector2,T& value){

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
void sVnorm (vector<T>& InpVector1,vector<T>& InpVector2,U& norm){

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
void display(vector<T> InpVector){

    for(auto i:InpVector ){
        cout << i << " " ;
    }
    cout << endl;
}



int main(){


    vector<double> arr = {1,2,3,4,5};
    vector<double> arr2(arr.size(),0);
    sVax(arr,arr2,2);

     vector<double> arr3(arr.size(),0);
    sVelemul(arr,arr2,arr3);

    display(arr);
    display(arr2);
    display(arr3);
}








