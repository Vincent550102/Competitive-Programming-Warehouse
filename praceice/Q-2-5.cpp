#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define Arr array<array<long long,2>,2>
ll p = 1000000007;
#define _ <<" "<<
Arr mat_time(Arr mata,Arr matb, ll p){
    //cout << "a" _ mata[0][0] _ mata[0][1] _ mata[1][0] _ mata[1][1]<<endl;
    //cout << "b" _ matb[0][0] _ matb[0][1] _ matb[1][0] _ matb[1][1]<<endl;
    Arr res_mat = {
            (mata[0][0]*matb[0][0]%p+mata[0][1]*matb[1][0]%p)%p, (mata[0][0]*matb[0][1]%p+mata[0][1]*matb[1][1]%p)%p,
            (mata[1][0]*matb[0][0]%p+mata[1][1]*matb[1][0]%p)%p, (mata[1][0]*matb[0][1]%p+mata[1][1]*matb[1][1]%p)%p
    };
    //cout << "res" _ res_mat[0][0] _ res_mat[0][1] _ res_mat[1][0] _ res_mat[1][1]<<endl;
    return res_mat;
}

Arr mat_pow_mod(Arr mat, ll y, ll p){
    //cout << y << endl;
    if(!y) return {1,0,0,1};
    if(y&1) return mat_time(mat, mat_pow_mod(mat, y-1, p), p);
    else{
            Arr tmp = mat_pow_mod(mat, y/2, p);
            return mat_time(tmp, tmp, p);
    }
}

int main() {
    ll y;
    while(cin >> y && y!=-1){
        Arr ans = mat_pow_mod({1,1,1,0}, y-1, p);
        cout << ans[0][0] << endl;
    }
}
