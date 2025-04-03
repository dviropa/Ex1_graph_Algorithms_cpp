// main.cpp
// Email: your_email@example.com

#include <iostream>
#include "Graph.h"
#include "Algorithms.h"

using namespace graph;

void printMenu() {
    std::cout << "\n=== Graph Menu ===\n";
    std::cout << "1. Add Edge\n";
    std::cout << "2. Print Graph\n";
    std::cout << "3. Run BFS\n";
    std::cout << "4. Run DFS\n";
    std::cout << "5. Run Dijkstra\n";
    std::cout << "6. Run Prim\n";
    std::cout << "7. Run Kruskal\n";
    std::cout << "8. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    int size;
    std::cout << "Enter the number of vertices in the graph: ";
    std::cin >> size;

    Graph g(size);

    int choice;
    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int u, v, w;
                std::cout << "Enter source, destination and weight: ";
                std::cin >> u >> v >> w;
                try {
                    g.addEdge(u, v, w);
                    std::cout << "Edge added successfully.\n";
                } catch (std::exception& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 2: {
                std::cout << "\nGraph:\n";
                g.printGraph();
                break;
            }
            case 3: {
                int s;
                std::cout << "Enter start vertex for BFS: ";
                std::cin >> s;
                Graph bfsTree = Algorithms::bfs(g, s);
                std::cout << "\nBFS Tree:\n";
                bfsTree.printGraph();
                break;
            }
            case 4: {
                int s;
                std::cout << "Enter start vertex for DFS: ";
                std::cin >> s;
                Graph dfsTree = Algorithms::dfs(g, s);
                std::cout << "\nDFS Tree:\n";
                dfsTree.printGraph();
                break;
            }
            case 5: {
                int s;
                std::cout << "Enter start vertex for Dijkstra: ";
                std::cin >> s;
                try {
                    Graph dijkstraTree = Algorithms::dijKstra(g, s);
                    std::cout << "\nDijkstra Result:\n";
                    dijkstraTree.printGraph();
                } catch (std::exception& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 6: {
                int s;
                std::cout << "Enter start vertex for Prim: ";
                std::cin >> s;
                Graph primTree = Algorithms::prim(g, s);
                std::cout << "\nPrim's MST:\n";
                primTree.printGraph();
                break;
            }
            case 7: {
                Graph kruskalTree = Algorithms::kruskal(g);
                std::cout << "\nKruskal's MST:\n";
                kruskalTree.printGraph();
                break;
            }
            case 8: {
                std::cout << "Exiting...\n";
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    return 0;
}
