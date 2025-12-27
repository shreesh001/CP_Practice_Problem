#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        int subarray=0;
        int el=a[0];
        int cnt=1;
        for (int i=1;i<n;i++){
            if (a[i]==el || a[i]==el+1){
                continue;
            }
            else{
                cnt++;
                el=a[i];
            }
        }
        cout<<cnt<<endl;
    }
}