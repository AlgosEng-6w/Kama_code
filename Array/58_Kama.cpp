#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    vector<int>arr(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    vector<int>ans(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        ans[i] = sum;
    }
    int a, b;
    while (scanf("%d %d", &a, &b) == 2) {
        if (!a) printf("%d\n", ans[b]);
        else printf("%d\n", ans[b]-ans[a-1]);
    }
    return 0;
}