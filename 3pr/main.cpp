#include <iostream>

using namespace std;

template<typename T1, typename T2> class DoubleBox
{
private:
    T1 q=T1();
    T2 w=T2();
public:
    DoubleBox() {};
    DoubleBox(const T1 n, const T2 m) : q(n), w(m) {};

    void set(const T1 n, const T2 m)
    {
        q=n;
        w=m;
    }
    void get(T1 &n, T2 &m)
    {
        n=q;
        m=w;
    }
};
int main()
{
    int Box1;
    double Box2;
    DoubleBox<double,int> Box(12.36, 4);
    Box.get(Box2,Box1);

    cout<<Box1<<"\t"<<Box2<<endl;

    Box.set(2.8, 13);
    Box.get(Box2, Box1);
    cout<<Box1<<"\t"<<Box2<<endl;

    return 0;
}
