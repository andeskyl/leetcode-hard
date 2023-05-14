#define max(a, b) ({__typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b;})
int gcdMem[14][14] = {0};
int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
int gcdWithMem(int a, int b) {return gcdMem[a][b] > 0 ? gcdMem[a][b] : gcd(a, b);}
int getMaxScore(int* nums, int numsSize, int* maxScoreMem, int step, unsigned short used) {
    if (maxScoreMem[used] > 0) return maxScoreMem[used];
    else if (step > numsSize / 2) return 0;
    for (int i = 0; i < numsSize; i++) {
        if (used & (1 << i)) continue;
        for (int j = i + 1; j < numsSize; j++) {
            if (used & (1 << j)) continue;
            unsigned short new_used = used | (1 << i) | (1 << j);
            int res = step * gcd(nums[i], nums[j]) + getMaxScore(nums, numsSize, maxScoreMem, step + 1, new_used);
            maxScoreMem[used] = max(maxScoreMem[used], res);
        }
    }
    return maxScoreMem[used];
}
int maxScore(int* nums, int numsSize) {
    int* maxScoreMem = malloc((1 << numsSize) * sizeof(int));
    memset(maxScoreMem, 0, sizeof(maxScoreMem));
    return getMaxScore(nums, numsSize, maxScoreMem, 1, 0);
}