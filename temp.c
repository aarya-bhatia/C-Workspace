#include <stdio.h>

#define MAX 300
#define STEP 20

int main() {
    printf("%s\t%s\n","°F","°C");
    for(int i = 0; i < MAX; i += STEP) {
        double c = (5.0/9.0) * (i-32);
        printf("%3d %6.1f\n", i, c);
    }
    return 0;
}