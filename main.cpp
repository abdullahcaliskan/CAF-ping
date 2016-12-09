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
using namespace std;

using ping_atom = atom_constant<atom("ping")>;
using pong_atom = atom_constant<atom("pong")>;

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

behavior ping(event_based_actor* self){

}

behavior server(broker* self, const actor& buddy){
    aout(self) << "Server is running" << endl;
    return {
        [=](const new_connection_msg& msg){
            aout(self) << "Server accepted new connection" << endl;
        }
    }
}

void run_server(actor_system& system, const config& cfg) {
    cout << "Run in server-mode" << endl;
    //auto pong_actor = system.spawn(pong);
    auto server_actor = system.middleman().spawn_server(server)
}

void caf_main(actor_system& system, const config& cfg){
    // Server-mode enable ise, run_server değilse, run client
    auto f = cfg.server_mode ? run_server : run_client;
}