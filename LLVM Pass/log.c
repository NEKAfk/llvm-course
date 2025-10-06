#include <stdio.h>

void TraceLogger(char *user, char *operand) {
    printf("%s\t<-\t%s\n", user, operand);
}