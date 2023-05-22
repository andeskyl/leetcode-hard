#define max(a, b) ({__typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b;})
#define min(a, b) ({__typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b;})
int candy(int* ratings, int ratingsSize) {
    int up_count = 0, down_count = 0, dir = 1, res = 1;
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1] && dir == 1) {
            up_count++;
        } else if (ratings[i] < ratings[i - 1]) {
            down_count++, dir = -1;
        } else {
            int n = max(up_count, down_count), k = min(up_count, down_count);
            res += (n + 2) * (n + 1) / 2 + k * (k + 1) / 2 - 1;
            up_count = 0, down_count = 0, dir = 1;
            if (ratings[i] == ratings[i - 1]) res++;
            else up_count++;
        }
    }
    int n = max(up_count, down_count), k = min(up_count, down_count);
    res += (n + 2) * (n + 1) / 2 + k * (k + 1) / 2 - 1;
    return res;
}