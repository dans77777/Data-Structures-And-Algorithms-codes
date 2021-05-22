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
    Pair <int,double> p1;
    p1.setX(10.12);
    p1.setY(20.120);
    cout<<p1.getX()<<endl;
    cout<<p1.getY();
}
