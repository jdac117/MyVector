#include <iostream>
#include <string>
#include <stdexcept>
#include "myvector.h"

using namespace std;

int main() {
    cout << "MY CUSTOM VECTOR DEMO\n";
    cout << "----------------------\n\n";

    MyVector<int> numbers;

    cout << "Initial size: " << numbers.size() << endl;
    cout << "Initial capacity: " << numbers.capacity() << endl;

    cout << "\nAdding numbers...\n";

    for (int i = 1; i <= 6; i++) {
        numbers.push_back(i * 10); // 10-60 by 10

        cout << "Added " << i * 10
            << " | Size: " << numbers.size()
            << " | Capacity: " << numbers.capacity()
            << endl;
    }

    cout << "\nStored numbers:\n";

    for (size_t i = 0; i < numbers.size(); i++) {
        cout << numbers.at(i) << " ";
    }

    cout << "\n\nTesting element modification...\n";
    numbers.at(0) = 100;
    cout << "First element: " << numbers.at(0) << endl;

    cout << "\nTesting invalid index...\n";

    try {
        cout << numbers.at(20) << endl;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\nTesting with strings...\n";

    MyVector<string> names;

    names.push_back("Alex");
    names.push_back("Jordan");
    names.push_back("Taylor");

    for (size_t i = 0; i < names.size(); i++) {
        cout << names.at(i) << endl;
    }

    return 0;
}
