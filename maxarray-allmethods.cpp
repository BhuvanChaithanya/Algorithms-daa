#include <iostream>
using namespace std;
#include <limits.h>
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
        int getSize() { // Function added to retrieve the size of the array
        return size;
    }
        void addElement(int element);
        void insertAtBegin(int element);
        void insertAtPosition(int element, int position);
        void printArray();
        void selectionSort();
        void bubbleSort();
        void insertionSort();
        void mergeSort(int low, int high);
        void merge(int low, int mid, int high);
        int kadanesAlgorithm();
        int bruteForceAlgorithm();
         struct SubarrayInfo {
        int start;
        int end;
        int sum;

        SubarrayInfo(int start, int end, int sum) : start(start), end(end), sum(sum) {}
    };

    SubarrayInfo maxSubarray(int low, int high);
    SubarrayInfo maxSubarrayHelper(int low, int high);
        
};
Array::SubarrayInfo Array::maxSubarray(int low, int high) {
    SubarrayInfo result = maxSubarrayHelper(low, high);
    return result;
}

Array::SubarrayInfo Array::maxSubarrayHelper(int low, int high) {
    // Base case: Only one element
    if (low == high) {
        return SubarrayInfo(low, high, arr[low]);
    }

    // Divide the array into two halves
    int mid = low + (high - low) / 2;

    // Find the maximum subarray in the left half
    SubarrayInfo leftMax = maxSubarrayHelper(low, mid);

    // Find the maximum subarray in the right half
    SubarrayInfo rightMax = maxSubarrayHelper(mid + 1, high);

    // Find the maximum subarray that crosses the middle
    int leftSum = INT_MIN;
    int sum = 0;
    int leftIndex = mid;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            leftIndex = i;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;
    int rightIndex = mid + 1;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            rightIndex = i;
        }
    }

    // Calculate the sum of the maximum subarray that crosses the middle
    int crossSum = leftSum + rightSum;

    // Compare the three subarrays and return the maximum
    if (leftMax.sum >= rightMax.sum && leftMax.sum >= crossSum) {
        return leftMax;
    } else if (rightMax.sum >= leftMax.sum && rightMax.sum >= crossSum) {
        return rightMax;
    } else {
        return SubarrayInfo(leftIndex, rightIndex, crossSum);
    }
}
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
void Array::bubbleSort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void Array::insertionSort() {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
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
int Array::kadanesAlgorithm() {
    int maxSum = arr[0];
    int currentSum = arr[0];
    
    for (int i = 1; i < size; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}
int Array::bruteForceAlgorithm() {
    int maxSum = arr[0];

    for (int i = 0; i < size; i++) {
        int currentSum = 0;

        for (int j = i; j < size; j++) {
            currentSum += arr[j];
            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum;
}
int main() {
    Array myArray(100);
    myArray.addElement(-2);
    myArray.addElement(1);
    myArray.addElement(-3);
    myArray.addElement(4);
    myArray.addElement(-1);
    myArray.addElement(2);
    myArray.addElement(1);
    myArray.addElement(-5);
    myArray.addElement(4);

    myArray.printArray();

    Array::SubarrayInfo maxSubarray = myArray.maxSubarray(0, myArray.getSize() - 1);
    cout << "Maximum Subarray Sum: " << maxSubarray.sum << endl;
    cout << "Start Index: " << maxSubarray.start << endl;
    cout << "End Index: " << maxSubarray.end << endl;

    return 0;
}




