#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void dijkstra(int src, vector<vector<pair<int, int>>>& graph, int n) {
    vector<int> dist(n, INF);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for(auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if(dist[v] > d + weight) {
                dist[v] = d + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << "Distance to " << i << " is " << dist[i] << endl;
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> graph(n);
    graph[0] = {{1, 10}, {3, 5}};
    graph[1] = {{2, 1}, {3, 2}};
    graph[2] = {{4, 4}};
    graph[3] = {{1, 3}, {2, 9}, {4, 2}};
    graph[4] = {{0, 7}, {2, 6}};

    dijkstra(0, graph, n);
    return 0;
}
