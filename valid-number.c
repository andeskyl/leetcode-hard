bool isNumber(char* s){
    bool is_valid = false;
    for (bool after_first = false, after_dot = false, after_e = false; *s != '\0'; s++) {
        if (isdigit(*s)) is_valid = true;
        else if ((*s == '+' || *s == '-') && (!after_first || s[-1] == 'e' || s[-1] == 'E'));
        else if (*s == '.' && !after_dot && !after_e) after_dot = true;
        else if ((*s == 'e' || *s == 'E') && is_valid && !after_e && after_first && (isdigit(s[-1]) || s[-1] == '.')) {
            after_e = true;
            is_valid = false;
        } else return false;
        after_first = true;
    }
    return is_valid;
}