#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        for (int i=0;i<n;i++){
                cin>>a[i];
        }
        long long maxdiff=0;
        for (int k=1;k*k<=n;k++){
            if (n%k==0){
                long long maxval=0;
                long long minval=1e15;
                long long sum=0;
                int cnt=0;
                for (int i=0;i<n;i++){
                    sum+=a[i];
                    cnt++;
                    if (cnt==k){
                        maxval=max(maxval,sum);
                        minval=min(minval,sum);
                        sum=0;
                        cnt=0;
                    }
                }
                maxdiff=max(maxdiff,maxval-minval);
                int div=n/k;
                if (div!=n){
                    maxval=0;
                    minval=1e15;
                    sum=0;
                    cnt=0;
                    for (int i=0;i<n;i++){
                    sum+=a[i];
                    cnt++;
                    if (cnt==div){
                        maxval=max(maxval,sum);
                        minval=min(minval,sum);
                        sum=0;
                        cnt=0;
                    }
                    }
                    maxdiff=max(maxdiff,maxval-minval);
                }
            }
        }
        cout<<maxdiff<<endl;
    }
}