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
        void bubbleSort();
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

void Array::bubbleSort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
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
    
    myArray.bubbleSort();
    
    myArray.printArray();
    
    return 0;
}
