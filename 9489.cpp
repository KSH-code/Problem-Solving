#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int MAX = 1e6 + 1;
bool solve()
{
    int N, K;
    cin >> N >> K;
    if (N + K == 0)
        return false;

    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int parent[MAX];
    int depth[MAX];
    for (int i = 0; i < MAX; i++)
        depth[i] = parent[i] = -1;
    vector<vector<int>> nodes_by_depth(N + 1);
    int prev = arr[0];
    depth[arr[0]] = 0;
    nodes_by_depth[0].push_back(arr[0]);
    int cur_depth = 1;
    int j = -1;
    for (int i = 1; i < N; i++)
    {
        if (prev + 1 != arr[i])
            j++;
        if (nodes_by_depth[cur_depth - 1].size() == j)
            cur_depth++, j = 0;
        nodes_by_depth[cur_depth].push_back(arr[i]);
        int p = nodes_by_depth[cur_depth - 1][j];
        parent[arr[i]] = p;
        depth[arr[i]] = cur_depth;

        prev = arr[i];
    }

    int result = 0;
    if (parent[K] > 0 && parent[parent[K]] > 0)
    {
        int gp = parent[parent[K]];
        for (auto sibling : nodes_by_depth[depth[K]])
        {
            if (parent[K] == parent[sibling])
                continue;
            if (parent[parent[sibling]] == gp)
                result++;
        }
    }
    cout << result << "\n";
    return true;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    while (solve())
        ;
    return 0;
}