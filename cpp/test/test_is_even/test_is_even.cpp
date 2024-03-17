#include <iostream>
#include "../../src/first/is_even.h"

// В функции main() пользователь вводит целое число, после чего программа определяет его четность с помощью функций isEven0() и isEven1() и выводит соответствующее сообщение.

int main()
{
      int value;
      std::cout << "Enter a value: ";
      std::cin >> value;

      if (isEven0(value))
      {
            std::cout << value << " is even." << std::endl;
      }
      else
      {
            std::cout << value << " is odd." << std::endl;
      }

      if (isEven1(value))
      {
            std::cout << value << " is even." << std::endl;
      }
      else
      {
            std::cout << value << " is odd." << std::endl;
      }

      return 0;
}