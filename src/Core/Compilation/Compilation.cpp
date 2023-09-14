#include "Compilation.hpp"
#include <iostream>
#include <cstdlib>

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
        if (flags.debug || this->coreDatas.params.getParams().debug) {
            this->flags.push_back("-g3");
            this->flags.push_back("-fsanitize=address");
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
        for (std::string path : this->coreDatas.params.getParams().includes) {
            this->flags.push_back("-I" + path);
        }
        for (std::string lib : this->coreDatas.params.getParams().libs) {
            this->flags.push_back("-l" + lib);
        }
        for (std::string p : this->flags) {
            std::cout << p << std::endl;
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
        std::cout << "Starting GPP" << std::endl;
        this->gpp.run(this->files, this->flags);
        std::cout << "Ending GPP" << std::endl;
    }

    int Compilation::runprgm(void)
    {
        std::cout << "Starting Run" << std::endl;
        int res = std::system("./cpptester");
        std::cout << "Ending Run " << res << std::endl;
        return res / 256; // Why 256 ? It's perl's system fault
    }

    Compilation::~Compilation() {
        system("rm -f ./cpptester");
    }
}
