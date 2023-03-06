int min(int a, int b) {return a < b ? a : b;}
int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
int nthMagicalNumber(int n, int a, int b) {
    int lcm = a / gcd(a, b) * b, period = lcm / a + lcm / b - 1, target = n % period;
    long last_lcm = (long) (n / period) * lcm, start = last_lcm, 
         end = start + (long) min(a, b) * target, mid, res;
    while (start <= end) {
        mid = (start + end) / 2;
        if ((mid - last_lcm) / a + (mid - last_lcm) / b < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
            res = mid;
        }
    }
    return res % 1000000007;
}