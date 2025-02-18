#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Contact {
    string name;
    string phone;
};

int binarySearch(vector<Contact>& contacts, string target) {
    int low = 0, high = contacts.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (contacts[mid].name == target) {
            return mid;
        } else if (contacts[mid].name < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<Contact> contacts = {
        {"Alice", "123-456-7890"},
        {"Bob", "234-567-8901"},
        {"Charlie", "345-678-9012"},
        {"David", "456-789-0123"}
    };

    string nameToFind;
    cout << "Enter the name to search for: ";
    cin >> nameToFind;

    int index = binarySearch(contacts, nameToFind);
    if (index != -1) {
        cout << "Found " << contacts[index].name << " - Phone: " << contacts[index].phone << endl;
    } else {
        cout << "Contact not found.\n";
    }
    return 0;
}


#include <iostream>
#include <stack>
using namespace std;

void decimalToBinary(int number) {
    stack<int> binaryStack;
    while (number > 0) {
        binaryStack.push(number % 2);
        number /= 2;
    }
    cout << "Binary representation: ";
    while (!binaryStack.empty()) {
        cout << binaryStack.top();
        binaryStack.pop();
    }
    cout << endl;
}

int main() {
    int number;
    cout << "Enter a non-negative integer: ";
    cin >> number;
    decimalToBinary(number);
    return 0;
}


