#define max(a, b) ({__typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b;})
int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
int getMaxScore(int* nums, int numsSize, int* ms, int step, unsigned short used) {
    if (ms[used] > 0) return ms[used];
    else if (step > numsSize / 2) return 0;
    for (int i = 0; i < numsSize; i++) {
        if (used & (1 << i)) continue;
        for (int j = i + 1; j < numsSize; j++) {
            if (used & (1 << j)) continue;
            unsigned short new_used = used | (1 << i) | (1 << j);
            int res = step * gcd(nums[i], nums[j]) + getMaxScore(nums, numsSize, ms, step + 1, new_used);
            ms[used] = max(ms[used], res);
        }
    }
    return ms[used];
}
int maxScore(int* nums, int numsSize) {
    int* ms = malloc((1 << numsSize) * sizeof(int));
    memset(ms, 0, sizeof(ms));
    return getMaxScore(nums, numsSize, ms, 1, 0);
}