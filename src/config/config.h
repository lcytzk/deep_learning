#ifndef __DL_CONFIG_H__
#define __DL_CONFIG_H__

class Config {
    public:
        Config();
        Config(int argc, char *argv[]);
    private:
        bool debug = false;
};

Config::Config() {}

Config::Config(int argc, char *argv[]) {
    ParameterParser parser(argc, argv);
    if(parser.exist("debug")) debug = true;
}

#endif
