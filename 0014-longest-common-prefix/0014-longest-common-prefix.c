#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0)
        return "";

    // Assume first string is prefix
    char *prefix = strs[0];

    // Compare with remaining strings
    for (int i = 1; i < strsSize; i++) {

        // Reduce prefix until it matches current string
        while (strncmp(prefix, strs[i], strlen(prefix)) != 0) {
            prefix[strlen(prefix) - 1] = '\0';  // remove last char

            // If prefix becomes empty
            if (strlen(prefix) == 0)
                return "";
        }
    }

    return prefix;
}