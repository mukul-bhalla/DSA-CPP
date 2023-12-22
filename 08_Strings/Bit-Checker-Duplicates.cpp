#include <iostream>
using namespace std;
int main()
{
    char s[10];
    long int H = 0, x = 0;
    int i;
    gets(s);
    for (i = 0; s[i] != '\0'; i++)
    {
        x = 1;
        x = x << (s[i] - 97);
        if ((x & H) > 0)
        {
            cout << s[i] << "is a duplicate" << endl;
        }
        else
        {
            H = H | x;
        }
    }
    return 0;
}