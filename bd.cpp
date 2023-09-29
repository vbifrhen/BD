#include <map>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Anime
{
    char name[20];
    int ended;
    char data[10];
    int review;
};

class DataStorage
{
private:
    std::map<int, Anime> data_;

public:
    void Add(int id, const Anime &item)
    {
        data_[id] = item;
    }

    Anime &Get(int id)
    {
        auto it = data_.find(id);
        if (it == data_.end())
        {
            throw std::runtime_error("Element not found");
        }
        return it->second;
    }

    void Update(int id, const Anime &item)
    {
        data_[id] = item;
    }

    void Remove(int id)
    {
        data_.erase(id);
    }

    void Clear_all()
    {
        data_.clear();
    }

    void WriteToFile(const std::string &filename)
    {
        std::ofstream file(filename, std::ios::out);
        if (!file.is_open())
        {
            throw std::runtime_error("Unable to open file");
        }

        for (const auto &pair : data_)
        {
            const int id = pair.first;
            const Anime &item = pair.second;
            file << id << pair.first << ' '
                 << item.name << ' '
                 << item.ended << ' '
                 << item.data << ' '
                 << item.review << '\n';
        }

        file.close();
    }

    void Print()
    {
        for (const auto &pair : data_)
        {
            const int id = pair.first;
            const Anime &item = pair.second;
            std::cout << id << ' '
                      << item.name << ' '
                      << item.ended << ' '
                      << item.data << ' '
                      << item.review << '\n';
        }
    }
};

void printMenu() {
    std::cout << " МЕНЮ:\n";
    std::cout << "  1.Ввод БД:\n";
    std::cout << "  2.Вывод БД:\n";
    std::cout << "  3.Редактирование данных:\n";
    std::cout << "  4.Поиск данных по айди\n";
    std::cout << "  5.Очистить экран\n";
    std::cout << "  6.Выход(полное окончание)\n\n";
}


int main()
{
    DataStorage storage;
    int id;
    Anime item;
    int menu_option = 8;

    system("cls");
    printMenu();

    while (true)
    {
        if (1 <= menu_option && menu_option <= 9)
        {
            switch (menu_option)
            {
            case 1:
            {
                std::cout << "Ввод БД:\n";
                std::cout << "  1.из файла\n";
                std::cout << "  2.с клавиатуры\n";
                std::cin >> menu_option;
                if (menu_option == 1)
                {
                    std::cout << "Введите название файла:\n";
                    std::string name;
                    std::cin >> name;
                    std::fstream file(name, std::fstream::in);
                    if (!file.is_open())
                    {
                        std::cerr << "Ошибка открытия файла" << std::endl;
                    }
                    else
                    {
                        std::string line;
                        while (std::getline(file, line))
                        {
                            std::stringstream ss(line);
                            ss >> id >> item.name >> item.ended >> item.data >> item.review;
                            storage.Add(id, item);
                        }
                    }
                }
                if (menu_option == 2)
                {
                    std::cout << "Введите количество строк:\n";
                    int count;
                    std::cin >> count;
                    std::cout << "Введите БД построчно:\n";
                    for (int i = 0; i < count; i++)
                    {
                        std::cin >> id >> item.name >> item.ended >> item.data >>
                            item.review;
                        storage.Add(id, item);
                    }
                }
                printMenu();
                break;
            }
            case 2:
            {
                std::cout << "Вывод БД:\n";
                std::cout << "  1.в файл\n";
                std::cout << "  2.на экран\n";
                std::cin >> menu_option;
                if (menu_option == 1)
                {
                    std::cout << "Введите название файла:\n";
                    std::string name;
                    std::cin >> name;
                    try
                    {
                        storage.WriteToFile(name);
                    }
                    catch (const std::runtime_error &e)
                    {
                        std::cerr << e.what() << std::endl;
                    }
                }
                if (menu_option == 2)
                {
                    storage.Print();
                }
                printMenu();
                break;
            }
            case 3:
            {
                std::cout << "Редактирование данных:\n";
                std::cout << "  1.очистить БД\n";
                std::cout << "  2.добавить запись\n";
                std::cout << "  3.удалить запись\n";
                std::cout << "  4.изменить запись по id\n";
                std::cin >> menu_option;
                if (menu_option == 1)
                {
                    storage.Clear_all();
                }
                if (menu_option == 2)
                {
                    std::cin >> id >> item.name >> item.ended >> item.data >>
                        item.review;
                    storage.Add(id, item);
                }
                if (menu_option == 3)
                {
                    std::cout << "Введите id:\n";
                    std::cin >> id;
                    storage.Remove(id);
                }
                if (menu_option == 4)
                {
                    std::cout << "Введите id:\n";
                    std::cin >> id;
                    std::cout << "Введите обновлённую строку:\n";
                    std::cin >> item.name >> item.ended >> item.data >>
                        item.review;
                    storage.Update(id, item);
                }
                printMenu();
                break;
            }
            case 4:
            {
                std::cout << "Введите id:\n";
                std::cin >> id;
                try
                {
                    item = storage.Get(id);
                    std::cout << id << item.name << item.ended << item.data << item.review;
                }
                catch (const std::runtime_error &e)
                {
                    std::cerr << e.what() << std::endl;
                }
                printMenu();
                break;
            }
            case 5:
            {
                system("cls");
                printMenu();
                break;
            }
            case 6:
            {
                return 0;
            }
            default:
            {
                std::cout << "ERROR! \n\n";
                break;
            }
            }
        }
        else
        {
            std::cout << "ERROR! \n\n";
        }
        std::cin >> menu_option;
    }
    return 0;
}
