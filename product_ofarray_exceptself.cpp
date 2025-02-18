#include <iostream>
using namespace std;
int main() 
{
    int arr[4] = {1,2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[n];
    int prefix = 1;
    for (int i = 0; i < 4; i++) {
        result[i] = prefix;
        prefix *= arr[i];
    }
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= arr[i];
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}


