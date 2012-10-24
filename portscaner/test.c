#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    perror("test failed.\n");
    printf("end.\n");
    exit(-1);
}
