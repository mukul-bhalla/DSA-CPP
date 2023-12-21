#include <iostream>
using namespace std;
int main()
{
    char str[10];
    int H[26] = {0}, i;
    cout << "Enter a string :";
    gets(str);
    for (i = 0; str[i] != '\0'; i++)
    {
        H[str[i] - 97]++;
    }
    for (i = 0; i < 26; i++)
    {
        if (H[i] > 1)
            cout << char(i + 97) << "occurs " << H[i] << " times" << endl;
    }

    return 0;
}