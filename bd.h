#include <map>
#include <stdexcept>

struct anime {
  char name[20];
  int ended;
  char data[10];
  int review;
};

class DataStorage {
private:
    std::map<int, anime> data;

public:
    void add(int id, const anime& item) {
        data[id] = item;
    }

    anime& get(int id) {
        auto it = data.find(id);
        if (it == data.end()) {
            throw std::runtime_error("Element not found");
        }
        return it->second;
    }

    void update(int id, const anime& item) {
        data[id] = item;
    }

    void remove(int id) {
        data.erase(id);
    }
};
