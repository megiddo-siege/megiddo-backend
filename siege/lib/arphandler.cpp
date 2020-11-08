#include "arphandler.hpp"

ARPHandler::ARPHandler(std::string *hw_victim, std::string *hw_target, std::string *ip_victim, std::string *ip_target){
    this->hw_victim = *hw_victim;
    this->hw_target = *hw_target;
    this->ip_victim = *ip_victim;
    this->ip_target = *ip_target;
    *this->to_stop = false;
}