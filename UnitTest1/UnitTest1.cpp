#include "pch.h"
#include "CppUnitTest.h"
#include "../lr3_2/Computer.h"
#include "../lr3_2/Computer.cpp"
#include "../lr3_2/HardDisk.h"
#include "../lr3_2/HardDisk.cpp"
#include "../lr3_2/MonitorComputer.h"
#include "../lr3_2/MonitorComputer.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        // 1. Перевірка конструктора HardDisk
        TEST_METHOD(TestHardDiskConstructor)
        {
            HardDisk disk(500);

            Assert::AreEqual(500, disk.GetCapacity());
        }

        // 2. Перевірка зміни обсягу диска
        TEST_METHOD(TestHardDiskSetter)
        {
            HardDisk disk(500);

            disk.SetCapacity(1000);

            Assert::AreEqual(1000, disk.GetCapacity());
        }

        // 3. Перевірка перетворення HardDisk у string
        TEST_METHOD(TestHardDiskString)
        {
            HardDisk disk(750);

            string result = static_cast<string>(disk);

            Assert::IsTrue(result.find("750") != string::npos);
        }


        // 4. Перевірка конструктора Computer
        TEST_METHOD(TestComputerConstructor)
        {
            HardDisk disk(1000);
            Computer computer(disk, "Lenovo", 25000);

            Assert::AreEqual(string("Lenovo"), string(computer.GetBrand()));
            Assert::AreEqual(25000.0, computer.GetPrice());
            Assert::AreEqual(1000, computer.GetDisk().GetCapacity());
        }

        // 5. Перевірка сетера ціни
        TEST_METHOD(TestComputerSetPrice)
        {
            Computer computer;

            computer.SetPrice(30000);

            Assert::AreEqual(30000.0, computer.GetPrice());
        }

        // 6. Перевірка оператора присвоєння
        TEST_METHOD(TestComputerAssignment)
        {
            HardDisk disk(2000);
            Computer computer1(disk, "HP", 35000);
            Computer computer2;

            computer2 = computer1;

            Assert::AreEqual(string("HP"), string(computer2.GetBrand()));
            Assert::AreEqual(35000.0, computer2.GetPrice());
            Assert::AreEqual(2000, computer2.GetDisk().GetCapacity());
        }


        // 7. Перевірка конструктора MonitorComputer
        TEST_METHOD(TestMonitorComputerConstructor)
        {
            HardDisk disk(1500);
            MonitorComputer computer(disk, "Acer", 40000, 27.0);

            Assert::AreEqual(string("Acer"), string(computer.GetBrand()));
            Assert::AreEqual(40000.0, computer.GetPrice());
            Assert::AreEqual(1500, computer.GetDisk().GetCapacity());
            Assert::AreEqual(27.0, computer.GetDiagonal());
        }

        // 8. Перевірка зміни діагоналі монітора
        TEST_METHOD(TestMonitorComputerSetDiagonal)
        {
            MonitorComputer computer;

            computer.SetDiagonal(32.0);

            Assert::AreEqual(32.0, computer.GetDiagonal());
        }
	};
}
