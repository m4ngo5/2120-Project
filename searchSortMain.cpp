// searchSortMain.cpp
// This program executes 3 search algorithms and 3 sorting algorithms and measures their time complexity using clocks and counters.

// The three search algorithms are:
// 1 - Binary Search
// 2 - Linear Search
// 3 - Interpolation Search

// The three sorting algorithms are:
// 1 - Selection Sort
// 2 - Heap Sort
// 3 - Quick Sort

// The search functions return the count of search iterations, rather than the position of a found element.
// The search functions return -1 if the element is not found.
// The search functions will repeat each test 'x' times according to the value of the defined constant 'REPS'.
// The time calculations do not seem to work when compiled for Windows.  There is probably a missing system dependency.
#include <chrono>
#define TIME_UNIT nanoseconds
#define SEARCH_REPS 3
#define SORT_REPS 1
using namespace std;
using namespace std::chrono;
//Global Variable Declarations
high_resolution_clock::time_point start;
high_resolution_clock::time_point stop;
//int primesArr[250000];
int count = 0;
//void loadPrimes(int);
typedef std::chrono::duration<int,std::nano> timestamp;
timestamp time1, time2, time3, time4, time5, time6, avg;

#include <iostream>
#include <fstream>
#include <cctype>

#include "sortAlgos.h"
#include "searchAlgos.h"

using namespace std;
using namespace std::chrono;



int main(){

    // Search Algorithms
    //searchAlgos startSearches;
    //startSearches.runSearches(SEARCH_REPS);

    // Sort Algorithms
    sortAlgos startSort;
    startSort.sortAll(SORT_REPS);

    return 0;
}
