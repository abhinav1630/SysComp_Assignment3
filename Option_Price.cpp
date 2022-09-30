//
// Created by Abhinav Agrawal on 9/23/22.
//

# include <iostream>
# include <math.h>
# include <cmath>
# include "Option.h"
# include "Option_Price.h"
# include "Pricing_Method.h"
# include <vector>

using namespace std;

double optionPayoff(double strike, double spot, bool call){
    if (call){
        return max((spot - strike), 0.0);
    }
    else{
        return max((strike-spot), 0.0);
    }
}

double isCallOption(char flag)
{
    return flag == 'C' || flag == 'c';
}



Option_Price::Option_Price (char flag, double strike_price, double spot, double rate, double time_to_maturity, double sigma) :
        Option{strike_price, spot, rate, time_to_maturity, sigma}, flag{flag}
{
}

Option_Price::~Option_Price()
{
}



// Normal CDF code from Web.
// Link: https://stackoverflow.com/questions/2328258/cumulative-normal-distribution-function-in-c-c

double NormalCDF(double d)
{
    const double       A1 = 0.31938153;
    const double       A2 = -0.356563782;
    const double       A3 = 1.781477937;
    const double       A4 = -1.821255978;
    const double       A5 = 1.330274429;
    const double RSQRT2PI = 0.39894228040143267793994605993438;

    double K = 1.0 / (1.0 + 0.2316419 * fabs(d));

    double cnd = RSQRT2PI * exp(- 0.5 * d * d) *
                  (K * (A1 + K * (A2 + K * (A3 + K * (A4 + K * A5)))));

    if (d > 0)
        cnd = 1.0 - cnd;

    return cnd;
}

std::vector<double> Option_Price :: Binomial_Pricer() {
    double spot_price = getSpot();
    double rate = getRate();
    double strike = getStrike();
    double timeMaturity = getTimeMaturity();
    double volatility = getVolatility();

    vector<double> ans;

    double delta_t = 0.05;
    double up = exp(volatility * sqrt(delta_t));
    double down = 1 / up;

    double p = (exp(rate * delta_t) - down) / (up - down);
    double n_steps = timeMaturity / delta_t;
    double q = 1.0 - p;
    int m = int(n_steps);

    double option_delta = 0;


    vector<double> node(n_steps + 1);

    for (int i = 0; i <= n_steps; i++) {
        node[i] = optionPayoff(strike, spot_price * pow(up, 2.0 * i - n_steps), isCallOption(flag));
    }

    for (int j = n_steps - 1; j >= 0; j--) {
        for (int i = 0; i <= j; i++) {
            node[i] = (p * node[i + 1] + q * node[i]) * exp(-rate * delta_t);
        }
    }



    double k = node[0];
    ans.push_back(node[0]);
//    ans.push_back(option_delta);

    return ans;
}


//    vector<double> Node(n_steps + 1);
//    double stock_matrix [m+1][m+1] ={};
////    vector<vector<double>> stock_matrix(n_steps+1);
//
//    for(int j= 0;j<n_steps+1;j++){
//        for (int i = j;i<j+1;i++){
//            cout<<i;
//            stock_matrix[i][j]  = spot_price * pow(down, i) * pow(up, j-i);
//        }
//    }
//
//    vector<vector<double>> option_matrix(n_steps+1);
//
//    int z = n_steps;
//    for(int i = 0; i<n_steps +1; i++){
//        option_matrix[i][z] = optionPayoff(strike , stock_matrix[i][z], isCallOption(flag));
//    }
//
//    for (int j = n_steps-1; j>-1; j--){
//        for (int i = 0; i< j+1; i++){
//            double v_plus = option_matrix[i][j+1];
//            double v_minus = option_matrix[i+1][j+1];
//            option_matrix[i][j] =((((v_plus - v_minus)/(up-down)) * (1 + rate * delta_t)) + (up * v_minus - down * v_plus)
//                    /(up - down)) /(1+ rate * delta_t);
//
//        }
//    }
//
//    // Code for Calculating Delta to be done
//    double delta = 1.0;
//    double price_of_option_at_0 = option_matrix[0][0];
//    vector <double> ans;
//    ans.push_back(price_of_option_at_0);
//    ans.push_back(delta);
//
//    return ans;
//
//}

std::vector<double> Option_Price :: BSM_Pricer(){

    double spot_price = getSpot();
    double rate = getRate();
    double strike = getStrike();
    double timeMaturity = getTimeMaturity();
    double volatility = getVolatility();

    double price_of_option;
    double delta_black_scholes;
    vector <double> ans;
    double d1 = (1 / (volatility * sqrt (timeMaturity))) * (log(spot_price / strike)   + (rate + volatility * volatility
            / 2) * timeMaturity);
    double d2 = d1 - volatility * sqrt(timeMaturity);

    delta_black_scholes= NormalCDF(d1);
//    double cdf = NormalCDF(d1);

    if (isCallOption(flag)) {
        price_of_option = NormalCDF(d1) * spot_price - NormalCDF(d2) * strike * exp(-rate * timeMaturity);
//        cout<< price_of_option;
    }
    else {

        price_of_option = NormalCDF(-d2) * strike * exp(-1 * rate * timeMaturity) - NormalCDF(-d1) * spot_price;
    }

    ans.push_back(price_of_option);
    ans.push_back(delta_black_scholes);

    return ans;
}

