#include <iostream>

using namespace std;

template<class T> void Blader(T* arr, int size)
{
    T tmp;
    for(int x=0; x < size-1; x++) {
        for(int y=0; y < size-1; y++) {
            if (arr[y+1]<arr[y]) {
                tmp=arr[y+1];
                arr[y+1]=arr[y];
                arr[y]=tmp;

            }
        }
    }
}
int main()
{
    int a[8]= {75,42,17,12,100,31,95,26};
    int b=8;
    cout<<"Массив, содержащий челые числа в случайном порядке: ";
    for(int x=0; x < b; x++) {
        cout << a[x]<<" ";
    }
    cout<<endl;
    Blader(a,b);
    cout<<"Массив, содержащий целые числа по возрастанию в последовательном порядке: ";
    for(int x=0; x < b; x++) {
        cout<<a[x]<<" ";
    }
    cout<<endl;
    double c[8]= {14.1, 25.3, 66.2, 31.1, 11.9, 92.2, 0.7,6.7};
    cout<<"Массив, содержащий числа с плавающей точкой в случайном порядке: ";
    for(int x=0; x<b; x++) {
        cout<<c[x]<<" ";
    }
    cout<<endl;
    Blader (c,b);
    cout<<"Массив, содержащий числа с плавающей точкой в последовательном порядке по возрастанию: ";
    for(int x=0; x<b; x++) {
        cout<<c[x]<<" ";
    }
    cout<<endl;
    return 0;
}
