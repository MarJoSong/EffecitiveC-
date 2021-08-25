#include <iostream>
#include "demo.hpp"

int main() {
#if 1

  D db;
  B* pB = &db;
  D* pD = &db;
  pB->mf();
  pD->mf();
  B& rB = db;
  rB.mf();
  D& rD = db;
  rD.mf();

#endif
  return 0;
}
