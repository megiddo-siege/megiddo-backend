#include <iostream>
#include "../lib/arphandler.hpp"

using namespace Megiddo;

void inputEntry(std::string &hw_victim, std::string &hw_target, std::string &ip_victim, std::string &ip_target, std::string &iface){
    // Assuming input is correct since it's received from python directly as a subprocess
    std::cout << "iface: ";
    std::cin >> iface;
    std::cout << "hw_victim: ";
    std::cin >> hw_victim;
    std::cout << "hw_target: ";
    std::cin >> hw_target;
    std::cout << "ip_victim: ";
    std::cin >> ip_victim;
    std::cout << "ip_target: ";
    std::cin >> ip_target;
}

int main(){
    std::string hw_victim, hw_target, ip_victim, ip_target, iface;
    //inputEntry(hw_victim, hw_target, ip_victim, ip_target, iface);
    hw_victim = "FF:FF:FF:FF:FF:F9";
    hw_target = "AB:CD:EF:AB:CD:EF";
    ip_victim = "127.0.0.2";
    ip_target = "127.0.0.3";
    ARPHandler *arphandler = new ARPHandler(&hw_victim,&hw_target,&ip_victim,&ip_target, "lo");

    return 0;
}
