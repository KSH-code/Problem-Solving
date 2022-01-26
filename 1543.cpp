#include <iostream>
#include <string>
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string a, b;
    getline(cin, a);
    getline(cin, b);
    int result = 0;
    for (int i = 0; i < a.length(); i++)
    {
        bool found = true;
        for (int j = 0; j < b.length(); j++)
        {
            if (a[i + j] != b[j])
            {
                found = false;
                break;
            }
        }
        if (!found)
            continue;
        result += found;
        i += b.length() - 1;
    }
    cout << result;
    return 0;
}