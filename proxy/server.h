#pragma once
#include <string>
#include "proton/variant.hpp"
#include "enet/include/enet.h"
#include "world.h"

class server {
   private:
    ENetHost* m_proxy_server;
    ENetHost* m_real_server;
    ENetPeer* m_server_peer;
    ENetPeer* m_gt_peer;
    
    
    void handle_outgoing();
    void handle_incoming();
    bool connect();
    void disconnect(bool reset);
   public:
    int m_user = 0;
    int m_token = 0;
    std::string m_server = "213.179.209.168";
    int m_port = 17255;
    int m_proxyport = 17255;
    world m_world;
    bool start();
    void quit();
    bool setup_client();
    void redirect_server(variantlist_t& varlist);
    void send(bool client, int32_t type, uint8_t* data, int32_t len);
    void send(bool client, variantlist_t& list, int32_t netid = -1, int32_t delay = 0);
    void send(bool client, std::string packet, int32_t type = 2);
    void SendPacketRaw(bool client, int a1, void* packetData, size_t packetDataSize, void* a4, int packetFlag);
    void addBlock(int a, int b, int c);
    void sendState(int netid);
    void poll();
};
extern server* g_server;
