#include<bits/stdc++.h>
using namespace std;
#define mxN 20
#define _ <<' '<<
int G[mxN][mxN], n;
int ans = 0;

void sol(int k, int sum, int *p){
    /*cout << k _ sum << endl << " > ";
    for(int i = 0; i<k; i++){
        cout << p[i] << " ";
    }
    cout << endl;*/
    if(k>=n){
        ans = max(sum, ans);
        return;
    }
    bool vaild[mxN];

    for(int i = 0; i<n; i++){
        vaild[i] = true;
    }

    for(int i = 0; i<k; i++){
        if(p[i]!=-1){
            vaild[p[i]] = false;
            if(p[i]-(k-i)<n)
                vaild[p[i]-(k-i)] = false;
            if(p[i]+(k-i)>=0)
                vaild[p[i]+(k-i)] = false;
        }

    }
    for(int i = 0; i<n; i++){
        if(vaild[i]){
            //cout << k _ i << endl;
            p[k] = i;
            sol(k+1, sum + G[i][k], p);
        }
    }
    p[k] = -1;
    sol(k+1, sum , p);

}

int main(){
    int p[mxN] = {0};
    cin >> n;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin >> G[i][j];

    sol(0, 0, p);
    cout << ans << endl;

}
