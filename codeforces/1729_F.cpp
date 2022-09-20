#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string str; cin >> str;
    int N = str.size();
    int w, M; cin >> w >> M;

    vector<vector<int>> arr(9);
    int init = 0;
    for (int i = 0; i < w; i++) init = (init + str[i] - '0') % 9;
    arr[init].push_back(1);
    for (int i = 1; i + w <= N; i++) {
        init -= str[i-1] - '0';
        init += str[i+w-1] - '0';
        init = (init + 9) % 9;
        arr[init].push_back(i+1);
    }
    int prefix[N]; memset(prefix, 0, sizeof prefix);
    for (int i = 0; i < N; i++) {
        if (i) prefix[i] += prefix[i-1];
        prefix[i] *= 10;
        prefix[i] += str[i] - '0';
        prefix[i] %= 9;
    }
    while (M--) {
        int l,r,k; cin >> l >> r >> k;
        int n = (prefix[r-1] + 9 - (l==1?0:prefix[l-2])) % 9;
        int rl = -1, rr = -1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (arr[i].size() && arr[j].size()) {
                    if ((i * n + j) % 9 == k) {
                        int first = arr[i][0];
                        int last = arr[j][0];
                        if (i == j && arr[j].size() >= 2) last = arr[j][1];
                        else if (i == j) continue;
                        if (rl == -1) {
                            rl = first;
                            rr = last;
                        }
                        if (rl > first || (rl == first && rr > last)) {
                            rl = first;
                            rr = last;
                        }
                    }
                }
            }
        }
        cout << rl << ' ' << rr << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
