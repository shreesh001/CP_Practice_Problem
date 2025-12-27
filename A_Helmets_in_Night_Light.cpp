#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool comp(vector<int> &a,vector<int> &b){
    return a[1]<b[1];
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,p;
        cin>>n>>p;
        vector<vector<int>> a(n,vector<int>(2,0));
        for (int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i][0]=x;
        }
        for (int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i][1]=x;
        }
        sort(a.begin(),a.end(),comp);
        
    }
}