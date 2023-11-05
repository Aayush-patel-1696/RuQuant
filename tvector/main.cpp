/*

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

#include <iostream>
#include <vector>
#include <math>

using namespace std;

// vector<double> sVax (vector <double> InpVector,int a){

//     int size = InpVector.size();
//     vector<double> OutVector(size,0);
//     for(int i=0; i< size;i++){

//         OutVector[i] = a*InpVector[i];

//     }

//     return OutVector;

// }

void sVax (vector <double>& InpVector,int a){

    int size = InpVector.size();
    for(int i=0; i< size;i++){

        InpVector[i] = a*InpVector[i];

    }

 
}

void sVax(vector <double>& InpVector,vector <double>& OutVector, int a){

    if(InpVector.size()==OutVector.size()){
 
            for(int i=0; i< InpVector.size();i++){
                OutVector[i] = a*InpVector[i];
            }
    }

    else{
        /* Handle Error*/
    }

}


void sVelemul (vector<double>& InpVector1,vector<double>& InpVector2,vector<double>& OutVector){

    if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){
 
            for(int i=0; i< InpVector1.size();i++){
                OutVector[i] = InpVector1[i]*InpVector2[i];
            }
    }

    else{
        /* Handle Error*/
    }

}

void sVcheckelem(vector<double>& InpVector1,double ele){
    
     for(auto i:InpVector1){
        if (i==ele){
            return 1;
        }
     }

     return 0;

}

void sVelediv (vector<double>& InpVector1,vector<double>& InpVector2,vector<double>& OutVector){

    if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){
 

            if (sVcheckelem(InpVector2,0)){
                for(int i=0; i< InpVector1.size();i++){
                    OutVector[i] = InpVector1[i]/InpVector2[i];
                }
            }
            else{
                /*handle Error*/
            }
    }

    else{
        /* Handle Error*/
    }

}

void sVaxpby(vector <double>& InpVector1,vector <double>& InpVector2,vector<double>& OutVector,int a,int b){

     if((InpVector1.size()==OutVector.size()) && (InpVector2.size()==InpVector1.size())){
 
            for(int i=0; i< InpVector1.size();i++){
                OutVector[i] = a*InpVector1[i] + b*InpVector2[i];
            }
    }

}


void sVdot (vector<double>& InpVector1,vector<double>& InpVector2,double& value){

    if((InpVector1.size()==InpVector2.size())){
        value = 0;
        for(int i=0;i<InpVector1.size();i++){
            value+= InpVector1[i]*InpVector2[i];
        }
    }

    else{
        /* Handle Error*/
    }

}

void sVnorm (vector<double>& InpVector1,vector<double>& InpVector2,double& norm){

    if((InpVector1.size()==InpVector2.size())){
        value = 0;
        for(int i=0;i<InpVector1.size();i++){
            norm+= InpVector1[i]*InpVector1[i];
        }
        norm = pow(norm,0.5)
    }

    else{
        /* Handle Error*/
    }

}


void display(vector<double> InpVector){

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








