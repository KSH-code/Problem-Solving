#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    string str; cin >> str;
    string result = "";
    for (int i = N-1; i >= 0; i--) {
        if (str[i] == '0') {
            result = (char) ('a' + stoi(str.substr(i-2,2)) - 1) + result;
            i -= 2;
        }
        else {
            result = (char) ('a' + str[i] - '0' - 1) + result;
        }
    }
    cout << result;
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
