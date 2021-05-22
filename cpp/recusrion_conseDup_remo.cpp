#include<iostream>
using namespace std;



 void remConse(char input[])
 {
     if(input[0]=='\0')
     {
         return;
     }

     if(input[0]==input[1])
     {
         for(int i=0;input[i]!='\0';i++)
         {
             input[i]=input[i+1];
         }
         remConse(input);
     }
     else{
            remConse(input+1);
     }
 }

int main()
{
    char input[100];
    cin>>input;
    remConse(input);
    cout<<input;
}
