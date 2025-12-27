#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        set<int> st;
        for (int i=0;i<n;i++){
            st.insert(arr[i]);
        }
        int ind=0;
        for (auto el:st){
            if (ind!=el) {
                break;
            }
            ind++;
        }
        cout<<ind<<endl;
    }
}
