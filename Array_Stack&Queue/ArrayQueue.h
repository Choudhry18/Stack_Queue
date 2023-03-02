#include "Queue.h"

template<typename T>
class ArrayQueue:public Queue<T>
{
public:
        ArrayQueue();
        ~ArrayQueue() {delete [] data;}
        ArrayStack(const ArrayStack &s);
        void enqueue(const T &t);
        T dequeue();
        T peek() const;
        bool isEmpty() const;
private:
        int head;
        int tail;
        int sz;
        T* data;
};

template <typename T>
ArrayQueue<T>::ArrayQueue() : head{0}, tail{0}, sz{10}, data{new T[10]}
{
}
template <typename T>
ArrayStack<T>::ArrayQueue(const ArrayQueue &s) : top{s.top}, tail{s.tail}, sz{s.sz}, data{new T[s.sz]}
{
    for(int i=0; i<top; i++) data[i] = s.data[i];
}
template <typename T>
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

template <typename T>
T ArrayQueue<T>::dequeue() {
        T ret = data[head];
        head = (head+1)%sz;
        return ret;
}

template <typename T>
T ArrayQueue<T>::peek() const {
        return data[head];
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
        return head == tail;
}
