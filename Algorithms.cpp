#include "Algorithms.h"
#include <iostream>

namespace graph {

Graph Algorithms::bfs(Graph g, int s) {
    const int MAX = g.get_size();
    bool visited[MAX] = {false};

    if (s < 0 || s >= MAX) {
        std::cout << "Invalid start node\n";
        return Graph(0);
    }

    Graph tree(g.get_size());
    Queue q;

    q.push(s);
    visited[s] = true;


    while (!q.isEmpty()) {
        int current = q.peek();
        q.pop();

        std::cout << current << " ";

        int* neighbors = g.get_neighbors(current);
        if (neighbors == nullptr) continue;

        int i = 0;
        while (neighbors[i] != -1) {
            int neighbor = neighbors[i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                tree.addEdge(current, neighbor, 0);
            }
            i++;
        }

        delete[] neighbors;
    }

    std::cout << std::endl;
    return tree;
}

Graph Algorithms::dfs(Graph g, int x) {
    const int MAX = g.get_size();
    if (x < 0 || x >= MAX) {
        std::cout << "Invalid start node\n";
        return Graph(0);
    }

    bool* visited = new bool[MAX]();
    Graph tree(MAX);
    Stack s;

    s.push(x);
    visited[x] = true;


    while (!s.isEmpty()) {
        int current = s.top();
        s.pop();

        std::cout << current << " ";

        int* neighbors = g.get_neighbors(current);
        if (neighbors == nullptr) continue;

        int i = 0;
        while (neighbors[i] != -1) {
            int neighbor = neighbors[i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
                tree.addEdge(current, neighbor, 0);
            }
            i++;
        }

        delete[] neighbors;
    }

    std::cout << std::endl;
    delete[] visited;
    return tree;
}

    Graph Algorithms::dijKstra(Graph g, int s) {
    if (s < 0 || s >= g.get_size()) {
        throw std::invalid_argument("Start node is out of bounds.");
    }

    int count = 0;
    Edge* edges = g.get_all_edges(count);
    for (int i = 0; i < count; ++i) {
        if (edges[i].getWeight() < 0) {
            delete[] edges;
            throw std::invalid_argument("Dijkstra algorithm does not support negative edge weights.");
        }
    }

    Graph g_ans(g.get_size());
    const int MAX = g.get_size();
    int distance[MAX];
    int parent[MAX];
    bool visited[MAX] = {false};
    int INF = INT_MAX;

    for (int i = 0; i < MAX; ++i) {
        distance[i] = INF;
        parent[i] = -1;
    }
    distance[s] = 0;

    for (int count = 0; count < MAX; ++count) {
        int u = -1;
        int minDist = INF;
        for (int i = 0; i < MAX; ++i) {
            if (!visited[i] && distance[i] < minDist) {
                minDist = distance[i];
                u = i;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        int* neighbors = g.get_neighbors(u);
        int i = 0;
        while (neighbors && neighbors[i] != -1) {
            int v = neighbors[i];
            int weight = g.get_weight(u, v);
            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
            }
            i++;
        }
        delete[] neighbors;
    }

    for (int i = 0; i < MAX; ++i) {
        if (parent[i] != -1) {
            int w = g.get_weight(parent[i], i);
            g_ans.addEdge(parent[i], i, w);
        }
    }

    delete[] edges;
    return g_ans;
}


Graph Algorithms::prim(Graph g, int s) {
    if (s < 0 || s >= g.get_size()) {
        throw std::invalid_argument("Start node is out of bounds.");
    }
    const int MAX = 100;
    int INF = INT_MAX;
    int key[MAX];
    int parent[MAX];
    bool inMST[MAX] = {false};

    for (int i = 0; i < g.get_size(); ++i) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[s] = 0;

    for (int count = 0; count < g.get_size(); ++count) {
        int u = -1;
        int minKey = INF;
        for (int i = 0; i < g.get_size(); ++i) {
            if (!inMST[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        if (u == -1) break;

        inMST[u] = true;

        int* neighbors = g.get_neighbors(u);
        int i = 0;
        while (neighbors && neighbors[i] != -1) {
            int v = neighbors[i];
            int w = g.get_weight(u, v);

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
            i++;
        }
        delete[] neighbors;
    }

    Graph mst(g.get_size());
    for (int i = 0; i < g.get_size(); ++i) {
        if (parent[i] != -1) {
            int w = g.get_weight(parent[i], i);
            mst.addEdge(parent[i], i, w);
        }
    }

    return mst;
}

Graph Algorithms::kruskal(Graph g, int s) {
    if (s < 0 || s >= g.get_size()) {
        throw std::invalid_argument("Start node is out of bounds.");
    }
    int n = g.get_size();
    Graph mst(n);
    UnionFind uf(n);

    int edgeCount = 0;
    Edge* edges = g.get_all_edges(edgeCount);

    sortEdges(edges, edgeCount);

    for (int i = 0; i < edgeCount; ++i) {
        int u = edges[i].getSrc();
        int v = edges[i].getDest();
        int w = edges[i].getWeight();

        if (!uf.connected(u, v)) {
            uf.unite(u, v);
            mst.addEdge(u, v, w);
        }
    }

    delete[] edges;
    return mst;
}

} // namespace graph
