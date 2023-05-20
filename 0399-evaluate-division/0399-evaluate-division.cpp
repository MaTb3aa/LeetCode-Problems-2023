class Solution {
public:

typedef unordered_map<string, unordered_map<string, double>> Graph;

void addEdge(Graph& graph, const string& u, const string& v, double weight) {
    graph[u][v] = weight;
    graph[v][u] = 1 / weight;
}
double dfs(const Graph& graph, const string& start, const string& end, unordered_map<string, bool>& visited) {
   
    if (graph.find(start) == graph.end() || graph.find(end) == graph.end() || visited[start]) {
        return -1.0;
    }

    if (start == end) {
        return 1.0;
    }

    visited[start] = true;
    for (const auto& neighbor : graph.at(start)) {
        double result = dfs(graph, neighbor.first, end, visited);
        if (result != -1.0) {
            return neighbor.second * result;
        }
    }

    visited[start] = false;
    return -1.0;
}

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        Graph graph;

    for (int i = 0; i < equations.size(); i++) {
        const string& a = equations[i][0];
        const string& b = equations[i][1];
        double val = values[i];
        addEdge(graph, a, b, val);
    }

    vector<double> results;
    for (const auto& query : queries) {
        const string& start = query[0];
        const string& end = query[1];
        unordered_map<string, bool> visited;
        results.push_back(dfs(graph, start, end, visited));
    }

    return results;
    }
};