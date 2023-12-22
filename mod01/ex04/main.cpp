
#include <iostream>
#include <fstream>

std::string removeTxtExtension(const std::string& filename){
    size_t last_dot = filename.find_last_of(".");
    if ((int)last_dot != -1 && filename.substr(last_dot) == ".txt")
    {
        return filename.substr(0, last_dot);
    }
    return (filename);
}

std::string myReplace(std::string &line, std::string s1, std::string s2)
{
    size_t found;
    int lastPos = 0;
    std::string result;


    while ((found = line.find(s1, lastPos)) != std::string::npos)
    {
        result.append(line, lastPos, found - lastPos);
        result.append(s2);
        lastPos = found + s1.length();
    }
    result.append(line, lastPos);
    return result;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 0;
    }
    else
    {
        std::string filename = argv[1];
        std::string newFilename = removeTxtExtension(filename) + ".replace.txt";
        std::ifstream inputFile(filename);
        std::ofstream newFile(newFilename);
        
        if (inputFile.is_open() && newFile.is_open())
        {
            std::string oldLine;
            std::string newLine;
            std::string s1 = argv[2];
            std::string s2 = argv[3];
            
            while (std::getline(inputFile, oldLine))
            {
                newLine = myReplace(oldLine, s1, s2);
                newFile << newLine << std::endl;
                newLine.clear();
            }
        }
    }
    return 0;
}