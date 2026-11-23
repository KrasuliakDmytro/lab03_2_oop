
#pragma once

#include <iostream>
#include <string>
#include "HardDisk.h"

using namespace std;

class Computer
{
private:
    HardDisk disk;
    char* brand;
    double price;

public:
    // Конструктори
    Computer();
    Computer(const HardDisk& disk, const char* brand, double price);
    Computer(const Computer& other);

    // Оператор присвоєння
    Computer& operator=(const Computer& other);

    // Деструктор
    virtual ~Computer();

    // Методи встановлення
    void SetDisk(const HardDisk& disk);
    void SetBrand(const char* brand);
    void SetPrice(double price);

    // Методи отримання
    HardDisk GetDisk() const;
    const char* GetBrand() const;
    double GetPrice() const;

    // Функція виведення
    virtual void Show() const;

    // Перетворення в рядок
    operator string() const;

    // Операції введення та виведення
    friend istream& operator>>(istream& in, Computer& computer);
    friend ostream& operator<<(ostream& out, const Computer& computer);
};

// Функція отримання і повернення об'єкта базового класу
Computer ProcessComputer(Computer computer);

// Функція демонстрації поліморфізму
void DisplayComputer(const Computer& computer);
