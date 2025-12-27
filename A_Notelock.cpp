#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int prot=0;
        int len=0;
        int ind=-1;
        for (int i=0;i<n;i++){
            if (prot==0 && s[i]=='1'){
                prot++;
                ind=i;
            }
            else if (prot!=0 && s[i]=='1' && i-ind>=k){
                prot++;
                ind=i;
            }
            else if (prot!=0 && s[i]=='1' && i-ind<k){
                ind=i;
            }
        }
        cout<<prot<<"\n";
    }
}