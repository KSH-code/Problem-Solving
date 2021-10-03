#include <iostream>
#include <queue>
#include <utility>

using namespace std;

vector<vector<pair<int, int>>> edges(20001);
int distances[20001];
int V, E, S;

void dijkstra(int start)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, start});

  while (pq.size() > 0)
  {
    pair<int, int> edge = pq.top();
    pq.pop();

    int weight = edge.first;
    int next = edge.second;

    if (distances[next] < weight)
      continue;

    for (auto &edge : edges[next])
    {
      int next_weight = weight + edge.first;
      int next_next = edge.second;
      if (distances[next_next] > next_weight)
      {
        distances[next_next] = next_weight;
        pq.push({next_weight, next_next});
      }
    }
  }
}

int main()
{
  scanf("%d%d%d", &V, &E, &S);

  for (int i = 0; i < E; i++)
  {
    int s, e, w;
    scanf("%d%d%d", &s, &e, &w);
    edges[s].push_back({w, e});
  }

  for (int i = 1; i <= V; i++)
    distances[i] = 999999999;

  dijkstra(S);

  distances[S] = 0;

  for (int i = 1; i <= V; i++)
    if (distances[i] == 999999999)
      printf("INF\n");
    else
      printf("%d\n", distances[i]);

  return 0;
}
