#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myArray;
    myArray.push_back(1);
    myArray.push_back(2);
    myArray.push_back(3);
    for (int i = 0; i < myArray.size(); i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;
    return 0;
}
