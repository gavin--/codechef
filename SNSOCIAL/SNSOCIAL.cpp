#include <iostream>
#include <queue>
using namespace std;
 
int main() {
    int T;
    cin >> T;
    for(int n, m; cin >> n >> m; ) {
        int a[n][m], v = 0, result = -1;
        queue<pair<int, int>> queue;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
                if(a[i][j] > v) {
                    v = a[i][j];
                }
            }
        }
        vector<bool> visited[n];
        for(int i = 0; i < n; i++) {
            visited[i].resize(m);
            for(int j = 0; j < m; j++) {
                if(a[i][j] == v) {
                    queue.emplace(i, j);
                    visited[i][j] = true;
                }
            }
        }
        do {
            for(auto size = queue.size(); size > 0; size--) {
                for(int i = -1; i <= 1; i++) {
                    for(int j = -1; j <= 1; j++) {
                        auto x = queue.front().first + i, y = queue.front().second + j;
                        if(x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                            visited[x][y] = true;
                            queue.emplace(x, y);
                        } 
                    }
                }
                queue.pop();
            }
            result++;
        } while(!queue.empty());
        cout << result << endl;
    }
    return 0;
}
