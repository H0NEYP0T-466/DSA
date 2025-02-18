#include<iostream>
#include<stack>
using namespace std;
void nextSmallElement(int heights[], int next[], int n) {
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--) {
        while (s.top() != -1 && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        next[i] = s.top();
        s.push(i);
    }
}
void prevSmallElement(int heights[], int prev[], int n) {
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++) {
        while (s.top() != -1 && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        prev[i] = s.top();
        s.push(i);
    }
}
int largestRectangleArea(int heights[], int n) {
    int next[n], prev[n];
    nextSmallElement(heights, next, n);
    prevSmallElement(heights, prev, n);
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        if (next[i] == -1) next[i] = n;
        int width = next[i] - prev[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }   
    return maxArea;
}
int main() {
    int heights[] = {2, 1, 5, 6, 2, 3};
    int n = sizeof(heights) / sizeof(heights[0]);
    cout << largestRectangleArea(heights, n) << endl;
    return 0;
}

