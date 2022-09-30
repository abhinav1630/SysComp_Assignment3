//
// Created by Abhinav Agrawal on 9/23/22.
//

#ifndef SYSCOMP_ASSIGNMENT3_OPTION_PRICE_H
#define SYSCOMP_ASSIGNMENT3_OPTION_PRICE_H

# include "Option.h"
#include "Pricing_Method.h"

class Option_Price : public Option, public Pricing_Method{

public:
    char flag;
    Option_Price(char flag, double strike_price, double spot, double rate, double time_to_maturity, double volatility);
    ~Option_Price();
    std::vector<double> BSM_Pricer();
    std::vector<double> Binomial_Pricer();
private:

protected:

};

#endif //SYSCOMP_ASSIGNMENT3_OPTION_PRICE_H
