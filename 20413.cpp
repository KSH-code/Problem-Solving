#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    ll s,g,p,d; cin >> s >> g >> p >> d;

    string str; cin >> str;
    ll prev = 0;
    ll result = 0;
    for (int i = 0; i < N; i++) {
        ll current = 0;
        switch(str[i]) {
            case 'B':
                current = s-prev-1;
                break;
            case 'S':
                current = g-prev-1;
                break;
            case 'G':
                current = p-prev-1;
                break;
            case 'P':
                current = d-prev-1;
                break;
            case 'D':
                current = d;
                break;
        }
        if (i + 1 < N) {
            switch (str[i+1]) {
            case 'B':
                if (current > s-1)
                current = max(current, s-1);
                break;
            case 'S':
                if (current > g-1)
                current = max(current, g-1);
                break;
            case 'G':
                if (current > p-1)
                current = max(current, p-1);
                break;
            case 'P':
                if (current > d-1)
                current = max(current, d-1);
                break;
            case 'D':
                if (current > d)
                current = max(current, d);
                break;
            }
        }
        if (current < 0) {
            result += current;
            current = 0;
        }
        result += current;
        prev = current;
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
