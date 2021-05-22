#include<iostream>
using namespace std;


int length(char s[])
{
    if(s[0]=='\0'){return 0;}

    return 1+ length(s+1);
}


int convertStoI(char s[],int n)
{
    if(n==0){return 0;}

    int smallans= convertStoI(s,n-1);
    int lastDigit= s[n-1]-'0';
    int ans= smallans*10+lastDigit;
    return ans;


}


int main()
{
    char s[]="12345";
    int n= length(s);
    //cout<<n;
    int a= convertStoI(s,n);
    cout<<a;

}
