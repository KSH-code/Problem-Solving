#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char str = '*';
            int k = n;
            while (k >= 1)
            {
                if (i / k % 3 == 1 && j / k % 3 == 1)
                    str = ' ';
                k /= 3;
            }
            cout << str;
        }
        cout << "\n";
    }
    return 0;
}