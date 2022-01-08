#include "dataReader.hpp"
#include <fstream>
#include <vector>
#include <iostream>

DataReader::DataReader() {

}

DataReader::~DataReader() {

}

DataReader::DataReader(const std::string& fileName) {
    readFile(fileName);
}

std::vector<std::string> DataReader::getNames() {
    return names;
}

std::vector<std::string> DataReader::getHeights() {
    return heights;
}

std::vector<std::string> DataReader::getWeights() {
    return weights;
}

std::vector<std::string> DataReader::getTypes() {
    return types;
}

std::vector< std::vector<std::string> > DataReader::getFriends() {
    return friendsVectors;
}
                                          
void DataReader::readFile(std::string inputFile) {
    std::string line = "";
    std::ifstream file(inputFile);
    if(file.is_open()) {
        while(getline(file, line)) {
            if(line.size() > 1 && line[0] != '/' && line[1] != '/'){
                separateCategories(line);
            }
        }
        file.close();
    }
}

void DataReader::separateCategories(std::string& line) {
    std::string temp = "";
    int index = 0;

    filterName(line, index);
    filterHeight(line, index);
    filterWeight(line, index);
    filterType(line, index);
    filterFriend(line, index);
}

void DataReader::filterName(std::string& line, int& index) {
    std::string temp = "";
    for(int i = 0; i < line.size(); i++) {
        if(line[i] != '/' && line[i] != ' ') {
            temp += line[i];
        }
        if(line[i] == '/') {
            names.push_back(temp);
            index = i;
            break;
        }
    }
}

void DataReader::filterHeight(std::string& line, int& index) {
    std::string temp = "";
    for(int i = index + 2; i < line.size(); i++) {
        if(line[i] != '/' && line[i] != ' ') {
            temp += line[i];
        }

        if(line[i] == '/') {
            heights.push_back(temp);
            index = i;
            break;
        }
    }
}

void DataReader::filterWeight(std::string& line, int& index) {
    std::string temp = "";
    for(int i = index + 2; i < line.size(); i++) {
        if(line[i] == ' ' && line[i + 1] == '/') {
            weights.push_back(temp);
            index = i;
            break;
        }
        if(line[i] != '/') {
            temp += line[i];
        }
    }
}

void DataReader::filterType(std::string& line, int& index) {
    std::string temp = "";
    for(int i = index + 2; i < line.size(); i++) {
        if(line[i] != '/' && line[i] != ' ') {
            temp += line[i];
        }
        if(line[i] == '/') {
            types.push_back(temp);
            index = i;
            break;
        }
    }
}

void DataReader::filterFriend(std::string& line, int& index) {
    std::vector<std::string> container;
    std::string temp = "";
    for(int i = index + 2; i < line.size(); i++) {
        if(line[i] == ',' || i == line.size() - 1) {
            if(i == line.size() - 1) {
                temp += line[i];
            }
            container.push_back(temp);
            temp =  "";
            i += 2;
        }
        temp += line[i];
    }
    friendsVectors.push_back(container);
}

