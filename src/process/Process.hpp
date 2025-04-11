#pragma once
#include "Mesage.hpp"
#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <atomic>

class Process {
protected:
    int id;
    std::string name;
    std::queue<Message> messageQueue;
    std::mutex queueMutex;
    std::condition_variable queueCV;
    std::atomic<bool> running{true};
    std::thread workerThread;

    virtual void handleMessage(const Message& msg);
    void processLoop();

public:
    Process(int pid, const std::string& pname);
    virtual ~Process();

    int getId() const;
    void sendMessage(const Message& msg);
    void stop();
};
