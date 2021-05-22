#include<iostream>
#include<vector>
using namespace std;

class priority
{
    public:

    vector<int>pq;
    int data;
    priority()
    {
        //data=this->data;
    }

    int getSize()
    {
        return pq.size();
    }
    bool isEmpty()
    {
        return pq.size()==0;
    }

    int getMin()
    {
        if(isEmpty())
        {
            return 0;
        }
        return pq[0];
    }

    void insert(int data)
    {
        pq.push_back(data);
        int CI= pq.size()-1;
        int PI= (CI-1)/2;

        while(CI>0)
        {
            if(pq[CI]<pq[PI])
            {
                swap(pq[CI],pq[PI]);
                CI=PI;
            }
            else
            {
                break;
            }

        }

    }

    int removeMin()
    {
        if(isEmpty())
        {
            return 0;
        }
        swap(pq[0],pq[pq.size()-1]);
        int ans=pq[pq.size()-1];
        pq.pop_back();
       int PI=0;

        while(true)
        {
            int  rci=2*PI+2;
            int lci=2*PI+1;
            int min=PI;
            if(lci<pq.size() && pq[lci]<pq[min])
            {
                min=lci;
            }
            if(rci<pq.size() && pq[rci]<pq[min])
            {
                min=rci;
            }
            if(min==PI)
            {
                break;
            }
            swap(pq[PI], pq[min]);
            PI=min;
        }
        return ans;
    }


};
int main()
{
   priority p;
    p.insert(20);
      p.insert(1);
        p.insert(200);
    cout<<p.getSize()<<endl;
    cout<<p.getMin()<<endl;
    while(p.getSize()!=0)
    {
          cout<<p.removeMin()<<" ";
    }
return 0;

}
