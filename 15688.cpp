#include <iostream>
using namespace std;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1e6 * 2 + 1;
    int N;
    cin >> N;
    int map[t];
    for (int i = 0; i < t; i++)
        map[i] = 0;
    for (int i = 0; i < N; i++)
    {
        int c;
        cin >> c;
        map[(int)(c + 1e6)]++;
    }
    for (int i = 0; i < t; i++)
    {
        while (map[i]--)
            cout << (int)(i - 1e6) << "\n";
    }
    return 0;
}