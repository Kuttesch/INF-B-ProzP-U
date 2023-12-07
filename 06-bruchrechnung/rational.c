#include "rational.h"



struct bruch_s add(struct bruch_s b1, struct bruch_s b2) {
    struct bruch_s sum;

    sum.zaehler = b1.zaehler * b1.nenner + b2.zaehler * b2.nenner;
    sum.nenner = b1.nenner * b1.nenner;

    sum = kuerzen(sum);
    return sum;
}

struct bruch_s sub(struct bruch_s b1, struct bruch_s b2) {
    struct bruch_s dif;

    dif.zaehler =  b1.zaehler * b1.nenner - b2.zaehler * b2.nenner;
    dif.nenner = b1.nenner * b1.nenner;

    dif = kuerzen(dif);
    return dif;
}

struct bruch_s mul(struct bruch_s b1, struct bruch_s b2) {
    struct bruch_s pro;

    pro.zaehler = b1.zaehler * b2.zaehler;
    pro.nenner = b1.nenner * b2.nenner;

    pro = kuerzen(pro);
    return pro;
}

struct bruch_s div(struct bruch_s b1, struct bruch_s b2) {
    struct bruch_s quo;

    quo.zaehler = b1.zaehler * b2.nenner;
    quo.nenner = b1.nenner * b2.zaehler;

    quo = kuerzen(quo);
    return quo;
}

int ggT(int a, int b)
{
    int ret;

    if(b == 0) {
        ret = a;
    } else {
        ret = ggT(b, a % b);
    }

    return ret;
}

struct bruch_s kuerzen(struct bruch_s b) {
    struct bruch_s gekuerzt;

    int ggt = ggT(b.zaehler, b.nenner);

    gekuerzt.zaehler = b.zaehler / ggt;
    gekuerzt.nenner = b.nenner / ggt;

    return gekuerzt;
}