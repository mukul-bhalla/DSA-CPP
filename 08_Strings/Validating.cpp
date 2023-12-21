#include <iostream>
using namespace std;
int valid(char *s)
{
    int i, c;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (!(s[i] >= 65 && s[i] <= 90) && !(s[i] >= 97 && s[i] <= 122) && !(s[i] >= 48 && s[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char s[10];
    gets(s);
    cout << valid(s);
    return 0;
}