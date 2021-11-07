    #include<bits/stdc++.h>
    #define _ <<" "<<
    using namespace std;
    int main(){
        int n;cin >> n;
        vector<int> v(n);
        map<int,int>MP;

        for(int i = 0; i<n; i++){
            cin >> v[i];
            MP[v[i]] = 0;
        }
        int cnter = 0;
        for(auto &x:MP){
            x.second = cnter++;
        }
        int tar = MP.size();
        for(int i = 0; i<n; i++)
            v[i] = MP[v[i]];
        vector<int> cnt(tar, 0);
        /*for(int x:v){
            cout << x << " ";
        }
        cout << endl;
    */
        int now = 0, ans = INT_MAX;
        for(int i = 0, j = 0; i<n; i++){
            if(!cnt[v[i]])
                now++;
            cnt[v[i]]++;
            //cout << i _ now _ tar << endl;
            if(now == tar){
                for(; j<=i; j++){
                    if(cnt[v[j]]>1)
                        cnt[v[j]]--;
                    else{
                        //cout << i _ j << endl;
                        ans = min(ans, i-j+1);
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
