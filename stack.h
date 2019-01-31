/**********************************************************************
* FILENAME:        stack.h
*
* DESCRIPTION/PURPOSE:
* Design and implementation of stack
*
* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 01/31/2019
* SUBMISSION DATE: 01/31/2019
**********************************************************************/
#include<iostream>
#include<cstring>
#include<fstream>
#define cap 30
using namespace std;

template <typename T>
class Stack
{
private:
    int capacity;
    T *arr;
    int top;
public:
    Stack(int len=cap)
    {
        arr = new T[len+1];
        top = -1;
        capacity = len;
    }
    ~Stack()
    {
        delete[] arr;
        top=0;
        capacity=0;
    }

    void push(T c)
    {
        if(isFull())
            cout << "Stack is Full" << endl;
        else
            arr[++top]=c;
    }

    T pop()
    {
        T var;
        if(isEmpty())
        {
            cout << "Stack is empty" << endl;
            return var;
        }
        else
            return arr[top--];
    }

    T peek()
    {
        T var;
        if(isEmpty())
        {
            cout << "Stack is empty" << endl;
            return var;
        }
        else
            return arr[top];
    }

    bool isEmpty()
    {
        return top==-1;
    }

    bool isFull()
    {
        return top==capacity-1;
    }
    int Size(){
        return top+1;
    }
};
