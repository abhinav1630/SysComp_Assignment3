//
// Created by Abhinav Agrawal on 9/23/22.
//

#ifndef SYSCOMP_ASSIGNMENT3_OPTION_H
#define SYSCOMP_ASSIGNMENT3_OPTION_H


class Option{

private:
     void init();
     double K;
     double S;
     double r;
     double t;
     double sigma;
public:
     Option();
     Option(double strike, double spot, double rate, double time_to_maturity, double sigma );
     ~Option();
     double  getStrike(){
         return K;
     }
     double getSpot(){
         return S;
     }
     double getRate(){
         return r;
     }
     double getTimeMaturity(){
         return t;
     }
     double getVolatility(){
         return sigma;
     }

     void setStrike(double strike){
         K = strike;
     }
    void setSpot(double spot){
        S = spot;
    }
    void setRate(double rate) {
        r = rate;
    }
    void setTimeMaturity(double ttm){
        t = ttm;
    }
    void setVolatility(double vol){
        sigma = vol;
    }
protected:

};

#endif //SYSCOMP_ASSIGNMENT3_OPTION_H
