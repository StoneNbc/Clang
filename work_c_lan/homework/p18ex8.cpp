#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
#include <algorithm>
#include<windows.h>

using namespace std;


void reverse(int a, int b, int *rec);
int main()
{
    LARGE_INTEGER nFreq;
    LARGE_INTEGER t1;
    LARGE_INTEGER t2;
    LARGE_INTEGER t3;
    LARGE_INTEGER t4;
    double dt;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&t1);

    int a[10] = {1, 2, 3, 4, 5,6,7,8,9,10};
    int b[5] = {11,12,13,14,15};
    int c[15] = {1, 2, 3, 4, 5,6,7,8,9,10,11,12,13,14,15};
    int alen = sizeof(a)/sizeof(a[0]);
    int blen = sizeof(b)/sizeof(b[0]);
    int clen = sizeof(c)/sizeof(c[0]);

    for (int i = 0; i < clen; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
        reverse(alen, blen, c);


    for (int i = 0; i < clen; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    //cout << "The my way run time is: " <<(double)clock() << " " << endl;

    QueryPerformanceCounter(&t2);
    dt = (t2.QuadPart - t1.QuadPart) / (double)nFreq.QuadPart;
    cout << "My Running time :" << dt * 100000 << "us" << endl;//dt



}

void reverse(int a, int b, int rec[])
{
    int temp = 0;
    int reclen = a + b;
    if (a > b)
    {
        for (int i = 0; i < b; i++)
        {
            temp = rec[reclen - b];
            rec[reclen - b] = rec[i];
            rec[i] = temp;
        }
        for (int i = 1; i <= (a - b)/2; i++)
        {
            // cout<<"change"<< b + i<< reclen -b -i <<endl;
            temp = rec[b + i - 1];
            rec[b + i - 1] = rec[reclen - b - i];
            rec[reclen - b - i] = temp;
        }
    }
}
