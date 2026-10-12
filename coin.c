#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum coin_res {
      TAILS, // 0
      HEADS, // 1
      UNDEF, // 2
} rslt; 

typedef struct {
   enum coin_res rslt;
} COIN;

int cin_mem() {
   return sizeof(COIN);
}

int init_cin(COIN *buf) {
    if (buf == NULL || sizeof(*buf) != sizeof(COIN)) {
        return -1;
    }
    buf = malloc(sizeof(COIN));
    if (buf == NULL) {
        return -2;
    }
    buf->rslt = UNDEF;
    return 0;
}

int flip_cin(COIN *coin) {
    if (coin == NULL || sizeof(*coin) != sizeof(COIN)) {
        return -1;
    }
    srand(time(NULL));
    enum coin_res rslt = (rand() % 2) ? HEADS : TAILS;
    coin->rslt = rslt;
    return 0;
}

int get_cin_result(COIN *coin) {
    if (coin == NULL || sizeof(*coin) != sizeof(COIN)) {
        return -1;
    } else if (coin->rslt == UNDEF) {
        return 1;
    }
    return coin->rslt;
}

void free_cin(COIN *coin) {
    if (coin != NULL) {
        free(coin);
        coin == NULL;
    }
}

