bool xorGame(int* nums, int numsSize) {
    int n = 0;
    for (int i = 0; i < numsSize; n ^= nums[i], i++);
    return n == 0 || numsSize % 2 == 0;
}