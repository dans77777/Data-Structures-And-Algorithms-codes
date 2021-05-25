#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int>> v, int sv, vector<bool>&visited)
{
    int n=v.size();
    queue<int>q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty())
    {
        int cv=q.front();

        q.pop();
        for(int i=0;i<n;i++)
        {
            if(v[cv][i]==1 && visited[i]==false)
            {
                q.push(i);
                visited[i]=true;
            }
        }


    }
}
void print(vector<vector<int>> v,vector<bool>&visited)
{
    int n=v.size();
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {cnt++;
            bfs(v,i,visited);
        }
    }
cout<<"Number of connected compopnents are "<<cnt;
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
