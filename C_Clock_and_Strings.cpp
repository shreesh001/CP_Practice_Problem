#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if (a>b){
            int temp=a;
            a=b;
            b=temp;
        }
        if (c>d){
            int temp=c;
            c=d;
            d=temp;
        }
        if ((c>a && c<b && d>a && d<b)){
            cout<<"NO"<<endl;
        }
        else if ((c<a && d<a) || (c>b && d>b) || (c<a && d>b)){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}