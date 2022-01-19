#include <iostream>
#include <vector>
using namespace std;
int N, M;
int arr[100];

void dfs(int x, int count)
{
    if (count == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = x; i <= N; i++)
    {
        arr[count] = i;
        dfs(i + 1, count + 1);
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    dfs(1, 0);
    return 0;
}