//  Name: Andrei Modiga
//  Assignment number: 5
//  Assignment: Sort Comparison
//  File name: compare.cpp
//  Date last modified: November 15, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment. 


#include <iostream>
#include <algorithm> 
#include <vector>   
#include "Stopwatch.h"


// Insertion sort
void insertionSort(std::vector<int>& a) {
    int size = a.size();

    for (int i = 1; i < size; i++) {
        int j = i;

        while (j > 0 && a[j] < a[j - 1]) {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;

        }
    }
}

// Exchange sort
void exchangeSort(std::vector<int> & a) {

    int i, j;
    int temp;   // holding variable
    int numLength = a.size();

    for (i = 0; i < (numLength - 1); i++) {   // element to be compared
    
        for (j = (i + 1); j < numLength; j++) {  // rest of the elements
    
            if (a[i] < a[j]) {         // descending order
                temp = a[i];          // swap
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return;
}


// Selection sort
void selectionSort(std::vector<int> & a) {
    int size = a.size();

    for (int i = 0; i < size; i++) {
        int min = i;
        // To sort in descending order, change > to < in this line.
        // Select the minimum element in each loop.
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        } 
        // put min at the correct position
        if (min != i) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}


// Heapsort
void heapify(std::vector<int> & a, int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest]) {
        largest = l;
    }
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void heapSort(std::vector<int>& v) {
    int size = v.size();
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(v, size, i);
    }
    // Heap sort
    for (int i = size - 1; i >= 0; i--)
    {
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;
        heapify(v, i, 0);  // Heapify root element to get highest element at root again
    }
}

// Quicksort
// function to rearrange array (find the partition point)
int partition(std::vector<int> & a, int low, int high) {
    // select the rightmost element as pivot
    int pivot = a[high];
    // pointer for greater element
    int i = low - 1;

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            // swap element at i with element at j
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    // swap pivot with the greater element at i
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    // return the partition point
    return i + 1;
}

void quick_sort(std::vector<int>& a, int low, int high)
{
    if (low < high) {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int p = partition(a, low, high);
        // recursive call on the left of pivot
        quick_sort(a, low, p - 1);
        // recursive call on the right of pivot
        quick_sort(a, p + 1, high);
    }
}

// quick sort Driver
void quickSort(std::vector<int> & a) {
    // perform quicksort on data
    quick_sort(a, 0, a.size() - 1);
}


// TestStdSortTime
void testStdSort(std::vector<int>& a) {
    std::vector<int> v_copy = a;
    Stopwatch timer;
    timer.start();
    std::sort(v_copy.begin(), v_copy.end());
    timer.stop();
    std::cout << "Time: " << timer.elapsed() << std::endl;
}

// TestSortedTime
void testSort(std::vector<int> & a, void (*sort)(std::vector<int>&)) {
    std::vector<int> v_copy = a;
    Stopwatch timer;
    timer.start();
    sort(v_copy);
    timer.stop();
    std::cout << "Time: "<< timer.elapsed() << std::endl;
}


void Sorting(int n) {
    std::cout << "Test number 3 out of 3: " << n << std::endl;

    std::vector<int> a;
    for (int i = 0; i < n; i++) {
        a.push_back(rand() % 100000); // Random Arr
    }
    //StdSortTest
    std::cout <<"Standard Sort"<< std::endl;
    testStdSort(a);
    //SelectionSortTest
    std::cout <<"Selection Sort"<< std::endl;
    testSort(a, selectionSort);
    //InsertionSortTest
    std::cout <<"Insertion Sort"<< std::endl;
    testSort(a, insertionSort);
    //ExchangeSortTest
    std::cout <<"Exchange Sort"<< std::endl;
    testSort(a, exchangeSort);
    //HeapSortTest
    std::cout <<"Heap Sort"<< std::endl;
    testSort(a, heapSort);
    //QuickSortTest
    std::cout <<"Quick Sort"<< std::endl;
    testSort(a, quickSort);
}

int main() {
    Sorting(10);
    Sorting(100);
    Sorting(1000);
    Sorting(10000);
    Sorting(100000);
}