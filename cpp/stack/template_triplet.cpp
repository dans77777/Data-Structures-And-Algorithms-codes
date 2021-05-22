#include<iostream>
using namespace std;
template<typename T, typename V>
 class Pair
 {
 T x;
 V y;

 public:
     void setX(T x)
     {
         this->x=x;
     }
     T getX()
     {
         return x;
     }
     void setY(V y)
     {
         this->y=y;
     }
     V getY()
     {
         return y;
     }
 };
int main()
{
    Pair <Pair<int,int>,int>p;
    Pair<int,int>p2;
    p2.setX(97);
    p2.setY(98);
    p.setX(p2);
    p.setY(20);
    cout<<p.getX().getX()<<" ";
    cout<<p.getX().getY()<<" ";
    cout<<p.getY();
}
