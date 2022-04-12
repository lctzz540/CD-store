#include <iostream>
#include "cd.h"

//Phuong thuc khoi tao
CD::CD(){
  std::cout << "Nhap ten CD" << std::endl;
  std::cin >> this->name;
  std::cout << "Nhap gia CD" << std::endl;
  std::cin >> this->price;
  std::cout << "Nhap gia thue CD" << std::endl;
  std::cin >> this->rent_price;
  std::cout << "So luong nhap vao" << std::endl;
  std::cin >> this->quantity;
  this->rented = 0;
  this->sold = 0;
  this->for_rent = 0;
}
//Phuong thuc cho thue
void CD::CDrental(){
  if (this->quantity != 0) {
    this->rented ++;
    this->quantity --;
    this->current_revenue = (this->rented * this->rent_price) + (this->sold * this->price);
    this->for_rent ++;
  }else {
    std::cout << "Sorry this CD is no longer available" << std::endl;
  }
}
//Phuong thuc ban
void CD::CDsales(){
  if(this->quantity != 0){
    this->sold ++;
    this->quantity --;
    this->current_revenue = (this->rented * this->rent_price) + (this->sold * this->price);
  }
  else{
    std::cout << "Sorry this CD is no longer available" << std::endl;
  }
}
//Phuong thuc tra CD
void CD::CDreturn(){
  if(for_rent != 0){
    this->quantity ++;
    this->for_rent --;
  } else
  {
    std::cout << "Currently no one is renting this type of CD" << std::endl;
  }
}
//Phuong thuc tinh doanh thu cua CD
void CD::revenue(){
  std::cout << "Doanh thu cua CD hien tai" << this->name << "la" << this->current_revenue << std::endl;
}
