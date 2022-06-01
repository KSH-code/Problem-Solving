#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
const int MAX = 1e8;
const int MAX_SIZE = 1<<16;

int distances[MAX_SIZE];
int arr[16][16];
int N;
string str;
int P;

typedef pair<int,int> pii;
void solve(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin>>arr[i][j];
    }

    cin >> str >> P;

    auto compare = [](pii a, pii b) {
        return a > b;
    };
    priority_queue<pii, vector<pii>, decltype(compare)> q(compare);

    int result = MAX, b = 0;

    for (int i = 0; i < N; i++) if (str[i]=='Y')b|=1<<i;

    distances[b]=0;
    q.push({0,b});
    fill(distances, distances+MAX_SIZE, MAX);

    auto get_count = [](int visited) {
        int count = 0;
        for (int i = 0; i < N; i++) if (visited & 1 << i) count++;
        return count;
    };



    while (q.size()) {
        auto [cost, visited] = q.top(); q.pop();
        if (get_count(visited) >= P) {
            cout << cost;
            return;
        }

        for (int i = 0; i < N; i++) {
            int cur_visited = visited|1<<i;
            if (visited != cur_visited) continue;

            for (int j = 0; j < N; j++) {
                int next_visitied = visited|1<<j;
                if (visited == next_visitied) continue;

                int next_cost = cost+arr[i][j];
                if (distances[next_visitied] > next_cost) {
                    distances[next_visitied] = next_cost;
                    q.push({next_cost, next_visitied});
                }
            }
        }
    }

    cout << -1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
