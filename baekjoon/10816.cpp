#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{

  int N;
  scanf("%d", &N);
  unordered_map<int, int> map;
  for (int i = 0; i < N; i++)
  {
    int n;
    scanf("%d", &n);
    if (map.find(n) != map.end())
    {
      map[n]++;
    }
    else
    {
      map[n] = 1;
    }
  }

  int M;
  scanf("%d", &M);
  for (int i = 0; i < M; i++)
  {
    int m;
    scanf("%d", &m);
    printf("%d ", map[m]);
  }
  return 0;
}
