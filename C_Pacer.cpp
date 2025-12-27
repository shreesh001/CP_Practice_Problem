#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int> >a(n);
        for (int i=0;i<n;i++){
            cin>>a[i].first;
            cin>>a[i].second;
        }
        int flag=0;
        int pt=m;
        for (int i=0;i<n;i++){
            int el1=0;
            int el2=0;
            if (a[i].first%2!=0) el1=1;
            if (a[i].second%2!=0) el2=1;
            if (flag==0){
                if (el1!=el2){
                    pt--;
                    flag=1;
                }
            }
            if (flag==1){
                if (el1==el2){
                    pt--;
                    flag=0;
                }
            }
        }
        cout<<pt<<endl;
    }
}