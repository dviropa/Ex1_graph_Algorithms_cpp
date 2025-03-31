#ifndef UNION_FIND_H
#define UNION_FIND_H

class UnionFind {
private:
    int* parent;
    int* rank;
    int size;

public:
    UnionFind(int n);
    ~UnionFind();

    // פעולה למציאת הנציג של קבוצה (עם קיבוע מסלול)
    int find(int x);

    // מאחד בין שתי קבוצות
    void unite(int x, int y);

    // לבדוק אם שני איברים באותה קבוצה
    bool connected(int x, int y);
};

#endif // UNION_FIND_H
