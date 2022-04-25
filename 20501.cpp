#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    bitset<2000> bs[N+1];
    for (int i = 1; i <= N; i++) {
        string str; cin >> str;
        for (int j = 0; j < N; j++) {
            bs[i].set(j,str[j]=='1');
        }
    }

    int query; cin >> query;
    for (int i = 0; i < query; i++) {
        int a,b; cin >> a>>b;
        cout << (bs[a] & bs[b]).count() << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
