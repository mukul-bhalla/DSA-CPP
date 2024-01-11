#include<iostream>
#include<stdlib.h>
using namespace std;
struct Rectangle{
    int l;
    int b;
};
int main(){
    // int a = 10;
    // int * p;
    // p = &a;

    // cout<<p<<endl;
    // cout<<*p<<endl;
    // cout<<a;


    // int A[5]={1,2,3,4,5};
    // int *p;
    // p = A;          //OR &A[0]
    // for (int i = 0 ;i<5;i++){
    //     cout<<p[i]<<endl;
    // }

    // int *p;
    // p = new int[5];
    // p[0]=10;
    // p[1]=15;
    // p[2]=20;
    // p[3]=25;
    // p[4]=40;
    // for (int i = 0 ;i<5;i++){
    //     cout<<*(p+i)<<endl;
    // }

    // delete [ ]p; 


    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle  *p5;

    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;

    return 0;
}