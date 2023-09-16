#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct anime {
  int id;
  char name[20];
  int ended;
  char data[10];
  int review;
};

int main() {
  vector<anime> spisok;
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
              sscanf(line, "%d %19s %d %8s %d", &id, name, &ended, data,
                     &review);
            }
          }
        }
        if (meniu == 2) {
          std::cout << "Введите количество строк:\n";

          std::cout << "Введите БД построчно:\n";
          for (int i = 0; i < count; i++) {
            scanf("%d %19s %d %8s %d", &id, name, &ended, data, &review);
          }
        }
      }
      elif (meniu == 2) { ; }
      elif (meniu == 3) {
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
        }
        if (meniu == 4) {
        }
      }
      elif (meniu == 4) {
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
      elif (meniu == 5) { ; }
      elif (meniu == 6) { ; }
      elif (meniu == 7) { ; }
      elif (meniu == 8) {
        system("cls");
        std::cout << " МЕНЮ:\n";
        std::cout << "  1.Ввод БД:\n";
        std::cout << "  2.Просмотр всей БД\n";
        std::cout << "  3.Редактирование данных:\n";
        std::cout << "  4.Вывод БД:\n";
        std::cout << "  5.Поиск данных по пробегу\n";
        std::cout << "  6.Сортировка по году выпуска\n";
        std::cout << "  7.О разработчике\n";
        std::cout << "  8.Очистить экран\n";
        std::cout << "  9.Выход\n\n";
      }
      elif (meniu == 9) { break; }
    } else {
      cout << "ERROR! \n\n";
    }
    cin >> meniu;
  }
  system("pause");
  return 0;
}