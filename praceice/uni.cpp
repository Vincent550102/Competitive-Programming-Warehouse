#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    map<int,int> MP;
    for(int &x:v){
        cin >> x;
        MP[x] = x;
    }
    int cnt = 0;
    for(auto &x:MP){
        x.second = cnt++;
    }



    for(int x:v)
        cout << MP[x] << " ";
    cout << endl;
}
