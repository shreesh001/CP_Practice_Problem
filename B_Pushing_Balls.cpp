#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        vector<vector<char> >a(n,vector<char>(m));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        bool flag1=true;
        bool flag2=true;
        for (int i=n-1;i>=0;i--){
            for (int j=m-1;j>=0;j--){
                flag1=true;
                flag2=true;
                if (a[i][j]=='1'){
                    for (int k=i-1;k>=0;k--){
                        if (a[k][j]=='0') {
                            flag1=false;
                            break;
                        }
                    }
                    for (int k=j-1;k>=0;k--){
                        if (a[i][k]=='0') {
                            flag2=false;
                            break;
                        }
                    }
                    if (flag1==false && flag2==false){
                        break;
                    }
                }
            }
            if (flag1==false && flag2==false){
                break;
            }
        }
        if (flag1==false && flag2==false){
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"YES"<<"\n";
        }
    }
}