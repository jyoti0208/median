#include <iostream>

using namespace std;

#define MAX_HEAP_SIZE 128
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

class Maxheap
{
public:
    int* array;
    int heap_size;
public:
    Maxheap(int size)
    {
        heap_size = -1;
       // cout<<"allocated";
        array = new int[size];
        //cout<<"done"<<endl;
    }

    int left(int i);

    int right(int i);

    int parent(int i);

    int top(void);

    int get_heap_size()
    {
        return heap_size + 1;
    }

    void heapify(int i);

    int pop();

    bool push(int key);
};

class Minheap
{
public:
    int* array;
    int heap_size;
public:
    Minheap(int size)
    {
        heap_size = -1;
        array = new int[size];
    }

    int left(int i);

    int right(int i);

    int parent(int i);

    int top(void);

    int get_heap_size()
    {
        return heap_size + 1;
    }

    void heapify(int i);

    int pop();

    bool push(int key);
};

