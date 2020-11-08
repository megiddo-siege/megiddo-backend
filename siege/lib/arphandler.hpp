#ifndef ARPHANDLER_H
#define ARPHANDLER_H

#include <tins/tins.h>
#include <thread>
#include <atomic>


class ARPHandler{
    public:
        ARPHandler(std::string *hw_victim, std::string *hw_target, std::string *ip_victim, std::string *ip_target);
        void send();
        void stop();
        void send();
    private:
        std::string hw_victim, hw_target, ip_victim, ip_target;
        std::thread sender;
        std::atomic<bool> *to_stop;
};

#endif