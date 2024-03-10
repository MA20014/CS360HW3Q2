#include <iostream>
#include <vector>

// Define a class for Integer Set
class IntegerSet {
private:
    std::vector<bool> elements; // Vector to store set elements (0-100)

public:
    // Constructor to initialize an empty set
    IntegerSet() : elements(101, false) {}

    // Additional constructor to initialize set from an array
    IntegerSet(int arr[], int size) : elements(101, false) {
        // Initialize set elements from the given array
        for (int i = 0; i < size; ++i) {
            if (arr[i] >= 0 && arr[i] <= 100) {
                elements[arr[i]] = true;
            }
        }
    }

    // Function to perform union of two sets
    IntegerSet unionOfSets(const IntegerSet& set2) const {
        IntegerSet result;
        // Combine elements from both sets
        for (int i = 0; i < 101; ++i) {
            result.elements[i] = elements[i] || set2.elements[i];
        }
        return result;
    }

    // Function to perform intersection of two sets
    IntegerSet intersectionOfSets(const IntegerSet& set2) const {
        IntegerSet result;
        // Find common elements between two sets
        for (int i = 0; i < 101; ++i) {
            result.elements[i] = elements[i] && set2.elements[i];
        }
        return result;
    }

    // Function to insert an element into the set
    void insertElement(int k) {
        // Ensure element is within range
        if (k >= 0 && k <= 100) {
            elements[k] = true;
        }
    }

    // Function to delete an element from the set
    void deleteElement(int m) {
        // Ensure element is within range
        if (m >= 0 && m <= 100) {
            elements[m] = false;
        }
    }

    // Function to print the set
    void printSet() const {
        bool isEmpty = true;
        // Iterate over elements and print those which are present in the set
        for (int i = 0; i < 101; ++i) {
            if (elements[i]) {
                std::cout << i << " ";
                isEmpty = false;
            }
        }
        // If set is empty, print ---
        if (isEmpty) {
            std::cout << "---";
        }
        std::cout << std::endl;
    }

    // Function to check if two sets are equal
    bool isEqualTo(const IntegerSet& set2) const {
        // Iterate over elements and compare corresponding elements in both sets
        for (int i = 0; i < 101; ++i) {
            if (elements[i] != set2.elements[i]) {
                return false;
            }
        }
        return true;
    }
};

// Main function to test IntegerSet class
int main() {
    // Create sets and perform operations
    IntegerSet set1, set2;
    set1.insertElement(10);
    set1.insertElement(30);
    //set1.insertElement(20);
    set2.insertElement(10);
    set2.insertElement(30);

    // Print sets
    std::cout << "Set 1: ";
    set1.printSet();
    std::cout << "Set 2: ";
    set2.printSet();

    // Perform union of sets and print result
    IntegerSet set3 = set1.unionOfSets(set2);
    std::cout << "Union of Set 1 and Set 2: ";
    set3.printSet();

    // Perform intersection of sets and print result
    IntegerSet set4 = set1.intersectionOfSets(set2);
    std::cout << "Intersection of Set 1 and Set 2: ";
    set4.printSet();

    // Check if sets are equal and print result
    std::cout << "Is Set 1 equal to Set 2? " << (set1.isEqualTo(set2) ? "Yes" : "No") << std::endl;

    // Create set from array and print
    int arr[] = {40, 50, 60};
    IntegerSet set5(arr, sizeof(arr) / sizeof(arr[0]));
    std::cout << "Set 5: ";
    set5.printSet();

    return 0;
}
