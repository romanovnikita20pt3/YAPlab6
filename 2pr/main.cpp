#include <iostream>

using namespace std;

template<class T> class Rectangle
{
private:
    T h=T();
    T a=T();
public:
    Rectangle() {};
    Rectangle(T x, T y)
    {
        h=x;
        a=y;
    }
    bool operator> (const Rectangle x)
    {
        return (h*a>x.h*x.a);
    }
    friend ostream& operator<< (ostream& outputStream, Rectangle x)
    {
        return outputStream<< x.h* x.a;
    }
};
void Comparison (int m[])
{
    for(int i=0; i<3; i++) {
        if (m[i]>m[i+1]) {
            cout<<"Больше";
        } else if (m[i]<m[i+1]) {
            cout<<"Меньше";
        }
    }
}
template<typename T> void Blader(T* arr, int length)
{
    for(int i=length-1; i>=1; i--) {
        for(int j=0; j < 1; j++) {
            if (arr[j]>arr[j+1]) {
                T t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
}
int main()
{
    int x=25, y=163;
    double a=17.2, b=21.4;
    Rectangle <int> arr[3];
    Rectangle <double> buf[3];
    cout<<"Сравнение 2-х значений: "<< endl;
    for(int i=0; i<3; i++) {
        Rectangle <int> l(x-i,y);
        arr[i]=l;
        if (arr[i]> arr[i+1]) {
            cout<<"Больше"<<endl;
        } else {
            cout<<"Меньше"<<endl;
        }
        Rectangle <double> d(a-i,b);
        buf[i]=d;
    }
    cout<<"Массив целых чисел перед сортировкой: ";
    for(int i=0; i<3; i++) {
        cout<<arr[i]<<" ";
    }
    Blader(arr,3);
    cout<<endl;
    cout<<"Массив целых чисел после сортировки: ";

    for(int i=0; i<3; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Массив чисел с плавающей точкой перед сортировкой: ";
    for(int i=0; i<3; i++) {
        cout<<buf[i]<<" ";
    }
    Blader (buf,3);
    cout<<endl;
    cout<<"Массив чисел с плавающей точкой после сортировки: ";
    for (int i=0; i<3; i++) {
        cout<<buf[i]<<" ";
    }
    cout<<endl;
    return 0;
}
