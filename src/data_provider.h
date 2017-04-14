#ifndef __DL_EXAMPLE_PROVIDER_H__
#define __DL_EXAMPLE_PROVIDER_H__

#include <string>

class ExampleProvider {
    public:
        ExampleProvider();
    private:
        bool stdinFlag = false;
        string filename;
};

#endif
