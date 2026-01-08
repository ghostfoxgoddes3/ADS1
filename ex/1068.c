#include <stdio.h>
#include <string.h>

int main() {
    char expr[1001];
    
    while (fgets(expr, 1001, stdin) != NULL) {
        int count = 0;
        int ok = 1;
        
        for (int i = 0; expr[i] != '\0'; i++) {
            if (expr[i] == '(') {
                count++;
            }
            else if (expr[i] == ')') {
                if (count == 0) {
                    ok = 0;     // fechou sem abrir
                    break;
                }
                count--;
            }
        }
        
        if (ok && count == 0)
            printf("correct\n");
        else
            printf("incorrect\n");
    }
    return 0;
}
