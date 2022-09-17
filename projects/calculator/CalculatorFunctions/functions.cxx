#include "CalculatorFunctions.h"

void trim(string &str) {
  const char *typeOfWhitespaces = " \t\n\r\f\v";

  str.erase(str.find_last_not_of(typeOfWhitespaces) + 1);
  str.erase(0, str.find_first_not_of(typeOfWhitespaces));
}

void sayHi() {
  cout << "--------------------------------------------------------------"
       << endl;
  cout << "|----                                                    ----|"
       << endl;
  cout << "|---     Welcome to the simple calculator I designed!     ---|"
       << endl;
  cout << "|----                                                    ----|"
       << endl;
  cout << "|------------------------------------------------------------|"
       << endl;
  cout << "|                                                            |"
       << endl;
  cout << "|   You can use it directly like with python                 |"
       << endl;
  cout << "|                                                            |"
       << endl;
  cout << "|                     Just enter a mathematical expression   |"
       << endl;
  cout << "|                                                            |"
       << endl;
  cout << "|   Press 'exit' to close the program                        |"
       << endl;
  cout << "--------------------------------------------------------------"
       << endl;
}

int priority(string operatorStr) {
  if (operatorStr == "+" || operatorStr == "-")
    return 1;
  else if (operatorStr == "*" || operatorStr == "/")
    return 2;
  else if (operatorStr == "**" || operatorStr == "%")
    return 3;

  return 0;
}

void handle(string infix, double &result) {
  queue<string> postfix;
  stack<string> helper;
  stack<double> nums;

  string::const_iterator ch = infix.begin();
  while (ch != infix.end()) {
    if (*ch == ' ') {
      ch++;
      continue;
    } else if ((*ch == '-' && ch == infix.begin() && isdigit(*(ch + 1))) ||
               (*ch == '-' && *(ch - 1) == '(' && isdigit(*(ch + 1)))) {
      string temp;
      temp.push_back(*ch);
      while (isdigit(*(ch + 1)) || *(ch + 1) == '.') {
        ch++;
        temp.push_back(*ch);
      }
      postfix.push(temp);
    } else if (isdigit(*ch)) {
      string temp;
      temp.push_back(*ch);
      while (isdigit(*(ch + 1)) || *(ch + 1) == '.') {
        ch++;
        temp.push_back(*ch);
      }
      postfix.push(temp);
    } else if (*ch == '(') {
      string temp(1, *ch);
      helper.push(temp);
    } else if (*ch == ')') {
      while (helper.top() != "(") {
        postfix.push(helper.top());
        helper.pop();
      }
      helper.pop();
    } else if (isalpha(*ch)) {
      cout << "Arithmetic expressions do not allow letters, please try again!"
           << endl;
      result = std::numeric_limits<double>::max();
      return;
    } else {
      string temp;
      temp.push_back(*ch);
      while (!isdigit(*(ch + 1)) && *(ch + 1) != '(' && *(ch + 1) != ')' &&
             *(ch + 1) != ' ' && !isalpha(*(ch + 1))) {
        ch++;
        temp.push_back(*ch);
      }
      while (!helper.empty() && priority(temp) <= priority(helper.top())) {
        postfix.push(helper.top());
        helper.pop();
      }
      helper.push(temp);
    }

    ch++;
  }

  while (!helper.empty()) {
    postfix.push(helper.top());
    helper.pop();
  }

  while (!postfix.empty()) {
    string curStr = postfix.front();

    if (isdigit(curStr[0]) || (curStr[0] == '-' && isdigit(curStr[1]))) {
      nums.push(std::stod(curStr));
    } else {
      double a, b;
      if (!nums.empty()) {
        b = nums.top();
        nums.pop();
      }
      if (!nums.empty()) {
        a = nums.top();
        nums.pop();
      }
      if (curStr == "+")
        nums.push(a + b);
      else if (curStr == "-")
        nums.push(a - b);
      else if (curStr == "*")
        nums.push(a * b);
      else if (curStr == "/" && b != 0)
        nums.push(a / b);
      else if (curStr == "/" && b == 0) {
        cout << "Divided by zero is not allowed!" << endl;
        result = std::numeric_limits<double>::max();
        return;
      } else if (curStr == "**")
        nums.push(pow(a, b));
      else if (curStr == "%")
        nums.push((int)a % (int)b);
      else {
        cout << "There is an invalid operator [" << curStr
             << "], please try again" << endl;
        result = std::numeric_limits<double>::max();
        return;
      }
    }

    postfix.pop();
  }

  if (nums.size() == 1) {
    cout << nums.top() << endl;
    result = nums.top();
  } else {
    cout << "Incorrect expression entered, please try again!" << endl;
    result = std::numeric_limits<double>::max();
    return;
  }
}

void sayBye() {
  cout << endl;
  cout << " ______                               " << endl;
  cout << "< Bye! >                              " << endl;
  cout << " ------                               " << endl;
  cout << "       \\   ^__^                      " << endl;
  cout << "        \\  (oo)\\_______             " << endl;
  cout << "           (__)\\       )\\/\\        " << endl;
  cout << "               ||----w |              " << endl;
  cout << "               ||     ||              " << endl;
  cout << endl;
}
