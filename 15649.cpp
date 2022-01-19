#include <iostream>
using namespace std;
int n, m;
int value[9];
void dfs(int x, int c)
{
    if (c == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << value[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if ((x & (1 << i)) > 0)
            continue;

        value[c] = i;
        dfs(x + (1 << i), c + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dfs(0, 0);
    return 0;
}