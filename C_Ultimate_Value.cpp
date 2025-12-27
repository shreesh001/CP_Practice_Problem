#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        if (n==1){
            cout<<a[0]<<endl;
            continue;
        }
        int sum=0;
        int min1=a[0];
        int ind1=0;
        int max2=a[1];
        int ind2=1;
        for (int i=0;i<n;i+=2){
            sum+=a[i];
            if (min1>a[i]){
                min1=a[i];
                ind1=i;
            }
        }
        for (int i=1;i<n;i+=2){
            sum-=a[i];
            if (max2<=a[i]){
                max2=a[i];
                ind2=i;
            }
        }
        if (min1>=max2){
            if (n%2==0){
                sum+=(n-2);
            }
            else{
                sum+=(n-1);
            }
            cout<<sum<<endl;
            continue;
        }
        else{
            long long cost=abs(ind1-ind2);
            sum+=2*(max2-min1);
            sum+=cost;
            cout<<sum<<endl;
        }
    }
}