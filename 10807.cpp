#include <iostream>
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int map[201];
    for (int i = 0; i < 201; i++)
        map[i] = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        map[t + 100]++;
    }
    int t;
    cin >> t;
    cout << map[t + 100];
    return 0;
}