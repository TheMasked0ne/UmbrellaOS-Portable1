// main.cpp v 0.2

#include "microKernel.hpp"
#include "shellstartProcess.hpp"
#include "filesystemService.hpp"
#include <memory>

int main() {
    MicroKernel kernel;

    kernel.createProcess(1, "Shell", true);
    kernel.createProcess(3, "FileSystem");
    kernel.createProcess(2, "Logger");

    auto shell = std::dynamic_pointer_cast<ShellProcess>(kernel.getProcess(1));
    kernel.sendMessage(0, 2, "System boot completed.");

    if (shell) {
        shell->startShell();
    }

    kernel.shutdown();
    return 0;
}
