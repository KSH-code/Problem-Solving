#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N, M; cin >> N >> M;
    string str[N];
    for (int i = 0; i < N; i++) cin >> str[i];

    bool found = false;
    bool removed[M]; memset(removed, 0, sizeof removed);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N-1; j++) {
            if (str[j][i] > str[j+1][i]) {
                bool skip = false;
                for (int k = 0; k < i; k++) {
                    if (removed[k]) continue;
                    skip |= str[j][k] < str[j+1][k];
                }
                if (skip) continue;
                removed[i] = true;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < M; i++) result += removed[i];

    cout << result;
}

int main()
{
    solve();
    return 0;
}
