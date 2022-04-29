#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    int result = 0;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        stack<char> st;
        for (int j = 0; j < str.size(); j++) {
            char c = str[j];
            if (st.size() && st.top() == c) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        if (st.empty()) result++;
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
