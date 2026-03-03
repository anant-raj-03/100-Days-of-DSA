bool isValid(char* s) {
    char stack[10000];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        else {
            if (top == -1) return false;  // no matching opening

            if ((ch == ')' && stack[top] == '(') ||
                (ch == '}' && stack[top] == '{') ||
                (ch == ']' && stack[top] == '[')) {
                top--;  
            } else {
                return false; 
            }
        }
    }

    return top == -1;      
}