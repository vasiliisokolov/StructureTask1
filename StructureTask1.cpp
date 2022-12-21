#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct staff
{
    std::string name = "unknown";
    std::string paymentDate = "12.12.12";
    int sum = 0;
};

void data_write(staff&);
void data_read();

int main()
{
    int control;
    std::cout << "Choose the operation: " << std::endl;
    std::cout << "Press 1 to load data, press 2 to read the statement." << std::endl;
    std::cin >> control;
    if (control != 2 && control != 1)
    {
        std::cerr << "Error! Wrong command!" << std::endl;
    }
    else if (control == 1)
    {
        std::cin.ignore();
        std::string buffer;
        staff load;
        std::cout << "Enter employer's name, date and summ of transaction: " << std::endl;
        std::getline(std::cin, buffer);
        std::stringstream temp_stream(buffer);
        temp_stream >> load.name >> load.paymentDate >> load.sum;
        std::cout << load.name;
        data_write(load);
    }
    else if (control == 2)
    {
        data_read();
    }
}

void data_write(staff& load)
{
    std::ofstream out("statemen.bin", std::ios::binary | std::ios::app);
    if (out.is_open())
    {
        int len = load.name.length();
        out.write((char*)len, sizeof(len));
        out.write(load.name.c_str(), sizeof(len));
        len = load.paymentDate.length();
        out.write((char*)len, sizeof(len));
        out.write(load.paymentDate.c_str(), sizeof(len));
        out.write((char*)load.sum, sizeof(load.sum));
        out << std::endl;
        out.close();
    }
    else
    {
        std::cerr << "Error! Library file does not exist!" << std::endl;
    }
}

void data_read()
{
    std::ifstream in("statement.bin", std::ios::binary | std::ios::in)
}
