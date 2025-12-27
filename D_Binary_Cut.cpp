#include<bits/stdc++.h>
using namespace std;
bool issorted(string s){
    string p=s;
    sort(p.begin(),p.end());
    if (s==p){
        return true;
    }
    return false;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        string s;
        cin>>s;
        int n=s.size();
        if (issorted(s)){
            cout<<1<<endl;
            continue;
        }
        int i=1;
        char prev=s[0];
        int cnt=0;
        while(i<n){
            if (prev!=s[i]){
                cnt++;
            }
            prev=s[i];
            i++;
        }
        if (cnt==1 && s[0]=='1'){
            cnt++;
        }
        cout<<cnt<<endl;
    }
}