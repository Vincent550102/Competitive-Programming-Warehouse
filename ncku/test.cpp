#include<bits/stdc++.h>
using namespace std;
int main(){
    multiset<int> c = {1, 2, 3, 4, 4, 5, 6, 7, 8, 9};
    c.erase(c.lower_bound(10));
    for(int x:c){
        cout << x << " ";
    }
    cout <<endl;
}
