
#pragma once

#include <iostream>
#include <string>

using namespace std;

// Функція повідомлення про помилку
void Error(const char* message);

class HardDisk
{
private:
    int capacity;

public:
    // Конструктори
    HardDisk();
    HardDisk(int capacity);
    HardDisk(const HardDisk& other);

    // Методи встановлення та отримання
    void SetCapacity(int capacity);
    int GetCapacity() const;

    // Перетворення в рядок
    operator string() const;

    // Операції введення та виведення
    friend istream& operator>>(istream& in, HardDisk& disk);
    friend ostream& operator<<(ostream& out, const HardDisk& disk);
};
