#include "ArrayClass.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int ArrayClass::left_child(int i) {
    return (i<<1) + 1;
}

int ArrayClass::right_child(int i) {
    return (i<<1) + 2;
}

ArrayClass::ArrayClass(int n) {
    size = n;
    arr = new int[n];
}
ArrayClass::~ArrayClass() {
    delete[] arr;
}

void ArrayClass::heapify(int n, int i) {
    int left_i = left_child(i);
    int right_i = right_child(i);
    int max = i;
    if(left_i < n && arr[left_i] > arr[max])
        max = left_i;
    if(right_i < n && arr[right_i] > arr[max])
        max = right_i;
    if(max != i) {
        std::swap(arr[i], arr[max]);
        heapify(n, max);
    }
}

void ArrayClass::build_heap() {
    for(int i = size/2 - 1; i >= 0;i--)
        heapify(size, i);
}

void ArrayClass::insertionSort() {
    for(int j = 1;j < size;j++){
        int element = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > element){
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = element;
    }
}

ArrayClass merge(int arr[], int p, int q, int r) {
    int l_array[q - p + 1];
    int r_array[r - q];

    for (int i = 0; i < q - p + 1; ++i) {
        l_array[i] = arr[i + p];
    }
    for (int i = 0; i < r - q; ++i) {
        r_array[i] = arr[i + q + 1];
    }
    int L = 0, R = 0;
    int i = p;
    while(L < q - p + 1&& R < r - q){
        if(l_array[L] < r_array[R]){
            arr[i] = l_array[L];
            L++;
        }
        else{
            arr[i] = r_array[R];
            R++;
        }
        i++;
    }
    while(L < q - p + 1){
        arr[i] = l_array[L];
        L++;
        i++;
    }
    while(R < r - q){
        arr[i] = r_array[R];
        R++;
        i++;
    }
}

void merge_sort(int arr[], int p, int r){
    if(p < r) {
        int q = p + (r - p) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void ArrayClass::mergeSort(){
    merge_sort(arr, 0, size - 1);
}

void ArrayClass::heapSort() {
    build_heap();

    for (int i = size - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(i, 0);
    }
}


void ArrayClass::create_random() {

    srand((unsigned) time(0));

    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 100) + 1;
    }
}

void ArrayClass::permutate() {
        std::random_shuffle(arr, arr + size);
}

void ArrayClass::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

