#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

unordered_set<string> words;

int score(int length)
{
    if (length < 3)
        return 0;
    if (length < 5)
        return 1;
    if (length == 5)
        return 2;
    if (length == 6)
        return 3;
    if (length == 7)
        return 5;
    if (length == 8)
        return 11;
    return 0;
}

int xxxx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int yyyy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool visited[4][4];

unordered_set<string> result_set;
unordered_set<string> found;
string dfs(int x, int y, char map[4][4], string str)
{
    str += map[x][y];
    visited[x][y] = true;

    auto result = str;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + xxxx[i];
        int ny = y + yyyy[i];
        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || visited[nx][ny] || str.size() == 8)
            continue;
        string nstr = str + map[nx][ny];
        auto temp = dfs(nx, ny, map, str);
        visited[nx][ny] = false;
        if (result_set.find(temp) == result_set.end())
            reverse(temp.begin(), temp.end());
        if (result_set.find(temp) != result_set.end() && found.find(temp) == found.end())
        {
            result = temp;
        }
    }

    if (result_set.find(result) != result_set.end())
        found.insert(result);

    return result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        result_set.insert(str);
        string temp;
        string temp_r;
        for (int j = 0; j < str.size(); j++)
        {
            temp += str[j];
            temp_r += str[str.size() - 1 - j];
        }
    }

    int T;
    cin >> T;
    while (T--)
    {
        char map[4][4];
        for (int i = 0; i < 4; i++)
        {
            cin >> map[i];
        }

        int score_sum = 0;
        string max_str = "";
        found.clear();
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int x = 0; x < 4; x++)
                    for (int y = 0; y < 4; y++)
                        visited[x][y] = false;
                while (1)
                {
                    int b = found.size();
                    dfs(i, j, map, "");
                    if (found.size() == b)
                        break;
                }
            }
        }

        for (auto str : found)
        {
            int found_score = score(str.size());
            score_sum += found_score;
            if (max_str.size() < str.size())
                max_str = str;
            else if (max_str.size() == str.size() && max_str > str)
                max_str = str;
        }
        cout << score_sum << ' ' << max_str << ' ' << found.size() << '\n';
    }

    return 0;
}