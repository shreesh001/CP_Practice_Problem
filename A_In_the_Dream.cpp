#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int slot=0;
        int consec=0;
        if (a>b){
            slot=b+1;
            consec=(a+b)/slot;
            if (consec>=3){
                cout<<"NO"<<endl;
            }
            else{
                int seca=c-a;
                int secb=d-b;
                if (seca>secb){
                    slot=secb+1;
                    consec=(seca+secb)/slot;
                    if (consec>=3){
                        cout<<"NO"<<endl;
                    }
                    else{
                        cout<<"YES"<<endl;
                    }
                }
                else{
                    slot=seca+1;
                    consec=(secb+seca)/slot;
                    if (consec>=3){
                        cout<<"NO"<<endl;
                    }
                    else{
                        cout<<"YES"<<endl;
                    }
                }
            }
        }
        else{
            slot=a+1;
            consec=(a+b)/slot;
            if (consec>=3){
                cout<<"NO"<<endl;
            }
            else{
                int seca=c-a;
                int secb=d-b;
                if (seca>secb){
                    slot=secb+1;
                    consec=(seca+secb)/slot;
                    if (consec>=3){
                        cout<<"NO"<<endl;
                    }
                    else{
                        cout<<"YES"<<endl;
                    }
                }
                else{
                    slot=seca+1;
                    consec=(secb+seca)/slot;
                    if (consec>=3){
                        cout<<"NO"<<endl;
                    }
                    else{
                        cout<<"YES"<<endl;
                    }
                }
            }
        }
    }
}