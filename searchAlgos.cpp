// searchAlgos.cpp
// 1 - Binary Search
// 2 - Linear Search
// 3 - Interpolation Search

//Written for C++99

#include <iostream>
#include <fstream>
#include <cctype>
#include <chrono>
#define TIME_UNIT nanoseconds
#define REPS 3
using namespace std;
using namespace std::chrono;

//Global Variable Declarations
high_resolution_clock::time_point start;
high_resolution_clock::time_point stop;
int primesArr[250000];
int count = 0;
void loadPrimes(int);
typedef std::chrono::duration<int,std::nano> timestamp;
timestamp time1, time2, time3, avg;

//Function declarations
void binary(int repetitions, int arrSize, int a, int b, int c);
void linear(int repetitions, int arrSize, int a, int b, int c);
int binarySearch(int arr[], int arrSize, int elem);     //returns count of iterations
int linearSearch(int arr[], int arrSize, int elem);     //returns count of iterations

int main(){
    
    //Create output filestream to results.txt
    loadPrimes(250000);
    
    ofstream ofs;
    ofs.open("results.csv");
    //write column headers to csv
    ofs << "Algorithm,Array Size,Repetition,Elem 1,Elem 1 Time (ns),Elem 1 Iterations,Elem 2,Elem 2 Time (ns),Elem 2 Iterations,Elem 3,Elem 3 Time (ns),Elem 3 Iterations,Avg (ns)" << endl;
    ofs.close();

//Binary Search Algorithm Searches
    //usage: binarySearchThree(primesToSearch, searchPrime1, searchPrime2, searchPrime3)
    binary(REPS, 10, 2, 5, 7);
    binary(REPS, 100, 3, 229, 523);
    binary(REPS, 1000, 3, 3571, 7907);
    binary(REPS, 10000, 3, 48611, 104723);
    binary(REPS, 100000, 3, 611953, 1299689);
    binary(REPS, 250000, 3, 1655131, 3497849);

//Linear Search Algorithm Searches
    //usage: linear(repetitions, primesToSearch, searchPrime1, searchPrime2, searchPrime3)
    linear(REPS, 10, 2, 5, 7);
    linear(REPS, 100, 3, 229, 523);
    linear(REPS, 1000, 3, 3571, 7907);
    linear(REPS, 10000, 3, 48611, 104723);
    linear(REPS, 100000, 3, 611953, 1299689);
    linear(REPS, 250000, 3, 1655131, 3497849);
    return 0;
}


void binary(int repetitions, int arrSize, int a, int b, int c){
    //Write algorithm run information to csv
    ofstream ofs;
    ofs.open("results.csv", std::ofstream::app);
    for(int i = 0; i < repetitions; i++){
        ofs << "Binary Search," << arrSize << "," << i+1 << ",";
        
        //search a
        count = binarySearch(primesArr, arrSize, a);
        time1 = duration_cast<TIME_UNIT>(stop - start);
        ofs << a << "," << duration_cast<nanoseconds>(stop-start).count() << "," << count << ",";
        
        //search b
        count = binarySearch(primesArr, arrSize, b);
        time2 = duration_cast<TIME_UNIT>(stop - start);
        ofs << b << "," << time2.count() << "," << count << ",";
        
        //search c
        count = binarySearch(primesArr, arrSize, c);
        time3 = duration_cast<TIME_UNIT>(stop - start);
        ofs << c << "," << time3.count() << "," << count << ",";

        //average
        ofs << 1.0*(time1.count() + time2.count() + time3.count())/3 << endl;
    }    
    ofs.close();
}
int binarySearch(int arr[], int arrSize, int elem){
    start = high_resolution_clock::now();
    int left = 0, right = arrSize-1, mid;
    count = 1;
    while(left <= right){
        mid = left + (right - 1)/2; //integer division takes the floor
        if(elem > arr[mid]) left = mid + 1;
        else if(elem < arr[mid]) right = mid - 1;
        else if(elem == arr[mid]){
            stop = chrono::high_resolution_clock::now();    
            return count;
        }
        count++;
    }  
    stop = chrono::high_resolution_clock::now();
    return -1;
}
void linear(int repetitions, int arrSize, int a, int b, int c){
    ofstream ofs;
    ofs.open("results.csv", std::ofstream::app);
    for(int i = 0; i < repetitions; i++){    
        //Write algorithm run information to csv
        ofs << "Linear Search," << arrSize << "," << i+1 << ",";
        
        //search a
        count = linearSearch(primesArr, arrSize, a);
        time1 = duration_cast<TIME_UNIT>(stop - start);
        ofs << a << "," << duration_cast<nanoseconds>(stop-start).count()/*time1.count()*/ << "," << count << ",";
        
        //search b
        count = linearSearch(primesArr, arrSize, b);
        time2 = duration_cast<TIME_UNIT>(stop - start);
        ofs << b << "," << time2.count() << "," << count << ",";
        
        //search c
        count = linearSearch(primesArr, arrSize, c);
        time3 = duration_cast<TIME_UNIT>(stop - start);
        ofs << c << "," << time3.count() << "," << count << ",";

        //average
        ofs << 1.0*(time1.count() + time2.count() + time3.count())/3 << endl;
    }
    ofs.close();
}
int linearSearch(int arr[], int arrSize, int elem){
    start = high_resolution_clock::now();
    int i;
    for(i = 0; i < arrSize; i++){
        if(arr[i] == elem){
            stop = chrono::high_resolution_clock::now();
            return i+1;
        }
    }
    stop = chrono::high_resolution_clock::now();
    return -1;
}
void loadPrimes(int loadSize) {
    //Open filestream to primes.txt and read first 250000 primes into primesArr
    ifstream fin;
    fin.open("primes.txt");
    for(int i = 0; i < loadSize; i++){
        fin >> primesArr[i];
    }
    fin.close();
}