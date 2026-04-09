int lengthOfLongestSubstring(char* s) {
 int lastIndex[256];
    
    // Initialize all characters as not seen
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int maxLength = 0;
    int start = 0;  // start of current window

    for (int i = 0; s[i] != '\0'; i++) {
        // If character is repeated, move start
        if (lastIndex[s[i]] >= start) {
            start = lastIndex[s[i]] + 1;
        }

        // Update last seen index
        lastIndex[s[i]] = i;

        // Calculate current length
        int currentLength = i - start + 1;

        // Update maximum length
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;   
}