#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <optional>
#include <cstring>
#include <iostream>

template <class T>
class ArrayList {
private:
    T* data;
    size_t size;
    size_t capcity;
    
    void resize() {
        size_t new_cap = capcity + (capcity >> 1);
        T *new_data = new T[new_cap];
        std::memcpy(new_data, data, size * sizeof(T));
        delete[] data;
        data = new_data;
        capcity = new_cap;
    }

public:
    ArrayList(size_t init_cap=10)
    : size(0), capcity(init_cap) {
        data = new T[capcity];
    }
    
    ~ArrayList() { delete[] data;}
    
    void add(const T& value) {
        if (size >= capcity) {
            resize();
        }
        data[size++] = value;
    }
    
    void remove(const T& value) {
        for (size_t i = 0; i < size; i++) {
            if (data[i] == value) {
                for (size_t j = i; j < size - 1; j++) {
                    data[j] = data[j + 1];
                }
                size--;
                return;
            }
        }
    }
    
    std::optional<T> get(size_t index) const {
        if (index < size) {
            return data[index];
        } else {
            return std::nullopt;
        }
    }
    
    [[nodiscard]] int getSize() const {
        return static_cast<int>(size);
    }
    
    [[nodiscard]] int getCapacity() const {
        return static_cast<int>(capcity);
    }
};
#endif
