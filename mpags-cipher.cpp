#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    const std::vector<std::string> cmdLineArgs { argv, argv+argc };
    const size_t n = cmdLineArgs.size();

    for (std::size_t i{0}; i < n; i++) {
        // print help message and version information
        if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
            std::cout << "some help messages" << std::endl;
        }

        else if (cmdLineArgs[i] == "--version") {
            std::cout << "version 0.1.0" << std::endl;
        }

        // check input and output file
        else if (cmdLineArgs[i] == "-i") {
            if (i != (n-1) && cmdLineArgs[i+1][0] != '-') {
                std::cout << "input file is " << cmdLineArgs[i+1] << std::endl;
            }
            else std::cout << "declare input file name" << std::endl;
        }

        else if (cmdLineArgs[i] == "-o") {
            if (i != (n-1) && cmdLineArgs[i+1][0] != '-') {
                std::cout << "output file is " << cmdLineArgs[i+1] << std::endl;
            }
            else std::cout << "declare output file name" << std::endl;
        }
        
        // ignore executable and i/o file names
        else if (cmdLineArgs[i] == " " || cmdLineArgs[i][0] == '.') {
            continue;
        }

        else if (cmdLineArgs[i][0] != '-' && cmdLineArgs[i-1][0] == '-') {
            continue;
        }

        // error message
        else std::cout << "unrecognized command" << std::endl;
    }
}