#include <iostream>
using namespace std;
template <class T>
class Arithematic
{
private:
    T a, b;

public:
    Arithematic(T a, T b)
    {
        this->a = a;
        this->b = b;
    }
    T add()
    {
        return a + b;
    }
};
int main()
{
    Arithematic<int> o(2, 4);
    cout << o.add();

    return 0;
}