#include <iostream>
using namespace std;
int anagram(char s[], char t[])
{
    int i;
    int *H = new int[26]();

    for (i = 0; s[i] != '\0'; i++)
    {
        H[s[i] - 97]++;
    }
    for (i = 0; t[i] != '\0'; i++)
    {
        H[t[i] - 97]--;
    }
    for (i = 0; i < 26; i++)
    {
        if (H[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char s[10], t[10];
    gets(s);
    gets(t);
    cout << anagram(s, t);
    return 0;
}