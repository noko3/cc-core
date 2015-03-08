//virtual bool CCFrontEnd::init();
//virtual bool CCFrontEnd::fini();

#include "frontend.h"

CCFrontEnd::CCFrontEnd() {
    // 1. read config
    // 2. start the client, or connect to a running one
    // 3. initialize common subsystems
    // 4. initialize compartments-dependent subsystems, this.init();
    this.config.readconf(); ///TODO might fail
    
    if (this.config["client.mode"] == (string)"tcp"
       || this.config["client.mode"] == (string)"udp") {
        string &addr = this.config["client.addr"]; ///TODO default addr
        uint16_t port;
        istringstream tmp(this.config["client.port"]; ///TODO default port
        tmp >> port;
    }
    this.client = new Client(CC_CLIENT_SLAVE); ///TODO if(this.client==null) ...
    ///TODO client.mode not set
    if (this.config["client.mode"] == (string)"tcp")
        this.client.connect(M_TCP, addr, port);
    else if (this.config["client.mode"] == (string)"udp")
        this.client.connect(M_UDP, addr, port);
    else if (this.config["client.mode"] == (string)"usock")
        this.client.connect(M_SOCK, this.config["client.socket"];
    else if (this.config["client.mode"] == (string)"launch") {
        Client::config ccfg = this.client.start();
        this.client.connect(ccfg);
    }
    
    /* this.init_subsystems() *////TODO
    
    
    this.init();
}

CCFrontEnd::~CCFrontEnd() {
    // 1. gracefully disconnect from the client
    // 2. save changes
    // 3. stop compartment-dependent subsystems, this.fini();
    // 4. stop common subsystems
    this.client.disconnect();
    
    this.config.save();
    this.config.close();
    
    this.fini();
    
    /* this.kill_subsystems(); *////TODO
}

bool CCFrontEnd::tick() {
    return true;
}
