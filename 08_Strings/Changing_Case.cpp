#include <iostream>
using namespace std;
int main()
{
    string name;
    cout << "Enter your first name: ";
    cin >> name;
    int i = 0;
    while (name[i] != '\0')
    {
        if (name[i] <= 90)
        {
            name[i] += 32;
        }
        else
        {
            name[i] -= 32;
        }
        i++;
    }
    cout << name;
    return 0;
}