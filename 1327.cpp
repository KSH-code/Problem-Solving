#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

int N, K;

struct Node {
    int *arr;
    int count;
};

bool sorted(int arr[8]) {
    for (int i = 1; i < N; i++) if (arr[i] < arr[i-1]) return false;

    return true;
}

int calculate(int arr[8]) {
    int result = 0;
    for (int i = 0; i < N; i++) result = result * 10 + arr[i];
    return result;
}

void solve(){
    cin >> N >> K;
    int arr[8]; for (int i = 0; i < N; i++) cin >> arr[i];

    if (sorted(arr)) {
        cout << 0;
        return;
    }

    unordered_set<int> visited;

    queue<Node> q; q.push({arr,0});
    while (q.size()) {
        auto [x, count] = q.front(); q.pop();

        for (int i = 0; i <= N-K; i++) {
            auto nx = new int[8];
            copy(x, x+N, nx);
            for (int j = 0; j < K/2; j++) swap(nx[i+j], nx[i+K-1-j]);

            if (sorted(nx)) {
                cout << count+1;
                return;
            }

            int v = calculate(nx);
            if (visited.count(v)) continue;
            visited.insert(v);

            q.push({nx, count+1});
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
