

//时间复杂度O(n) 空间复杂度为O(n)

#include <iostream>

#define MAX 1024

using namespace std;
int *MergeArray(int *arr1, int *arr2, int len1, int len2);
int Mid(int *c,int num);

int main(){
    // int a[5]{11,13,15,17,19};
    // int b[5]{2,4,6,8,20};
    int a[5]{3,5,6,7,9};
    int b[5]{2,4,6,8,20};

    int alen = sizeof(a)/sizeof(a[0]);
    int blen = sizeof(b)/sizeof(b[0]);

    int * c=MergeArray(a,b,alen,blen);
    
    int res =Mid(c,alen+blen);
    cout<<res<<endl;
    return 0;
}

int Mid(int *c,int num){
    
    if(num%2==0)
        return c[num/2-1];
    else
        return c[num/2];

}

int *MergeArray(int *arr1, int *arr2, int len1, int len2) {
    if (arr1 == nullptr) {
        return arr2;
    }
    if (arr2 == nullptr) {
        return arr1;
    }
    if ((len1 + len2) > MAX) {
        return nullptr;
    }
 
    int *mergedArray = new int[len1 + len2];
    int p = len1 + len2 - 1;
    int p1 = len1 - 1;
    int p2 = len2 - 1;
    while (p1 >= 0 && p2 >= 0) {
        if (arr1[p1] > arr2[p2]) {
            mergedArray[p--] = arr1[p1--];
        } else {
            mergedArray[p--] = arr2[p2--];
        }
    }
    while (p1 >= 0) {
        mergedArray[p--] = arr1[p1--];
    }
    while (p2 >= 0) {
        mergedArray[p--] = arr2[p2--];
    }
 
    return mergedArray;
}
