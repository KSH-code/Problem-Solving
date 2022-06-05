#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

string solve(int N, int M){
    vector<vector<int>> edges(N+1);
    while(M--) {
        int a,b;cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    bool visited[N+1]; memset(visited,0 ,sizeof visited);
    int parents[N+1]; memset(parents, 0, sizeof parents);

    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        queue<int> q;
        q.push(i);
        visited[i] = true;

        bool tree = true;
        while (q.size()) {
            int x = q.front(); q.pop();
            for (auto nx : edges[x]) {
                if (parents[x] == nx) continue;
                if (visited[nx]) {
                    tree = false;
                    continue;
                }
                parents[nx] = x;
                visited[nx] = true;
                q.push(nx);
            }
        }

        if (tree) result++;
    }

    if (result == 1) {
        return "There is one tree.";
    } else if (result) {
        string trees = to_string(result);
        return "A forest of "+trees+" trees.";
    } else {
        return "No trees.";
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    for (int i = 1; true; i++) {
        int N, M; cin >> N >> M;
        if (N+M==0) break;
        printf("Case %i: %s\n",i,solve(N,M).c_str());
    }
    return 0;
}
