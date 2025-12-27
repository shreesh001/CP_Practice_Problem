#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int ispossible(long long x,long long mid){
    long long dupx=1ll*2*x;
    long long ans=0;
    for (int i=mid;i>0;i--){
        ans+=(1ll<<i);
        if (ans>dupx){
            return 2;
        }
    }
    if (ans==dupx){
        return 1;
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long k,x;
        cin>>k>>x;
        long long cakesC=1ll<<k;
        int flag1=0;
        if (x>cakesC){
            x=(2*cakesC)-x;
            flag1=1;
        }
        int step=-1;
        long long low=0;
        long long high=120+5;
        while(low<=high){
            long long mid=(low+high)/2;
            int val=ispossible(x,mid);
            if (val==1){
                step=mid;
                break;
            }
            else if (val==2){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if (step==-1){
            cout<<0<<endl;
        }
        else{
            cout<<step<<endl;
            if (flag1==1){
                for (int i=1;i<step;i++){
                    cout<<1<<" ";
                }
                cout<<2;
            }
            else{
                for (int i=1;i<step;i++){
                    cout<<2<<" ";
                }
                cout<<1;
            }
        }
        cout<<endl;
    }
}