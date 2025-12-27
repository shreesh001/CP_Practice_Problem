#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        cin>>n>>k;
        vector<long long> a(n),b(k);
        for (int i=0;i<n;i++) cin>>a[i];
        for (int i=0;i<k;i++) cin>>b[i];
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        sort(b.begin(),b.end());
        int lastbuy=-1;
        long long totalpaid=0;
        for (int i=0;i<k;i++){
            int grp=b[i];
            for (int j=lastbuy+1;j<=min(n-1,lastbuy+grp);j++){
                totalpaid+=a[j];
            }
            lastbuy+=grp;
            if (lastbuy>n-1) break;
            totalpaid-=a[lastbuy];
        }
        if (lastbuy+1<=n-1){
            while(lastbuy+1!=n){
                totalpaid+=a[lastbuy+1];
                lastbuy++;
            }
        }
        cout<<totalpaid<<endl;
    }
}