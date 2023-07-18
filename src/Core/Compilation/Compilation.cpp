#include "Compilation.hpp"

namespace Compil
{
    void Compilation::_createFiles(struct Files files)
    {
        this->files = this->builtinFiles;
        for (std::string file : files.files) {
            this->files.push_back(file);
        }
    }

    void Compilation::_createFlags(struct Flags flags)
    {
        if (flags.debug) {
            this->flags.push_back("-g3");
            this->flags.push_back("-fsanitize=adress");
        }
        if (flags.optimisation) {
            this->flags.push_back("-03");
        }
        if (flags.warns) {
            this->flags.push_back("-W");
            this->flags.push_back("-Wall");
            this->flags.push_back("-Wextra");
        }
        if (flags.warnError) {
            this->flags.push_back("-Werror");
        }
        if (flags.defaultInclude) {
            this->flags.push_back("-I" + this->coreDatas.getIncludePath());
        }
        if (flags.defaultName) {
            this->flags.push_back("-o");
            this->flags.push_back("cpptester");
        }
    }

    void Compilation::_setupBuiltinFiles(struct Files builtinFiles)
    {
        this->builtinFiles = builtinFiles.files;
    }

    Compilation::Compilation(
        struct Files files,
        struct Files builtinFiles, 
        struct Flags flags, 
        struct coreData datas
    ) : coreDatas(datas) {
        this->_setupBuiltinFiles(builtinFiles);
        this->_createFiles(files);
        this->_createFlags(flags);
    }

    void Compilation::run(void)
    {
        this->gpp.run(this->files, this->flags);
    }

    void Compilation::runprgm(void)
    {
        system("./cpptester");
    }
}