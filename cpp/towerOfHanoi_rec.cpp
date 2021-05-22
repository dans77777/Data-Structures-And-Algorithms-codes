#include<iostream>
using namespace std;

int tower(int n)
{
    if(n==0){return 0;}

    return tower(n-1) + 1+  tower(n-1);
}


int main()
{

    int n;
    cin>>n;
   int s= tower(n);
   cout<<s;

}
