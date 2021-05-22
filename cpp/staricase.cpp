#include<iostream>
using namespace std;


int stair(int n)
{
    int a=1;
    int b=1;
    int c=1;

    for(int i=2;i<=n;i++)
    {
        a=b;
        b=c;
        c=a+b;
    }
    return c;
}


int main()
{
    int n=4;

   int ans= stair(4);
   cout<<ans;
}
