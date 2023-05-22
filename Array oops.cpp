#include <iostream>
using namespace std;

class Array {
    private:
        int *arr;
        int size;
        int capacity;
    public:
        Array(int capacity) {
            this->capacity = capacity;
            arr = new int[capacity];
            size = 0;
        }
        void addElement(int element);
        void insertAtBegin(int element);
        void insertAtPosition(int element, int position);
        void printArray();
        void selectionSort();
        void mergeSort(int low, int high);
        void merge(int low, int mid, int high);
};

void Array::addElement(int element) {
    if (size == capacity) {
        cout << "Array is full" << endl;
        return;
    }
    arr[size] = element;
    size++;
}

void Array::printArray() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Array::insertAtBegin(int element) {
    if (size == capacity) {
        cout << "Array is full" << endl;
        return;
    }
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = element;
    size++;
}

void Array::insertAtPosition(int element, int position) {
    if (size == capacity) {
        cout << "Array is full" << endl;
        return;
    }
    if (position < 0 || position > size) {
        cout << "Invalid position" << endl;
        return;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i-1];
    }
    arr[position] = element;
    size++;
}

void Array::selectionSort() {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}
void Array::mergeSort(int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        
        merge(low, mid, high);
    }
}
void Array::merge(int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    
    int left[n1], right[n2];
    
    for (int i = 0; i < n1; i++) {
        left[i] = arr[low + i];
    }
    
    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = low;
    
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        
        k++;
    }
    
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
int main() {
    Array myArray(100);
    myArray.addElement(1);
    myArray.addElement(2);
    myArray.addElement(3);
    myArray.insertAtBegin(5);
    myArray.insertAtPosition(9,2);
    
    myArray.printArray();
    
    myArray.mergeSort(0,4);
    
    myArray.printArray();
    
    return 0;
}
