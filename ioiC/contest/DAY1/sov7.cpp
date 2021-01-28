#include <bits/stdc++.h>
using namespace std;
#define maxn 200005

//int n;
//pair<int, int> p[maxn];
//long double angle, cos_v, sin_v;
//
//bool cmp(pair<int, int> a, pair<int, int> b) {
//    auto v1 = make_pair(a.first * cos_v - a.second * sin_v
//                      , a.first * sin_v + a.second * cos_v);
//    auto v2 = make_pair(b.first * cos_v - b.second * sin_v
//                      , b.first * sin_v + b.second * cos_v);
//    return v1 < v2;
//}

int main() {
    cin.tie(0), cout.sync_with_stdio(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // random number generator
    for(int i = 0; i<5; i++){
    	cout << rng();
	}
	return 0;
}
