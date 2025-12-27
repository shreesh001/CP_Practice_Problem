#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    vector<int>t(q);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<q;i++){
        cin>>t[i];
    }
    map<int,int>mpp;
    for (int i=0;i<n;i++){
        if (mpp.find(a[i])==mpp.end()){
            mpp[a[i]]=i+1;
        }
    }
    int cnt=0;
    vector<int>ans;
    for (int i=0;i<q;i++){
        if (i>0 && t[i]==t[i-1]) {
            ans.push_back(1);
            continue;
        }
        ans.push_back(mpp[t[i]]);
        if (i!=q-1 && mpp[t[i]]>mpp[t[i+1]]) {
            cnt++;
            mpp[t[i+1]]+=cnt; 
        }
        mpp[t[i]]=1;
    }
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}