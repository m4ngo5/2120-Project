// searchAlgos.cpp
// 1 - Binary Search
// 2 - Linear Search
// 3 - Interpolation Search

#ifndef SEARCHALGOS_H
#define SEARCHALGOS_H

#include <iostream>
#include <fstream>
#include <cctype>
#include <chrono>
using namespace std;
using namespace std::chrono;

class searchAlgos{
    private:
        int primesArr[250000];
        void loadPrimes(int loadSize);
        int binarySearch(int arr[], int arrSize, int elem);             //returns count of iterations
        int linearSearch(int arr[], int arrSize, int elem);             //returns count of iterations
        int interpolationSearch(int arr[], int arrSize, int elem);      //returns count of iterations
    public:
        searchAlgos();
        ~searchAlgos();
        void runSearches(int repetitions);
        void binary(int repetitions, int arrSize, int a, int b, int c);
        void linear(int repetitions, int arrSize, int a, int b, int c);
        void interpolation(int repetitions, int arrSize, int a, int b, int c);
};

#include "searchAlgos.cpp"
#endif