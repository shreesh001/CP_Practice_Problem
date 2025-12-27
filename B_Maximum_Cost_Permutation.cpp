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
        int l=-1;
        int r=-1;
        for (int i=0;i<n;i++){
            if (a[i]==0){
                l=i;
                break;
            }
        }
        for (int i=n-1;i>=0;i--){
            if (a[i]==0){
                r=i;
                break;
            }
        }
        int l1=-1;
        int r1=-1;
        for (int i=0;i<l;i++){
            if (a[i]!=i+1){
                l1=i;
                break;
            }
        }
        for (int i=n-1;i>r;i--){
            if (a[i]!=i+1){
                r1=i;
                break;
            }
        }
        if (l==r && (l==0 || l==n-1)){
            if (l==0){
                for (int i=1;i<n;i++){
                    if (a[i]!=i+1){
                        l=i;
                        break;
                    }
                }
            }
            else if (l==n-1){
                for (int i=n-2;i>=0;i--){
                    if (a[i]!=i+1){
                        r=i;
                        break;
                    }
                }
            }
        }
        if (l1!=-1 && l1<l) l=l1;
        if (r1!=-1 && r1>r) r=r1;
        int cost=r-l+1;
        if (l==r){
            cost=0;
        }
        cout<<cost<<endl;
    }
}