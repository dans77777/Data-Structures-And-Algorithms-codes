#include<iostream>
using namespace std;

template<typename V>
 class MapNode
 {
 public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key, V value)
    {
        key= this.key;
        value=this.value;
        next=NULL;
    }
    ~MapNode()
    {
        delete next;
    }

 };

 class mymap
 {
     MapNode<V>** buckets;
     int count;
     in bucketNums;

     mymap()
     {
         count=0;
         bucketNums=5;
         MapNode<V>* buckets= new MapNode<V>[bucketNums];
          for(int i=0;i<bucketNums;i++)
         {
             buckets[i]= NULL;
         }
     }
     ~ mymap()
     {
         for(int i=0;i<bucketNums;i++)
         {
             delete buckets[i];
         }
         delete buckets[];
     }

int getIndex(string key)
{
    int hashcode=0
    base=1;
    int p=37;
    for(int i=key.length()-1;i>=0;i--)
    {
       hashcode+=key[i]*base;
       hascode=hashcode%bucketNums;
       base=base*p;
       base=base%bucketNums;
    }


    return hashcode%bucketNums;
}

     int getSize()
     {
         return count;
     }
     void insert(string key, V value)
     {
        int bucketIndex= getIndex(key);
        MapNode<V>* head= buckets[bucketIndex];
        while(head!=NULL)
        {
            if(head->key==key)
            {
                head->value=value;
            }
            head=head->next;
        }
        MapNode<V>* node= new MapNode<V>(key,value);
         node->next=buckets[bucketIndex];
         buckets[bucketIndex]=node;
         count++;
     }
     V remove(string key)
     {
         int bucketIndex= getIndex(key);
         MapNode<V>* head= buckets[bucketIndex];
          MapNode<V>* prev= NULL;
         while(head!=NULL)
         {
             if(head->key==key)
             {
                 if(prev==NULL)
                 {
                     buckets[bucketIndex]=head->next;
                 }
                 else{
                    prev->next=head->next;
                 }
                 V value= head->value;
                 head->next=NULL;
                 delete head;
                 count--;
                 return value;
             }
             prev=head;
             head=head->next;
         }
return 0;

     }

     V getValue(string key)
     {
         int bucketIndex= getIndex(key);
         MapNode<V>* head= buckets[bucketIndex];

         while(head!=NULL)
         {
             if(head->key==key)
             {

                 return head->value;

             }

             head=head->next;
         }
return 0;

     }

 };
