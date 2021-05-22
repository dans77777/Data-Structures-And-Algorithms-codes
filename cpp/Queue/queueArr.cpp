#include<iostream>
using namespace std;



template<typename T>
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


template<typename T>
class Queue
{

   int size;
   Node<T> *head;
   Node<T> *tail;

 public:
  Queue()
   {
       head=NULL;
       tail=NULL;
       size=0;
   }

    int getSize()
    {
       return size;
    }

    bool isEmpty()
    {
       return head==NULL;
    }

    void insert(T ele)
    {
Node<T> *newNode= new Node<T>(ele);

if(head==NULL)
{
head=newNode;
tail=newNode;
}
else{
tail->next=newNode;
tail=newNode;
}
size++;

    }

    void pop()
    {
        if(head==NULL)
        {
            cout<<"No data to pop";
        }
        Node<T> *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        size--;

    }

    T getFront()
    {
        if(isEmpty())
        {
            cout<<"no front here"<<endl;
            return 0;
        }
return head->data;
    }
};
int main()
{

Queue<int>q;
q.insert(100);
q.insert(200);
q.insert(300);
q.insert(400);
cout<<q.getFront()<<endl;
q.pop();
cout<<q.getFront()<<endl;
cout<<q.getSize()<<endl;
cout<<q.isEmpty();



}
