class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> inDegrees(numCourses);
    queue<int> zeroDegrees;
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;

    for (int i = 0; i < prerequisites.size(); ++i) {
      vector<int> curr = prerequisites[i];
      int from = curr[1];
      int to = curr[0];

      inDegrees[to]++;
      graph[from].push_back(to);
    }

    for (int i = 0; i < inDegrees.size(); ++i) {
      if (inDegrees[i] == 0) {
        zeroDegrees.push(i);
      }
    }

    while (!zeroDegrees.empty()) {
      int node = zeroDegrees.front();
      zeroDegrees.pop();
      visited.insert(node);
      for (int i = 0; i < graph[node].size(); ++i) {
        if (visited.find(graph[node][i]) == visited.end()) {
          if (inDegrees[graph[node][i]] > 0) {
            inDegrees[graph[node][i]]--;
          }
          if (inDegrees[graph[node][i]] == 0) {
            zeroDegrees.push(graph[node][i]);
          }
        }
      }
    }

    return visited.size() == numCourses;
  }
};
