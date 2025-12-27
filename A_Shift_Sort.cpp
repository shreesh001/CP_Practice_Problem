#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cntzero=0;
        for (int i=0;i<n;i++){
            if (s[i]=='0'){
                cntzero++;
            }
        }
        int cnt0=0;
        for (int i=0;i<cntzero;i++){
            if (s[i]=='0'){
                cnt0++;
            }
        }
        cout<<cntzero-cnt0<<endl;
    }
}