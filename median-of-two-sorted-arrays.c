int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}
void swapInt(int* ptr1, int* ptr2) {
    int tmp; tmp = *ptr1; *ptr1 = *ptr2; *ptr2 = tmp;
}
void swapPtr(void** ptr1, void** ptr2) {
    void* tmp; tmp = *ptr1; *ptr1 = *ptr2; *ptr2 = tmp;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        swapPtr(&nums1, &nums2);
        swapInt(&nums1Size, &nums2Size);
    }
    int total = nums1Size + nums2Size, targetSize = total / 2;
    int start = 0, end = nums1Size, count1, count2;
    int leftEnd1, rightStart1, leftEnd2, rightStart2;
    do {
        count1 = (start + end) / 2;
        count2 = targetSize - count1;
        leftEnd1 = count1 > 0 ? nums1[count1 - 1] : INT_MIN;
        rightStart1 = count1 < nums1Size ? nums1[count1] : INT_MAX;
        leftEnd2 = count2 > 0 ? nums2[count2 - 1] : INT_MIN;
        rightStart2 = count2 < nums2Size ? nums2[count2] : INT_MAX;
        if (leftEnd1 > rightStart2) {
            end = count1 - 1;
        } else start = count1 + 1;
    } while (start <= end && (leftEnd1 > rightStart2 || leftEnd2 > rightStart1));
    return total % 2 ? min(rightStart1, rightStart2) : (max(leftEnd1, leftEnd2) + min(rightStart1, rightStart2)) / 2.0;
}