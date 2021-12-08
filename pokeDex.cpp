#include "pokeDex.hpp"
#include <vector>
#include <iostream>

PokeDex::PokeDex(){

}

PokeDex::~PokeDex(){

}

PokeDex::PokeDex(std::vector<std::string> inputNames,
                 std::vector<std::string> inputHeights,
                 std::vector<std::string> inputWeights,
                 std::vector<std::string> inputTypes,
                 std::vector< std::vector<std::string> > inputFriendsVectors) {
    names = inputNames;
    heights = inputHeights;
    weights = inputWeights;
    types = inputTypes;
    friendsVectors = inputFriendsVectors;
}

Pokemon PokeDex::getPokemonOf(int inputNumber) {
    Pokemon tempPokemon(names[inputNumber],
                        heights[inputNumber],
                        weights[inputNumber],
                        types[inputNumber],
                        friendsVectors[inputNumber]);

    return tempPokemon;
}
//seauch friend's name of number
std::vector<Pokemon> PokeDex::getFriendsOf(Pokemon inputPoke) {
    std::vector<Pokemon> pokeFriends;
    std::vector<std::string> friendNames = inputPoke.getFriends();

    for(int i = 0; i < friendNames.size(); i++) {
        for(int j = 0; j < names.size(); j++) {
            if(friendNames[i] == names[j]) {
                Pokemon pokemonFriends(names[j],
                                       heights[j],
                                       weights[j],
                                       types[j],
                                       friendsVectors[j]);
                pokeFriends.push_back(pokemonFriends);
            }
        }
    }

    return pokeFriends;
}