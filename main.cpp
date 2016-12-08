#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <memory>
#include <cstdint>
#include <cassert>

#include <caf/all.hpp>
#include <caf/io/all.hpp>
#include <caf/config.hpp>

using namespace caf;
using namespace caf::io;

class config : public actor_system_config {
public:
    uint16_t port = 0;
    std::string ip_addr = "127.0.0.1";
    bool server_mode = false;

    // Constructor
    config() {
        opt_group{custom_options_, "global"}
                .add(port, "port,p", "set port")
                .add(ip_addr, "ip,i", "set ip address (ignored in server mode)")
                .add(server_mode, "server-mode,s", "enable server mode");
    }
};

void caf_main(actor_system& system, const config& cfg){

}