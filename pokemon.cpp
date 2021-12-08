#include "pokemon.hpp"
#include <vector>
#include <iostream>
Pokemon::Pokemon() {

}

Pokemon::Pokemon(std::string name,
                 std::string height,
                 std::string weight,
                 std::string type,
                 std::vector<std::string> friends) {
    this -> name = name;
    this -> height = height;
    this -> weight = weight;
    this -> type = type;
    this -> friends = friends;
}

Pokemon::~Pokemon() {

}

std::string Pokemon::getName() {
    return name;
}

std::string Pokemon::getHeight() {
    return height;
}

std::string Pokemon::getWeight() {
    return weight;
}

std::string Pokemon::getType() {
    return type;
}

std::vector<std::string> Pokemon::getFriends() {
    return friends;
}

std::string Pokemon::correction1Of(std::string inputInfo) {
    int len = 9 - inputInfo.size();
    std::string total = "";
    for(int i = 0; i < len; i++) {
        total += " ";
    }
    return total;
}

std::string Pokemon::correction2Of(std::string inputInfo) {
    int len = 13 - inputInfo.size();
    std::string total = "";
    for(int i = 0; i < len; i++) {
        total += "-";
    }
    return total;
}

void Pokemon::info() {
    std::cout << "---------"<< name << correction2Of(name) << std::endl;
    std::cout << "| Height  : " << height << correction1Of(height) << " |" << std::endl;
    std::cout << "| Weight  : " << weight << correction1Of(weight) << " |" << std::endl;
    std::cout << "| Type    : " << type << correction1Of(type) << " |" << std::endl;
    std::cout << "| Friends : " << friends.size() << correction1Of("1") << " |" << std::endl;
    std::cout << "----------------------"<< std::endl;
}