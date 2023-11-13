#include<iostream>
#include <thread>
#include<vector>
#include <algorithm>

using namespace std;



// void pfill(vector<int> &array,int i){
//     fill(array.begin() +  i*1000/4 , array.begin() + (i+1)*(1000/4), i);
// }


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

template <typename T,typename U >
requires RuVector<T> && ScalerValue<U> 
void sVax(vector <T>& InpVector,vector <T>& OutVector, U a,int start,int end){

    if(InpVector.size()==OutVector.size()){
           
            for(int i= start; i< end;i++){
                OutVector[i] = a*InpVector[i];
            }
    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

}

template <typename T,typename U >
requires RuVector<T> && ScalerValue<U> 
void tVax(vector <T>& InpVector,vector <T>& OutVector, U a){

    if(InpVector.size()==OutVector.size()){
 
            size_t num_threads = 4;
            size_t chunk_size = InpVector.size() / num_threads;

            // Create a vector to store thread objects
            thread tarray[4];

            // Launch threads to perform vector scalar multiplication on different chunks
            for (int i = 0; i < num_threads; ++i) {
                size_t start = i * chunk_size;
                size_t end = (i == num_threads - 1) ? InpVector.size() : (i + 1) * chunk_size;
                tarray[i] = thread(sVax<T,U>, ref(InpVector),ref(OutVector), a, start, end);
            }

            // Join the threads to wait for them to complete
            for(int i=0;i<4;i++){
            if(tarray[i].joinable())
                tarray[i].join();
            }


    }

    else{
        throw std::invalid_argument("Input and output vector sizes must be the same.");
    }

}

template <typename T>
// requires RuVector<T>
void display(vector<T>& InpVector){

    for(auto i:InpVector ){
        cout << i << " " ;
    }
    cout << endl;
}





int main(){


    vector<double> arr = {1,2,3,4,5,8,9,10,11,12};
    vector<double> arr2(arr.size(),0);
    tVax(arr,arr2,2.0);

    display(arr2);

    return 0;

}

//g++-10 -std=c++2a main_thread.cpp -o out -lpthread

