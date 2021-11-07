#include<bits/stdc++.h>
using namespace std;
#define _ <<" "<<
int n;
vector<int> v;
// is that L can get L different color
bool f(int L, int tar){
    vector<int> cnt(tar, 0);
    int num = 0;
    for(int i = 0; i<n; i++){
        if(!cnt[v[i]])
            num++;
        cnt[v[i]]++;
        if(i-L>=0){
            if(cnt[v[i-L]]==1){
                num--;
            }
            cnt[v[i-L]]--;
        }
        //cout << i _ num _ tar << endl;
        if(num == L) return 1;
    }
    return 0;

}

int main(){
    cin >> n;
    v.resize(n);
    map<int,int> MP;
    for(int &x:v){
        cin >> x;
        MP[x] = 0;
    }
    int cnter = 0;
    for(auto &x:MP){
        x.second = cnter++;
    }
    for(int &x:v)
        x = MP[x];
    int tar = MP.size();

    //cout << f(5, tar);


    /*for(int i = 0; i<n; i++){
        cout << i _ f(i, tar) << endl;
    }*/
    int lb = 1, rb = n-1;
    while(lb<=rb){
        int mb = lb+rb>>1;
        if(f(mb, tar)) lb = mb+1;
        else rb = mb-1;
    }
    cout << rb << endl;
}
