#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool ismaxormin(int val,set<int> &setper){
    if (val==(*setper.begin())){
        return true;
    }
    if (val==(*setper.rbegin())){
        return true;
    }
    return false;
}
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
        set<int> setper(a.begin(),a.end());
        int l=0;
        int r=n-1;
        int flag=0;
        while(l<r){
            if (ismaxormin(a[l],setper)){
                setper.erase(a[l]);
                l++;
                continue;
            }
            if (ismaxormin(a[r],setper)){
                setper.erase(a[r]);
                r--;
                continue;
            }
            flag=1;
            break;
        }
        if (flag==1){
            cout<<l+1<<" "<<r+1<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}