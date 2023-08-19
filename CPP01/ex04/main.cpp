#include "Replace.hpp"

string  filename(string file)
{
    string  newFile;
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
        ifstream inFile(av[1]);
        string fileName;
        string findStr = av[2];
        string replaceStr = av[3];
        string line;
        int len;
        
        if (!inFile){
            cout << "File is not open.\n";
            exit(0);
        }
        inFile.seekg(0, std::ios::end);
        if (inFile.tellg() == 0){
            cout << "File is empty.\n";
            exit(0);
        }
        inFile.seekg(0, std::ios::beg);
        fileName = filename(av[1]);
        ofstream outFile(fileName + ".replace");
        while (getline(inFile, line))
        {
            if (line.find(findStr) != string::npos)
            {
                len = line.find(findStr);
                line.erase(len, findStr.length());
                line.insert(len, av[3]);
            }
            outFile << line << endl;
        }
        outFile.close();
        inFile.close();
    }
    
    return (0);
}