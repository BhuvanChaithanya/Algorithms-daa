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
        void printArray();
};

void Array::addElement(int element) {
            if (size == capacity) {
                cout << "Array is full" << endl;
                return;
            }
            arr[size] = element;
            size++;
        }

void Array::printArray()
{
    for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
}

int main() {
    Array myArray(5);
    myArray.addElement(1);
    myArray.addElement(2);
    myArray.addElement(3);
    myArray.printArray();
    return 0;
}
