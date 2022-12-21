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

void init_staf(staff&, std::string&);
void data_write(staff&);
void data_read();

int main()
{
    int control;
    std::cout << "Choose the operation: " << std::endl;
    std::cout << "Press 1 to load data, press 2 to read the statement." << std::endl;
    std::cin >> control;
    std::cin.ignore();
    if (control != 2 && control != 1)
    {
        std::cerr << "Error! Wrong command!" << std::endl;
    }
    else if (control == 1)
    {
        std::string buffer;
        std::cout << "Enter employer's name, date and summ of transaction: " << std::endl;
        std::getline(std::cin, buffer);
        staff load;
        //std::cout << load.name << " " << load.paymentDate << " " << load.sum << std::endl;
        init_staf(load, buffer);
        //std::cout << load.name << " " << load.paymentDate << " " << load.sum << std::endl;
        data_write(load);
    }
    else if (control == 2)
    {
        data_read();
    }
}

void init_staf(staff& load, std::string& buffer)
{
    
    std::stringstream temp_stream(buffer);
    temp_stream >> load.name >> load.paymentDate >> load.sum;
}

void data_write(staff& load)
{
    std::ofstream out("statement.bin", std::ios::binary | std::ios::app);
    if (out.is_open())
    {
        std::cout << load.name << " " << load.paymentDate << " " << load.sum << std::endl;
        int len = load.name.length();
        out.write((char*)&len, sizeof(len));
        out.write(load.name.c_str(), len);
        len = load.paymentDate.length();
        out.write((char*)&len, sizeof(len));
        out.write(load.paymentDate.c_str(), len);
        out.write((char*)&load.sum, sizeof(load.sum));
        
        out.close();
    }
    else
    {
        std::cerr << "Error! Library file does not exist!" << std::endl;
    }
}

void data_read()
{
    
    std::ifstream in("statement.bin", std::ios::binary);
    if (in.is_open())
    {
        staff show;
        while (!in.eof())
        {
            
            std::cout << show.name << " " << show.paymentDate << " " << show.sum << std::endl;
            int len;
            in.read((char*)&len, sizeof(len));
            show.name.resize(len);
            in.read((char*)show.name.c_str(), len);
            in.read((char*)&len, sizeof(len));
            show.paymentDate.resize(len);
            in.read((char*)show.paymentDate.c_str(), len);
            in.read((char*)&show.sum, sizeof(show.sum));
            std::cout << show.name << " " << show.paymentDate << " " << show.sum << std::endl;

        }
        in.close();
    }
    else
    {
        std::cerr << "Error! Statement not found!" << std::endl;
    }
    
}
