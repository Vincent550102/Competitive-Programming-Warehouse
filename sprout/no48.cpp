#include<bits/stdc++.h>
using namespace std;
//vector<int>T,S;
int rt,T[10005],S[10005];
void back_(int l,int r){
    if(l>r)return;
    int i;
    for(i=l;i<=r;i++)if(T[i]==S[rt])break;
    rt++;
    back_(l,i-1);
    back_(i+1,r);
    cout<<T[i]<<endl;
}
int main(){
    int M;
    int st=0;
    while(cin>>M){
        S[st]=M;
        T[st++]=M;
    }
    sort(T,T+st);
    rt=0;
    back_(0,st-1);
}
