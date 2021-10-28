#include <bits/stdc++.h> 
using namespace std; 

#define size(arr) sizeof(arr)/sizeof(arr[0]);


int main(){

    int a[5] = {5, 2, 6,3 ,5};
    int n = size(a);
    sort((a), a + n);
    for(int i = 0; i < n; i++){
        cout << a[i];
    }


    return 0;

}