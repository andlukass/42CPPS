#include <BitcoinExchange.hpp>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Btc::isValidDate(const std::string& dateStr) {
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-') {
        return false;
    }

    int year, month, day;
    std::istringstream iss(dateStr);
    char dash1, dash2;
    iss >> year >> dash1 >> month >> dash2 >> day;

    if (iss.fail() || dash1 != '-' || dash2 != '-') {
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }

    if (day < 1) {
        return false;
    }

    int maxDays;
    switch (month) {
        case 2:
            maxDays = isLeapYear(year) ? 29 : 28;
            break;
        case 4: case 6: case 9: case 11:
            maxDays = 30;
            break;
        default:
            maxDays = 31;
            break;
    }

    if (day > maxDays) {
        return false;
    }

    if (year < 1900 || year > 2100) {
        return false;
    }

    return true;
}

Btc::Btc(std::string dataPath) {
	this->parseDataFile(dataPath);
}

Btc::~Btc() {
}

Btc& Btc::operator=(Btc const &var) {
    if (this == &var)
        return *this;
    this->_data.clear();
    this->_data = var._data;
    return *this;
}

Btc::Btc(Btc const &var) {
    this->_data.clear();
    this->_data = var._data;
}

void Btc::parseDataFile(std::string dataPath) {
    std::ifstream file(dataPath);
    std::string line;
    int lineCount = 0;
    if (!file.is_open()) {
        throw std::runtime_error("Could not open data file");
    }
    while (std::getline(file, line)) {
        if (lineCount == 0 || line.empty()) {
            lineCount++;
            continue;
        }
        std::stringstream ss(line);
        std::string date;
        float value;
        std::getline(ss, date, ',');
        if (!this->isValidDate(date)) {
            throw std::runtime_error("Invalid date among the data file");
        }
        ss >> value;
        if (ss.fail()) {
            throw std::runtime_error("Invalid value among the data file");
        }
        if (value < 0) {
            throw std::runtime_error("Invalid negative value among the data file");
        }
        this->_data[date] = value;
        lineCount++;
    }
    file.close();
    if (this->_data.empty()) {
        throw std::runtime_error("No data found in the file");
    }
}

float Btc::findClosestDateValue(const std::string& dateStr) {
    std::map<std::string, float>::iterator it = this->_data.lower_bound(dateStr);
    return it->second;
}

void Btc::parseInput(std::string inputPath) {
    std::ifstream file(inputPath);
    std::string line;
    int lineCount = 0;
     if (!file.is_open()) {
        throw std::runtime_error("Could not open input file");
    }
    while (std::getline(file, line)) {
         if (lineCount == 0 || line.empty()) {
            lineCount++;
            continue;
        }

        std::string modifiedLine = line;
        std::string::size_type pos = modifiedLine.find(" | ");
        if (pos != std::string::npos) {
            modifiedLine.replace(pos, 3, "|");
        }

        std::stringstream ss(modifiedLine);
        std::string date;
        float value;
        std::getline(ss, date, '|');
        ss >> value;
        if (ss.fail() || !this->isValidDate(date)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        float closestValue = this->findClosestDateValue(date);
        std::cout << date << " => " << value << " = " << closestValue * value << std::endl;
        lineCount++;
    }
}

void Btc::printDatabase() {
    for (std::map<std::string, float>::iterator it = this->_data.begin(); it != this->_data.end(); it++) {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}