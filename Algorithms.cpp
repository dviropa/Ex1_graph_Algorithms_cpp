#include "Algorithms.h"
#include <iostream>
#include <climits>

namespace graph {

     Graph Algorithms::bfs(Graph &g, int s) {
    const int MAX = g.get_size();
    if (s < 0 || s >= MAX) {
        throw std::invalid_argument("Start node is out of bounds.");
    }

    bool *visited = new bool[MAX]{false};
    Graph tree(g.get_size());
    Queue q;

    q.push(s);
    visited[s] = true;

    while (!q.isEmpty()) {
        int current = q.peek();
        q.pop();
        std::cout << current << " ";

        int* neighbors = g.get_neighbors(current);
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
    delete[] visited;
    return tree;
}

  Graph Algorithms::dfs(Graph& g, int x) {
    const int MAX = g.get_size();
    if (x < 0 || x >= MAX) {
        throw std::invalid_argument("Start node is out of bounds.");
    }

    bool* visited = new bool[MAX]{false};
    Graph tree(MAX);
    Stack s;

    s.push(x);
    visited[x] = true;

    while (!s.isEmpty()) {
        int current = s.top();
        s.pop();
        std::cout << current << " ";

        int* neighbors = g.get_neighbors(current);
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

 Graph Algorithms::dijKstra(Graph& g, int s) {
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

    const int MAX = g.get_size();
    int* distance = new int[MAX];
    int* parent = new int[MAX];
    bool* visited = new bool[MAX]{false};
    Graph g_ans(MAX);
    const int INF = INT_MAX;

    for (int i = 0; i < MAX; ++i) {
        distance[i] = INF;
        parent[i] = -1;
    }
    distance[s] = 0;

    for (int i = 0; i < MAX; ++i) {
        int u = -1;
        int minDist = INF;
        for (int j = 0; j < MAX; ++j) {
            if (!visited[j] && distance[j] < minDist) {
                minDist = distance[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        int* neighbors = g.get_neighbors(u);
        int k = 0;
        while (neighbors && neighbors[k] != -1) {
            int v = neighbors[k];
            int weight = g.get_weight(u, v);
            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
            }
            k++;
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
    delete[] distance;
    delete[] parent;
    delete[] visited;
    return g_ans;
}

 Graph Algorithms::prim(Graph& g, int s) {
    if (s < 0 || s >= g.get_size()) {
        throw std::invalid_argument("Start node is out of bounds.");
    }

    const int MAX = g.get_size();
    int* key = new int[MAX];
    int* parent = new int[MAX];
    bool* inMST = new bool[MAX]{false};
    const int INF = INT_MAX;

    for (int i = 0; i < MAX; ++i) {
        key[i] = INF;
        parent[i] = -1;
    }
    key[s] = 0;

    for (int count = 0; count < MAX; ++count) {
        int u = -1;
        int minKey = INF;
        for (int i = 0; i < MAX; ++i) {
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

    Graph mst(MAX);
    for (int i = 0; i < MAX; ++i) {
        if (parent[i] != -1) {
            int w = g.get_weight(parent[i], i);
            mst.addEdge(parent[i], i, w);
        }
    }

    delete[] key;
    delete[] parent;
    delete[] inMST;
    return mst;
}

 Graph Algorithms::kruskal(Graph& g) {

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
