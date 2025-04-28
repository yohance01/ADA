#include <iostream>
using namespace std;

const int MAX = 20;
int graph[MAX][MAX];
int color[MAX];

bool isSafe(int v, int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) return false;
    }
    return true;
}

bool solve(int v, int m, int V) {
    if (v == V) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c, V)) {
            color[v] = c;
            if (solve(v + 1, m, V)) return true;
            color[v] = 0;
        }
    }
    return false;
}

void graphColoring(int m, int V) {
    for (int i = 0; i < V; i++) color[i] = 0;

    if (!solve(0, m, V)) {
        cout << "No solution\n";
    } else {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
        }
    }
}

int main() {
    int V, E, m;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) graph[i][j] = 0;
    }
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    cout << "Enter number of colors: ";
    cin >> m;
    graphColoring(m, V);
    return 0;
}
