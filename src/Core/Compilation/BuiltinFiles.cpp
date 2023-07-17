#include "./BuiltinFiles.hpp"

namespace Compil {
    BuiltinFiles::BuiltinFiles(struct Env env, struct Params params) {
        std::string prefix = "";

        if (env.sourcesPath) {
            prefix = *env.sourcesPath;
        } else if (params.getParams().sourceDir) {
            prefix = *params.getParams().sourceDir;
        } else {
            prefix = ".";
        }

        this->files = {
            prefix + "/src/Tests/Assert/Be.cpp",
            prefix + "/src/Tests/Assert/To.cpp",
            prefix + "/src/Tests/Assert/Expect.cpp"
        };
    }
}