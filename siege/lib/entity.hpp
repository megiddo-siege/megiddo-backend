#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>

class Entity{
    /*
    This class represents an ip and a method of siege
    */
    public:
        enum Method
        {
            mitm,
            block
        };
        Entity(std::string *ip, Method method);
        std::string getIP();
        Method getMethod();
    private:
        std::string ip;
        Method method;
};

#endif