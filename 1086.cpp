#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[32768][100];

int N;
string strs[15];
int mod;

int s[15][100];

ll dfs(int bits, int r) {
    if (dp[bits][r] != -1) return dp[bits][r];

    ll result=0;

    if (bits == (1<<N)-1) result += r==0;
    for (int i = 0; i < N; i++) {
        if (bits & (1<<i)) continue;
        if (s[i][r] == -1) {
            s[i][r] = r;
            string str = strs[i];
            for (int j = 0; j < str.size(); j++) {
                s[i][r] *= 10;
                s[i][r] += str[j] - '0';
                s[i][r] %= mod;
            }
        }
        result += dfs(bits | (1<<i), s[i][r]);
    }

    return dp[bits][r] = result;
}

void solve(){
    cin >> N; for (int i = 0; i < 32768; i++) for (int j = 0; j < 100; j++) dp[i][j] = -1;
    for (int i = 0; i < 15; i++) for (int j = 0; j < 100; j++) s[i][j] = -1;
    for (int i = 0; i < N; i++) cin >> strs[i];
    cin >> mod;
    ll num = dfs(0,0);
    ll den = 1; for (ll i = 2; i <= N; i++) den *= i;
    ll g = gcd(num, den);
    cout << num/g << '/' << den/g;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
