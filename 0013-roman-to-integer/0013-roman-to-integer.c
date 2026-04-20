int romanToInt(char* s) {
    int values[256] = {0};

    values['I'] = 1;
    values['V'] = 5;
    values['X'] = 10;
    values['L'] = 50;
    values['C'] = 100;
    values['D'] = 500;
    values['M'] = 1000;

    int total = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (values[s[i]] < values[s[i + 1]])
            total -= values[s[i]];
        else
            total += values[s[i]];
    }

    return total;    
}