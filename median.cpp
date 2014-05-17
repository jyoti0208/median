#include "Maxheap.h"

int mean(int a, int b)
{
    return (a+b)/2;
}

int Maxheap::left(int i)
{
    return 2*i + 1;
}

int Maxheap::right(int i)
{
    return 2 * (i+1);
}

int Maxheap::parent(int i)
{
    if( i <= 0)
    {
        return -1;
    }
    return (i-1)/2;
}

int Maxheap::top(void)
{
    int max = 0;
    if(heap_size >= 0)
    {
        max = array[0];
    }
    return max;
}

void Maxheap::heapify(int i)
{
    int largest, temp, l, r;
    l = 2*i;
    r = 2*i+1;
    if(array[l] > array[i] && l <= heap_size)
        largest = l;
    else
        largest = i;
    if(array[r] >array[largest] && r <= heap_size)
        largest = r;
    if(largest != i)
    {
        temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        heapify(largest);
    }

}

int Maxheap::pop()
{
    int del = -1;
    int temp;
    if(heap_size > -1)
    {
        del = array[0];
        temp = array[0];
        array[0] = array[heap_size];
        array[heap_size] = temp;        
        heap_size--;
        heapify(parent(heap_size + 1));
    }
    return del;
}

bool Maxheap::push(int key)
{
    bool  ret = false;
    if(heap_size < MAX_HEAP_SIZE)
    {
        ret = true;
        heap_size++;
        array[heap_size] = key;
       // cout<<"done"<<endl;
        heapify(heap_size);
    }
    return ret;
}

int Minheap::left(int i)
{
    return 2*i + 1;
}

int Minheap::right(int i)
{
    return 2 * (i+1);
}

int Minheap::parent(int i)
{
    if( i <= 0)
    {
        return -1;
    }
    return (i-1)/2;
}

int Minheap::top(void)
{
    int max = 0;
    if(heap_size >= 0)
    {
        max = array[0];
    }
    return max;
}

void Minheap::heapify(int i)
{
    int smallest, temp, l, r;
    l = 2*i;
    r = 2*i+1;
    if(array[l] < array[i] && l <= heap_size)
        smallest = l;
    else
        smallest = i;
    if(array[r] < array[smallest] && r <= heap_size)
        smallest = r;
    if(smallest != i)
    {
        temp = array[i];
        array[i] = array[smallest];
        array[smallest] = temp;
        heapify(smallest);
    }
}

int Minheap::pop()
{
    int del = -1;
    int temp;
    if(heap_size > -1)
    {
        del = array[0];
        temp = array[0];
        array[0] = array[heap_size];
        array[heap_size] = temp;        
        heap_size--;
        heapify(parent(heap_size + 1));
    }
    return del;
}

bool Minheap::push(int key)
{
    bool  ret = false;
    if(heap_size < MAX_HEAP_SIZE)
    {
        ret = true;
        heap_size++;
        array[heap_size] = key;
       // cout<<"fault"<<endl;
        heapify(heap_size);
        //cout<<"right"<<endl;
    }
    return ret;
}

int get_median(int e, Maxheap*& left, Minheap*& right)
{   

    if(((left->get_heap_size() + right->get_heap_size()) % 2) ==0)
    {
        if(left->get_heap_size() > 0 && e < left->top())
        {
            left->push(e);
            e = left->top();
          //  cout<<"val="<<e;
            
            left->pop();
            //cout<<"noe"<<e;
        }
        right->push(e);
        //cout<<"left1= "<<left->top()<<endl;
        //cout<<"right11= "<<right->top()<<endl;
        return  right->top();
    }
    else
    {
        if(right->get_heap_size() > 0 && right->top() < e)
        {
            right->push(e);
            e = right->top();
            //cout<<"e="<<e;
            right->pop();
        }
        left->push(e);
       // cout<<"left2= "<<left->top()<<endl;
       // cout<<"right2= "<<right->top()<<endl;
        return mean(left->top(), right->top());
    }
}

void print_median(int* arr, int size)
{
    int m = 0;
    Maxheap* left = new Maxheap(MAX_HEAP_SIZE);
    Minheap* right = new Minheap(MAX_HEAP_SIZE);
    for(int i =0; i < size; i++)
    {
        m = get_median(arr[i], left, right);
        cout<<m<<endl;
    }
    delete left;
    delete right;
}

int main()
{
    int arr[6] = {5,15,1,4,9,7};
    int size = ARRAY_SIZE(arr);
    print_median(arr, size);
   // Minheap* left = new Minheap(MAX_HEAP_SIZE);
    //left->push(23);
    return 0;
}
