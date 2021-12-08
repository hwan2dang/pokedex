#ifndef pokemon_hpp
#define pokemon_hpp

#include <vector>
#include <iostream>

class Pokemon {
public:
    //- Constructors
    Pokemon();
    Pokemon(std::string name,
            std::string height,
            std::string weight,
            std::string type,
            std::vector<std::string> friends);
    ~Pokemon();

    //- Getters
    std::string getName();
    std::string getHeight();
    std::string getWeight();
    std::string getType();
    std::vector<std::string> getFriends();
    std::string correction1Of(std::string inputInfo);
    std::string correction2Of(std::string inputInfo);
    void info();

private:

    std::string name;
    std::string height;
    std::string weight;
    std::string type;
    std::vector<std::string> friends;
};

#include "pokemon.cpp"
#endif