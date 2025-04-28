#include <iostream>
using namespace std;

int knapsack(int W, int weights[], int values[], int n) {
    int dp[W + 1] = {0};

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    return dp[W];
}

int main() {
    int n = 4;
    int W = 7;
    int weights[] = {1, 3, 4, 5};
    int values[] = {1, 4, 5, 7};

    cout << "Maximum value in Knapsack = " << knapsack(W, weights, values, n) << endl;
    return 0;
}
