#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int> &q)
{
    stack<int> s;

    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }


}

int main()
{
    queue<int>q;
    int ele;
    for(int i=0;i<5;i++)
    {
        cin>>ele;
        q.push(ele);
    }
    reverse(q);
   while(!q.empty()){
        cout<<q.front();
        q.pop();
    }
}
