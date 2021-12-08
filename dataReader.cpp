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

//Bug - CS50IDE <- update
/*
bool DataReader::isComment(std::string inputString) {
     for(int i = 0; i < inputString.size() - 1; i++) {
         if(inputString[i] == '/'  && i < inputString.size() - 1) {
             return inputString[i] == inputString[i + 1];
         }
     }
     return false;
}
*/
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
            //------WRong------
            if(i == line.size() - 1) {
                temp += line[i];
            }
            //-----------------
            container.push_back(temp);
            temp =  "";
            i += 2;
        }
        temp += line[i]; //'y'
    }
    friendsVectors.push_back(container);
}

/*
std::string DataReader::subString(std::string str, int start, int end) {
    std::string result = "";
    for(int i = start; i <= end; i++) {
        result += str[i];
    }
    return result;
}
*/

/*
void DataReader::decode(std::vector<std::string> inputVector) {
    std::string str = "";
    str = inputVector[0];

    int index = 0;
    int point = 0;
    std::string tempLine = "";
    while(index < str.size()) {
        std::string spliter1 = subString(str, index, index + 2);
        std::string spliter2 = subString(str, index, index + 1);
        if(spliter1 == " / ") {
            index += 3;
            if(point == 0) {
                names.push_back(tempLine);
            } else if(point == 1) {
                heights.push_back(tempLine);
            } else if(point == 2) {
                weights.push_back(tempLine);
            } else if(point == 3) {
                types.push_back(tempLine);
            }
            tempLine = "";
            point++;
        } else if(spliter2 == ", ") {
            tempLine = "";
            index += 2;
            if(point == 4) {
                friendsVectors[0].push_back(tempLine);
            } else if(point == 5) {
                friendsVectors[1].push_back(tempLine);
            } else if(point == 6) {
                friendsVectors[2].push_back(tempLine);
            } else if(point == 7) {
                friendsVectors[3].push_back(tempLine);
            } else if(point == 8) {
                friendsVectors[4].push_back(tempLine);
            }
            point++;
        } else {
            tempLine += str[index];
            index++;
        }
    }
}
*/
/*
std::vector<std::string> split(std::string inputLine) {
    for(int i = 0; i < inputLine.length(); i++) {
        if(inputLine[i] != '/') {
            std::string line = "";
            while(getline(inputLine, line)) {
                lines.push_back(line);
            }
        }
    }
}
*/


//making condition here
// void DataReader::decode(std::string line) {
//     istringstream split(line);
//     for(int i = 0; i < lines.size(); i++) {
//         std::string line = "";
//         while(getline())
//         while(getline(split, line, '/')) {
//             lines.push_back(line);
//         }
//     }
//     names.push_back(lines[i][j]);
// }