// // Infix to Postfix Conversion
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// struct Node
// {
//     char data;
//     struct Node *next;
// } *top = NULL;
// void push(char x)
// {
//     struct Node *t;
//     t = (struct Node *)malloc(sizeof(struct Node));

//     if (t == NULL)
//         printf("stack is full\n");
//     else
//     {
//         t->data = x;
//         t->next = top;
//         top = t;
//     }
// }
// char pop()
// {
//     struct Node *t;
//     char x = -1;

//     if (top == NULL)
//         printf("Stack is Empty\n");
//     else
//     {
//         t = top;
//         top = top->next;
//         x = t->data;
//         free(t);
//     }
//     return x;
// }
// void Display()
// {
//     struct Node *p;
//     p = top;
//     while (p != NULL)
//     {
//         printf("%d ", p->data);
//         p = p->next;
//     }
//     printf("\n");
// }
// int isBalanced(char *exp)
// {
//     int i;

//     for (i = 0; exp[i] != '\0'; i++)
//     {
//         if (exp[i] == '(')
//             push(exp[i]);
//         else if (exp[i] == ')')
//         {
//             if (top == NULL)
//                 return 0;
//             pop();
//         }
//     }
//     if (top == NULL)
//         return 1;
//     else
//         return 0;
// }
// int pre(char x)
// {
//     if (x == '+' || x == '-')
//         return 1;
//     else if (x == '*' || x == '/')
//         return 2;
//     return 0;
// }

// int isOperand(char x)
// {
//     if (x == '+' || x == '-' || x == '*' || x == '/')
//         return 0;
//     else
//         return 1;
// }

// char *InToPost(char *infix)
// {
//     int i = 0, j = 0;
//     char *postfix;
//     int len = strlen(infix);
//     postfix = (char *)malloc((len + 1) * sizeof(char));

//     while (infix[i] != '\0')
//     {
//         if (isOperand(infix[i]))
//             postfix[j++] = infix[i++];
//         else
//         {
//             if (pre(infix[i]) > pre(top->data))
//                 push(infix[i++]);
//             else
//             {
//                 postfix[j++] = pop();
//             }
//         }
//     }
//     while (top != NULL)
//         postfix[j++] = pop();
//     postfix[j] = '\0';
//     return postfix;
// }

// int Better_Pre_Out(char c)
// {
//     if (c == '+' || c == '-')
//         return 1;
//     if (c == '*' || c == '/')
//         return 3;
//     if (c == '^')
//         return 6;
//     if (c == '(')
//         return 7;
//     if (c == ')')
//         return 0;
//     else
//         return -1;
// }
// int Better_Pre_In(char c)
// {
//     if (c == '+' || c == '-')
//         return 2;
//     if (c == '*' || c == '/')
//         return 4;
//     if (c == '^')
//         return 5;
//     if (c == '(')
//         return 0;
//     else
//         return -1;
// }

// char *Better_Infix_to_Postfix(char *infix)
// {
//     int i = 0, j = 0;
//     char *postfix;
//     int len = strlen(infix);
//     postfix = (char *)malloc((len + 1) * sizeof(char));
//     while (infix[i] != '\0')
//     {
//         if (isOperand(infix[i]))
//         {
//             postfix[j++] = infix[i++];
//         }
//         else
//         {
//             if (Better_Pre_Out(infix[i]) > Better_Pre_In(top->data) || top == NULL)
//             {
//                 push(infix[i++]);
//             }
//             else
//             {

//                 if (Better_Pre_Out(infix[i]) == Better_Pre_In(top->data))
//                 {
//                     pop();
//                     i++;
//                 }
//                 else
//                     postfix[j++] = pop();
//             }
//         }
//     }
//     while (top != NULL)
//         postfix[j++] = pop();
//     postfix[j] = '\0';
//     return postfix;
// }

// int main()
// {
//     char *infix = "((a+b)*c)-d^e^f";
//     char *postfix = Better_Infix_to_Postfix(infix);

//     printf("%s ", postfix);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *S;
};

void push(struct Stack *st, char x)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

char pop(struct Stack *st)
{
    if (st->top == -1)
        printf("Stack Underflow");
    else
    {
        return st->S[st->top--];
    }
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '/' || x == '*' || x == '(' || x == ')' || x == '^')
        return 0;
    else
        return 1;
}

int outPre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '/' || x == '*')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
    else
        return -1;
}

int inPre(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '/' || x == '*')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    else
        return -1;
}

char *InToPost(char *infix)
{
    int len = strlen(infix);
    int i = 0, j = 0;
    struct Stack st;
    char *postfix = (char *)malloc((len + 1) * sizeof(char));
    st.size = len;
    st.top = -1;
    st.S = (char *)malloc(st.size * sizeof(char));

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (st.top == -1 || outPre(infix[i]) > inPre(st.S[st.top]))
                push(&st, infix[i++]);
            else
            {
                if (outPre(infix[i]) == inPre(st.S[st.top]))
                {
                    pop(&st);
                    i++;
                }
                else
                    postfix[j++] = pop(&st);
            }
        }
    }
    while (st.top != -1)
    {
        postfix[j++] = pop(&st);
    }

    postfix[j] = '\0';
    return postfix;
}

void main()
{
    char *infix = "((a+b)*c)-d^e^f";

    char *postfix = InToPost(infix);

    printf("\n%s", postfix);
}