#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
#include <algorithm>
#include <windows.h>

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

    auto start = std::chrono::system_clock::now();
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[5] = {11, 12, 13, 14, 15};
    int c[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int alen = sizeof(a) / sizeof(a[0]);
    int blen = sizeof(b) / sizeof(b[0]);
    int clen = sizeof(c) / sizeof(c[0]);

    for (int i = 0; i < clen; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;

    reverse(0, alen + blen - 1, c);
    reverse(0, blen - 1, c);
    reverse(blen, alen + blen - 1, c);

    for (int i = 0; i < clen; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    // cout << "The book way run time is: " << clock()  << " " << endl;

    QueryPerformanceCounter(&t2);
    dt = (t2.QuadPart - t1.QuadPart) / (double)nFreq.QuadPart;
    cout << "book Running time :" << dt * 1000000 << "us" << endl; // dt
}

void reverse(int left, int right, int *c)
{
    int mid = (left + right) / 2;
    for (int i = 0; i < mid - left; i++)
    {
        int temp = c[left + i];
        c[left + i] = c[right - i];
        c[right - i] = temp;
    }
}