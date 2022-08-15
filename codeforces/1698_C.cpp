#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

using pii = pair<int,int>;

void solve(){
    int N; cin >> N;

    vector<int> negative;
    vector<int> zero;
    vector<int> positive;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (a < 0) negative.push_back(a);
        else if (a == 0) zero.push_back(a);
        else positive.push_back(a);
    }
    if (negative.size() > 2 || positive.size() > 2) {
        cout << "NO";
        return;
    }

    vector<int> f;
    for (auto p : positive) f.push_back(p);
    for (auto n : negative) f.push_back(n);
    if (zero.size() > 0) f.push_back(0);
    if (zero.size() > 1) f.push_back(0);

    N = f.size();
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (i == j && j == k) continue;
                if (find(f.begin(), f.end(), f[i]+f[j]+f[k]) == f.end()) {
                    cout << "NO";
                    return;
                }
            }
        }
    }
    cout << "YES";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
