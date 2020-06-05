#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Database.h"

void DB::addProduct(std::string Name, float Price, bool Premium, int Type) {
    db.push_back(Product());
    db[db.size() - 1].setID(db.size());
    db[db.size() - 1].setName(Name);
    db[db.size() - 1].setPrice(Price);
    db[db.size() - 1].setPremium(Premium);
    db[db.size() - 1].setType(Type);
}
void DB::showOne(int N) const {
    if (N < 0 || size_t(N) > db.size()) std::cout << "Wrong ID\n";
    else {
        std::cout << std::setw(checkSize()) << db[N].getID() << "|" 
        << std::setw(getTheLongest()) << db[N].getName() << "|" 
        << std::setw(10) << db[N].getPrice() << "|" 
        << std::setw(7) << db[N].getPremium() << "|" 
        << std::setw(4) << db[N].getType() << "|\n";
    }
}
int DB::checkSize() const {
    if (db.size() < 100) return 2;
    else return std::to_string(db.size()).size();
}
void DB::displayHeader() const {
    std::cout << std::setw(std::to_string(getSize()).size()) << "ID"<< "|" 
    << std::setw(getTheLongest()) << "Name" << "|" 
    << std::setw(10) << "Price" << "|Premium|Type|\n";
}
int DB::getSize() const {
    return db.size();
}
void DB::deleteProduct(int N) {
    --N;
    db.erase(db.begin() + N);
}
void DB::saveOne(const std::string &fileName, int N) const {
    std::ofstream sv(fileName, std::ios::app);
    if (sv) sv << db[N].getName() << s << db[N].getPrice() << "\n";
    else std::cout << "FILE ERROR\n";
    sv.close();
}
void DB::saveAll(const std::string &fileName) {
    std::ofstream sv(fileName, std::ios::app);
    if (sv) {
        for (size_t i = 0; i < db.size(); ++i) {
            sv << endeCode(db[i].getName(), true) << s 
            << endeCode(std::to_string(db[i].getPrice()), true) << s 
            << endeCode(std::to_string(db[i].getPremium()), true) << s 
            << endeCode(std::to_string(db[i].getType()), true) << "\n";
        }
    } else std::cout << "FILE ERROR\n";
    sv.close();
}
void DB::Upload(const std::string &fileName) {
    std::string Name;
    float Price;
    bool Premium;
    int Type;
    std::fstream sv;
    sv.open(fileName);
    if (sv) {
        std::string line;
        std::string tempo;
        int c = 0;
        getline(sv, line);
        do {
            int pom;
            c = 0;
            do {
                pom = line.find(s);
                tempo.append(line, 0, pom);
                line.erase(0, pom + 1);
                switch (c) {
                    case 0: Name = endeCode(tempo, false); break;
                    case 1: Price = std::stof(endeCode(tempo, false)); break;
                    case 2: pom = std::stoi(endeCode(tempo, false)); if (pom == 0) Premium = false; else Premium = true; break;
                    case 3: Type = std::stoi(endeCode(tempo, false)); break;
                }
                tempo.clear();
                ++c;
            } while (c < 4);
            addProduct(Name, Price, Premium, Type);
            getline(sv, line);
        } while (line != "");
        sv.close();
    } else std::cout << "FILE ERROR\n";
}
int DB::getTheLongest() const{
    uint max = db[0].getName().size();
    for (size_t i = 1; i < db.size(); ++i) {
        if (db[i].getName().size() > max)
            max = db[i].getName().size();
    }
    return max;       
}
std::string DB::endeCode(std::string Data, bool way) {
    std::string output;
    uint max;
    max = Data.size();
    output.resize(max);
    for (uint i = 0; i < max; ++i) {
        if (way == true) {
            if (i != Data.find(".")) output[i] = (Data[i] + 13) % 256;
            else output[i] = Data[i];
        }
        else {
            if (i != Data.find(".")) output[i] = (Data[i] - 13) % 256;
            else output[i] = Data[i];
        }
    }
    return output;
}