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
        int flag=0;
        int l=0;
        int r=0;
        while(r<n){
            if (s[r]=='0'){
                r++;
                l=r;
            }
            else {
                r++;
            }
            if ((r-l)==k){
                flag=1;
                break;
            }
        }
        int cnt1=0;
        if (flag==1){
            cout<<"NO";
        }
        else{
            cout<<"YES"<<endl;
            for (int i=0;i<n;i++){
                if (s[i]=='1'){
                    cnt1++;
                }
            }
            int k=1;
            int j=cnt1+1;
            for (int i=0;i<n;i++){
                if (s[i]=='1'){
                    cout<<k<<" ";
                    k++;
                }
                else{
                    cout<<j<<" ";
                    j++;
                }
            }
        }
        cout<<endl;
    }
}