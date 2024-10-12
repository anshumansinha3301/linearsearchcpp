#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[][10], int source, int size) {
    vector<int> distance(size, INT_MAX); // Initialize distances
    distance[source] = 0; // Distance from source to itself is 0
    set<pair<int, int>> s; // Set to store vertex and its distance
    s.insert({0, source}); // Insert source into the set

    while (!s.empty()) {
        // Get the vertex with the minimum distance
        auto top = *(s.begin());
        int u = top.second;
        s.erase(s.begin());

        // Update distances for adjacent vertices
        for (int v = 0; v < size; v++) {
            if (graph[u][v] != 0) { // Check if there is an edge
                if (distance[u] + graph[u][v] < distance[v]) {
                    // Update distance
                    distance[v] = distance[u] + graph[u][v];
                    s.insert({distance[v], v});
                }
            }
        }
    }

    // Print the distance array
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < size; i++) {
        cout << i << "\t\t" << distance[i] << endl;
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[10][10] = {
        {0, 7, 9, 0, 0, 14},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 2},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {14, 0, 2, 0, 9, 0}
    };
    int size = 6; // Number of vertices

    int source = 0; // Starting vertex
    dijkstra(graph, source, size);

    return 0;
}
