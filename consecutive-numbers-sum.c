int consecutiveNumbersSum(int n){
    int res = 1;
    for (int k = 2; n >= (k + 1) * k / 2; k++)
        if ((2 * n) % k == 0 && ((2 * n) / k - k - 1) % 2 == 0) res++;
    return res;
}