#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        long long n,q;
        cin>>n>>q;
        vector<long long> a(n),b(q);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        for (int i=0;i<q;i++){
            cin>>b[i];
        }
        long long prev=31;
        for (int i=0;i<q;i++){
            if (b[i]>=prev) continue;
            for (int j=0;j<n;j++){
                if (a[j]%(1<<b[i])==0){
                    a[j]+=(1<<(b[i]-1));
                }
            }
            prev=b[i];
        }
        for (int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}