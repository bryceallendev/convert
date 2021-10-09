/*
    convert.cpp

    Convert the string

    Note: The "CONCERNS" are for pedagogical purposes only
*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

// Conversion function type
typedef void(*Conversion)(char& c);

int main(int argc, char* argv[]) {

    // requires conversion option and string
    // CONCERNS: argc, argv, argv[0], error handling
    if (argc != 3) {
        std::cerr << "usage: " << argv[0] << " <option> <string>\n";
        return 1;
    }

    // conversion option
    // CONCERNS: argc == 3, argv, argv[1] is option, option
    std::string option(argv[1]);
    
    // input string
    // CONCERNS: argc == 3, argv, argv[2] is string, string
    std::string s = argv[2];

    // map from the option to the conversion
    // CONCERNS: "--upper", "--lower", invalid options, error handling, string, std::toupper(), std::tolower(), ctype
    Conversion conversion = nullptr;
    if (option == "--upper") {

        conversion = [](char& c) { c = std::toupper(c); };

    } else if (option == "--lower") {

        conversion = [](char& c) { c = std::tolower(c); };

    } else {

        std::cerr << "Invalid conversion option: " << option << '\n';
        return 1;
    }

    // applying the conversion
    // CONCERNS: string, conversion()
    std::for_each(s.begin(), s.end(), conversion);
    

    // output converted string
    // CONCERNS: string, myforeach(), output format
    std::for_each(s.cbegin(), s.cend(), [](char c) { std::cout << c; });
    std::cout << '\n';

    return 0;
}
