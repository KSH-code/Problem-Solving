#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;

string A, B;
int N;

void input() {
    string str; cin >> str;
    stringstream ss(str);

	getline(ss, str, '=');
    A=str;
    getline(ss, str, '=');
    B=str;

    N = A.size();

    assert(N<=1000);
}

int tc[5001][1000];

const int INF = 1e9;
const int INITIAL = -1;

int dfs(int x, int remains) {
    if (x >= N) return INF;
    if (tc[remains][x] != INITIAL) return tc[remains][x];

    int cur = 0;
    tc[remains][x] = INF;
    for (int i = x; i < N; i++) {
        cur = cur * 10 + A[i] - '0';

        if (cur > remains) break;
        if (cur == remains) {
            if (i + 1 == N) {
                tc[remains][x] = 1;
                return 1;
            }
        }

        int next = dfs(i + 1, remains - cur);
        int found = next + 1;
        tc[remains][x] = min(tc[remains][x], found);
    }
    return tc[remains][x];
}

void trace(int x, int remains) {
    int cur = 0;
    for (int i = x; i < N; i++) {
        cur = cur * 10 + A[i] - '0';
        cout << A[i];
        if (dfs(x, remains) == dfs(i+1,remains-cur)+1) {
            if (i + 1 < N) cout << '+';
            trace(i+1, remains-cur);
            return;
        }
    }
}

void solve(){
    input();

    for (int i = 0; i <= 5000; i++) for (int j = 0; j < 1000; j++) tc[i][j] = INITIAL;

    int sum = stoi(B);
    trace(0, sum);
    cout << '=' << B;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
