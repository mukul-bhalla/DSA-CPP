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
        i++;
    }
    cout << "Length of your name is " << i;

    return 0;
}