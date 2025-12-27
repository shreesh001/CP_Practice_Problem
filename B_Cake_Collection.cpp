#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        vector<long long> a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        long long cakes=0;
        long long time=1;
        for (int i=n-1;i>=0;i--){
            if((m+1-time)>0){
                cakes+=(a[i]*(m+1-time));
                time++;
            }
            else{
                break;
            }
        }
        cout<<cakes<<endl;
    }
}