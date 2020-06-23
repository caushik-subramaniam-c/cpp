#include <iostream>
using namespace std;
template <class T>
class Stack {
    int top, capacity;
    T* array;
    int isFull() {
        if (top == capacity-1)
            return 1;
        else
            return 0;
    }
    int isEmpty() {
        if (top == -1)
            return 1;
        else
            return 0;
    }
    public:
        Stack<T>(int length) {
            array = new T(length);
            capacity = length;
            top = -1;
        }
        void push(T element) {
            if (!isFull()) {
                top = top + 1;
                array[top] = element;
            }
        }
        T pop() {
            if(!isEmpty()) {
                T temp = array[top];
                top = top - 1;
                return temp;
            }
        }
        void display() {
            for (int i = 0; i <= top; i++)
                cout << array[i] << " ";
            cout << "\n";
        }
        T peek() {
            if (!isEmpty()) {
                return array[top];
            }
        }
        int size() {
            return top+1;
        }
};

template <class T> // using a template class can be useful to create a queue of any type
class Queue {
    Stack<T> *s1, *s2;
    public:
        Queue(int length) {
            s1 = new Stack<int>(length); // create two stacks of length equal to the length of the queue required
            s2 = new Stack<int>(length);
        }
        void enQueue(T element) {
            s1->push(element); // to enqueue element to the queue, push the element to stack 1
        }
        T deQueue() { // to dequeue an element from the qeueue
            while (s1->size() > 0) {
                T t = s1->pop(); //  pop the elements in stack 1 
                s2->push(t); // store them in stack 2
            }
            T temp = s2->pop(); // and pop an element from stack 2
            while(s2->size() > 0) {
                T t = s2->pop(); // pop elements from stack 2
                s1->push(t); //  store them back in stack 1
            }
            return temp; // return the element popped from stack 2
        }
        T front() {
            while (s1->size() > 0) {
                T t = s1->pop(); // pop the elements from stack 1
                s2->push(t); // store them in stack 2
            }
            T front = s2->peek(); // view the front element
            while(s2->size() > 0) {
                T t = s2->pop(); // pop the elements from stack 2
                s1->push(t); // store them back to stack 1
            }
            return front; // return the front element
        }
        void display() {
            s1->display();
        }
};

int main() {
    Queue<int> queue(5); // create a new queue of 5 elements
    queue.enQueue(1); // add 5 elements
    queue.enQueue(2);
    queue.enQueue(3);
    queue.enQueue(4);
    queue.enQueue(5);
    queue.enQueue(6); //  adding 6 th element will have no effect on the queue, it will be ignored
    cout << "Front:" << queue.front() << "\n"; // view front element
    cout << "Dequeued: " << queue.deQueue() << "\n"; // dequeue an element
    cout << "Front:" << queue.front() << "\n";
    cout << "Dequeued: " << queue.deQueue() << "\n";
    cout << "Queue: ";
    queue.display(); // display the status of queue
    return 0;
}