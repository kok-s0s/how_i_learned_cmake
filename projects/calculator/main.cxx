#include <cstring>
#include <iostream>

#include "CalculatorConfig.h"

#ifdef USE_CALCULATOR
#include "CalculatorFunctions.h"
#endif

using std::cout;
using std::endl;
using std::string;

void showConfig(char *);

int main(int argc, char *argv[]) {
#ifdef USE_CALCULATOR
  string infix = "";

  sayHi();
  showConfig(argv[0]);

  while (true) {
    cout << ">>> ";
    getline(std::cin, infix);
    if (infix == "")
      continue;
    else if (infix == "cls" || infix == "clear") {
      cout << "\033[2J\033[1;1H";
      sayHi();
      continue;
    } else if (infix == "exit")
      break;
    trim(infix);
    handle(infix);
  }

  sayBye();
#else
  cout << "Wrong!" << endl;
#endif
  return 0;
}

void showConfig(char *name) {
  cout << name << " Version " << Calculator_VERSION_MAJOR << "."
       << Calculator_VERSION_MINOR << endl;
  cout << "--------------------------------------------------------------"
       << endl;
}
