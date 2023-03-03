#include <iostream>

using namespace std;

struct Heap{
    int *heapArr;
    int currentHeapSize;
    int maxHeapSize;
};

void heapifyDown(Heap *heap, int i, int n){
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && heap->heapArr[left] > heap->heapArr[largest])
        largest = left;

    if (right <= n && heap->heapArr[right] > heap->heapArr[largest])
        largest = right;

    if (largest != i){
        swap(heap->heapArr[i], heap->heapArr[largest]);
        heapifyDown(heap, largest, n);
    }
    return;
}

void insert(Heap *heap, int key){
    heap->heapArr[++heap->currentHeapSize] = key;
    return;
}

void buildHeap(Heap *heap, int n){
    for (int t = n / 2; t >= 1; t--){
        heapifyDown(heap, t, n);
    }
    return;
}

int extractMax(Heap *&heap){
    int root = heap->heapArr[1];

    swap(heap->heapArr[1], heap->heapArr[heap->currentHeapSize]);

    heap->currentHeapSize--;

    heapifyDown(heap, 1, heap->currentHeapSize);
    return root;
}


Heap *initHeap(){
    Heap *heap = new Heap();
    heap->currentHeapSize = 0;
    heap->maxHeapSize = 64;
    heap->heapArr = new int[heap->maxHeapSize];
    return heap;
}

void printKLargest(Heap *heap, int k) {
    int n = heap->currentHeapSize;
    buildHeap(heap, n);
    for (int t = 0;t<k;t++) {
        cout << extractMax(heap) << " ";
    }
    cout << endl;
    return;
}

int main() {
    Heap *heap = initHeap();
    int k;
    k = 8;

    insert(heap, 1);
    insert(heap, 23);
    insert(heap, 12);
    insert(heap, 9);
    insert(heap, 30);
    insert(heap, 2);
    insert(heap, 50);
    insert(heap, 100);

    printKLargest(heap, k);
}