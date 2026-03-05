int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1;
    
    for (int i = 0; i < tokensSize; i++) {
        
        // If operator
        if (strcmp(tokens[i], "+") == 0 ||
            strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 ||
            strcmp(tokens[i], "/") == 0) {
            
            int b = stack[top--];   // second operand
            int a = stack[top--];   // first operand
            
            if (strcmp(tokens[i], "+") == 0)
                stack[++top] = a + b;
            else if (strcmp(tokens[i], "-") == 0)
                stack[++top] = a - b;
            else if (strcmp(tokens[i], "*") == 0)
                stack[++top] = a * b;
            else if (strcmp(tokens[i], "/") == 0)
                stack[++top] = a / b;  // truncates toward zero automatically in C
        }
        else {
            // Number → convert string to int
            stack[++top] = atoi(tokens[i]);
        }
    }
    
    return stack[top];    
}