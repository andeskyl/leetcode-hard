int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}
int strongPasswordChecker(char* password) {
    int len = strlen(password), fixCond1 = max(6 - len, len - 20), fixCond2, fixCond3 = 0;
    int fixLower = 1, fixUpper = 1, fixDigit = 1, count = 1, mod[3] = {0};
    for (int i = 0; i < len; i++) {
        if (fixLower && islower(password[i])) fixLower = 0;
        else if (fixUpper && isupper(password[i])) fixUpper = 0;
        else if (fixDigit && isdigit(password[i])) fixDigit = 0;
        if (i < len - 1 && password[i] == password[i + 1]) count++;
        else {
            if (count >= 3) {
                fixCond3 += count / 3;
                mod[count % 3]++;
            }
            count = 1;
        }
    }
    fixCond2 = fixLower + fixUpper + fixDigit;
    if (len < 6) return max(fixCond1, fixCond2);
    else if (len < 20) return max(fixCond2, fixCond3);
    else {
        fixCond3 -= min(fixCond1, mod[0]);
        fixCond3 -= min(max(fixCond1 - mod[0], 0), mod[1] * 2) / 2;
        fixCond3 -= max(fixCond1 - mod[0] - mod[1] * 2, 0) / 3;
        return fixCond1 + max(fixCond2, fixCond3);
    }
}