#ifndef LIST_H
#define LIST_H

class List {
public:
    virtual int add(int num) = 0;
    virtual int get(int pos) = 0;
    virtual int size() = 0;
    virtual void swap(int pos1, int pos2) = 0;
    virtual void set(int pos, int num) = 0;
    virtual void print() = 0;
};

#endif
