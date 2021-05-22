#include<iostream>
using namespace std;
template<typename T>
class Stack
{
    int capacity;
    int top;
    T *arr;

public:

    Stack()
    {
        capacity=4;
        arr= new T[capacity];
        top=0;
    }
    int size()
    {
        return top;
    }
    bool isEmpty()
    {
        return top==0;
    }
    void push(T ele)
    {
        if(top==capacity)
        {
            T *newarr= new T[capacity*2];
           // capacity= capacity*2;
            for(int i=0;i<capacity;i++)
            {
                newarr[i]=arr[i];
            }
            delete []arr;
            arr=newarr;
            capacity=2*capacity;
        }
        arr[top]=ele;
        top++;

    }
    void pop()
    {
        if(isEmpty())
        {
        cout<<"stack is empty";
        return;
        }
        top--;
    }
T topget()
{
    if(isEmpty()){
            cout<<"Stack empty"<<endl;
            return 0;//bcz 0 is of all type -int,doubl;e,char
          }
         return arr[top-1];


}


};

int main()
{
    Stack <char> s;
    s.push(100);

        cout<<s.size()<<cout;
       // s.pop();
        // cout<<s.size();
       cout<<s.topget();
}
