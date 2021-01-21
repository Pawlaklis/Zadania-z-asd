
#ifndef Z1_ARRAYCLASS_H
#define Z1_ARRAYCLASS_H


class ArrayClass {
public:
    int size;
    int *arr;

    ArrayClass(int n);
    ~ArrayClass();

    int left_child(int i);

    int right_child(int i);

    void heapify(int i, int n);

    void build_heap();


    void insertionSort();

    void mergeSort();

    void heapSort();

    void create_random();

    void permutate();

    void print();
};


#endif //Z1_ARRAYCLASS_H
