//
// Created by Abhinav Agrawal on 9/23/22.
//

#include <iostream>
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>
#include "Option.h"
#include "Option_Price.h"

using namespace std;

int main() {
    double strike, spot, interest_rate, time_to_maturity, volatility;
    char option_type;
    cout << "Strike Price" << endl << "Spot Price" << endl << "Interest Rate" << endl
         << "Time to Maturity" << endl << "Vol" << endl << "Option Type" << endl;
    cin >> strike >> spot >> interest_rate >> time_to_maturity >> volatility >> option_type;

    if (!(option_type == 'c' || option_type == 'C' || option_type == 'p' || option_type == 'P')) {
        cout << "Option Type has to be in c,C,p,P" << endl;
        return 0;
    }

    Option_Price ip(option_type, strike, spot, interest_rate, time_to_maturity, volatility);

double ans ;

    for( auto ele: ip.Binomial_Pricer()){
//        ans = ele;
        cout<<"Price from Binomial "<<ele<<endl;
    }


    for( auto ele: ip.BSM_Pricer()){
//        ans = ele;
        cout<<"Price from Black Scholes "<<ele<<endl;
    }
}