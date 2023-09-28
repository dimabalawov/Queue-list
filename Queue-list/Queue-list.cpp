#include <iostream>
using namespace std;

template <typename T>
struct Elem
{
    T data;
    Elem* next, * prev;
};

template <class T>
class Queue
{
    Elem<T>* Head, * Tail;
    int Count;

public:
    Queue();
    ~Queue();
    int GetCount();
    void DelAll();
    void Extract();
    void Add(T n);
    void Print();
};
template <class T>
Queue<T>::Queue()
{
    Head = Tail = NULL;
    Count = 0;
}

template <class T>
void Queue<T>::Extract()
{
    if (Head == NULL)
        return;
    else
    {
        Elem<T>* temp = Head;
        Head = Head->next;
        delete temp;
        Count--;
    }
}
template <class T>
void Queue<T>::Add(T n)
{
    Elem<T>* t = new Elem<T>;
    t->data = n;
    t->prev = NULL;
    t->next = NULL;
    if (Count == 0)
        Tail = Head = t;
    else
    {
        t->prev = Tail;
        Tail->next = t;
        Tail = t;
    }
    Count++;
}
template <class T>
Queue<T>::~Queue()
{
    while (Count != 0)
        Extract();
}

template <class T>
void Queue<T>::Print()
{
    if (Count != 0)
    {
        Elem<T>* temp = Head;
        cout << "( ";
        while (temp != 0)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << ") ";
        cout << endl;
    }
}
template <class T>
void Queue<T>::DelAll()
{
    // Пока остаются элементы, удаляем по одному с головы
    while (Count != 0)
        Extract();
}
template <class T>
int Queue<T>::GetCount()
{
    return Count;
}

void main()
{
    Queue<int> a;
    a.Add(1);
    a.Add(2);
    a.Add(3);
    a.Print();
    a.Extract();
    a.Print();
}

