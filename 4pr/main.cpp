#include <iostream>
#include <string>
#include <array>
using namespace std;

template <size_t N> class superlong // Шаблонный класс
{
private:
    static constexpr size_t SIZE = N / 32 + (N % 32 != 0);
    array<uint32_t, N / 32 + (N % 32 != 0)> value;
    static string toHex(uint32_t u);
    string toHex();
public:
    superlong():value(
    {

    }) {}
    superlong(const array<uint32_t, N / 32 + (N % 32 != 0)>& v):value(v) {}
    superlong(const string & s);
    superlong<N>& operator=(const superlong<N>& s);
    superlong<N> operator+(const superlong<N>& s)const;
    template <size_t X>
    friend ostream& operator<< (ostream& stream, superlong<X>& s);
};

template <size_t N> // Конструктор инициализации строкой
superlong<N>::superlong(const string& s)
{
    // Проверка на принадлежность к 16-тиричным
    int len = s.length();
    string Alfa = "0123456789abcdef";
    try {
        for (int i = 1; i<len; i++) {
            if (Alfa.find(s[i]) == string::npos) {
                throw invalid_argument("");
            }
        }
    } catch (invalid_argument) {
        cerr << "Invalid_argument" << endl;
        exit(1);
    }
    value= {0};
    int i = 0;
    auto ptr_2 = s.end();
    auto ptr_b = s.begin();
    while (ptr_b != ptr_2) {
        auto ptr_1 = ptr_2 - 8;
        if (ptr_1 < ptr_b)
            ptr_1 = ptr_b;
        value[i] = stoul(string(ptr_1,ptr_2),0,16);
        ptr_2 = ptr_1;
        i++;
    }
}

template <size_t N> // Перегруженный оператор присваивания
superlong<N>& superlong<N>::operator=(const superlong<N>& s)
{
    value = s.value;
    return *this;
}

template <size_t N> // Перегруженный оператор сложения
superlong<N> superlong<N>::operator+(const superlong<N>& s)const
{
    superlong<N> sum;
    uint32_t CF=0;
    for (size_t i=0; i<SIZE; i++) {
        sum.value[i] = CF + value[i] + s.value[i];
        if (sum.value[i]<value[i])
            CF = 1;
        else
            CF = 0;
    }
    return sum;
}

template <size_t N> // Статический метод предстваления 32х раз.числа в виде 16-тиричных цифр
string superlong<N>::toHex(uint32_t u)
{
    const char d[]="0123456789abcdef";
    std::string s;
    for (int i=0; i<8; i++) {
        s = d[u & 0xf]+s;
        u >>=4;
    }
    return s;
}

template <size_t N> // Метод представления длинного числа в виде строки 16х цифр
string superlong<N>::toHex()
{
    string s;
    for (auto e:value)
        s=superlong<N>::toHex(e) + s;
    return s;
}

template <size_t X> // Перегруженный опертор вывода, выводящий длинное число в 16-тиричном виде
ostream& operator<<(std::ostream& stream, superlong<X>& s)
{
    stream<<s.toHex();
    return stream;
}

int main(int argc, char **argv)
{
    const size_t SZ = 1024;
    superlong<SZ> num1("abc");
    superlong<SZ> num2("abw"); // w не является 16-тиричной цифрой
    cout<<num1<<endl;
    cout<<num2<<endl;
    return 0;
}
