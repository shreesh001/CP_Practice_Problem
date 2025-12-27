#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<long long> a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        int cntN=0;
        for (int i=0;i<n;i++){
            if (a[i]<0){
                cntN++;
            }
            a[i]=abs(a[i]);
        }
        sort(a.begin(),a.end());
        long long sum=0;
        for (int i=1;i<n;i++){
            sum+=a[i];
        }
        if (cntN%2==1){
            sum=sum-a[0];
        }
        else{
            sum=sum+a[0];
        }
        cout<<sum<<endl;
    }
}