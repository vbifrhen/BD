#include "bd.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
  DataStorage storage;
  int id;
  anime item;
  int meniu = 8;
  setlocale(LC_ALL, "rus");
  while (1) {
    if (1 <= meniu && meniu <= 9) {
      if (meniu == 1) {
        std::cout << "Ввод БД:\n";
        std::cout << "  1.из файла\n";
        std::cout << "  2.с клавиатуры\n";
        std::cin >> meniu;
        if (meniu == 1) {
          std::cout << "Введите название файла:\n";
          std::string name;
          std::cin >> name;
          std::fstream file(name, std::fstream::in);
          if (!file.is_open()) {
            std::cerr << "Ошибка открытия файла" << std::endl;
          } else {
            std::string line;
            while (std::getline(file, line)) {
              std::stringstream ss(line);
              ss >> id >> item.name >> item.ended >> item.data >> item.review;
              storage.add(id, item);
            }
          }
        }
        if (meniu == 2) {
          std::cout << "Введите количество строк:\n";
          int count;
          std::cin >> count;
          std::cout << "Введите БД построчно:\n";
          for (int i = 0; i < count; i++) {
            std::cin >> id >> item.name >> item.ended >> item.data >>
                     item.review;
              storage.add(id, item);
        }
        }
      }
      else if (meniu == 2) {
        std::cout << "Вывод БД:\n";
        std::cout << "  1.в файл\n";
        std::cout << "  2.на экран\n";
        std::cin >> meniu;
        if (meniu == 1) {
        }
        if (meniu == 2) {
          ;
        }
      }
      else if (meniu == 3) {
        std::cout << "Редактирование данных:\n";
        std::cout << "  1.очистить БД\n";
        std::cout << "  2.добавить запись\n";
        std::cout << "  3.удалить запись\n";
        std::cout << "  4.изменить запись по id\n";
        std::cin >> meniu;
        if (meniu == 1) {
        }
        if (meniu == 2) {
          ;
        }
        if (meniu == 3) {
          std::cout << "Введите id:\n";
            std::cin >> id;
          storage.remove(id);
        }
        if (meniu == 4) {
          std::cout << "Введите id:\n";
            std::cin >> id;
            std::cout << "Введите обновлённую строку:\n";
            std::cin >> item.name >> item.ended >> item.data >>
                     item.review;
            storage.update(id, item);
        }
      }
      
      else if (meniu == 4) { 
        std::cout << "Введите id:\n";
        try {
                item = storage.get(id);
                std::cout << id << item.name << item.ended << item.data <<
                     item.review;
            } catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl;
            }}
      else if (meniu == 5) { ; }
      else if (meniu == 6) { ; }
      else if (meniu == 7) {
        system("cls");
        std::cout << " МЕНЮ:\n";
        std::cout << "  1.Ввод БД:\n";
        std::cout << "  2.Вывод БД:\n";
        std::cout << "  3.Редактирование данных:\n";
        std::cout << "  4.Поиск данных по айди\n";
        std::cout << "  5.Сортировка по году выпуска\n";
        std::cout << "  6.О разработчике\n";
        std::cout << "  7.Очистить экран\n";
        std::cout << "  8.Выход\n\n";
      }
      else if (meniu == 8) { break; }
    } else {
      std::cout << "ERROR! \n\n";
    }
    std::cin >> meniu;
  }
  system("pause");
  return 0;
}