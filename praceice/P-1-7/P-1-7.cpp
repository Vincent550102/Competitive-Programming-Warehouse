#include<bits/stdc++.h>
#define P 10009
using namespace std;
vector<int> v;
int n;
int sol(int i = 0, int now = 1){
    if(i >= n){
        return now==1;
    }
    return sol(i+1, now*v[i]%P) + sol(i+1, now);
}

int main(){
    cin >> n;
    v.resize(n);
    for(int &x:v)
        cin >> x;

    cout << sol()-1 << endl;

}
