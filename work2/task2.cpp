#include <iostream>
#include <vector>

int main() {
  int numRows;
  std::cout << "Введите количество строк: ";
  std::cin >> numRows;

  // Используем вектор векторов для хранения строк
  std::vector<std::vector<int>> array(numRows);

  // Запрашиваем строки и их элементы
  for (int i = 0; i < numRows; ++i) {
    int numElements;
    std::cout << "Введите количество элементов в строке " << i + 1 << ": ";
    std::cin >> numElements;

    // Запрашиваем элементы для текущей строки
    std::cout << "Введите элементы для строки " << i + 1 << ": ";
    for (int j = 0; j < numElements; ++j) {
      int element;
      std::cin >> element;
      array[i].push_back(element);
    }
  }

  // Печатаем массив построчно
  std::cout << "Элементы массива:" << std::endl;
  for (int i = 0; i < numRows; ++i) {
    std::cout << "Строка " << i + 1 << ": ";
    for (int j = 0; j < array[i].size(); ++j) {
      std::cout << array[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}