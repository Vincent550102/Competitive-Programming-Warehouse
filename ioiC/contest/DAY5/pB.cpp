#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int lli

template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 998244353, abc = 864197532, N = 201, logN = 17, K = 333;
int dp[2][1001][12];

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, a, c, e, s;
    cin >> t >> n >> a;
    int ans = 0;
    
    for (int i = 1; i <= n; ++i) {
        cin >> c >> e >> s;
        for (int j = 0; j <= t; ++j) {
            for (int k = 0; k <= a + 1 && j + k <= t; ++k) {
                dp[i & 1][j][k] = dp[i & 1 ^ 1][j][k];
//                cout << i << " " << d[i&1^1] << endl;
                if (j && k + 1 <= a + 1) dp[i & 1][j][k] = max(dp[i & 1][j][k], dp[i & 1][j - 1][k + 1]);
                if (k) dp[i & 1][j][k] = max(dp[i & 1][j][k], dp[i & 1][j][k - 1]);
                int E = min(j + k - e, j);
//                if (E >= c) dp[i & 1][j][k] = max(dp[i & 1][j][k], dp[i & 1][E - c][e] + s);
				if (E >= c) dp[i & 1][j][k] = max(dp[i & 1][j][k], dp[i & 1][E - c][min(c, a + 1)] + s);
                ans = max(ans, dp[i & 1][j][k]);
//                cout << i << ' ' << j << ' '	 << j + k << ' ' << dp[i & 1][j][k] << endl;
            }
        }
    }
    cout << ans << endl;
}
