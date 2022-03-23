/*
** EPITECH PROJECT, 2022
** csv.cpp
** File description:
** .
*/

#include "IGraphicsLib.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <iterator>

std::vector<std::string> csv_read_row(std::istream &in, char delimiter)
{
    std::stringstream ss;
    bool inQuotes = false;
    char c;
    std::vector<std::string> row;
    
    while(in.good()) {
        c = in.get();
        if (!inQuotes && c == '"')
            inQuotes=true;
        else if (inQuotes && c == '"') {
            if (in.peek() == '"')
                ss << (char)in.get();
            else
                inQuotes=false;
        } else if (!inQuotes && c == delimiter) {
            row.push_back(ss.str());
            ss.str("");
        } else if (!inQuotes && (c == '\r' || c == '\n')) {
            if (in.peek()=='\n')
                in.get();
            row.push_back(ss.str());
            return row;
        } else
            ss << c;
    }
    return row;
}

std::vector<std::vector<std::string>> csvToTable(const std::string &filepath)
{
    std::vector<std::string> row;
    std::vector<std::vector<std::string>> table;
    std::ifstream myFile(filepath);

    if(!myFile.is_open())
        throw std::runtime_error("Could not open file");
    while (myFile.good()) {
        row = csv_read_row(myFile, ',');
        table.push_back(row);
    }
    myFile.close();
    return table;
}

// int main (int argc, char** argv)
// {
//     int num;
//     std::vector<std::vector<std::string>> table = csvToTable(argv[1]);

//     //double loop to acces the data AS INTS
//     for (unsigned int i = 0; i < table.size(); i++) {
//         for (unsigned int j = 0; j < table[0].size(); j++) {
//             num = atoi(table[i][j].c_str()); 
//             std::cout << table[i][j] << "\t";
//         }
//         std::cout << std::endl;
//     }
//     return 0;
// }
