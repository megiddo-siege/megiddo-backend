#include "entity.hpp"

Entity::Entity(std::string *ip, Method method){
    this->ip = *ip;
    this->method = method;
}

std::string Entity::getIP(){
    return this->ip;
}

Entity::Method Entity::getMethod(){
    return this->method;
}