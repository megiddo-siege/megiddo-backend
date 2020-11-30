#include <iostream>
#include "../lib/arphandler.hpp"

using namespace Megiddo;

int main(){
    std::string hw_victim, hw_target, ip_victim, ip_target;
    hw_victim = "FF:FF:FF:FF:FF:F9";
    hw_target = "AB:CD:EF:AB:CD:EF";
    ip_victim = "127.0.0.2";
    ip_target = "127.0.0.3";
    ARPHandler *arphandler = new ARPHandler(&hw_victim,&hw_target,&ip_victim,&ip_target, "lo");
    arphandler->send();

    return 0;
}
