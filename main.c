#include <stdio.h>
#include <stdlib.h>
#include "coin.h"

int main(void) {
    char input_buf[2];
    const char yes[2] = { 'y', 'Y'};
    const char no[2] = { 'n', 'N'};  

    printf("Flip Coin? Y/N\n");
    fgets(input_buf, sizeof(input_buf), stdin);
    for (int i = 0; i < 2; i++) {
        if (input_buf[0] == yes[i]) {
            COIN *coin_buf = malloc(sizeof(cin_mem()));
           
            if (coin_buf == NULL) {
                fprintf(stderr, "Error: Failed to allocate memory for coin\n");
                return 1;
            }
 
            init_cin(coin_buf);
            flip_cin(coin_buf);

            if (get_cin_result(coin_buf) == 0) {
                printf("Result: HEADS\n");
            } else if (get_cin_result(coin_buf) == 1) {
                printf("Result: TAILS\n");
            } else {
                printf("Result: UNDEFINED\n");
            }
            return 0;
        } else if (input_buf[0] == no[i]) {
            printf("Exiting...\n");
            return 0;
        }
    }
}