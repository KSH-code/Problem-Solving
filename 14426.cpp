#include <iostream>
#include <string>

using namespace std;

void solve(){
    int N, M; cin >> N >> M;
    string arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];
    int result = 0;
    for (int i = 0; i < M; i++) {
        string str; cin >> str;
        for (int j = 0; j < N; j++) {
            bool found = true;
            for (int k = 0; k < str.size(); k++) {
                if (str[k] != arr[j][k]) {
                    found = false;
                    break;
                }
            }
            if (!found) continue;
            result++;
            break;
        }
    }
    cout << result;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    solve();
    return 0;
}
