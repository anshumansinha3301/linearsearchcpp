#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[][10], int source, int size) {
    vector<int> distance(size, INT_MAX);
    distance[source] = 0; 
    set<pair<int, int>> s; 
    s.insert({0, source});

    while (!s.empty()) {
        auto top = *(s.begin());
        int u = top.second;
        s.erase(s.begin());

        for (int v = 0; v < size; v++) {
            if (graph[u][v] != 0) { 
                if (distance[u] + graph[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph[u][v];
                    s.insert({distance[v], v});
                }
            }
        }
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < size; i++) {
        cout << i << "\t\t" << distance[i] << endl;
    }
}

int main() {
    int graph[10][10] = {
        {0, 7, 9, 0, 0, 14},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 2},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {14, 0, 2, 0, 9, 0}
    };
    int size = 6; 

    int source = 0; 
    dijkstra(graph, source, size);

    return 0;
}
