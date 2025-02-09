#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int d = 0; d < n; d++) {
            vector<int> diag;
            for (int i = d, j = 0; i < n; i++, j++) diag.push_back(grid[i][j]);
            sort(diag.begin(), diag.end(), greater<int>());
            for (int i = d, j = 0, k = 0; i < n; i++, j++, k++) grid[i][j] = diag[k];
        }
        for (int d = 1; d < n; d++) {
            vector<int> diag;
            for (int i = 0, j = d; j < n; i++, j++) diag.push_back(grid[i][j]);
            sort(diag.begin(), diag.end());
            for (int i = 0, j = d, k = 0; j < n; i++, j++, k++) grid[i][j] = diag[k];
        }
        return grid;
    }
};
