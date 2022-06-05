#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string str;

bool force_remove(int i) {
    for (; i < str.size(); i++) if (str[i] == '*') return true;
    return false;
}

void solve(){
    cin >> str;
    int K; cin >> K;

    int N = str.size();
    int letters = 0;
    for (auto c : str) if (c != '*' && c != '?') letters++;


    string result = "";
    for (int i = 0; i < N; i++) {
        if (str[i] != '?' && str[i] != '*') {
            if (i + 1 < N) {
                if (str[i + 1] == '?') {
                    if (force_remove(i+2) || result.size() >= K) continue;
                    bool add = false;
                    int c = 0;
                    for (int j = i+2; j < N; j++) c += str[j] != '?' && str[j] != '*';
                    if (c + result.size() < K) result += str[i];
                    i++;
                } else if (str[i + 1] == '*') {
                    if (force_remove(i+2) || result.size() >= K) continue;
                    bool add = false;
                    int c = 0;
                    for (int j = i+2; j < N; j++) c += str[j] != '?' && str[j] != '*';
                    while (c + result.size() < K) result += str[i];
                    i++;
                } else result += str[i];
            } else {
                result += str[i];
            }
        }
    }

    if (result.size() != K) cout << "Impossible";
    else cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
