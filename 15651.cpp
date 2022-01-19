#include <iostream>
#include <vector>
using namespace std;
int N, M;
int arr[100];

void dfs(int count)
{
    if (count == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        int prev = arr[count];
        arr[count] = i;
        dfs(count + 1);
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    dfs(0);
    return 0;
}