#include <iostream>
#include <string>
using namespace std;
int main()
{
    char s[10];
    int i, vowels = 0, consonants = 0, words;
    cout << "Enter your name";
    gets(s);
    words = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            vowels++;
        }
        else if ((s[i] <= 90 && s[i] >= 65) || (s[i] <= 122 && s[i] >= 97))
        {
            consonants++;
        }
        else if (s[i] == ' ')
        {
            while (s[i] == ' ')
                i++;
            cout << words << endl;
            words++;
        }
    }
    words++;
    cout << vowels << " " << consonants << " " << words;
    return 0;
}