#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        long long a,b;
        cin>>a>>b;
        long long val=a^b;
        if (a==b){
            cout<<0<<"\n";
            continue;
        }
        if (val<=a){
            cout<<1<<"\n";
            cout<<val<<"\n";
            continue;
        }
        int op=0;
        int x=a;
        vector<int> ans;
        while(a>=0 && op<=100){
            x=x^(a-1);
            a--;
            ans.push_back(a);
            if (x==b) break;
            op++;
        }
        if (op>100 || a<0) {
            cout<<-1<<"\n";
            continue;
        }
        cout<<(int)ans.size();
        cout<<"\n";
        for (auto el:ans) cout<<el<<" ";
        cout<<"\n";
    }
}