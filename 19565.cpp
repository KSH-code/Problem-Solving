#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string str; cin >> str;
    int count = 1;
    char c = str[0];
    for (int i = 1; i < str.size(); i++) {
        if (c >= str[i]) count++;
        c = str[i];
    }
    cout << count;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
