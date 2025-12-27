#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<long long>a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        long long ans=-1;
        int flag=0;
        for (long long i=2;i<=2000;i++){
            for (int j=0;j<n;j++){
                if (gcd(a[j],i)==1) {
                    ans=i;
                    flag=1;
                    break;
                }
            }
            if (flag==1) break;
        }
        cout<<ans<<endl;
    }
}