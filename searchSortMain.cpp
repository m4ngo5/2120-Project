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

// The search functions will repeat each test 'x' times according to the value of the defined constant 'REPS'.
// The time calculations do not seem to work when compiled for Windows.  There is probably a missing system dependency.
#include <chrono>
#define TIME_UNIT nanoseconds
#define TIME_UNIT2 microseconds
#define SEARCH_REPS 5
#define SORT_REPS 5
using namespace std;
using namespace std::chrono;
// Global Variable Declarations
// Declare start and stop time_point variables
high_resolution_clock::time_point start;
high_resolution_clock::time_point stop;

// Declare nanosecond and microsecond timestamp variables
typedef std::chrono::duration<int,std::nano> timestamp;
timestamp time1, time2, time3, time4, time5, time6, avg;
typedef std::chrono::duration<int,std::micro> timestamp2;
timestamp2 time1micro, time2micro, time3micro, time4micro, time5micro, time6micro;

// Counter variable
int count = 0;

// Include language libraries
#include <iostream>
#include <fstream>
#include <cctype>

// Include the search and sort algorithm header files
#include "sortAlgos.h"
#include "searchAlgos.h"

using namespace std;
using namespace std::chrono;

int main(){

    // Instantiate search algorithm object
    searchAlgos startSearches;
	// Run searches a specified number of times
    startSearches.runSearches(SEARCH_REPS);

    // Instantiate sort algorithm object
    sortAlgos startSort;
	// Run sorts a specified number of times
    startSort.sortAll(SORT_REPS);

	// End program
    return 0;
}
