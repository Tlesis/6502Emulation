#include <stdio.h>

void dec(int* num) {
    num--;
}

int inital(int num) {
    dec(&num);
}

int main() {
    int two = 2;
    inital(two);
    printf("Value: %d", two);
}