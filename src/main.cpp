#include <iostream>
#include <fstream>
#include <iomanip>
#include "terminal.h"

int main(int argc, char *argv[]) {
    if (argc == 5) {
        std::string path = argv[0];
        std::string inputPath = argv[1];
        std::string outputPath = argv[2];
        std::string feature = argv[3];
        std::string order = argv[4];

        std::ifstream file;
        file.open(inputPath);
        std::string allLine = "";
        std::string inputLine = "";
        while (std::getline(file, inputLine)) {
            allLine += inputLine + " ";
        }
        file.close();

        std::ofstream wrFile;
        wrFile.open(outputPath);
        Terminal terminal(allLine + " " + feature + " " + order);
        wrFile << terminal.showResult();
        wrFile.close();
    }
    return 0;
}
