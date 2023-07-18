#include "./BuiltinFiles.hpp"

namespace Compil {
    BuiltinFiles::BuiltinFiles(struct coreData datas) {
        std::string prefix = datas.getSourcesPath();

        this->files = {
            prefix + "/src/Tests/TestSuite.cpp",
            prefix + "/src/Tests/TestMain.cpp"
        };
    }
}