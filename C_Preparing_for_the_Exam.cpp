#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a(m),q(k);
        for (int i=0;i<m;i++) cin>>a[i];
        for (int i=0;i<k;i++) cin>>q[i];
        if ((n-k)==0){
            string s(m, '1');
            cout<<s<<endl;
            continue;
        }
        if ((n-k)>=2){
            string s(m, '0');
            cout<<s<<endl;
            continue;
        }
        if ((n-k)==1){
            unordered_map<int,int>mpp;
            for (int i=0;i<k;i++){
                mpp[q[i]]++;
            }
            string s="";
            for (int i=0;i<m;i++){
                if (mpp.find(a[i])!=mpp.end()){
                    s=s+'0';
                }
                else{
                    s=s+'1';
                }
            }
            cout<<s<<endl;
        }
        
    }
}