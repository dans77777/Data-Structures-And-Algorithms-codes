#include<bits/stdc++.h>
using namespace std;
int stBruteforce(int n)
{
    if(n<=1)
    {
        return 0;
    }

    int x=  stBruteforce(n-1);
    int y=INT_MAX;
    int z=INT_MAX;

    if(n%2==0)
    {
        y= stBruteforce(n/2);
    }
     if(n%3==0)
    {
        y= stBruteforce(n/3);
    }

    return min(x,min(y,z))+1;
}



int stBottomUp(int n)
{   if(n<=1)
    {
        return 0;
    }

    int *a=new int[n+1];

   a[0]=0;
   a[1]=0;

 for(int i=2;i<=n;i++)
 {
      int x=  a[i-1];
    int y=INT_MAX;
    int z=INT_MAX;

    if(i%2==0)
    {
        y= a[i/2];
    }
     if(i%3==0)
    {
        z= a[i/3];
    }

    a[i]= min(x,min(y,z))+1;

 }


     return a[n];
}


int stDp(int n)
{
    int *a=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        a[i]=-1;
    }
    if(n<=1)
    {
        return 0;
    }
if(a[n]!=-1)
{
    return a[n];
}
    int x=  stDp(n-1);
    int y=INT_MAX;
    int z=INT_MAX;

    if(n%2==0)
    {
        y= stDp(n/2);
    }
     if(n%3==0)
    {
        y= stDp(n/3);
    }

     int ans= min(x,min(y,z))+1;
     a[n]=ans;
     return ans;
}


int main()
{
 cout<< stBottomUp(11);

}
