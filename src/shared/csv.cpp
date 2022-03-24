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

std::vector<std::string> csvToVector(const std::string &filepath)
{
    std::vector<std::string> row;
    std::vector<std::string> output;
    std::ifstream myFile(filepath);

    if(!myFile.is_open())
        throw std::runtime_error("Could not open file");
    while (myFile.good()) {
        row = csv_read_row(myFile, ',');
        output.insert(output.end(), row.begin(), row.end());
    }
    myFile.close();
    return output;
}