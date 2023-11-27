#ifndef _RATIONAL_H_
#define _RATIONAL_H_
struct bruch_s{
    int zaehler;
    int nenner;
};
struct bruch_s rational_product(struct bruch_s fraction1, struct bruch_s fraction2);
struct bruch_s rational_quotient(struct bruch_s dividend, struct bruch_s divisor);
struct bruch_s rational_sum(struct bruch_s fraction1, struct bruch_s fraction2);
struct bruch_s rational_diff(struct bruch_s fraction1, struct bruch_s fraction2);

#endif
