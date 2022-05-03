#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>

int main(){
    uint8_t array[2] = {"0F", "32"};
    printf("values are %X and %X\ndecimals are %d and %d", array[0], array[1], array[0], array[1]);

}