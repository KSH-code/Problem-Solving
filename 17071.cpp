#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

const int MAX = 1e5*5+1;
const int MAX_VALUE = 1e5*5;
int first_visited[MAX];
int visited[MAX][2];

void solve()
{
    int N, K; cin >> N >> K;
    for (int i = 0; i < MAX; i++) first_visited[i] = -1;
    for (int i = 0; i + K <= MAX_VALUE; i++) {
        K += i;
        first_visited[K] = i;
    }
    queue<pair<int, int>> q;
    int result = 9999999;
    q.push({N, 0});
    while (q.size()) {
        auto [x, count] = q.front(); q.pop();
        if (first_visited[x] > -1) {
            if (first_visited[x] >= count && (first_visited[x] - count) % 2 == 0) result = min(result, first_visited[x]);
        }

        int xxx[] = {x*2, x+1, x-1};
        for (int i = 0; i < 3; i++) {
            int next = xxx[i];
            int next_count = count + 1;
            int flag = next_count % 2;
            if (next < 0 || next > MAX_VALUE) continue;
            if (visited[next][flag]) continue;
            visited[next][flag] = next_count;
            q.push({next, next_count});
        }
    }
    cout << (result == 9999999 ? -1 : result);
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
