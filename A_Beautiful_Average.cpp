#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        int maxi=0;
        for (int i=0;i<n;i++){
            int el;
            cin>>el;
            maxi=max(maxi,el);
        }
        cout<<maxi<<"\n";
    }
}