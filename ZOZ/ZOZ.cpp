#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, k; cin >> n >> k; ) {
        int a[n], sum = 0, result = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        for(int i = 0; i < n; i++) {
            if(a[i] + k > sum - a[i]) {
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
