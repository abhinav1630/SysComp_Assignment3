//
// Created by Abhinav Agrawal on 9/23/22.
//

#ifndef SYSCOMP_ASSIGNMENT3_PRICING_METHOD_H
#define SYSCOMP_ASSIGNMENT3_PRICING_METHOD_H

# include "Option.h"

class Pricing_Method{

public:
    virtual std::vector<double> BSM_Pricer() = 0;
    virtual std:: vector <double> Binomial_Pricer() = 0;


};
#endif //SYSCOMP_ASSIGNMENT3_PRICING_METHOD_H
