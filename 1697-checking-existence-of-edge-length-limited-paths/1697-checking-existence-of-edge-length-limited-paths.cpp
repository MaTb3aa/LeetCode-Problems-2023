class Solution {
public:
    vector<int> parent;

    int find(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }

    void join(int u, int v) {
        parent[find(u)] = find(v);
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        // Process queries
        vector<pair<int, int>> q;
        vector<bool> result(queries.size(), false);
        for (int i = 0; i < queries.size(); i++)
            q.emplace_back(queries[i][2], i);

        sort(q.begin(), q.end());

        int i = 0;
        for (auto& p : q) {
            int u = queries[p.second][0];
            int v = queries[p.second][1];
            int w = p.first;

            while (i < edgeList.size() && edgeList[i][2] < w) {
                join(edgeList[i][0], edgeList[i][1]);
                i++;
            }

            result[p.second] = find(u) == find(v);
        }

        return result;
    }
};
