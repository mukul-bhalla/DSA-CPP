#include <iostream>
using namespace std;
int compare(char *s, char *p)
{
    int i, j;
    for (i = 0, j = 0; s[i] != '\0' || p[j] != '\0'; i++, j++)
    {
        if (s[i] != p[j])
            return 0;
    }
    return 1;
}
int palindrome(char *s)
{
    int i, j = 0;
    while (s[j] != '\0')
        j++;
    for (i = 0, --j; i <= j; i++, j--)
    {
        if (s[i] != s[j])
            return 0;
    }
    return 1;
}
int main()
{
    // cout << compare("paint", "paint");
    cout << palindrome("abcddcbaa");
    return 0;
}