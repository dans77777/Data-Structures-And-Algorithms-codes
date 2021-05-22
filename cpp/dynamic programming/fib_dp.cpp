#include<iostream>
using namespace std;

int fibRecursive(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }

    return(fibRecursive(n-1)+fibRecursive(n-2));


}

int fibMemorization(int n, int *arr)
{
    if(n==0|| n==1)
    {
        return n;
    }

    if(arr[n]!=0)
    {
        return arr[n];
    }
    int ans= fibMemorization(n-1,arr)+fibMemorization(n-2,arr);
    arr[n]=ans;

    return ans;

}
int fibMemIterative(int n)
{
      int *arr= new int[n+1];
    arr[0]=0;
    arr[1]=1;

   for(int i=2;i<=n;i++)
   {
       arr[i]=arr[i-1] + arr[i-2];
   }
   int op=arr[n];
   delete []arr;
   return op;

}
int main()
{
    int n;
    cin>>n;
    int *arr= new int[n+1];
for(int i=0;i<=n;i++)
{
    arr[i]=0;
}

    cout<<fibMemorization(n,arr)<<endl;
   cout<<fibMemIterative(n);
cout<<fibRecursive(n)<<endl;
}
