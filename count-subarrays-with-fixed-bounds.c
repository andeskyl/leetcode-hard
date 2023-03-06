int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}
long long countSubarrays(int* nums, int numsSize, int minK, int maxK){
    long long res = 0;
    for (int i = 0, lastMin = -1, lastMax = -1, lastInvalid = -1; i < numsSize; i++) {
        if (nums[i] < minK || nums[i] > maxK) {
            lastInvalid = i;
        } else {
            lastMin = nums[i] == minK ? i : lastMin;
            lastMax = nums[i] == maxK ? i : lastMax;
            res += max(min(lastMin, lastMax) - lastInvalid, 0);
        }
    }
    return res;
}