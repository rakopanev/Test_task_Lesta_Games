#include <iostream>
#include "../../src/second/circular_buffer.h"

// Функция main() инициализирует два экземпляра класса CircularBuffer0 и CircularBuffer1, добавляет в них значения 1, 2, 3 и извлекает их с помощью методов push() и pop().
// Затем проверяет, что буферы не пусты с помощью метода isEmpty() и выводит соответствующее сообщение в консоль.

int main()
{
      CircularBuffer0<int> circular_buffer_0;
      circular_buffer_0.push(1);
      circular_buffer_0.push(2);
      circular_buffer_0.push(3);
      std::cout << circular_buffer_0.pop() << std::endl;
      std::cout << circular_buffer_0.pop() << std::endl;
      if (!circular_buffer_0.isEmpty())
      {
            std::cout << "Buffer 'circular_buffer_0' is not empty!" << std::endl;
      }

      CircularBuffer1<int> circular_buffer_1(10);
      circular_buffer_1.push(1);
      circular_buffer_1.push(2);
      circular_buffer_1.push(3);
      std::cout << circular_buffer_1.pop() << std::endl;
      std::cout << circular_buffer_1.pop() << std::endl;
      if (!circular_buffer_1.isEmpty())
      {
            std::cout << "Buffer 'circular_buffer_1' is not empty!" << std::endl;
      }

      CircularBuffer0<int> circular_buffer_2;
      for(int i = 0; i < circular_buffer_2.size(); i++)
      {
            circular_buffer_2.push(i);
      }
      if (circular_buffer_2.isFull())
      {
            std::cout << "Buffer 'circular_buffer_2' is full!" << std::endl;
      }

      CircularBuffer1<int> circular_buffer_3(10);
      for(int i = 0; i < circular_buffer_3.size(); i++)
      {
            circular_buffer_3.push(i);
      }
      if (circular_buffer_3.isFull())
      {
            std::cout << "Buffer 'circular_buffer_3' is full!" << std::endl;
      }
      
      return 0;
}