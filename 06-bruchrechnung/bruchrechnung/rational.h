#ifndef BRUCHRECHNUNG_RATIONAL_H
#define BRUCHRECHNUNG_RATIONAL_H

struct bruch_s {
    int zaehler;
    int nenner;
};

struct bruch_s add(struct bruch_s bruch1, struct bruch_s bruch2);
struct bruch_s sub(struct bruch_s bruch1, struct bruch_s bruch2);
struct bruch_s mul(struct bruch_s bruch1, struct bruch_s bruch2);
struct bruch_s div(struct bruch_s bruch1, struct bruch_s bruch2);


struct bruch_s kuerzen(struct bruch_s bruch);

int ggT(int a, int b);

#endif //BRUCHRECHNUNG_RATIONAL_H
