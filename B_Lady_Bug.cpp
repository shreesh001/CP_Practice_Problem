#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        int len1=(n+1)/2;
        int cnt01=0;
        int bottom1=0;
        for (int i=0;i<n;i+=2){
            if (a[i]=='0') cnt01++;
            if (i+1<n && b[i+1]=='0') bottom1++;
        }
        int req1=len1-cnt01;

        int len2=n/2;
        int cnt02=0;
        int bottom2=0;
        for (int i=0;i<n;i+=2){
            if (i+1<n && a[i+1]=='0') cnt02++;
            if (b[i]=='0') bottom2++;
        }
        int req2=len2-cnt02;
        if (req2<=bottom2 && req1<=bottom1){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
}