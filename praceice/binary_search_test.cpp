#include<bits/stdc++.h>
using namespace std;
#define All(x) x.begin(),x.begin()+x.size()
int my_binary_search(vector<int> v, int tar){
    int lb = 0, rb = v.size()-1;
    while(lb<=rb){
        int mb = lb+rb>>1;
        if(v[mb]<tar) lb = mb+1;
        else rb = mb-1;
    }
    return lb;
}

int main(){
    vector<int> v1 = {1,3,4,7,9,10};
    if(my_binary_search(v1, 0) != lower_bound(All(v1), 0)-v1.begin()){
        printf("1 wrong");
    }
    cout << my_binary_search(v1, 0) << lower_bound(All(v1), 0)-v1.begin();
    vector<int> v2 = {2,15,17,19,23};
    if(my_binary_search(v2, 19) != lower_bound(All(v2), 19)-v2.begin()){
        printf("2 wrong");
    }
    vector<int> v3 = {2,5,13,19,23};
    if(my_binary_search(v3, 28) != lower_bound(All(v3), 28)-v3.begin()){
        printf("3 wrong %d %d", my_binary_search(v3, 28), lower_bound(All(v3), 28)-v3.begin());
    }
    printf("3 wrong %d %d", my_binary_search(v3, 28), lower_bound(All(v3), 28)-v3.begin());
}
