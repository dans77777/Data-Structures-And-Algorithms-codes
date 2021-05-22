#include<iostream>
#include<vector>
using namespace std;

void sub(string input, string output,vector <string>&s)
{
    if(input.length()==0)
    {
          s.push_back(output);
        return;
    }
    sub(input.substr(1),output,s);
    sub(input.substr(1),output+input[0],s);
}

int main()
{
    string input, output;
    cin>>input;
    vector <string>s;
    sub(input, output,s);
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i]<<endl;
    }

}
