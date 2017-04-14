#include <string>
#include <vector>

#include "command_line_parser.h"

const std::string ParameterParser::NO_VALUE = "";

ParameterParser::ParameterParser(int argc, char *argv[]) {
    validate = parseCommandLine(argc,argv);
}

bool ParameterParser::parseCommandLine(int argc, char* argv[]) {
    int i = 1;
    try {
        while(i < argc) {
            if(argv[i][0] == '-') {
                if(argv[i][1] == '-') {
                    std::string key(argv[i] + 2);
                    map[key] = "";
                } else {
                    std::string key(argv[i] + 1);
                    std::string value(argv[++i]);
                    map[key] = value;
                }
            }
            i += 1;
        }
    } catch (...) {
        return false;
    }
    return true;
}

bool ParameterParser::valid() {
    return validate;
}

std::string ParameterParser::get(const std::string &key) {
    auto value = map.find(key);
    if(value == map.end()) {
        return NO_VALUE;
    }
    return value->second;
}

bool ParameterParser::getIfExist(const std::string &key, std::string &value) {
    auto val = map.find(key);
    if(val == map.end()) {
        return false;
    }
    value = val->second;
    return true;
}
        
bool ParameterParser::exist(const std::string &key) {
    return map.find(key) != map.end();
}
