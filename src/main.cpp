#include <iostream>
#include <fstream>
#include "terminal.h"

int main(int argc, char *argv[]) {
    if (argc == 5) {
        std::string path = argv[0];
        std::string input = argv[1];
        std::string output = argv[2];
        std::string feature = argv[3];
        std::string order = argv[4];

        std::ifstream file;
        file.open(input);
        std::string allLine = "";
        std::string inputLine;
        //std::getline(file, inputLine);
        while (std::getline(file, inputLine))
        {
            allLine +=inputLine + " ";
        }
        file.close();

        std::ofstream wrFile;
        wrFile.open(output);
        Terminal terminal(allLine + " " + feature + " " + order);
        wrFile << terminal.showResult();
        wrFile.close();
    }
    return 0;
}
