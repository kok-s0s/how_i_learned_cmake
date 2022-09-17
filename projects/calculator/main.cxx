#include <cstring>
#include <iostream>
#include <limits>
#include <queue>

#include "CalculatorConfig.h"

#ifdef USE_CALCULATOR
#include "CalculatorFunctions.h"
#endif

using std::cout;
using std::endl;
using std::queue;
using std::string;

struct historyUnit {
  string infix;
  double result;
};

void showConfig(char *);

int main(int argc, char *argv[]) {
#ifdef USE_CALCULATOR
  queue<historyUnit> historys;
  int curIndex = 0;
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
    historyUnit temp;
    handle(infix, temp.result);
    if (temp.result != std::numeric_limits<double>::max()) {
      temp.infix = infix;
      historys.push(temp);
      curIndex++;
      if (curIndex > 10) {
        historys.pop();
        curIndex--;
      }
    }
    cout << "curFrontInfix: " << historys.front().infix << endl;
    cout << "curFrontResult: " << historys.front().result << endl;
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
