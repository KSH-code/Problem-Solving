#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};


void solve(){
    int N, M; cin >> N >> M;
    string strs[N]; for (auto &a : strs) cin >> a;
    set<string> s;
    bool down[N][M]; memset(down, 0, sizeof down);
    bool right[N][M]; memset(right, 0, sizeof right);
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        if (strs[i][j] == '#') continue;
        string str;
        str = strs[i][j];
        int nx = i + 1;
        while (nx < N && !down[i][j]) {
            if (strs[nx][j] != '#') str += strs[nx][j];
            else break;
            down[nx][j] = true;
            nx++;
        }
        if (str.size() > 1) s.insert(str);

        str = strs[i][j];
        int ny = j + 1;
        while (ny < M && !right[i][j]) {
            if (strs[i][ny] != '#') str += strs[i][ny];
            else break;
            right[i][ny] = true;
            ny++;
        }
        if (str.size() > 1) s.insert(str);
    }
    cout << *s.begin();
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
