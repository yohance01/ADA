#include <iostream>
using namespace std;

const int MAX = 20;
int graph[MAX][MAX];
int path[MAX];
int V;

bool isSafe(int v, int pos) {
    if (graph[path[pos-1]][v] == 0) return false;
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) return false;
    }
    return true;
}

bool solve(int pos) {
    if (pos == V) {
        if (graph[path[pos-1]][path[0]] == 1) return true;
        else return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            if (solve(pos+1)) return true;
            path[pos] = -1;
        }
    }
    return false;
}

void hamiltonianCycle() {
    for (int i = 0; i < V; i++) path[i] = -1;
    path[0] = 0;

    if (!solve(1)) {
        cout << "No Hamiltonian Cycle\n";
    } else {
        cout << "Hamiltonian Cycle: ";
        for (int i = 0; i < V; i++) {
            cout << path[i] << " ";
        }
        cout << path[0] << endl;
    }
}

int main() {
    int E;
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
    hamiltonianCycle();
    return 0;
}
