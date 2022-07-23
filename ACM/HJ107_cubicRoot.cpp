#include <iostream>
#include <cmath>
#include <iomanip>
 
int main(int argc, char** argv) {
      double input = 0.0;
      std::cin >> input;
      double sign = input >= 0 ? 1 : -1;
      input = input * sign;
      double left = 0;
      double right = input > 1.0 ? input : 1.0;
      double result = input;
      // 二分法
      while (right - left > 1.0e-2) {
        const double middle = (left + right) * 0.5;
        result = middle;
        if (middle * middle * middle < input) {
          left = middle;
        } else {
          right = middle;
        }
      }
      result *= sign;
      std::cout << std::fixed << std::setprecision(1) << result;
}