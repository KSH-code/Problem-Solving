#include <iostream>
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    int arr[N + 1][N + 1];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> arr[i][j];

    int sum[N + 1][N + 1];
    for (int i = 1; i <= N; i++)
    {
        sum[i][0] = 0;
        for (int j = 1; j <= N; j++)
        {
            sum[i][j] = sum[i][j - 1] + arr[i][j];
        }
    }

    while (M--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = 0;
        for (int i = x1; i <= x2; i++)
        {
            result += sum[i][y2] - sum[i][y1 - 1];
        }
        cout << result << "\n";
    }
    return 0;
}