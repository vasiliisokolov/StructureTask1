#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct staff
{
    std::string name;
    std::string paymentDate;
    int sum = 0;
};
void data_write();
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
    }
    else if (control == 2)
    {

    }
}

void data_write()
{
}

void data_read()
{
}
