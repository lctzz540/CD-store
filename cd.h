#ifndef CD_H
#define CD_H
#include <string>
using namespace std;

class CD{
  public:
    //Thuoc tinh cua CD
    string name;
    float price;
    float rent_price;
    int amount;
    int rented;
    int selled;
    int for_rent;
    float current_revenue;
    //Cac phuong thuc cua CD
    CD();
    void CDrental();
    void CDsell();
    void CDreturn();
    void revenue();
};

#endif
