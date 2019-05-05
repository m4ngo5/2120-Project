// sortAlgos.cpp
// 1 - Selection Sort
// 2 - Heap Sort
// 3 - Quick Sort

searchAlgos::searchAlgos(){

}
searchAlgos::~searchAlgos(){
}
void searchAlgos::runSearches(int repetitions){
    // load primes numbers from primes.txt into primesArr
    loadPrimes(250000);

    //Create output filestream
    ofstream ofs;
    
    //open output filestream object to searchResults.csv and overwrite any existing data
    ofs.open("searchResults.csv");
    
    //write column headers to searchResults.csv
    ofs << "Algorithm,Array Size,Repetition,Elem 1,Elem 1 Time (ns),Elem 1 Iterations,Elem 2,Elem 2 Time (ns),Elem 2 Iterations,Elem 3,Elem 3 Time (ns),Elem 3 Iterations,Avg (ns)" << endl;
    ofs.close();
    
    //Binary Search Algorithm Searches
    //usage: binarySearchThree(primesToSearch, searchPrime1, searchPrime2, searchPrime3)
    binary(repetitions, 10, 2, 5, 7);
    binary(repetitions, 100, 3, 229, 523);
    binary(repetitions, 1000, 3, 3571, 7907);
    binary(repetitions, 10000, 3, 48611, 104723);
    binary(repetitions, 100000, 3, 611953, 1299689);
    binary(repetitions, 250000, 3, 1655131, 3497849);

    //Linear Search Algorithm Searches
    //usage: linear(repetitions, primesToSearch, searchPrime1, searchPrime2, searchPrime3)
    linear(repetitions, 10, 2, 5, 7);
    linear(repetitions, 100, 3, 229, 523);
    linear(repetitions, 1000, 3, 3571, 7907);
    linear(repetitions, 10000, 3, 48611, 104723);
    linear(repetitions, 100000, 3, 611953, 1299689);
    linear(repetitions, 250000, 3, 1655131, 3497849);

    //Interpolation Search Algorithm Searches
    //usage: binarySearchThree(primesToSearch, searchPrime1, searchPrime2, searchPrime3)
    interpolation(repetitions, 10, 2, 5, 7);
    interpolation(repetitions, 100, 3, 229, 523);
    interpolation(repetitions, 1000, 3, 3571, 7907);
    interpolation(repetitions, 10000, 3, 48611, 104723);
    interpolation(repetitions, 100000, 3, 611953, 1299689);
    interpolation(repetitions, 250000, 3, 1655131, 3497849);
}
void searchAlgos::binary(int repetitions, int arrSize, int a, int b, int c){
    //Write algorithm run information to csv
    ofstream ofs;
    ofs.open("searchResults.csv", std::ofstream::app);
    for(int i = 0; i < repetitions; i++){
        ofs << "Binary Search," << arrSize << "," << i+1 << ",";
        
        //search a
        count = binarySearch(primesArr, arrSize, a);
        time1 = duration_cast<TIME_UNIT>(stop - start);
        ofs << a << "," << time1.count() << "," << count << ",";
        
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
int searchAlgos::binarySearch(int arr[], int arrSize, int elem){
    start = chrono::high_resolution_clock::now();
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
void searchAlgos::linear(int repetitions, int arrSize, int a, int b, int c){
    ofstream ofs;
    ofs.open("searchResults.csv", std::ofstream::app);
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
int searchAlgos::linearSearch(int arr[], int arrSize, int elem){
    start = chrono::high_resolution_clock::now();
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
void searchAlgos::interpolation(int repetitions, int arrSize, int a, int b, int c){
    //Write algorithm run information to csv
    ofstream ofs;
    ofs.open("searchResults.csv", std::ofstream::app);
    for(int i = 0; i < repetitions; i++){
        ofs << "Interpolation Search," << arrSize << "," << i+1 << ",";
        
        //search a
        count = interpolationSearch(primesArr, arrSize, a);
        time1 = duration_cast<TIME_UNIT>(stop - start);
        ofs << a << "," << duration_cast<nanoseconds>(stop-start).count() << "," << count << ",";
        
        //search b
        count = interpolationSearch(primesArr, arrSize, b);
        time2 = duration_cast<TIME_UNIT>(stop - start);
        ofs << b << "," << time2.count() << "," << count << ",";
        
        //search c
        count = interpolationSearch(primesArr, arrSize, c);
        time3 = duration_cast<TIME_UNIT>(stop - start);
        ofs << c << "," << time3.count() << "," << count << ",";

        //average
        ofs << 1.0*(time1.count() + time2.count() + time3.count())/3 << endl;
    }    
    ofs.close();
}
int searchAlgos::interpolationSearch(int arr[], int arrSize, int elem){
    start = chrono::high_resolution_clock::now();
    int left = 0, right = arrSize-1, pos;
    count = 1;
    while(left <= right && elem >= arr[left] && elem <= arr[right]){
        if(left == right){
            if(arr[left] == elem){
                stop = chrono::high_resolution_clock::now();
                return count;
            }
            stop = chrono::high_resolution_clock::now();  
            return -1;
        }
        pos = left + ( ( (double)(right - left) / (arr[right] - arr[left])) * (elem - arr[left]));
        if(arr[pos] == elem){
            stop = chrono::high_resolution_clock::now();
            return count; 
        }
        if(arr[pos] < elem) left = pos + 1;
        else{
            right = pos - 1;
        }
        count++;
    }
    stop = chrono::high_resolution_clock::now();  
    return -1;
}
void searchAlgos::loadPrimes(int loadSize) {
    //Open filestream to primes.txt and read first 250000 primes into primesArr
    ifstream fin;
    fin.open("primes.txt");
    for(int i = 0; i < loadSize; i++){
        fin >> primesArr[i];
    }
    fin.close();
}