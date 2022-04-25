#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    stack<pair<int,int>> st;
    ll result=0;
    for (int i = 0; i < N; i++) {
        int a; cin >> a; int t = 1;
        while (st.size() && st.top().first <= a) {
            auto [c,d] = st.top(); st.pop();
            if (c == a) {
                result += d;
                t = d + 1;
            } else {
                result += d;
            }
        }
        if (st.size()) result++;
        st.push({a,t});
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
