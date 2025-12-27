#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<long long>a(n),maxel(n);
        long long maxi=0;
        for (int i=0;i<n;i++){
            cin>>a[i];
            maxi=max(maxi,a[i]);
            maxel[i]=maxi;
        }
        long long sum=0;
        vector<long long>ksum;
        ksum.push_back(maxel[n-1]);
        for (int i=n-1;i>=1;i--){
            sum+=a[i];
            sum+=maxel[i-1];
            ksum.push_back(sum);
            sum-=maxel[i-1];
        }
        for (int i=0;i<n;i++){
            cout<<ksum[i]<<" ";
        }
        cout<<endl;

    }
}