#include <iostream>
using namespace std;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int map[2001];
    for (int i = 0; i < 2001; i++)
        map[i] = 0;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        map[t + 1000]++;
    }
    for (int i = 0; i < 2001; i++)
    {
        if (map[i])
            cout << i - 1000 << " ";
    }
    return 0;
}