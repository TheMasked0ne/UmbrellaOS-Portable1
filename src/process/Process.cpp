#include "Process.hpp"
#include <iostream>

Process::Process(int pid, const std::string& pname) : id(pid), name(pname) {
    workerThread = std::thread(&Process::processLoop, this);
}

Process::~Process() {
    stop();
    if (workerThread.joinable()) workerThread.join();
}

int Process::getId() const { return id; }

void Process::sendMessage(const Message& msg) {
    std::lock_guard<std::mutex> lock(queueMutex);
    messageQueue.push(msg);
    queueCV.notify_one();
}

void Process::stop() {
    running = false;
    queueCV.notify_all();
}

void Process::handleMessage(const Message& msg) {
    std::cout << "[" << name << "] Received: " << msg.data << "\n";
}

void Process::processLoop() {
    while (running) {
        std::unique_lock<std::mutex> lock(queueMutex);
        queueCV.wait(lock, [&]() { return !messageQueue.empty() || !running; });

        while (!messageQueue.empty()) {
            Message msg = messageQueue.front();
            messageQueue.pop();
            lock.unlock();
            handleMessage(msg);
            lock.lock();
        }
    }
}
