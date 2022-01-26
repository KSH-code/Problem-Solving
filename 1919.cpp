#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;
    int map[27][2];
    for (int i = 0; i < 27; i++)
        map[i][0] = map[i][1] = 0;
    for (int i = 0; i < a.length(); i++)
        map[a[i] - 'a'][0]++;
    for (int i = 0; i < b.length(); i++)
        map[b[i] - 'a'][1]++;

    int result = 0;
    for (int i = 0; i < 27; i++)
    {
        result += abs(map[i][0] - map[i][1]);
    }

    cout << result;
    return 0;
}