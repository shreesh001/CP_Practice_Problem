#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int>a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        int x=-1;
        int y=-1;
        for (int i=1;i<n;i++){
            for (int j=0;j<i;j++){
                if ((a[i]%a[j])%2==0){
                    x=a[j];
                    y=a[i];
                    break;
                }
            }
        }
        if (x==-1){
            cout<<-1<<endl;
            continue;
        }
        cout<<x<<" "<<y<<endl;
    }
}