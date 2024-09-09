#include <A.h>
#include <cstdlib>
#include <iostream>
#include <string>

int main() {
  A *a = new A();

  std::string text = a->main();

  std::cout << text << std::endl;
  std::cout << "" << '\n';
  return 0;
}
