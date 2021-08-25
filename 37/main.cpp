#include <iostream>
//#include "demo1.hpp"
#include "demo2.hpp"

int main() {
  Unit *pu;
  auto *ptu = new TenUnit;
  auto *phu = new HunUnit;
  //pu->gCount();
  ptu->getCount();
  //phu->gCount();

  pu = ptu;
  pu->getCount();
  pu = phu;
  pu->getCount();


  return 0;
}
