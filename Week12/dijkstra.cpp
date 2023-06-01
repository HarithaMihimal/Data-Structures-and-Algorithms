
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
typedef pair<int, int> Int_pair; // Pair of integers (node, distance)
const int INF = numeric_limits<int>::max(); // Infinity
// Dijkstra's algorithm function that takes an adjacency matrix representation of the graph and the starting node as input
    vector<int> dijkstra(const vector<vector<int>>& graph, int begin) {
    int num = graph.size(); // Number of nodes in the graph
    vector<int> dist(num, INF); // Initialize distances with infinity for all nodes except the start node
    dist[begin] = 0;

    // Priority queue to store the nodes with their minimum distances
    priority_queue<Int_pair, vector<Int_pair>,greater<Int_pair>> pri_queue;
    pri_queue.push(make_pair(0, begin));

    while (!pri_queue.empty()) {
        int current_distance = pri_queue.top().first;
        int node = pri_queue.top().second;
        pri_queue.pop();

        // Skip if the current distance is already greater than the recorded distance
        if (current_distance > dist[node]) {
            continue;
        }

        for (int nearest_neighbour = 0; nearest_neighbour < num; nearest_neighbour++) {
            int weight = graph[node][nearest_neighbour];

            // Ignore non-existent or zero-weight edges
            if (weight == 0)
                continue;

            int distance = current_distance + weight;

            // Update distance if a shorter path is found
            if (distance < dist[nearest_neighbour]) {
                dist[nearest_neighbour] = distance;
                pri_queue.push(make_pair(distance, nearest_neighbour));
            }
        }
    }

    return dist;
}

int main() {
    int n = 6; // Number of nodes in the graph

    // Adjacency matrix representation of the graph
    vector<std::vector<int>> graph = {
            {0, 10, 0, 0, 15, 5},
            {10, 0, 10, 30, 0, 0},
            {0, 10, 0, 12, 5, 0},
            {0, 30, 12, 0, 0, 20},
            {15, 0, 5, 0, 0, 0},
            {5, 0, 0, 20, 0, 0}
    };

    int begin_node = 0;
    vector<int> distances = dijkstra(graph, begin_node);//create least distances vector using reterned values

    cout << "Least time duration from City " << begin_node << ":" << endl;
   
    for (int i = 0; i < n; i++) {//loop for print times and cities
        cout<<"City : "<<begin_node<<"\tto\tCity " << i << "\t-->\tTime : " << distances[i] << endl;
    }

    return 0;
}
