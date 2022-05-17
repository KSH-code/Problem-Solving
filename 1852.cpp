#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[100001][3];
int N;
ll max_result() {
    bool visited[N][3]; memset(visited, 0, sizeof(visited));

    ll result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            if (visited[i][j]) continue;

            // 아래, 우측 다빔
            visited[i][j]=true;
            if (i + 1 < N && !visited[i+1][j] && (j+1<3 && !visited[i+1][j+1])) {
                if (abs(arr[i][j] - arr[i+1][j]) > abs(arr[i][j] - arr[i][j+1])) {
                    result += abs(arr[i][j] - arr[i+1][j]);
                    visited[i+1][j]=true;
                } else {
                    result += abs(arr[i][j] - arr[i][j+1]);
                    visited[i][j+1]=true;
                }
            } else if (j+1<3) {
                result += abs(arr[i][j] - arr[i][j+1]);
                visited[i][j+1]=true;
            } else {
                result += abs(arr[i][j] - arr[i+1][j]);
                visited[i+1][j]=true;
            }
        }
    }
    return result;
}
ll min_result() {
    bool visited[N][3]; memset(visited, 0, sizeof(visited));

    ll result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            if (visited[i][j]) continue;

            // 아래, 우측 다빔
            visited[i][j]=true;
            if (i + 1 < N && !visited[i+1][j] && (j+1<3 && !visited[i+1][j+1])) {
                if (abs(arr[i][j] - arr[i+1][j]) < abs(arr[i][j] - arr[i][j+1])) {
                    result += abs(arr[i][j] - arr[i+1][j]);
                    visited[i+1][j]=true;
                } else {
                    result += abs(arr[i][j] - arr[i][j+1]);
                    visited[i][j+1]=true;
                }
            } else if (j+1<3) {
                result += abs(arr[i][j] - arr[i][j+1]);
                visited[i][j+1]=true;
            } else {
                result += abs(arr[i][j] - arr[i+1][j]);
                visited[i+1][j]=true;
            }
        }
    }
    return result;
}

void solve(){
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < 3; j++) cin >> arr[i][j];
    cout << max_result() << '\n';
    cout << min_result();
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
