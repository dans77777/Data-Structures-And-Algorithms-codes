#include<iostream>
using namespace std;

template <typename T>
class Node
{
public:
T data;
    Node<T> *next;

    Node(T data)
    {
        this->data=data;
        next=NULL;
    }
};

template <typename T>
class Stack
{
public:
    Node<T> *head;
    int size;

    Stack()
    {

        head=NULL;
        size=0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size==0;
    }
    void push(T ele)
    {
        Node<T> *newNode= new Node<T>(ele);
        newNode->next=head;
        head=newNode;
        size++;
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"stack is alredy empty";
            return;
        }
        Node<T> *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        size--;
    }

T top()
{
      if(isEmpty())
        {
            cout<<"stack is alredy empty";
            return 0;
        }
        return head->data;
}


};
int main()
{
    Stack <int> s;

  // cout<<s.top()<<endl;
   s.push(100);
   cout<<s.top()<<endl;
   s.push(200);
    cout<<s.top()<<endl;
   cout<<s.getSize()<<endl;

    s.pop();
    cout<<s.top()<<endl;

    s.pop();
    cout<<s.top()<<endl;

}
