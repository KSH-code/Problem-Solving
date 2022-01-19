#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[21][21];
int map[1 << 22];

void make_sum(int start, int x, int count)
{
    if (count == N / 2)
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (i == j)
                    continue;
                if ((x & (1 << i)) == 0 || (x & (1 << j)) == 0)
                    continue;
                sum += arr[i][j] + arr[j][i];
            }
        }
        map[x] = sum;
        return;
    }

    for (int i = start; i < N; i++)
    {
        make_sum(i + 1, x | (1 << i), count + 1);
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    make_sum(0, 0, 0);

    int result = 99999999;
    for (int i = 1; i < (1 << N); i++)
    {
        if (map[i])
        {
            result = min(result, abs(map[i] - map[(1 << N) - 1 - i]));
        }
    }

    cout << result;

    return 0;
}