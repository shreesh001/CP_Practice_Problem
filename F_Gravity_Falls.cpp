#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        int maxsz=0;
        vector<vector<int>> vec(n);
        for (int i=0;i<n;i++){
            int k;
            cin>>k;
            maxsz=max(maxsz,k);
            vec[i].resize(k);
            for (int j=0;j<k;j++){
                cin>>vec[i][j];
            }
        }
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
        return a > b; // min-heap (lexicographically smallest on top)
        };
        priority_queue<vector<int>, vector<vector<int> >, decltype(cmp)> pq(cmp);
        
        for (int i=0;i<n;i++){
            pq.push(vec[i]);
        }
        int ind=0;
        vector<int> ans(maxsz,0);
        while(!pq.empty()){
            vector<int> a=pq.top();
            pq.pop();
            if (ind<a.size()){
                for (int i=ind;i<a.size();i++){
                    ans[i]=a[i];
                }
                ind=a.size();
            }
        }
        for (int i=0;i<maxsz;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}