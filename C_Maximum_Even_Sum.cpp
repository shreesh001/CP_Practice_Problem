#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        long long maxsum=0;
            for (int i=1;i*i<=b;i++){
            if (b%i==0){
                long long sum=(i*a)+(b/i);
                if (sum%2==0){
                    maxsum=max(sum,maxsum);
                }
                sum=((b/i)*a)+((b)/(b/i));
                if (sum%2==0){
                    maxsum=max(sum,maxsum);
                }
            }
        }
        if (maxsum==0){
            cout<<-1<<endl;
        }
        else{
            cout<<maxsum<<endl;
        }
    }
}