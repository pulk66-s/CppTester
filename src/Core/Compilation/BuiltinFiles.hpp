#ifndef __CORE_COMPILATION_BUILTINFILES_HPP__
#define __CORE_COMPILATION_BUILTINFILES_HPP__

#include "./CompilationNamespace.hpp"
#include "./CompilFiles.hpp"
#include "./../Env.hpp"
#include "./../Params.hpp"

namespace Compil {
    struct BuiltinFiles : public Files {
        BuiltinFiles(struct Env env, struct Params params);
    };
}

#endif