#include <iostream>
using namespace std;
struct Stack
{
    int size;
    int Top;
    int *s;
};
void Create(struct Stack *st)
{
    int i;
    cout << "Enter size : ";
    cin >> st->size;
    st->Top = -1;
    st->s = new int[st->size];
}
void Display(struct Stack st)
{
    int i;
    for (i = st.Top; i >= 0; i--)
    {
        cout << st.s[i] << " ";
    }
    cout << endl;
}
void Push(struct Stack *st, int x)
{
    if (st->Top == st->size - 1)
    {
        cout << "Stack Overflow !" << endl;
    }
    else
    {
        st->Top++;
        st->s[st->Top] = x;
    }
}
int Pop(struct Stack *st)
{
    int x = -1;
    if (st->Top == -1)
        cout << "Stack Underflow !" << endl;
    else
    {
        x = st->s[st->Top--];
    }
    return x;
}
int Peek(struct Stack st, int pos)
{
    int x = -1;
    if (st.Top - pos + 1 < 0)
    {
        cout << "Invalid Index !" << endl;
    }
    else
    {
        x = st.s[st.Top - pos + 1];
    }
    return x;
}
int isEmpty(struct Stack st)
{
    if (st.Top == -1)
        return 1;
    return 0;
}
int isFull(struct Stack st)
{
    if (st.Top == st.size - 1)
        return 1;
    return 0;
}
int stackTop(struct Stack st)
{
    int x = -1;
    if (st.Top > -1 && st.Top < st.size)
        x = st.s[st.Top];
    return x;
}
int main()
{
    struct Stack st;
    Create(&st);
    Push(&st, 1);
    Push(&st, 2);
    Push(&st, 3);
    Push(&st, 4);
    Push(&st, 5);
    // // Push(&st, 6);
    // cout << Pop(&st) << endl;
    // cout << Pop(&st) << endl;
    // cout << Pop(&st) << endl;
    // cout << Pop(&st) << endl;
    // cout << Pop(&st) << endl;
    // cout << Pop(&st) << endl;
    // Display(st);
    // cout << Peek(st, 5);
    // cout << isEmpty(st);
    cout << stackTop(st);
    return 0;
}