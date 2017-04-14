#ifndef __COMMAND_LINE_PARSER_H__
#define __COMMAND_LINE_PARSER_H__

#include <string>
#include <unordered_map>


// A simple parser, -key value or --flag

class ParameterParser {
    private:
        const static std::string NO_VALUE;
        std::unordered_map<std::string, std::string> map;
        bool validate = false;

    public:
        ParameterParser() {}
        ParameterParser(int argc, char *argv[]);
        bool parseCommandLine(int argc, char* argv[]);
        bool valid();
        std::string get(const std::string &key);
        bool getIfExist(const std::string &key, std::string &value);
        bool exist(const std::string &key);
};

#endif
