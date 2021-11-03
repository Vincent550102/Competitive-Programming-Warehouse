#include<bits/stdc++.h>
using namespace std;
#define mxN 15
int m, n;
int ans = INT_MAX;

void sol(int mat[][mxN], int sum = 0, int r = m, int c = n){
    if(r==1||c==1){
        ans = min(ans, sum);
        return;
    }
    int nmat[mxN][mxN];
    int z = 0, o = 0;
    for(int i = 0; i<c; i++){
        if(mat[0][i]) o++;
        else z++;
    }
    for(int i = 1; i<r; i++){
        for(int j = 0; j<c; j++){
            nmat[i-1][j] = mat[i][j];
        }
    }
    sol(nmat, sum+min(z,o), r-1, c);

    z = o = 0;
    for(int i = 0; i<c; i++){
        if(mat[r-1][i]) o++;
        else z++;
    }
    for(int i = 0; i<r-1; i++){
        for(int j = 0; j<c; j++){
            nmat[i][j] = mat[i][j];
        }
    }
    sol(nmat, sum+min(z,o), r-1, c);

    z = o = 0;
    for(int i = 0; i<r; i++){
        if(mat[i][0]) o++;
        else z++;
    }
    for(int i = 0; i<r; i++){
        for(int j = 1; j<c; j++){
            nmat[i][j-1] = mat[i][j];
        }
    }
    sol(nmat, sum+min(z,o), r, c-1);

    z = o = 0;
    for(int i = 0; i<r; i++){
        if(mat[i][c-1]) o++;
        else z++;
    }
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c-1; j++){
            nmat[i][j] = mat[i][j];
        }
    }
    sol(nmat, sum+min(z,o), r, c-1);
}

int main(){
    int mat[mxN][mxN];
    cin >> m >> n;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> mat[i][j];
        }
    }

    sol(mat);
    cout << ans << endl;
}
