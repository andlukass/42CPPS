#pragma once

#include <algorithm>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Btc
{
private:
    std::map<std::string, float> _data;

    void parseDataFile(std::string dataPath);
    bool isValidDate(const std::string &dateStr);
    float findClosestDateValue(const std::string &dateStr);

public:
    Btc(std::string dataPath);
    ~Btc();
    Btc &operator=(Btc const &var);
    Btc(Btc const &var);

    void parseInput(std::string inputPath);
    void printDatabase();
};