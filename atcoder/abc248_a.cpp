#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string str;
    cin >> str;
    set<char> s;
    for (auto c : str) {
        s.insert(c);
    }
    for (char i = '0'; i <= '9'; i++) {
        if (!s.count(i)) {
            cout << i;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
