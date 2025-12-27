#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
long long check(vector<long long>&a){
    long long ans=a[0];
    for (int i=0;i<a.size();i++){
        ans=gcd(ans,a[i]);
    }
    return ans;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        long long n;
        cin>>n;
        vector<long long> v(n);
        for (int i=0;i<n;i++) cin>>v[i];
        vector<long long> fst,sec;
        for (int i=0;i<n;i++){
            if (i%2==0){
                fst.push_back(v[i]);
            }
            else{
                sec.push_back(v[i]);
            }
        }
        long long ft=check(fst);
        int flag=0;
        for (int i=0;i<sec.size();i++){
            if (sec[i]%ft==0){
                flag=1;
                break;
            }
        }
        if (flag==0){
            cout<<ft<<"\n";
            continue;
        }
        flag=0;
        long long sc=check(sec);
        for (int i=0;i<fst.size();i++){
            if (fst[i]%sc==0){
                flag=1;
                break;
            }
        }
        if (flag==0){
            cout<<sc<<"\n";
        }
        else{
            cout<<"0\n";
        }
    }
}