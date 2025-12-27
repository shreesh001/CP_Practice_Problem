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
        int num=a[0];
        int num2=a[1];
        int ans;
        for (int i=2;i<n;i++){
            if (num==num2){
                if (a[i]!=num){
                    ans=i+1;
                    break;
                }
            }
            else if (a[i]==num2 && a[i]!=num){
                ans=1;
                break;
            }
            else if (a[i]==num && a[i]!=num2){
                ans=2;
                break;
            }
        }
        cout<<ans<<endl;
    }
}