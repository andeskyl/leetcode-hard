#define max(a, b) ({__typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b;})
int trap(int* height, int heightSize) {
    int i = 0, j = heightSize - 1, leftMax = height[i], rightMax = height[j], res = 0;
    while (i <= j) {
        leftMax = max(height[i], leftMax);
        rightMax = max(height[j], rightMax);
        if (leftMax <= rightMax) res += leftMax - height[i++];
        else res += rightMax - height[j--];
    }
    return res;
}