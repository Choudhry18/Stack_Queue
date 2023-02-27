#include "Queue.h"

template<typename T>
class ArrayQueue:public Queue<T> {
public:
        ArrayQueue():head{0},tail{0},sz{10},data{new T[10]} {}
        ~ArrayQueue() {delete [] data;}
        void enqueue(const T &t);
        T dequeue() {}
        T peek() const {}
        bool isEmpty() const {}
private:
        int head,tail;
        int sz;
        T* data;
};

template<typename T>
void ArrayQueue<T>::enqueue(const T &t) {
        if((tail+1)%sz==head) {
                T *tmp = new T[sz*2];
                for (int i=0; i<sz-1; ++i) tmp[i]=data[(head+i)%sz];
                delete[] data;
                data = tmp;
                head = 0;
                tail = sz-1;
                sz *= 2;
        }
        data[tail] = t;
        tail=(tail+1)%sz;
}
