#ifndef dataReader_hpp
#define dataReader_hpp
#include <vector>
#include <string>
#include <fstream>

class DataReader {
public:
    DataReader();
    DataReader(const std::string& fileName);
    ~DataReader();
    std::vector<std::string> getNames();
    std::vector<std::string> getHeights();
    std::vector<std::string> getWeights();
    std::vector<std::string> getTypes();
    std::vector< std::vector<std::string> > getFriends();

private:
    std::vector<std::string> names;
    std::vector<std::string> heights;
    std::vector<std::string> weights;
    std::vector<std::string> types;
    std::vector< std::vector<std::string> > friendsVectors;

    void readFile(std::string inputFile);
    
    void separateCategories(std::string& line);
    void filterName(std::string& line, int& index);
    void filterHeight(std::string& line, int& index);
    void filterWeight(std::string& line, int& index);
    void filterType(std::string& line, int& index);
    void filterFriend(std::string& line, int& index);

};


#include "dataReader.cpp"
#endif