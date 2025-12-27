#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        map<char,int>mp;
        for (int i=0;i<n;i++){
            mp[t[i]]++;
        }
        int flag=0;
        for (int i=0;i<n;i++){
            if (mp.find(s[i])==mp.end()){
                flag=1;
                cout<<"NO\n";
                break;
            }
            else {
                mp[s[i]]--;
                if (mp[s[i]]==0) mp.erase(s[i]);
            }
        }
        if (flag==0) cout<<"YES\n";
    }
}