#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        ll n,x;
        cin>>n>>x;
        vector<ll> a(n),b(n),c(n);
        for (int i=0;i<n;i++) cin>>a[i];
        for (int i=0;i<n;i++) cin>>b[i];
        for (int i=0;i<n;i++) cin>>c[i];
        stack<ll> st1,st2,st3;
        for (int i=n-1;i>=0;i--){
            st1.push(a[i]);
            st2.push(b[i]);
            st3.push(c[i]);
        }
        ll ans=0;
        int flag=0;
        while(!st1.empty() || !st2.empty() || !st3.empty()){
            if (ans==x){
                flag=1;
                break;
            }
            ll el1= st1.empty() ? -1: st1.top();
            ll el2= st2.empty() ? -1: st2.top();
            ll el3= st3.empty() ? -1: st3.top();
            if (!st1.empty() && (x|el1)==(x) && ((ans|el1)<=x)){
                st1.pop();
                ans=ans|el1;
            }
            else if (!st2.empty() && (x|el2)==(x) && ((ans|el2)<=x)){
                st2.pop();
                ans=ans|el2;
            }
            else if (!st3.empty() && (x|el3)==(x) && ((ans|el3)<=x)){
                st3.pop();
                ans=ans|el3;
            }
            else{
                break;
            }
            if (ans==x){
                flag=1;
                break;
            }
        }
        if (flag==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}