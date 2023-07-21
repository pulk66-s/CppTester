#include "./BuiltinFiles.hpp"

namespace Compil {
    BuiltinFiles::BuiltinFiles(struct coreData datas) {
        std::string prefix = datas.getSourcesPath();

        this->files = {
            prefix + "/Tests/TestSuite.cpp",
            prefix + "/Tests/TestMain.cpp",
            prefix + "/Tests/operator/string.cpp",
            prefix + "/Tests/Logger/Logger.cpp"
        };
    }
}