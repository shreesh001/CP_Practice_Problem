#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int Length(int n) {
    if (n == 0) return 1;
    int cnt = 0;
    while (n > 0) {
        cnt++;
        n >>= 1; 
    }
    return cnt;
}
int number(vector<int>& a) {
    int num=0;
    for (int bit : a)
        num = num * 2 + bit;
    return num;
}
bool solve(int n,int len){
    vector<int> upper,lower;
    int times=0;
    while(times<len-1){
        int digit=(n>>times)&1;
        if (times==len-2 && len%2==0){
            upper.push_back(1);
        }
        else if (digit==1){
            upper.push_back(1);
            lower.push_back(0);
        }
        else{
            upper.push_back(1);
            lower.push_back(1);
        }
        times++;
    }
    reverse(lower.begin(),lower.end());
    upper.insert(upper.end(),lower.begin(),lower.end());
    vector<int> rev=upper;
    reverse(rev.begin(),rev.end());
    int num=number(upper)^number(rev);
    return num==n;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        if (n==0 || n==3){
            cout<<"YES"<<endl;
            continue;
        }
        int len=Length(n);
        if (solve(n,len)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}