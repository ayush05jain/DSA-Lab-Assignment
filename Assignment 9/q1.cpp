#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int INF = 9999999;

struct Edge {
    int u, v, weight;
};

void swapEdges(Edge &a, Edge &b) {
    Edge temp = a;
    a = b;
    b = temp;
}
void sortEdges(vector<Edge> &edges) {
    int n = edges.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                swapEdges(edges[j], edges[j + 1]);
            }
        }
    }
}
int minDistance(const vector<int> &dist, const vector<bool> &sptSet, int n) {
    int min = INF, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
int findParent(int i, vector<int> &parent) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void unionSets(int i, int j, vector<int> &parent) {
    int a = findParent(i, parent);
    int b = findParent(j, parent);
    parent[a] = b;
}
void BFS(int startNode, int n, const vector<vector<int>> &adj) {
    vector<bool> visited(n, false);
    vector<int> q; 
    int head = 0;  

    visited[startNode] = true;
    q.push_back(startNode);

    cout << "BFS Traversal: ";

    while (head < q.size()) {
        int u = q[head++];
        cout << u << " ";

        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0 && !visited[v]) {
                visited[v] = true;
                q.push_back(v);
            }
        }
    }
    cout << endl;
}
void DFSUtil(int u, int n, const vector<vector<int>> &adj, vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v = 0; v < n; v++) {
        if (adj[u][v] != 0 && !visited[v]) {
            DFSUtil(v, n, adj, visited);
        }
    }
}
void DFS(int startNode, int n, const vector<vector<int>> &adj) {
    vector<bool> visited(n, false);
    cout << "DFS Traversal: ";
    DFSUtil(startNode, n, adj, visited);
    cout << endl;
}
void Dijkstra(int startNode, int n, const vector<vector<int>> &adj) {
    vector<int> dist(n, INF);
    vector<bool> sptSet(n, false);

    dist[startNode] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        if (u == -1) break;

        sptSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && adj[u][v] && dist[u] != INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    cout << "Dijkstra's Shortest Paths from node " << startNode << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": \t" << (dist[i] == INF ? -1 : dist[i]) << endl;
    }
}
void Prim(int n, const vector<vector<int>> &adj) {
    vector<int> key(n, INF);
    vector<int> parent(n, -1);
    vector<bool> mstSet(n, false);

    key[0] = 0;  
    parent[0] = -1; 

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(key, mstSet, n); 
        if (u == -1) break;

        mstSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !mstSet[v] && adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj[u][v];
            }
        }
    }

    cout << "Prim's MST:\nEdge \tWeight\n";
    int mstWeight = 0;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " \t" << adj[i][parent[i]] << " \n";
        mstWeight += adj[i][parent[i]];
    }
    cout << "Total MST Weight: " << mstWeight << endl;
}
void Kruskal(int n, const vector<vector<int>> &adj) {
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adj[i][j] != 0) {
                Edge e;
                e.u = i;
                e.v = j;
                e.weight = adj[i][j];
                edges.push_back(e);
            }
        }
    }

    sortEdges(edges);

    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;

    vector<Edge> result;
    int mstWeight = 0;

    for (size_t i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        
        int setU = findParent(u, parent);
        int setV = findParent(v, parent);

        if (setU != setV) {
            result.push_back(edges[i]);
            mstWeight += edges[i].weight;
            unionSets(setU, setV, parent);
        }
    }

    cout << "Kruskal's MST:\nEdge \tWeight\n";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i].u << " - " << result[i].v << " \t" << result[i].weight << endl;
    }
    cout << "Total MST Weight: " << mstWeight << endl;
}
int main() {
    int n, choice, startNode;
    
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));

    cout << "Enter Adjacency Matrix (use 0 for no edge, positive value for weight):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    while (true) {
        cout << "\n------ GRAPH ALGORITHMS MENU ------\n";
        cout << "1. Breadth First Search (BFS)\n";
        cout << "2. Depth First Search (DFS)\n";
        cout << "3. Minimum Spanning Tree (Prim's)\n";
        cout << "4. Minimum Spanning Tree (Kruskal's)\n";
        cout << "5. Dijkstra's Shortest Path\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter start node (0 to " << n - 1 << "): ";
                cin >> startNode;
                BFS(startNode, n, adj);
                break;
            case 2:
                cout << "Enter start node (0 to " << n - 1 << "): ";
                cin >> startNode;
                DFS(startNode, n, adj);
                break;
            case 3:
                Prim(n, adj);
                break;
            case 4:
                Kruskal(n, adj);
                break;
            case 5:
                cout << "Enter start node (0 to " << n - 1 << "): ";
                cin >> startNode;
                Dijkstra(startNode, n, adj);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}