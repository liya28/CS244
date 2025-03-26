#include "list.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class ArrayList : public List {
    int *array;
    int index;
    int capacity;
    
    private:
        void dynamic_add() {
            if(index == capacity) {
                capacity += ceil(capacity * 0.5);
                array = (int*)realloc(array, sizeof(int) * capacity);
            }
        }
    
    public:
        ArrayList() {
            capacity = 4;
            index = 0;
            array = (int*)malloc(capacity * sizeof(int));
        }
        
        int add(int num) {
            dynamic_add();
            array[index++] = num;
            return index;
        }
        
        bool invalidPos(int pos) {
            return (pos >= index || pos < 0);
        }
        
        int get(int pos) {
            if (invalidPos(pos)) return -1;
            return array[pos];
        }
        
        int size() {
            return index;
        }

        void swap(int pos1, int pos2) {
            if (pos1 == pos2 || invalidPos(pos1) || invalidPos(pos2)) return;
            int temp = array[pos1];
            array[pos1] = array[pos2];
            array[pos2] = temp;
        }
        
        void set(int pos, int num) {
            if (invalidPos(pos)) return;
            array[pos] = num;
        }

        void print() {
            cout << "[";
            for (int i = 0; i < capacity; i++) {
                if (i < index) cout << array[i];
                else cout << "?";
                if (i != capacity - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
};
