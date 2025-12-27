#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<long long> a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<long long> ml;
        int maxi=a[0];
        ml.push_back(a[0]);
        for (int i=1;i<n;i++){
            if (a[i]>maxi){
                maxi=a[i];
            }
            ml.push_back(maxi);
        }
        long long total=0;
        for (int i=1;i<n;i+=2){
            if (a[i]>a[i-1] && (i + 1< n? a[i]>a[i + 1]:true)){
                continue;
            }
            else{
                long long op1=a[i-1];
                long long op2=0;
                if (i+1<n){
                    op2=a[i+1];
                }
                if (ml[i]<=op1){
                    total+=(op1-ml[i]+1);
                    a[i-1]-=(op1-ml[i]+1);
                }
                if (ml[i]<=op2){
                    total+=(op2-ml[i]+1);
                    a[i+1]-=(op2-ml[i]+1);
                }
            }
        }
        cout<<total<<endl;

    }
}