#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
  int N, M;
  scanf("%d%d", &N, &M);

  unordered_map<string, int> pokemon_char;
  unordered_map<int, string> pokemon_int;
  for (int i = 1; i <= N; i++)
  {
    char pokemon[20];
    scanf("%s", pokemon);
    pokemon_char[pokemon] = i;
    pokemon_int[i] = pokemon;
  }

  for (int i = 0; i < M; i++)
  {
    char n[20];
    scanf("%s", n);
    if (n[0] >= '0' && n[0] <= '9')
    {
      printf("%s\n", pokemon_int[atoi(n)].c_str());
    }
    else
    {
      string pokemon = n;
      printf("%d\n", pokemon_char[pokemon]);
    }
  }
  return 0;
}
