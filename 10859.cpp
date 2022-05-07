#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string str; cin >> str;

    ll r = stoll(str);
    for (ll i = 2; i * i <= r; i++) {
        if (r % i == 0) {
            cout << "no";
            return;
        }
    }
    if (r == 1) {
        cout << "no";
        return;
    }

    r = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '3' || str[i] == '4' || str[i] == '7') {
            cout << "no";
            return;
        }
        r *= 10;
        char c = str[str.size()-1-i];
        int t = c - '0';
        switch (t) {
            case 6:
                t = 9;
                break;
            case 9:
                t = 6;
                break;
        }
        r+=t;
    }

    for (ll i = 2; i * i <= r; i++) {
        if (r % i == 0 || r == 1) {
            cout << "no";
            return;
        }
    }
    if (r == 1) {
        cout << "no";
        return;
    }
    cout << "yes";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
