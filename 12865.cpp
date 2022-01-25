#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    int arr[N + 1][2];
    for (int i = 1; i <= N; i++)
        cin >> arr[i][0] >> arr[i][1];

    int d[N + 1][K + 1];
    for (int i = 0; i < N + 1; i++)
        for (int j = 0; j < K + 1; j++)
            d[i][j] = 0;

    for (int i = 1; i <= N; i++)
    {
        int w = arr[i][0];
        int p = arr[i][1];
        for (int j = 0; j <= K; j++)
        {
            if (j - w >= 0)
            {
                d[i][j ] = max(d[i - 1][j], d[i - 1][j - w] + p);
            }
            else
            {
                d[i][j] = d[i - 1][j];
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= K; i++)
        result = max(result, d[N][i]);

    cout << result;
    return 0;
}