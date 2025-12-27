#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        long long n,c;
        cin>>n>>c;
        vector<long long> a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        for (int i=0;i<n;i++){
            a[i]+=(i+1);
        }
        sort(a.begin(),a.end());
        long long cnttele=0;
        for (int i=0;i<n;i++){
            if (a[i]>c){
                break;
            }
            cnttele++;
            c=c-a[i];
        }
        cout<<cnttele<<endl;
    }
}