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

}

/**
 * Apply a move to the current position and return the new position
 */
Position_t convertMoveToPosition(Position_t current, Move_t move) {

}

/**
 * Let a pirate make a single step
 */
void step(Pirate_t * pirate) {

    // apply nextMove or UP to calculate new position


    // reduce rum by one, as long as available


    // get marker at new position and update pirate attributes


    // increment nextMoveIdx by one. (cyclical)
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
}

// Welcher Pirat erreicht zuerst das Schiff? Wieviel Gold konnte er finden und wie heißen seine Papageien?
int main(void) {
    loop();
    return 0;
}
