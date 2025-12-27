#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        if (n%2==0){
            cout<<-1<<"\n";
            continue;
        }
        for (int i=0;i<n;i++){
            cout<<n-i<<" ";
        }
        cout<<endl;
    }
}