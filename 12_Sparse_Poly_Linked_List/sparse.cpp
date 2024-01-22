#include <iostream>
using namespace std;
struct Node
{
    int col;
    int val;
    struct Node *next;
};
void Create(struct Node *p[], int m)
{
    int i, j, c, x, nr, r = 0;
    struct Node *last;
    while (r < m)
    {
        p[r] = NULL;
        cout << "Enter number of elements in row " << r + 1 << " : ";
        cin >> nr;
        for (j = 0; j < nr; j++)
        {
            if (p[r] == NULL)
            {
                p[r] = new Node;
                last = p[r];
                cout << "Enter for row " << r << endl
                     << "Enter and column and value : ";
                cin >> c >> x;
                last->col = c;
                last->val = x;
                last->next = NULL;
            }
            else
            {
                last->next = new Node;
                cout << "Enter for row " << r << endl
                     << "Enter and column and value : ";
                cin >> c >> x;
                last = last->next;
                last->col = c;
                last->val = x;
                last->next = NULL;
            }
        }
        r++;
    }
}
void Display(struct Node *p[], int m, int n)
{
    struct Node *last;
    int i, j;
    for (i = 0; i < m; i++)
    {
        last = NULL;
        if (p[i] != NULL)
        {
            last = p[i];
        }

        for (j = 0; j < n; j++)
        {
            if (last && last->col == j)
            {
                cout << p[i]->val << " ";
                last = last->next;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void Add(struct Node *p1[], struct Node *p2[], struct Node *p3[], int m1, int n1, int m2, int n2)
{
    if (m1 != m2 || n1 != n2)
    {
        cout << "Not Possible !" << endl;
    }
    int i = 0, c;
    struct Node *l1, *l2, *l3;
    while (i < m1)
    {
        l1 = p1[i], l2 = p2[i], l3 = p3[i];
        c = 0;
        while (l1 != NULL && l2 != NULL)
        {
            if (c == 0)
            {
                if (l1->col == l2->col)
                {
                    l3 = new Node;
                    l3->col = l1->col;
                    l3->val = l1->val + l2->val;
                    l3->next = NULL;
                    l1 = l1->next;
                    l2 = l2->next;
                }
                else if (l1->col > l2->col)
                {
                    l3 = new Node;
                    l3->col = l2->col;
                    l3->val = l2->val;
                    l3->next = NULL;
                    l2 = l2->next;
                }
                else
                {
                    l3 = new Node;
                    l3->col = l1->col;
                    l3->val = l1->val;
                    l3->next = NULL;
                    l1 = l1->next;
                }
                c++;
            }
            else
            {
                struct Node *temp;
                temp = new Node;
                l3->next = temp;
                l3 = temp;
                if (l1->col == l2->col)
                {
                    temp->col = l1->col;
                    temp->val = l1->val + l2->val;
                    temp->next = NULL;
                    l1 = l1->next;
                    l2 = l2->next;
                }
                else if (l1->col > l2->col)
                {
                    temp->col = l2->col;
                    temp->val = l2->val;
                    temp->next = NULL;
                    l2 = l2->next;
                }
                else
                {
                    temp->col = l1->col;
                    temp->val = l1->val;
                    temp->next = NULL;
                    l1 = l1->next;
                }
            }
        }
        while (l1)
        {
            struct Node *temp;
            temp = new Node;
            l3->next = temp;
            temp->col = l1->col;
            temp->val = l1->val;
            temp->next = NULL;
            l3 = temp;
            l1 = l1->next;
        }
        while (l2)
        {
            struct Node *temp;
            temp = new Node;
            l3->next = temp;
            temp->col = l2->col;
            temp->val = l2->val;
            temp->next = NULL;
            l3 = temp;
            l2 = l2->next;
        }
        i++;
    }
}
int main()
{
    int m1, n1, m2, n2;
    cout << "Enter dimensions of sparse matrix 1 :";
    cin >> m1 >> n1;
    cout << "Enter dimensions of sparse matrix 2:";
    cin >> m2 >> n2;
    struct Node *A[m1];
    struct Node *B[m2];
    struct Node *C[m1];
    Create(A, m1);
    Create(B, m2);
    // Display(A, m1, n1);
    // Display(B, m2, n2);
    Add(A, B, C, m1, n1, m2, n2);
    Display(C, m1, n1);
    return 0;
}