#include<bits/stdc++.h>
#define _ <<" "<<
using namespace std;
int main(){
    int m, n; cin >> m >> n;
    multiset<string> S;
    for(int i = 0; i<n; i++){
        string str, tmp = ""; cin >> str;
        set<char> uni;
        for(char c:str)
            uni.insert(c);
        for(char c:uni)
            tmp+=c;
        S.insert(tmp);
    }
    int ans = 0;

    for(string s:S){
        //cout << s << endl;
        vector<bool> chk(m, 0);
        for(char c:s){
            chk[c-'A'] = 1;
        }
        string tar = "";
        for(int i = 0; i<m; i++){
            if(!chk[i]) tar+='A'+i;
        }
        //cout << s _ tar << endl;
        if(S.find(tar)!=S.end())
            ans++;
    }
    cout << ans/2 << endl;
}
