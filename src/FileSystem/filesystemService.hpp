#pragma once
#include "Process.hpp"
#include <map>

class FileSystemService : public Process {
private:
  std::map<std::string, std::string> files;
  std::string trim(const std::strings& str);

public:
  FileSystemService(int pid, const std::string& name);

protected:
  void handleMessage(const Message& msg) override;
};
