#include <bits/stdc++.h>

void Bfs(int start, std::vector<std::vector<int>>& ss) {
  std::queue<int> que;
  que.push(start);
  std::vector<bool> used(ss.size(), false);
  std::vector<int> dists(ss.size());
  dists[start] = 0;
  used[start] = true;
  while (!que.empty()) {
    int cur_vertex = que.front();
    que.pop();
    for (auto to : ss[cur_vertex]) {
      if (!used[to]) {
        used[to] = true;
        que.push(to);
        dists[to] = dists[cur_vertex] + 1;
      }
    }
  }
  for (auto cur_dist : dists) {
    std::cout << cur_dist << '\n';
  }
}

void Run() {
  int vertexes;
  int edges;
  std::cin >> vertexes >> edges;
  std::vector<std::vector<int>> ss(vertexes);

  for (int i = 0; i < edges; ++i) {
    int from;
    int to;
    std::cin >> from >> to;
    ss[from].push_back(to);
    ss[to].push_back(from);
  }
  int start;
  std::cin >> start;
  Bfs(start, ss);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  freopen ("graph.txt", "r", stdin);
  Run();
}
