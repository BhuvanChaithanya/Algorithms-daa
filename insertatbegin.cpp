#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myArray;
    myArray.insert(myArray.begin(), 3);
    myArray.insert(myArray.begin(), 2);
    myArray.insert(myArray.begin(), 1);
    for (int i = 0; i < myArray.size(); i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;
    return 0;
}
