#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

// ==============================
// 邊的資料結構
// ==============================
struct Edge {
    int to;
    int weight;
};

// ==============================
// 回復路徑用
// ==============================
void printPath(const vector<int>& parent, int v, const vector<string>& name) {
    // TODO:
    // 使用遞迴或 stack 印出從起點到 v 的路徑
    // 例如：S -> B -> E -> T
}

// ==============================
// 最短路徑 DP
// ==============================
void shortestPathDP(const vector<vector<Edge>>& graph,
                    const vector<int>& topo,
                    int source,
                    int target,
                    const vector<string>& name) {
    const int INF = numeric_limits<int>::max() / 2;
    int n = graph.size();

    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    // TODO:
    // Step 1. 初始化
    // dist[source] = 0;

    // TODO:
    // Step 2. 依照 topo 順序做 DP
    // 對每個 u：
    //   若 dist[u] 不是 INF
    //   對每條邊 u -> v
    //      若 dist[u] + weight < dist[v]
    //         更新 dist[v]
    //         parent[v] = u

    cout << "Shortest Path DP\n";
    cout << "Distance = ";

    if (dist[target] >= INF / 2) {
        cout << "INF\n";
        cout << "Path: No path\n\n";
    } else {
        cout << dist[target] << "\n";
        cout << "Path: ";
        // TODO:
        // 呼叫 printPath(parent, target, name);
        cout << "\n\n";
    }
}

// ==============================
// 最長路徑 DP
// DAG 中可直接用 DP 解
// ==============================
void longestPathDP(const vector<vector<Edge>>& graph,
                   const vector<int>& topo,
                   int source,
                   int target,
                   const vector<string>& name) {
    const int NEG_INF = numeric_limits<int>::min() / 2;
    int n = graph.size();

    vector<int> dist(n, NEG_INF);
    vector<int> parent(n, -1);

    // TODO:
    // Step 1. 初始化
    // dist[source] = 0;

    // TODO:
    // Step 2. 依照 topo 順序做 DP
    // 對每個 u：
    //   若 dist[u] 不是 NEG_INF
    //   對每條邊 u -> v
    //      若 dist[u] + weight > dist[v]
    //         更新 dist[v]
    //         parent[v] = u

    cout << "Longest Path DP\n";
    cout << "Distance = ";

    if (dist[target] <= NEG_INF / 2) {
        cout << "-INF\n";
        cout << "Path: No path\n\n";
    } else {
        cout << dist[target] << "\n";
        cout << "Path: ";
        // TODO:
        // 呼叫 printPath(parent, target, name);
        cout << "\n\n";
    }
}

// ==============================
// 最大乘積路徑 DP
// 因為所有權重皆為正，可直接做乘積 DP
// ==============================
void maxProductPathDP(const vector<vector<Edge>>& graph,
                      const vector<int>& topo,
                      int source,
                      int target,
                      const vector<string>& name) {
    int n = graph.size();

    vector<long long> prod(n, 0);
    vector<int> parent(n, -1);

    // TODO:
    // Step 1. 初始化
    // prod[source] = 1;
    // 因為乘積的起始值應為 1

    // TODO:
    // Step 2. 依照 topo 順序做 DP
    // 對每個 u：
    //   若 prod[u] > 0
    //   對每條邊 u -> v
    //      candidate = prod[u] * weight
    //      若 candidate > prod[v]
    //         更新 prod[v]
    //         parent[v] = u

    cout << "Maximum Product Path DP\n";
    cout << "Product = ";

    if (prod[target] == 0) {
        cout << "0\n";
        cout << "Path: No path\n\n";
    } else {
        cout << prod[target] << "\n";
        cout << "Path: ";
        // TODO:
        // 呼叫 printPath(parent, target, name);
        cout << "\n\n";
    }
}

// ==============================
// 主程式
// ==============================
int main() {
    // 節點編號
    // 0:S, 1:A, 2:B, 3:C, 4:D, 5:E, 6:F, 7:G, 8:T
    vector<string> name = {"S", "A", "B", "C", "D", "E", "F", "G", "T"};
    int n = 9;

    vector<vector<Edge>> graph(n);

    // TODO:
    // 依照題目加邊
    //
    // S -> A (6)
    // S -> B (5)
    // S -> C (7)
    // S -> D (4)
    //
    // A -> E (3)
    // A -> F (10)
    //
    // B -> E (2)
    // B -> G (2)
    //
    // C -> F (1)
    // D -> G (3)
    //
    // E -> T (2)
    // F -> T (9)
    // G -> T (5)

    // 這張圖已經是 DAG，可直接手動給拓樸順序
    vector<int> topo = {
        0, // S
        1, 2, 3, 4, // A, B, C, D
        5, 6, 7,    // E, F, G
        8           // T
    };

    int source = 0; // S
    int target = 8; // T

    shortestPathDP(graph, topo, source, target, name);
    longestPathDP(graph, topo, source, target, name);
    maxProductPathDP(graph, topo, source, target, name);

    return 0;
}
