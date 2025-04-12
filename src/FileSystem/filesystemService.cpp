#include "filesystemService.hpp"
#include <sstream>
#include <iostream>

filesystemService::FileSystemService(int pid, const std::string& name)
  : Process(pid, name) {}

void FileSystemService::handleMessage(const Message& msg) {
  std::istringstream iss(msg.data);
  std::string command, filename, content;
  iss >> command >> filename;
  std::getline(iss, content);
  content = trim(content);

  std::string response;

  if (command == "write") {
        if (filename.empty()) {
            response = "Error: Missing filename.";
        } else {
            files[filename] = content;
            response = "File '" + filename + "' written.";
        }
    } else if (command == "read") {
        if (filename.empty()) {
            response = "Error: Missing filename.";
        } else if (files.count(filename)) {
            response = "Contents of '" + filename + "': " + files[filename];
        } else {
            response = "Error: File '" + filename + "' not found.";
        }
    } else if (command == "ls") {
        if (files.empty()) {
            response = "No files found.";
        } else {
            response = "Files:";
            for (const auto& [name, _] : files) {
                response += "\n - " + name;
            }
        }
    } else {
        response = "Unknown file command.";
    }

    sendMessage({id, msg.source, response});
}

std::string FileSystemService::trim(const std::string& str) {
    const auto begin = str.find_first_not_of(" ");
    if (begin == std::string::npos) return "";
    const auto end = str.find_last_not_of(" ");
    return str.substr(begin, end - begin + 1);
}
