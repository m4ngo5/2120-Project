// sortAlgos.cpp
// 1 - Selection Sort
// 2 - Heap Sort
// 3 - Quick Sort

#ifndef SORTALGOS_H
#define SORTALGOS_H

#include <iostream>
#include <fstream>
#include <cctype>
#include <chrono>
using namespace std;
using namespace std::chrono;

class sortAlgos{
    private:
        int sort10[10];
        int sort100[100];
        int sort1000[1000];
        int sort10000[10000];
        int sort100000[100000];
        int sort250000[250000];
        void loadArray(int* arr, int cap, const std::string& source);
        int selectionSort(int arr[], int arrSize);
        int heapSort(int arr[], int arrSize);
        int quickSort(int arr[], int low, int high);
        void heapify(int arr[], int heapSize, int root);
        int partition(int arr[], int low, int high);
        void flip(int* a, int* b);
        void printArray(int arr[], int arrSize); // for debugging and testing correct implementation of each sorting algorithm
    public:
        sortAlgos();
        ~sortAlgos();
        void shuffleArrays();
        void sortAll(int repetitions);
        void selectionSorting(ofstream&);
        void heapSorting(ofstream&);
        void quickSorting(ofstream&);
};
#include "sortAlgos.cpp"
#endif