#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

string before, after;
const int MAX = 1e4;

int memo[MAX+1][10];
int results[MAX];

int dfs(int x, int moved) {
    if (x == before.size()) return 0;

    int &ret = memo[x][moved];
    if (ret > -1) return ret;

    auto t = before[x] + moved;
    if (t > '9') t = '0' + (t - '9' - 1);

    int left = (t <= after[x]) ? after[x] - t : after[x] + 10 - t;
    int right = (t >= after[x]) ? t - after[x] : t + 10 - after[x];

    ret = min(
        dfs(x+1, (moved+left)%10)+left,
        dfs(x+1, moved)+right
    );

    return ret;
}

void trace(int x, int moved, int c) {
    if (x == before.size()) return;


    auto t = before[x] + moved;
    if (t > '9') t = '0' + (t - '9' - 1);

    int left = (t <= after[x]) ? after[x] - t : after[x] + 10 - t;
    int right = (t >= after[x]) ? t - after[x] : t + 10 - after[x];

    if (dfs(x+1, moved) + right == dfs(x, moved)) {
        cout << x+1 << ' ' << -right << '\n';
        trace(x+1, moved, c + right);
    } else {
        cout << x+1 << ' ' << left << '\n';
        trace(x+1, (left+moved) % 10, c + left);
    }
}

void solve(){
    int N; cin >> N;
    memset(memo, -1, sizeof memo);
    cin >> before >> after;

    int result = dfs(0,0);
    cout << result << '\n';

    trace(0,0,0);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
