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
        for (int i=0;i<n;i++) cin>>a[i];
        int checkeven=0;
        int checkodd=0;
        for (int i=0;i<n;i++){
            if (a[i]%2==0) checkeven=1;
            if (a[i]%2==1) checkodd=1;
        }
        if (checkeven==0 || checkodd==0){
            for (int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
        }
        else{
            sort(a.begin(),a.end());
            for (int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
        }
        cout<<"\n";
    }
}