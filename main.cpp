#include <iostream>
#include <vector>
#include "dataReader.hpp"
#include "pokeDex.hpp"
#include "pokemon.hpp"

using namespace std;

void displayVector(vector<string> v) {
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

int main() {
	DataReader dataReader("pokemons.txt");

	PokeDex myDex(dataReader.getNames(),
	               dataReader.getHeights(),
	               dataReader.getWeights(),
	               dataReader.getTypes(),
	               dataReader.getFriends());
	Pokemon pikachu = myDex.getPokemonOf(1);

 	pikachu.info();

 	vector<Pokemon> friends = myDex.getFriendsOf(pikachu);
 	for(int i = 0; i < friends.size(); i++) {
 		friends[i].info();
 	}
    return 0;
}