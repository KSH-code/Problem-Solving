#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    vector<int> v;
    int t;
    while (cin >> t) {
        v.push_back(t);
    }
    t=v.back();
    // A+: 1~5등
    // A0: 6~15등
    // B+: 16~30등
    // B0: 31~35등
    // C+: 36~45등
    // C0: 46~48등
    // F: 49~50등
    sort(v.begin(), v.end(), greater<>());
    auto index = find(v.begin(),v.end(),t) - v.begin() + 1;
    if (index <= 5) cout << "A+";
    else if (index <= 15) cout << "A0";
    else if (index <= 30) cout << "B+";
    else if (index <= 35) cout << "B0";
    else if (index <= 45) cout << "C+";
    else if (index <= 48) cout << "C0";
    else if (index <= 50) cout << "F";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
