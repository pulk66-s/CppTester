#ifndef __CORE_COMPILATION_BUILTINFILES_HPP__
#define __CORE_COMPILATION_BUILTINFILES_HPP__

#include "./CompilationNamespace.hpp"
#include "./CompilFiles.hpp"
#include "./../CoreDatas.hpp"

namespace Compil {
    struct BuiltinFiles : public Files {
        BuiltinFiles(struct coreData datas);
    };
}

#endif