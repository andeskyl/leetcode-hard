int getXORSum(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    int xorSum1 = 0, xorSum2 = 0;
    for (int i = 0; i < arr1Size; xorSum1 ^= arr1[i], i++);
    for (int j = 0; j < arr2Size; xorSum2 ^= arr2[j], j++);
    return xorSum1 & xorSum2;
}