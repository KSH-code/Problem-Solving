#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int a,b;cin>>a>>b;
    string str; cin >> str;
    int result = 0;
    for (int i = 0; i < a; i++) if (str[i] == '1') result += 11;

    for (int i = 0; i <= b; i++) {
        int c = a-1-i;
        if (c<0)break;
        if (str[c] == '1') {
            b-=i;
            str[c]='0';
            str[a-1]='1';
            result-=10;
            break;
        }
    }

    for (int i = 0; i <= b; i++) {
        if (i == a-1) break;
        if (str[i] == '1') {
            result-=1;
            break;
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
