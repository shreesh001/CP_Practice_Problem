#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int x,y,z;
        cin>>x>>y>>z;
        int a=x&y;
        int b=y&z;
        int c=x&z;
        if (a==b && b==c){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
}