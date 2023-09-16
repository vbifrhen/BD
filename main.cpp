#include <iostream>
using namespace std;

struct anime {
  int id;
  char imya[20];
  bool ended;
  char data{9};
  int review;
};

int main() {
  int meniu = 8;
  setlocale(LC_ALL, "rus");
  while (1) {
    if (1 <= meniu && meniu <= 9) {
      if (meniu == 1) {
        cout << "Ввод БД:\n";
        cout << "  1.из файла\n";
        cout << "  2.с клавиатуры\n";
      }
      if (meniu == 2) {
        ;
      }
      if (meniu == 3) {
        cout << "Редактирование данных:\n";
        cout << "  1.очистить БД\n";
        cout << "  2.добавить запись\n";
        cout << "  3.удалить запись\n";
      }
      if (meniu == 4) {
        cout << "Вывод БД:\n";
        cout << "  1.в файл\n";
        cout << "  2.на экран\n";
      }
      if (meniu == 5) {
        ;
      }
      if (meniu == 6) {
        ;
      }
      if (meniu == 7) {
        ;
      }
      if (meniu == 8) {
        system("cls");
        cout << " МЕНЮ:\n";
        cout << "  1.Ввод БД:\n";
        cout << "  2.Просмотр всей БД\n";
        cout << "  3.Редактирование данных:\n";
        cout << "  4.Вывод БД:\n";
        cout << "  5.Поиск данных по пробегу\n";
        cout << "  6.Сортировка по году выпуска\n";
        cout << "  7.О разработчике\n";
        cout << "  8.Очистить экран\n";
        cout << "  9.Выход\n\n";
      }
      if (meniu == 9) {
        break;
      }
    } else {
      cout << "ERROR! \n\n";
    }
    cout << "меню: ";
    cin >> meniu;
  }
  system("pause");
  return 0;
}