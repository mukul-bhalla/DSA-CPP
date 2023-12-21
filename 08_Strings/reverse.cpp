#include <iostream>
using namespace std;
char *reverse(char *s, char *ans)
{
    int i = 0, j, len;
    while (s[i] != '\0')
        i++;
    len = i;
    for (j = 0; j < len; j++)
    {
        ans[j] = s[--i];
    }
    ans[j] = '\0';
    return ans;
}

int main()
{
    char s[10] = "Python";
    int i, j;
    while (s[j] != '\0')
        j++;
    j--;
    for (i = 0; i < j; i++, j--)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    cout << s;
    return 0;
}