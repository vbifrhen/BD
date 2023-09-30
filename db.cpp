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
    void Add_fromfile(int id, const Anime &item)
    {
        auto it = data_.find(id);
        if (it == data_.end())
        {
            data_[id] = item;
        }
        else
        {
            std::stringstream ss;
            ss << "Element by this id: " << id << " already exist. In DB will be only first occurrence.";
            std::cerr << ss.str() << std::endl;
        }
    }

    void Add(int id)
    {
        auto it = data_.find(id);
        if (it == data_.end())
        {
            Anime item;
            std::cout << "Write new row:\n";
            std::cin >> item.name >> item.ended >> item.data >>
                item.review;
            data_[id] = item;
        }
        else
        {
            throw std::runtime_error("Element already exist");
        }
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

    void Update(int id)
    {
        auto it = data_.find(id);
        if (it != data_.end())
        {
            Anime item;
            std::cout << "Write updated row:\n";
            std::cin >> item.name >> item.ended >> item.data >>
                item.review;
            data_[id] = item;
        }
        else
        {
            throw std::runtime_error("Element by id doesn't found");
        }
    }

    void Remove(int id)
    {
        auto it = data_.find(id);
        if (it != data_.end()) {
            data_.erase(id);
        }
        else {
            throw std::runtime_error("Element by id doesn't exist");
        }
        
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
            const Anime &item = pair.second;
            file << pair.first << ' '
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
            const Anime &item = pair.second;
            std::cout << pair.first << ' '
                      << item.name << ' '
                      << item.ended << ' '
                      << item.data << ' '
                      << item.review << '\n';
        }
    }
};

void printMenu()
{
    std::cout << " MENU:\n";
    std::cout << "  1.Input DB:\n";
    std::cout << "  2.Output DB:\n";
    std::cout << "  3.Edit data:\n";
    std::cout << "  4.Find with id\n";
    std::cout << "  5.Clear the screen\n";
    std::cout << "  6.End the program\n\n";
}

int main()
{
    DataStorage storage;
    int id;
    Anime item;
    int menu_option = 5;

    while (true)
    {
        printMenu();
        std::cin >> menu_option;
        if (1 <= menu_option && menu_option <= 6)
        {
            switch (menu_option)
            {
            case 1:
            {
                std::cout << "Input DB:\n";
                std::cout << "  1.from file\n";
                std::cout << "  2.from console\n";
                std::cin >> menu_option;
                if (menu_option == 1)
                {
                    std::cout << "Write name of file:\n";
                    std::string name;
                    std::cin >> name;
                    std::fstream file(name, std::fstream::in);
                    if (!file.is_open())
                    {
                        std::cerr << "Unable to open file" << std::endl;
                    }
                    else
                    {
                        std::string line;
                        while (std::getline(file, line))
                        {
                            std::stringstream ss(line);
                            ss >> id >> item.name >> item.ended >> item.data >> item.review;
                            storage.Add_fromfile(id, item);
                        }
                    }
                }
                else if (menu_option == 2)
                {
                    std::cout << "Write number of rows:\n";
                    int count;
                    std::cin >> count;
                    for (int i = 0; i < count; i++)
                    {
                        std::cout << "Write the id:\n";
                        std::cin >> id;
                        try
                        {
                            storage.Add(id);
                        }
                        catch (const std::runtime_error &e)
                        {
                            std::cerr << e.what() << std::endl;
                        }
                    }
                }
                break;
            }
            case 2:
            {
                std::cout << "Output DB:\n";
                std::cout << "  1.into file\n";
                std::cout << "  2.on screen\n";
                std::cin >> menu_option;
                if (menu_option == 1)
                {
                    std::cout << "Write name of file:\n";
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
                break;
            }
            case 3:
            {
                std::cout << "Edit data:\n";
                std::cout << "  1.clear DB\n";
                std::cout << "  2.add row\n";
                std::cout << "  3.delete row\n";
                std::cout << "  4.change row by id\n";
                std::cin >> menu_option;
                if (menu_option == 1)
                {
                    storage.Clear_all();
                }
                else if (menu_option == 2)
                {
                    std::cout << "Write the id:\n";
                    std::cin >> id;
                    try
                    {
                        storage.Add(id);
                    }
                    catch (const std::runtime_error &e)
                    {
                        std::cerr << e.what() << std::endl;
                    }
                }
                else if (menu_option == 3)
                {
                    std::cout << "Write the id:\n";
                    std::cin >> id;
                    try
                    {
                        storage.Remove(id);
                    }
                    catch (const std::runtime_error &e)
                    {
                        std::cerr << e.what() << std::endl;
                    }
                }
                else if (menu_option == 4)
                {
                    std::cout << "Write the id:\n";
                    std::cin >> id;
                    try
                    {
                        storage.Update(id);
                    }
                    catch (const std::runtime_error &e)
                    {
                        std::cerr << e.what() << std::endl;
                    }
                }
                break;
            }
            case 4:
            {
                std::cout << "Write the id:\n";
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
                break;
            }
            case 5:
            {
                system("cls");
                break;
            }
            case 6:
            {
                return 0;
            }
            }
        }
        else
        {
            std::cout << "ERROR! \n\n";
            break;
        }
    }
    return 0;
}
