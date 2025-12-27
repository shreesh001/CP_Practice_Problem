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
        bool beautiful=false;
        bool morebeauty=false;
        vector<int> b(n);
        b=a;
        sort(b.begin(),b.end());
        if (b!=a){
            sort(b.rbegin(),b.rend());
            if (b!=a){
                beautiful=true;
            }
        }
        for (int i = 0; i + 1 < n; i++) {
            if (abs(a[i] - a[i + 1]) <= 1) {
                morebeauty = true;
                break;
            }
        }
        if (morebeauty){
            cout<<0<<endl;
        }
        else if(beautiful){
            cout<<1<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}