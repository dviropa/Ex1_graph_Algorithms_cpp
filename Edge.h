#ifndef EDGE_H
#define EDGE_H

class Edge {
private:
    int src;
    int dest;
    int weight;

public:
    Edge() : src(0), dest(0), weight(0) {}
    Edge(int src, int dest, int w);

    int getWeight() const;
    int getSrc() const;
    int getDest() const;

    void setWeight(int w);

    bool operator==(const Edge& other) const {
        return (src == other.src && dest == other.dest) ||
               (src == other.dest && dest == other.src);
    }
};

#endif // EDGE_H
