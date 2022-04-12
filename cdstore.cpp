#include <iostream>
#include "cd.h"
#include <map>
#include <string>

//Menu chinh cua chuong trinh
void menu(){
  std::cout << "==============================================" << std::endl;
  std::cout << "Day la phan mem quan ly mua ban va thue dia CD" << std::endl;
  std::cout << "1. Them CD moi" << std::endl;
  std::cout << "2. Chon CD" << std::endl;
  std::cout << "3. In danh sach CD" << std::endl;
  std::cout << "4. Tong doanh thu ban duoc" << std::endl;
  std::cout << "5. Thoat" << std::endl;
  std::cout << "Lua chon cua ban la?" << std::endl;
  std::cout << "==============================================" << std::endl;
}

//Xu ly CD theo menu 2
void action2(CD CD_selected){
  int selected;
  Choice2:
  std::cin >> selected;
  switch (selected) {
    case 1:{
      std::cout << "So luong: " << std::endl;
      int n;
      std::cin >> n;
      if (n > CD_selected.quantity || CD_selected.quantity == 0){
        std::cout << "Khong du hang, con thieu " << n - CD_selected.quantity << std::endl;
        int sale = CD_selected.quantity;
        for (int i = 0; i < sale; i++){
          CD_selected.CDsales();
        };
        std::cout << CD_selected.name << " da ban "<< sale << " con lai "<< CD_selected.quantity << std::endl;
      }else {
        for (int i = 0; i < n; i++){
          CD_selected.CDsales();
        };
      std::cout << CD_selected.name << " da ban "<< n << " con lai "<< CD_selected.quantity << std::endl;
      }
      break;
    }
    case 2:{
      std::cout << "So luong: " << std::endl;
      int n;
      cin >> n;
      if (n > CD_selected.quantity || CD_selected.quantity == 0){
        std::cout << "Khong du hang, con thieu " << n - CD_selected.quantity << std::endl;
        int rent = CD_selected.quantity;
        for (int i = 0; i < rent; i++){
          CD_selected.CDrental();
        };
        std::cout << CD_selected.name << " cho thue "<< rent << " con lai "<< CD_selected.quantity << std::endl;
      }else {
        for (int i = 0; i < n; i++){
          CD_selected.CDsales();
        };
      std::cout << CD_selected.name << " da cho thue "<< n << " con lai "<< CD_selected.quantity << std::endl;
      };
      break;
    }
    case 3:{
      std::cout << "So luong: " << std::endl;
      int n;
      cin >> n;
      for (int i = 0; i < n; i++){
        CD_selected.CDreturn();
      }
      std::cout << CD_selected.name << " da tra lai "<< n << " con lai "<< CD_selected.quantity << std::endl;
      break;
    }
    case 4:{
      std::cout << "Doanh thu cua CD la: " << CD_selected.current_revenue << std::endl;
      break;
    }
    case 5:{
      cout << CD_selected.name << " hien dang cho thue " << CD_selected.for_rent << " CD" << std::endl;
      break;
    }
    case 6:{
      break;
    }
    default:{
      std::cout << "Khong hop le, moi nhap lai" << std::endl;
      goto Choice2;
    }
  }
}

//Menu 2
void actionmenu2(CD CD_selected){
  std::cout << "==============================================" << std::endl;
  std::cout << "CD ban chon la: " << CD_selected.name << std::endl;
  std::cout << "1. Ban CD" << std::endl;
  std::cout << "2. Cho thue CD" << std::endl;
  std::cout << "3. Tra lai CD" << std::endl;
  std::cout << "4. Tinh doanh thu cua CD" << std::endl;
  std::cout << "5. So CD dang cho thue" << std::endl;
  std::cout << "6. Tro ve" << std::endl;
  std::cout << "Lua chon cua ban la?" << std::endl;
  std::cout << "==============================================" << std::endl;
  action2(CD_selected);
}

//Duyet map va in ten CD
void dump(map<string,CD>& mp){
  for (auto x: mp) {
    std::cout << x.first << "; so luong: " << x.second.quantity << "; gia ban: " << x.second.price << "; gia thue: "<< x.second.rent_price << std::endl;
  }
}

//Tinh tong cong doanh thu
void totalcal(map<string,CD>& mp){
  int total = 0;
  for (auto x: mp) {
    total += x.second.current_revenue;
  };
  std::cout << total << std::endl;
}

int main (int argc, char *argv[])
{
  //Tao map de luu tru thong tin CD
  map<string, CD> CDstore;
  //Tao mot label Menu de quay ve``
  Menu:
  //In ra menu
  menu();
  int choice;
  std::cin >> choice;
  //Lua chon cua nguoi dung theo cac chuc nang cua menu
  switch (choice) {
    case 1:{
      CD cdinput = CD();
      CDstore.insert(std::make_pair(cdinput.name, cdinput));
      std::cout << "CD da duoc them" << std::endl;
      goto Menu;
    }
    case 2:
      if(CDstore.empty()) cout << "Khong co CD nao! Moi them CD" << std::endl;
      else{
        Choice:
        std::cout << "Ten CD:" << std::endl;
        string cdname;
        std::cin >> cdname;
        try {
          actionmenu2(CDstore[cdname]);
        } catch (...) {
          goto Choice;
        };
      }
    goto Menu;
  case 3:
    std::cout << "Danh sach CD hien co" << std::endl;
    dump(CDstore);
    goto Menu;
  case 4:
    totalcal(CDstore);
    goto Menu;
  case 5:
    break;
  default:
    std::cout << "Chon lai" << std::endl;
    goto Menu;
  }
  return 0;
}
