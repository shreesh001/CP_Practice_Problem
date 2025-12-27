#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        int cnt=n%3;
        if (cnt!=0) {
            cnt=3-cnt;
        }
        cout<<cnt<<"\n";
    }
}