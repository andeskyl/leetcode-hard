bool isMatch(char* s, char* p) {
    for (char* lastMatch = s, *lastStar = NULL; *s;)
        if (*p == *s || *p == '?') {p++; s++;}
        else if (*p == '*') {lastStar = p++; lastMatch = s;}
        else if (lastStar) {p = lastStar + 1; s = ++lastMatch;}
        else return false;
    for (; *p == '*'; p++);
    return !*p;
}