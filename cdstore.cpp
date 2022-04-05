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
  std::cin >> selected;
  switch (selected) {
    case 1:{
      std::cout << "So luong:" << std::endl;
      int n;
      std::cin >> n;
      for (int i = 0; i < n; i++){
        CD_selected.CDsell();
      }
    }
    case 2:{
      std::cout << "So luong:" << std::endl;
      int n;
      cin >> n;
      for (int i = 0; i < n; i++){
        CD_selected.CDrental();
      }
    }
    case 3:{
      std::cout << "So luong:" << std::endl;
      int n;
      cin >> n;
      for (int i = 0; i < n; i++){
        CD_selected.CDreturn();
      }
    }
    case 4:{
      std::cout << "Doanh thu cua CD la:" << CD_selected.current_revenue << std::endl;
    }
    case 5:{
      cout << CD_selected.name << "hien dang cho thue" << CD_selected.for_rent << "CD" << std::endl;
    }
    case 6:{
      break;
    }
  }
}

//Menu 2
void actionmenu2(CD CD_selected){
  std::cout << "==============================================" << std::endl;
  std::cout << "CD ban chon la" << CD_selected.name << std::endl;
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
    std::cout << x.first << std::endl;
  }
}

//Tinh tong cong doanh thu
void totalcal(map<string,CD>& mp){
  float total = 0;
  for (auto x: mp) {
    total += x.second.current_revenue;
  };
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
