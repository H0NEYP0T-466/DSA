#include <iostream>
#include <vector>
#include <list>

// Hash function (hashCode)
int hashCode(int key, int size) {
    return key % size;
}

// Compression function (index calculation)
int compress(int code, int size) {
    return code % size;
}

// Node structure for chaining
struct Node {
    int key;
    int value;
    Node* next;
};

// Bucket array (hashmap)
class HashMap {
private:
    int size;
    std::vector<Node*> buckets;

public:
    HashMap(int size) : size(size), buckets(size, nullptr) {}

    // Insert key-value pair
    void insert(int key, int value) {
        int index = compress(hashCode(key, size), size);
        Node* newNode = new Node{key, value, nullptr};

        if (buckets[index] == nullptr) {
            buckets[index] = newNode;
        } else {
            Node* current = buckets[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Search for key
    int search(int key) {
        int index = compress(hashCode(key, size), size);
        Node* current = buckets[index];

        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1; // Key not found
    }

    // Delete key-value pair
    void remove(int key) {
        int index = compress(hashCode(key, size), size);
        Node* current = buckets[index];
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (previous == nullptr) {
                    buckets[index] = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }
};

int main() {
    HashMap hashmap(10);

    hashmap.insert(1, 10);
    hashmap.insert(2, 20);
    hashmap.insert(11, 110); // Collision with key 1

    std::cout << hashmap.search(1) << std::endl; // Output: 10
    std::cout << hashmap.search(2) << std::endl; // Output: 20
    std::cout << hashmap.search(11) << std::endl; // Output: 110

    hashmap.remove(1);

    std::cout << hashmap.search(1) << std::endl; // Output: -1 (Key not found)

    return 0;
}



