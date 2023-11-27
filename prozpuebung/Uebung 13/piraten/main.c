#include <stdio.h>
#include <stdlib.h>

#define NAME_MAX_LEN 50
#define BOARD_ROWS  9
#define BOARD_COLS 10

typedef struct Parrot_s {
    char name[NAME_MAX_LEN];
} Parrot_t;

typedef struct Position_s {
    int row;
    int col;
} Position_t;

typedef struct Pirate_s {
    char name;
    Position_t position;
    int nextMoveIdx;
    int rum;
    int gold;
    Parrot_t * parrots;
    int n_parrots;
} Pirate_t;

typedef enum Move_e {
    LEFT,
    DOWN,
    UP,
    RIGHT
} Move_t;

char board[BOARD_ROWS][BOARD_COLS] = {
        "...1...2..",
        ".gr.g.rp..",
        "..gp..rg..",
        "..rgr.g.rg",
        ".g.rg.p.r.",
        ".pg.g.r.g.",
        ".gr..pg.r.",
        "..gr.g.p..",
        "SSSSSSSSSS",
};

Move_t moves[] = {LEFT, LEFT, DOWN, RIGHT, RIGHT, DOWN};

/**
 * Add parrots to the pirate
 */
void catchParrots(Pirate_t * pirate) {
    if(pirate->parrots == NULL && pirate->gold > 0) {
        pirate->parrots = (Parrot_t*) malloc(pirate->gold * sizeof(Parrot_t));
    }
    else if(pirate->parrots != NULL && pirate->gold > 0) {
        pirate->parrots = (Parrot_t*) realloc(pirate->parrots, (pirate->n_parrots + pirate->gold) * sizeof(Parrot_t));
    }
    while(pirate->gold > 0) {
        sprintf(pirate->parrots[pirate->n_parrots].name, "Parrot (%d) (%d) %d",pirate->position.row, pirate->position.col, rand()%20);
        pirate->gold -= 1;
        pirate->n_parrots += 1;
    }
}

/**
 * Apply a move to the current position and return the new position
 */
Position_t convertMoveToPosition(Position_t current, Move_t move) {
    switch(move) {
        case UP:
            if(current.row > 0)
                current.row -=1 ;
            break;
        case DOWN:
            if(current.col < BOARD_COLS)
                current.row += 1;
            break;
        case LEFT:
            if(current.col > 0)
                current.col -= 1;
            break;
        case RIGHT:
            if(current.col < BOARD_ROWS-1)
                current.col += 1;
            break;
    }
    return current;
}

/**
 * Let a pirate make a single step
 */
void step(Pirate_t * pirate) {
    Position_t tmpPosition;
    // apply nextMove or UP to calculate new position
    if(pirate->rum != 1) {
        tmpPosition = convertMoveToPosition(pirate->position, moves[pirate->nextMoveIdx]);
    }
    else {
        tmpPosition = convertMoveToPosition(pirate->position, UP);
    }
    // reduce rum by one, as long as available
    if(pirate->rum > 0) {
        pirate->rum -= 1;
    }
    // get marker at new position and update pirate attributes
    pirate->position = tmpPosition;
    switch(board[pirate->position.row][pirate->position.col]) {
        case 'p':
            catchParrots(pirate);
            break;
        case 'g':
            pirate->gold += 1;
            board[pirate->position.row][pirate->position.col] = '.';
            break;
        case 'r':
            pirate->rum += 3;
            board[pirate->position.row][pirate->position.col] = '.';
            break;
    }
    // increment nextMoveIdx by one. (cyclical)
    if(pirate->nextMoveIdx == 5) {
        pirate->nextMoveIdx = 0;
    }
    else {
        pirate->nextMoveIdx += 1;
    }
}

void printPirate(Pirate_t * pirate) {
    printf("Pirate %c: pos(%d, %d) rum(%d) gold(%d)\n", pirate->name, pirate->position.row, pirate->position.col, pirate->rum, pirate->gold);
    for (int i = 0; i < pirate->n_parrots; ++i) {
        printf("%s\n", pirate->parrots[i].name);
    }
}

/**
 * Main loop to execute steps repeatedly and finally report the winner
 */
void loop() {
    Pirate_t pirate1 = {'1', {0, 3}, 0, 0, 0, NULL, 0};
    Pirate_t pirate2 = {'2', {0, 7}, 1, 0, 0, NULL, 0};

    // TODO
    while(board[pirate1.position.row][pirate1.position.row] != 'S') {
        step(&pirate1);
    }
    while(board[pirate2.position.row][pirate2.position.row] != 'S') {
        step(&pirate2);
    }
    printPirate(&pirate1);
    printPirate(&pirate2);
}

// Welcher Pirat erreicht zuerst das Schiff? Wieviel Gold konnte er finden und wie heißen seine Papageien?
int main(void) {
    loop();
    return 0;
}
