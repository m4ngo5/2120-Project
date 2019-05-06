// sortAlgos.cpp
// 1 - Selection Sort
// 2 - Heap Sort
// 3 - Quick Sort


sortAlgos::sortAlgos(){
}
sortAlgos::~sortAlgos(){
}
void sortAlgos::shuffleArrays(){
    loadArray(sort10, 10, "List10.txt");
    loadArray(sort100, 100, "List100.txt");
    loadArray(sort1000, 1000, "List1000.txt");
    loadArray(sort10000, 10000, "List10000.txt");
    loadArray(sort100000, 100000, "List100000.txt");
    loadArray(sort250000, 250000, "List250000.txt");
}
void sortAlgos::loadArray(int* arr, int cap, const std::string& source){
    ifstream ifs;
    ifs.open(source);
    for(int i = 0; i < cap; i++){
        ifs >> arr[i];
    }
}
void sortAlgos::sortAll(int repetitions){
    ofstream ofs;
    ofs.open("sortResults.csv");
    ofs << "Algorithm,Repetition,List10.txt Time(ns),List10.txt Iterations,List100.txt Time(ns),List100.txt Iterations,List1000.txt Time(ns),List1000.txt Iterations,List10000.txt Times(ns),List10000.txt Iterations,List100000.txt Time(ns),List100000.txt Iterations,List250000.txt Times(ns),List250000.txt Iterations,Avg Time(ns)\n";
    for(int i = 0; i < repetitions; i++){
        ofs << "Selection Sort," << i+1 << ",";
        shuffleArrays();       // load arrays with unsorted data
        selectionSorting(ofs); // sort all 6 arrays and write a line of results to sortResults.csv
    }
    for(int i = 0; i < repetitions; i++){
        ofs << "Heap Sort," << i+1 << ",";
        shuffleArrays();       // load arrays with unsorted data
        heapSorting(ofs);      // sort all 6 arrays and write a line of results to sortResults.csv
    }
    for(int i = 0; i < repetitions; i++){
        ofs << "Quick Sort," << i+1 << ",";
        shuffleArrays();       // load arrays with unsorted data
        quickSorting(ofs);     // sort all 6 arrays and write a line of results to sortResult.csv
    }
    ofs.close();
}
void sortAlgos::selectionSorting(ofstream& ofs){
    // sort List10.txt with selection sort
    start = chrono::high_resolution_clock::now();
    selectionSort(sort10, 10);
    stop = chrono::high_resolution_clock::now();
    time1micro = duration_cast<TIME_UNIT2>(stop - start);
    ofs << time1micro.count() << "," << count << ",";

    // sort List100.txt with selection sort
    start = chrono::high_resolution_clock::now();
    selectionSort(sort100, 100);
    stop = chrono::high_resolution_clock::now();
    time2micro = duration_cast<TIME_UNIT2>(stop - start);
    ofs << time2micro.count() << "," << count << ",";

    // sort List1000.txt with selection sort
    start = chrono::high_resolution_clock::now();
    selectionSort(sort1000, 1000);
    stop = chrono::high_resolution_clock::now();
    time3micro = duration_cast<TIME_UNIT2>(stop - start);
    ofs << time3micro.count() << "," << count << ",";

    // sort List10000.txt with selection sort
    start = chrono::high_resolution_clock::now();
    selectionSort(sort10000, 10000);
    stop = chrono::high_resolution_clock::now();
    time4micro = duration_cast<TIME_UNIT2>(stop - start);
    ofs << time4micro.count() << "," << count << ",";

    // sort List100000.txt with selection sort
    start = chrono::high_resolution_clock::now();
    selectionSort(sort100000, 100000);
    stop = chrono::high_resolution_clock::now();
    time5micro = duration_cast<TIME_UNIT2>(stop - start);
    ofs << time5micro.count() << "," << count << ",";

    // sort List250000.txt with selection sort
    start = chrono::high_resolution_clock::now();
    selectionSort(sort250000, 250000);
    stop = chrono::high_resolution_clock::now();
    time6micro = duration_cast<TIME_UNIT2>(stop - start);
    ofs << time6micro.count() << "," << count << ",";

    // average of the 6 sorts
    ofs << 1.0*(time1micro.count() + time2micro.count() + time3micro.count() + time4micro.count() + time5micro.count() + time6micro.count())/6 << endl;
}
void sortAlgos::heapSorting(ofstream& ofs){
    // sort List10.txt with heap sort
    start = chrono::high_resolution_clock::now();
    heapSort(sort10, 10);
    stop = chrono::high_resolution_clock::now();
    time1 = duration_cast<TIME_UNIT>(stop - start);
    ofs << time1.count() << "," << count << ",";

    // sort List100.txt with heap sort
    start = chrono::high_resolution_clock::now();
    heapSort(sort100, 100);
    stop = chrono::high_resolution_clock::now();
    time2 = duration_cast<TIME_UNIT>(stop - start);
    ofs << time2.count() << "," << count << ",";

    // sort List1000.txt with heap sort
    start = chrono::high_resolution_clock::now();
    heapSort(sort1000, 1000);
    stop = chrono::high_resolution_clock::now();
    time3 = duration_cast<TIME_UNIT>(stop - start);
    ofs << time3.count() << "," << count << ",";

    // sort List10000.txt with heap sort
    start = chrono::high_resolution_clock::now();
    heapSort(sort10000, 10000);
    stop = chrono::high_resolution_clock::now();
    time4 = duration_cast<TIME_UNIT>(stop - start);
    ofs << time4.count() << "," << count << ",";

    // sort List100000.txt with heap sort
    start = chrono::high_resolution_clock::now();
    heapSort(sort100000, 100000);
    stop = chrono::high_resolution_clock::now();
    time5 = duration_cast<TIME_UNIT>(stop - start);
    ofs << time5.count() << "," << count << ",";

    // sort List250000.txt with heap sort
    start = chrono::high_resolution_clock::now();
    heapSort(sort250000, 250000);
    stop = chrono::high_resolution_clock::now();
    time6 = duration_cast<TIME_UNIT>(stop - start);
    ofs << time6.count() << "," << count << ",";
    
    // average of the 6 sorts
    ofs << 1.0*(time1.count() + time2.count() + time3.count() + time4.count() + time5.count() + time6.count())/6 << endl;
}
void sortAlgos::quickSorting(ofstream& ofs){
    // sort List10.txt with quick sort
    start = chrono::high_resolution_clock::now();
    count = 0;
    count = quickSort(sort10, 0, 9);
    stop = chrono::high_resolution_clock::now();
    time1 = duration_cast<TIME_UNIT>(stop - start);
    ofs << time1.count() << "," << count << ",";
    
    // sort List100.txt with quick sort
    start = chrono::high_resolution_clock::now();
    count = 0;
    count = quickSort(sort100, 0, 99);
    stop = chrono::high_resolution_clock::now();
    time2 = duration_cast<TIME_UNIT>(stop - start);
    ofs << time2.count() << "," << count << ",";

    // sort List1000.txt with quick sort
    start = chrono::high_resolution_clock::now();
    count = 0;
    count = quickSort(sort1000, 0, 999);
    stop = chrono::high_resolution_clock::now();
    time3 = duration_cast<TIME_UNIT>(stop - start);
    ofs << time3.count() << "," << count << ",";

    // sort List10000.txt with quick sort
    start = chrono::high_resolution_clock::now();
    count = 0;
    count = quickSort(sort10000, 0, 9999);
    stop = chrono::high_resolution_clock::now();
    time4 = duration_cast<TIME_UNIT>(stop - start);
    ofs << time4.count() << "," << count << ",";

    // sort List100000.txt with quick sort
    start = chrono::high_resolution_clock::now();
    count = 0;
    count = quickSort(sort100000, 0, 99999);
    stop = chrono::high_resolution_clock::now();
    time5 = duration_cast<TIME_UNIT>(stop - start);
    ofs << time5.count() << "," << count << ",";

    // sort List250000.txt with quick sort
    start = chrono::high_resolution_clock::now();
    count = 0;
    count = quickSort(sort250000, 0, 249999);
    stop = chrono::high_resolution_clock::now();
    time6 = duration_cast<TIME_UNIT>(stop - start);
    ofs << time6.count() << "," << count << ",";   

    // average of the 6 sorts
    ofs << 1.0*(time1.count() + time2.count() + time3.count() + time4.count() + time5.count() + time6.count())/6 << endl;
}
int sortAlgos::selectionSort(int arr[], int arrSize){
    int min, minPos;
    count = 0;
    for(int i = 0; i < (arrSize-1); i++){
        minPos = i;
        min = arr[i];
        for(int j = i+1; j < arrSize; j++){
            if(arr[j] < min){
                minPos = j;
                min = arr[j];
            }
            count++; // counts the number of iterations
        }
        arr[minPos] = arr[i];
        arr[i] = min;
    }
    return count;
}
int sortAlgos::heapSort(int arr[], int arrSize){
    // create a maxheap from the input array
    count = 0;
    for(int i = arrSize / 2 - 1; i >= 0; i--){
        heapify(arr, arrSize, i);
    }

    // extract the max (root) from the heap and move it to the end then rebuild the remaining heap
    for(int i = arrSize - 1; i >= 0; i--){
        // swap max to end
        swap(arr[0], arr[i]);

        // call heapify to fix heap
        heapify(arr, i, 0);
    }
    return count;
}
void sortAlgos::heapify(int arr[], int heapSize, int root){
    // largest, root, left, and right are indexes of elements in the heap
    int largest = root;        // initialize largest as root
    int left = 2*root + 1;     // finds the left "node" of a given root
    int right = 2*root + 2;    // finds the right "node" of a given root
    
    // checks if the left or right node is larger than the given root
    if(left < heapSize && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < heapSize && arr[right] > arr[largest]){
        largest = right;
    }

    // if the one of the nodes was larger than the root, then swap it with the root
    if(largest != root){
        swap(arr[root], arr[largest]);
        heapify(arr, heapSize, largest);
    }
    count++;     // counts the number of heapify calls
}
int sortAlgos::quickSort(int arr[], int low, int high){
    if(low < high){
        int partIndex = partition(arr, low, high);
        quickSort(arr, low, partIndex - 1);
        quickSort(arr, partIndex + 1, high);
    }
    return count;
}
int sortAlgos::partition(int arr[], int low, int high){
    int pivot = arr[high];  // set pivot
    int i = (low - 1);      // index of smaller element
    count++;                // count the number of quickSort calls
    for(int j = low; j <= high - 1; j++){
        // if current element is smaller than of equal to pivot
        if(arr[j] <= pivot){
            i++;    // increment indox of smaller element
            flip(&arr[i], &arr[j]);
        }
    }
    flip(&arr[i + 1], &arr[high]);
    return(i + 1);
}
void sortAlgos::flip(int* a, int* b) {
    int t = *a; 
    *a = *b; 
    *b = t; 
}
void sortAlgos::printArray(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << "\t";
        if(i % 9 == 0) cout << endl;
    }
    cout << endl;
}
