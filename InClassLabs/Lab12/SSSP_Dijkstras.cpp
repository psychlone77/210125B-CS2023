// C++ program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph
#include <iostream>
#include <vector>
using namespace std;
#include <limits.h>

// Number of vertices in the graph
#define V 6

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[]) {

  // Initialize min value
  int min = INT_MAX;
  int min_index;

  for (int v = 0; v < V; v++)
    if (sptSet[v] == false && dist[v] <= min)
      min = dist[v], min_index = v;

  return min_index;
}

//function to find average distance from a source node
float average(int dist[], int srcNode) {
  float sum = 0;
  for (int i = 0; i < V; i++) {
    if (i == srcNode) {
      continue;
    }
    sum += dist[i];
  }
  return sum / (V - 1);
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[], int srcNode) {
  cout << "Vertex \t Time from Source" << endl;
  for (int i = 0; i < V; i++) {
    if (i == srcNode) {
      continue;
    }
    cout << i << " \t\t\t\t" << dist[i] << endl;
  }
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
float dijkstra(int graph[V][V], int src) {
  int dist[V]; // The output array.  dist[i] will hold the
               // shortest
  // distance from src to i

  bool sptSet[V]; // sptSet[i] will be true if vertex i is
                  // included in shortest
  // path tree or shortest distance from src to i is
  // finalized

  // Initialize all distances as INFINITE and stpSet[] as
  // false
  for (int i = 0; i < V; i++){
    dist[i] = INT_MAX;
    sptSet[i] = false;
  }

  // Distance of source vertex from itself is always 0
  dist[src] = 0;

  // Find shortest path for all vertices
  for (int count = 0; count < V - 1; count++) {
    // Pick the minimum distance vertex from the set of
    // vertices not yet processed. u is always equal to
    // src in the first iteration.
    int u = minDistance(dist, sptSet);

    // Mark the picked vertex as processed
    sptSet[u] = true;

    // Update dist value of the adjacent vertices of the
    // picked vertex.
    for (int v = 0; v < V; v++)

      // Update dist[v] only if is not in sptSet,
      // there is an edge from u to v, and total
      // weight of path from src to  v through u is
      // smaller than current value of dist[v]
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
          dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
  }

  // print the constructed distance array
  printSolution(dist, src);
  return average(dist, src);
}

// driver's code
int main() {

  /* Let us create the example graph discussed above */
  int graph[V][V] = {
  {0, 10, 0, 0, 15, 5},  
  {10, 0, 10, 30, 0, 0}, 
  {0, 10, 0, 12, 5, 0},
  {0, 30, 12, 0, 0, 20}, 
  {15, 0, 5, 0, 0, 0},  
  {5, 0, 0, 20, 0, 0},
  };

  vector<int> minSrcNodes; //vector to hold best source nodes 
  float minAvg = (float)INT_MAX;

  for (int i = 0; i < V; i++) {
    cout << "Source Node = " << i << endl;
    float avg = dijkstra(graph, i);

    if (avg == minAvg) {
      minSrcNodes.push_back(i);
    } 
    
    else if (avg < minAvg) {
      minSrcNodes.clear();
      minAvg = avg;
      minSrcNodes.push_back(i);
    }

    cout << "Average Time is: " << avg << endl;
    cout << "\n";
  }

  cout << "Best Source Node/s: ";
  for(int node : minSrcNodes){
    cout << node << ", ";
  }
  cout << endl;

  return 0;
}
