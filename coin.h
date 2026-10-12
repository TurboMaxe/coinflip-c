#ifndef COIN_H
#define COIN_H

typedef struct coin  COIN;

typedef enum coin_res rslt;

void init_cin(COIN *coin);

int flip_cin(COIN *coin);

void free_cin(COIN *coin);

int get_cin_result(COIN *coin);

int cin_mem();

#endif