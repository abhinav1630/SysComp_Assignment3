//
// Created by Abhinav Agrawal on 9/23/22.
//

#include "Option.h"

Option::Option() {
    init();
}

Option ::Option(double strike_price, double spot, double rate, double ttm, double volatility ) {

    K = strike_price;
    S = spot;
    r = rate;
    t = ttm;
    sigma = volatility;
}

Option :: ~Option() {}


//To Initialise the initial values. Post that we can do using the object of the option class;
void Option::init() {
    K = 100;
    S = 100;
    r = 0.05;
    t = 0.01;
    sigma = 0.2;
}

