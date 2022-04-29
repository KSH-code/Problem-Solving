#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string before; cin >> before;
    string after; cin >> after;
    int same_count = 0;
    for (int i = 0; i < before.size(); i++) {
        if (after[i] == before[i] && i < before.size() && i < after.size()) {
            same_count++;
        } else break;
    }
    if (same_count) {
        before = before.substr(same_count);
        after = after.substr(same_count);
    }
    same_count = 0;
    for (int i = 0; i < before.size(); i++) {
        if (after[after.size()-1-i] == before[before.size()-1-i] && i < before.size() && i < after.size()) {
            same_count++;
        } else break;
    }
    if (same_count) {
        after = after.substr(0, after.size() - same_count);
    }

    cout << after.size();
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
