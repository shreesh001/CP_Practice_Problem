#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        for (int i=0;i<n;i++) cin>>a[i];
        vector<long long> ans(n,0);
        ans[0]=1;
        int num=2;
        for (int i=1;i<n;i++){
            int diff=a[i]-a[i-1];
            if (diff>i){
                ans[i]=num;
                num++;
            }
            else{
                ans[i]=ans[i-diff];
            }
        }
        for (int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}