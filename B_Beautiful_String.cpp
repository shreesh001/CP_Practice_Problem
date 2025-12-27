#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool ischeck(string s){
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if (s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solve(string s){
    int n=s.size();
    int l=0;
    int r=0;
    while(r+1<n){
        if (s[r]-'0'<=s[r+1]-'0'){
            l=r;
            while (r+1<s.size() && s[r]-'0'<=s[r+1]-'0'){
                r++;
            }
            string str=s.substr(0,l)+s.substr(r+1,s.size()-r-1);
            if (ischeck(str)){
            cout<<r-l+1<<"\n";
            for (int i=l;i<=r;i++){
                cout<<i+1<<" ";
            }
            cout<<endl;
            return;
            }
        }
        r++;
    }
    if (r==n){
        cout<<-1<<endl;
        return;
    }
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        solve(s);
    }
}