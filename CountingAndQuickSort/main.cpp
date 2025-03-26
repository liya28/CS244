#include <iostream>
#include "arraylist.hpp"
#include "linkedlist.hpp"

void countingSort(List*);
void quickSort(List*, int, int);
int partition(List*, int, int);

int main() {
    char li;
    cout << "Enter type of list: ";
    cin >> li;
    
    List *list;
    if (li == 'A') list = new ArrayList();
    else list = new LinkedList();
    
    int length;
    cout << "Enter number of elements: ";
    cin >> length;
    
    int input;
    for (int i = 0; i < length; i++) {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> input;
        list->add(input);
    }
    
    char sortType;
    cout << "Enter sorting method: ";
    cin >> sortType;
    
    list->print();
    
    if (sortType == 'C') countingSort(list);
    else quickSort(list, 0, list->size() - 1);
    
    
    return 0;
}

void countingSort(List *list) {
    int n = list->size();
    if (n == 0) return;  // Handle empty list case
    
    // Step 1: Find max and min values
    int max = list->get(0);
    int min = list->get(0);
    
    for (int i = 1; i < n; i++) {
        int num = list->get(i);
        if (num > max) max = num;
        if (num < min) min = num;
    }
    
    int offset = (min < 0) ? -min : 0;  // Shift negative values
    int range = max - min + 1;  // Adjust range for negative values
    
    // Step 2: Create and initialize count array
    int *count = new int[range](); 
    
    // Step 3: Count occurrences
    for (int i = 0; i < n; i++) {
        count[list->get(i) - min]++;  // Shift index by min
    }
    
    // Step 4: Compute cumulative sum
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    
    // Step 5: Build the sorted array
    int *output = new int[n];
    
    for (int i = n - 1; i >= 0; i--) {
        int val = list->get(i);
        int pos = --count[val - min];  // Adjust position
        output[pos] = val;
    }
    
    // Step 6: Copy sorted values back to list
    for (int i = 0; i < n; i++) {
        list->set(i, output[i]);
    } 
    
    // Print sorted list
    cout << "Sorted list: ";
    list->print();
    
    // Free allocated memory
    delete[] count;
    delete[] output;
}

void quickSort(List* list, int low, int high) {
    if (low < high) {
        int pivot_idx = partition(list, low, high);
        quickSort(list, low, pivot_idx - 1);
        quickSort(list, pivot_idx + 1, high);
    }
}

int partition(List* list, int low, int high) {
    int pivot = list->get(low);  // Keep first element as pivot
    int i = low + 1;
    int j = high;
    
    while (true) {
        while (i <= j && list->get(i) <= pivot) i++;  // Move i to a larger value
        while (j >= i && list->get(j) > pivot) j--;  // Move j to a smaller value
        
        if (i < j) {
            list->swap(i, j);
            cout << "Swapping indices " << i << " and " << j << ": ";
            list->print();
        } else {
            break;
        }
    }

    // Place pivot at the correct position
    if (low != j) list->swap(low, j);
    
    cout << "Moving pivot to index " << j << ": ";
    list->print();

    return j;
}
