#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }

};

Node* insert()
{
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;

    while(data!=-1)
    {
        Node *n= new Node(data);
        if(head==NULL)
        {
            head=n;
            tail=n;

        }
        else
        {
            tail->next=n;
            tail=n;
        }
        cin>>data;
    }
    return head;
}
Node* insertIth(Node *head, int i,int data)
{

    int counter=1;
    if(i<0)
    {
        return head;
    }

    if(i==0)
    {
        Node *n =new Node(data);
        n->next=head;
        head=n;
        return head;
    }
    Node *copyHead=head;
    while( counter<=i-1 && head!=NULL )
    {

        head=head->next;
        counter++;
    }
    if(head)
    {
        Node *n =new Node(data);
        n->next=head->next;
        head->next=n;
        return copyHead;

    }
    return copyHead;


}

Node* deleteIth(Node *head, int i)
{

    int counter=1;
    if(i<0)
    {
        return head;
    }

    if(i==0)
    {
        Node *newnode=head;

        newnode=head->next;
        head->next=NULL;
        delete(head);
        return newnode;
    }
    Node *copyHead=head;
    Node *temp=head;

    while( counter<=i-1 && head!=NULL )
    {

        // head=head->next;

        temp=temp->next;
        counter++;
    }
    if(temp && temp->next)
    {
        Node *curr=temp->next;
        temp->next=curr->next;
        curr->next=NULL;
        delete(curr);
        return copyHead;
    }
    return copyHead;


}

void print(Node *head)//head by value not reference
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

int main()
{
    int i,data;
    Node *head=insert();
    print(head);
    cin>>i;
    //  cin>>data;
    // head= insertIth(head,i,data);
    // cout<<endl;
    // print(head);
    head= deleteIth(head,i);
    cout<<endl;
    print(head);
}
