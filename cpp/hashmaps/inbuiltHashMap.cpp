#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
    unordered_map<string, int> mymap;
    //Insert
    pair<string,int> p("abc",1);//way 1
    mymap.insert(p);

    mymap["hi"]=1;//2nd way

    cout<<"Size  :"<<mymap.size()<<endl;

    //Acess 2 ways
   cout<<mymap.at("abc")<<endl;
   cout<<mymap["abc"]<<endl;

   //Access invalid values

   
   cout<<mymap["ab"]<<endl;// i will push into map and return value 0;

   //check value is present in map or not
   if(mymap.count("ab")>0)
   {
       cout<<"present"<<endl;
   }
   else
   {
       cout<<"not present"<<endl;
   }
}
