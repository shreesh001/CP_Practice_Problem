#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        long long n,p;
        cin>>n>>p;
        vector< vector <long long> > a(n,vector<long long>(2,0));
        for (int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i][1]=x;
        }
        for (int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i][0]=x;
        }

        sort(a.begin(),a.end());

        if (a[0][0]>=p){
            cout<<(1ll)*n*p<<"\n";
            continue;
        }

        long long cost=p;
        int i=0;
        int flag=1;
        while(i<n && flag<n){
            if (a[i][0]>=p) break;
            if (flag==n) break;
            int time=a[i][1];
            int need=n-flag;
            int cnt=min(need,time);
            cost+=(long long)cnt*a[i][0];
            flag+=cnt;
            i++;
        }
        if (flag<n){
            cost+=(n-flag)*p;
        }
        cout<<cost<<"\n";
    }
}