#include <iostream>
#define SIZE 10
using namespace std;

int hashfn(int key)
{
    return key % 10;
}
int probe(int H[], int key)
{

    int index = hashfn(key);
    int i = 0;
    while ((H[(index + i) % 10]) != 0 && i < 10)
    {
        i++;
    }
    return (index + i) % SIZE;
}

void insert(int H[], int key)
{
    int index = hashfn(key);
    if (H[index] != 0)
    {
        index = probe(H, key);
    }

    H[index] = key;
}

int Search(int H[], int key)
{
    int index = hashfn(key);
    int i = 0;
    while (H[(index + i) % SIZE] != key)
    {
        i++;
    }
    return (index + i) % SIZE;
}

int main()
{
    int HT[10] = {0};
    insert(HT, 12);
    insert(HT, 25);
    insert(HT, 35);
    insert(HT, 26);
    cout << Search(HT, 2);
    // for (int x : HT)
    // {
    //     cout << x << " ";
    // }
    return 0;
}