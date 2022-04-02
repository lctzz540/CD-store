#include <iostream>
#include "cd.h"

CD::CD(){
  std::cout << "Nhap ten CD" << std::endl;
  std::cin >> this->name;
  std::cout << "Nhap gia CD" << std::endl;
  std::cin >> this->price;
  std::cout << "Nhap gia thue CD" << std::endl;
  std::cin >> this->rent_price;
  std::cout << "So luong nhap vao" << std::endl;
  std::cin >> this->amount;
  this->rented = 0;
  this->selled = 0;
}
void CD::CDrental(){
  if (this->amount != 0) {
    this->rented ++;
    this->amount --;
    this->current_revenue = this->rented * this->rent_price + this->selled*this->price;
  }else {
    std::cout << "Sorry this CD is no longer available" << std::endl;
  }
}
void CD::CDsell(){
  if(this->amount != 0){
    this->selled ++;
    this->amount --;
    this->current_revenue = this->rented * this->rent_price + this->selled*this->price;
  }
  else{
    std::cout << "Sorry this CD is no longer available" << std::endl;
  }
}
void CD::CDreturn(){
  this->amount ++;
}
void CD::revenue(){
  std::cout << "Doanh thu cua CD hien tai" << this->name << "la" << this->current_revenue << std::endl;
}
