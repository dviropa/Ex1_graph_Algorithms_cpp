//
// Created by דביר on 3/23/2025.
//

#include "UnionFind.h"

UnionFind::UnionFind(int n) {
    size = n;
    parent = new int[n];
    rank = new int[n];

    for (int i = 0; i < n; ++i) {
        parent[i] = i; // כל איבר הוא קבוצה בפני עצמו
        rank[i] = 0;
    }
}

UnionFind::~UnionFind() {
    delete[] parent;
    delete[] rank;
}
int UnionFind:: find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void UnionFind:: unite(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);

    if (xRoot == yRoot) return;

    // הצמדת העץ הקטן לעץ הגדול
    if (rank[xRoot] < rank[yRoot]) {
        parent[xRoot] = yRoot;
    } else if (rank[xRoot] > rank[yRoot]) {
        parent[yRoot] = xRoot;
    } else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }

}
bool UnionFind:: connected(int x, int y) {
    return find(x) == find(y);
}