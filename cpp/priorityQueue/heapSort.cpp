#include<iostream>
using namespace std;

void heapSort(int *pq, int n)
{
    for(int i=1; i<n; i++)
    {
        int CI=i;

        while(CI>0)
        {
            int PI=(CI-1)/2;
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

    int size=n;


    while(size>=1)
    {
        swap(pq[0],pq[size-1]);
        size--;
        int PI=0;
        while(true){
        int lci=2*PI+1;
        int rci=2*PI+2;
        int min=PI;

        if(lci<size && pq[lci]<pq[min])
        {
            min=lci;
        }
        if(rci<size && pq[rci]<pq[min])
        {
            min=rci;
        }
        if(min==PI)
        {
            break;
        }
        swap(pq[PI],pq[min]);

        PI=min;


        }
    }
}

int main()
{
    int pq[]={5,1,2,0,8};
    heapSort(pq,5);

    for(int i=0;i<5;i++){
    cout<<pq[i]<<" ";
   }

   return 0;
}
