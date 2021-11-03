#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> S;
    for(int i = 0; i<50; i++){
        S.insert(rand()%100);
    }
    for(int x:S){
        cout << x << " ";
    }
}
