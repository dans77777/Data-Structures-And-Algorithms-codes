#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>> v, int sv, vector<bool>&visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        if(v[sv][i]==1 && visited[i]==false)
        {
            dfs(v,i,visited);
        }
    }
}
print(vector<vector<int>> v, vector<bool>&visited)
{
int n=v.size();
for(int i=0;i<n;i++)
{
    if(!visited[i])
    {
        dfs(v,i,visited);
    }
}

}
int main()
{
    int n,e;
    cout<<"number of vertex"<<endl;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n,0));
    cin>>e;
     vector<bool>visited(n,false);
    for(int i=1;i<=e;i++)
    {
        int v1,v2;
        cout<<"enter vertex 1 and  vertex 2"<<endl;
        cin>>v1>>v2;
        v[v1][v2]=1;
         v[v2][v1]=1;

    }
    print(v,visited);
return 0;

}
