#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        string s;
        cin>>s;
        ll n=s.size();
        ll l=-1;
        ll r=0;
        ll maxlen=0;
        ll len1=0;
        ll len2=0;
        for (int i=0;i<n;i++){
            if (s[i]=='1'){
                len1++;
            }
            else{
                break;
            }
        }
        for (int i=n-1;i>=0;i--){
            if (s[i]=='1'){
                len2++;
            }
            else{
                break;
            }
        }
        if (len1==n){
            maxlen=n;
            cout<<(1ll*maxlen*maxlen)<<endl;
            continue;
        } 
        else maxlen=len1+len2;

        while(r<n){
            while(r<n && s[r]=='1'){
                maxlen=max(maxlen,r-l);
                r++;
            }
            if (s[r]=='0'){
                l=r;
            }
            r++;
        }
        if(maxlen==1 || maxlen==0){
            cout<<maxlen<<endl;
        }
        else if (maxlen<n) {
            cout<<(((maxlen+1)/2)*((maxlen+2)/2))<<endl;
        }
    }
}