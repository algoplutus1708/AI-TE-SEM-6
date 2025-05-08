#include <bits/stdc++.h>
using namespace std;

pair<int, int> costFn(int val) {
    vector<vector<int>> finalState = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (finalState[i][j] == val) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int h(vector<vector<int>> currState) {
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (currState[i][j] != 0) {
                pair<int, int> p = costFn(currState[i][j]);
                ans += abs(p.first - i);
                ans += abs(p.second - j);
            }
        }
    }
    return ans;
}

bool isGoal(vector<vector<int>> state) {
    vector<vector<int>> goal = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    return state == goal;
}

string matToString(vector<vector<int>> mat) {
    string s;
    for (auto &row : mat)
        for (auto &cell : row)
            s += to_string(cell);
    return s;
}

vector<vector<int>> swapPos(vector<vector<int>> mat, pair<int, int> a, pair<int, int> b) {
    swap(mat[a.first][a.second], mat[b.first][b.second]);
    return mat;
}

void printMatrix(vector<vector<int>> mat) {
    for (auto &row : mat) {
        for (int val : row) {
            if (val == 0) cout << "_ ";
            else cout << val << " ";
        }
        cout << "\n";
    }
    cout << "---------\n";
}

void solve(vector<vector<int>> initialState) {
    priority_queue<pair<int, pair<vector<vector<int>>, int>>,
                   vector<pair<int, pair<vector<vector<int>>, int>>>,
                   greater<>> pq;
    
    set<string> visited;
    map<string, string> parent;
    map<string, int> g_cost;

    string initialStr = matToString(initialState);
    g_cost[initialStr] = 0;

    pq.push({h(initialState), {initialState, 0}});
    parent[initialStr] = "";

    vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    while (!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        auto currState = curr.second.first;
        int g = curr.second.second;
        string currStr = matToString(currState);

        if (visited.count(currStr)) continue;
        visited.insert(currStr);

        if (isGoal(currState)) {
            // Backtrack to print the path
            vector<string> path;
            while (!currStr.empty()) {
                path.push_back(currStr);
                currStr = parent[currStr];
            }
            reverse(path.begin(), path.end());

            cout << "Solution found in " << path.size()-1 << " steps:\n";
            for (string &s : path) {
                vector<vector<int>> mat(3, vector<int>(3));
                for (int i = 0; i < 9; i++) {
                    mat[i / 3][i % 3] = s[i] - '0';
                }
                printMatrix(mat);
            }
            return;
        }

        // Locate the empty tile (0)
        pair<int, int> pos;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (currState[i][j] == 0)
                    pos = {i, j};

        for (auto dir : directions) {
            int newX = pos.first + dir.first;
            int newY = pos.second + dir.second;
            if (newX >= 0 && newX < 3 && newY >= 0 && newY < 3) {
                auto newState = swapPos(currState, pos, {newX, newY});
                string newStr = matToString(newState);
                int new_g = g + 1;

                if (!g_cost.count(newStr) || new_g < g_cost[newStr]) {
                    g_cost[newStr] = new_g;
                    int f = new_g + h(newState);
                    pq.push({f, {newState, new_g}});
                    parent[newStr] = currStr;
                }
            }
        }
    }

    cout << "No solution found.\n";
}

int main() {
    vector<vector<int>> initialState = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}
    };

    solve(initialState);
    return 0;
}
