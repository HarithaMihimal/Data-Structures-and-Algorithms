#include <iostream>
#include <climits>

#define V 6
using namespace std;
// Function to find the vertex with minimum key value
int minmum_Key(int key[], bool mstSet[])
{
    int min = INT_MAX, minimum_index;  // difine all edges are infinity
    int v=0;
    while(v<V){  // Loop through all vertices in the graph
        if (!mstSet[v] && key[v] < min)  // If the vertex has not been included in the MST and its key value is less than the current minimum key
        {
            min = key[v];  // Update the minimum key value
            minimum_index = v; // Set the minimum index to the current vertex
        }
        v++; // Increment
    }
    return minimum_index; // Return the index
}


void primMST(int graph[V][V])
{
    int  key[V], parent[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {  // Set all keys to maximum value and all vertices to not yet included in MST.

        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    // Start the MST at vertex 0 by setting its key to 0.
    key[0] = 0;
    // Vertex 0 has no parent, so set its parent to -1.
    parent[0] = -1;
    // Keep track of the number of edges in the MST so far.
     int count=0;
    while(count<V-1)

    {
        // Select the vertex with the smallest key value that is not yet included in the MST.

        int u = minmum_Key(key, mstSet);
        mstSet[u] = true; // Mark the selected vertex as included in the MST.

        for (int v = 0; v < V; v++)
        { // If the edge between u and v exists, v is not yet in the MST, and the weight
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
        count++;
    }
    // Print out the edges and their weights in the MST.
    cout << "Edge\t\tWeight"<<endl;
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " to " << i << "  \t" << graph[i][parent[i]] <<endl;
    }

}

int main()
{  //create the adjacency matrix
    int graph[V][V] = {{0, 3, 0, 0, 0, 1},
                       {3, 0, 2, 1, 10, 0},
                       {0, 2, 0, 3, 0, 5},
                       {0, 1, 3, 0, 5, 0},
                       {0, 10, 0, 5, 0, 4},
                       {1, 0, 5, 0, 4, 0}};

    primMST(graph);  //call the primMST function

    return 0;
}
