#ifndef CD_H
#define CD_H
#include <string>
using namespace std;

class CD{
  public:
    string name;
    float price;
    float rent_price;
    int amount;
    int rented;
    int selled;
    float current_revenue;
    CD();
    void CDrental();
    void CDsell();
    void CDreturn();
    void revenue();
};

#endif
