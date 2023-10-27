#include "Replace.hpp"

std::string  ft_filename(std::string file)
{
    std::string  newFile;
    int loc;
    int len;
    loc = file.find('.');
    len = file.length() - loc;
    file.erase(loc, len);
    newFile = file;
    return (newFile);
}

int main(int ac, char **av)
{
    if (ac == 4){
        std::ifstream inFile(av[1]);
        std::string fileName;
        std::string findStr = av[2];
        std::string replaceStr = av[3];
        std::string line;
        
        if (!inFile){
            std::cout << "File is not open.\n";
            exit(0);
        }
        inFile.seekg(0, std::ios::end);
        if (inFile.tellg() == 0){
            std::cout << "File is empty.\n";
            exit(0);
        }
        inFile.seekg(0, std::ios::beg);
        fileName = ft_filename(av[1]);
        std::ofstream outFile(fileName + ".replace");
        while (getline(inFile, line))
        {
            size_t found = 0;
            while ((found = line.find(findStr, found)) != std::string::npos)
            {
                line.replace(found, findStr.length(), replaceStr);
                found += replaceStr.length();
            }
            outFile << line << std::endl;
        }
        outFile.close();
        inFile.close();
    }
    return 0;
}