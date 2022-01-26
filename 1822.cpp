#include <iostream>
#include <set>
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int nA, nB;
    set<int> A;
    cin >> nA >> nB;
    for (int i = 0; i < nA; i++)
    {
        int t;
        cin >> t;
        A.insert(t);
    }
    for (int i = 0; i < nB; i++)
    {
        int t;
        cin >> t;
        A.erase(t);
    }
    cout << A.size() << "\n";
    for (auto t : A)
        cout << t << " ";
    return 0;
}