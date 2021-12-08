#ifndef pokeDex_hpp
#define pokeDex_hpp
#include <vector>
#include <fstream>
#include "pokemon.hpp"

class PokeDex {
public:

    PokeDex();
    PokeDex(std::vector<std::string> inputNames,
            std::vector<std::string> inputHeights,
            std::vector<std::string> inputWeigths,
            std::vector<std::string> inputTypes,
            std::vector< std::vector<std::string> > inputFriendsVectors);
    ~PokeDex();

    Pokemon getPokemonOf(int inputNumber);
    std::vector<Pokemon> getFriendsOf(Pokemon inputPoke);

private:

    std::vector<std::string> names;
    std::vector<std::string> heights;
    std::vector<std::string> weights;
    std::vector<std::string> types;
    std::vector< std::vector<std::string> > friendsVectors;

};

#include "pokeDex.cpp"
#endif
