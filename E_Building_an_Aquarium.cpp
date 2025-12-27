#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool ispossible(vector<long long> &a, long long mid,long long x){
    long long water=0;
    for (int i=0;i<a.size();i++){
        if (a[i]<mid){
            water+=(mid-a[i]);
        }
    }
    if (water>x){
        return false;
    }
    return true;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        long long n,x;
        cin>>n>>x;
        vector<long long> a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        long long low=1;
        long long high=1e10;
        while(low<=high){
            long long mid=(low+high)/2;
            if (ispossible(a,mid,x)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        cout<<high<<endl;
    }
}