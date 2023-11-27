

struct bruch_s{
    int zaehler;
    int nenner;
};
struct bruch_s rational_reduce(struct bruch_s fraction) {
    int a = fraction.zaehler;
    int b = fraction.nenner;
    if (fraction.zaehler == 0) {
        fraction.nenner = 1;
        return fraction;
    }
    if(a != b) {
        while (b != 0) {

            int rem = a % b;
            a = b;
            b = rem;
        }
    }
    fraction.zaehler = fraction.zaehler/a;
    fraction.nenner = fraction.nenner/a;
    return fraction;
}

struct bruch_s rational_product(struct bruch_s factor1, struct bruch_s factor2) {
    struct bruch_s fractionOut = {0,0};
    fractionOut.nenner = factor1.nenner * factor2.nenner;
    fractionOut.zaehler = factor1.zaehler * factor2.zaehler;
    return rational_reduce(fractionOut);
}

struct bruch_s rational_quotient(struct bruch_s dividend, struct bruch_s divisor) {
    struct bruch_s fractionOut = {0,0};
    fractionOut.nenner = dividend.nenner * divisor.zaehler;
    fractionOut.zaehler = dividend.zaehler * divisor.nenner;
    return rational_reduce(fractionOut);
}

struct bruch_s rational_sum(struct bruch_s fraction1, struct bruch_s fraction2) {
    struct bruch_s sumOut = {0,0};
    sumOut.nenner = fraction1.nenner * fraction2.nenner;
    sumOut.zaehler = (fraction1.zaehler * fraction2.nenner) + (fraction2.zaehler * fraction1.nenner);
    return rational_reduce(sumOut);
}

struct bruch_s rational_diff(struct bruch_s fraction1, struct bruch_s fraction2) {
    struct bruch_s diffOut = {0,0};
    diffOut.nenner = fraction1.nenner * fraction2.nenner;
    diffOut.zaehler = (fraction1.zaehler * fraction2.nenner) - (fraction2.zaehler * fraction1.nenner);
    return rational_reduce(diffOut);
}

