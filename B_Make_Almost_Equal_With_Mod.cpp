#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<long long> a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        long long ans=0;
        for (int k=1;k<=63;k++){
            set<long long> s;
            long long div= 1ll<<k;
            for (int i=0;i<n;i++){
                s.insert(a[i]%div);
            }
            if (s.size()==2){
                ans=div;
                break;
            }
        }
        cout<<ans<<endl;
    }
}