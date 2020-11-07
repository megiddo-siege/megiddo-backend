#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>

class Entity{
    public:
        enum Method
        {
            mitm,
            self
        };
        Entity(std::string *ip, Method method);
        std::string getIP();
        Method getMethod();
    private:
        std::string ip;
        Method method;
};

#endif