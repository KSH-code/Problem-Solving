#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    bool used[N+1]; memset(used, 0, sizeof(used));
    bool visited[N+1]; memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        used[a] = true;
        if (visited[a-1] && visited[a+1]) {

        } else if (visited[a] && used[a+1]) {
            a++;
        } else if (!used[a-1] && !visited[a-1]) {
            if (a>1)
            a--;
        }
        visited[a] = true;

        cout << a << ' ';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
