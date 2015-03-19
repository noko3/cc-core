#ifndef __CC_PLUGIN_H__
#define __CC_PLUGIN_H__

#include <map>
#include <list>
#include <cstring>
#include <functional>
using namespace std;

namespace CC {
#define PLUGIN_SLAVE  0
#define PLUGIN_MASTER 1

template<typename... VA_ARGS>
class Plugin {
  protected:
    list<Plugin&> slaves;
    bool connect_to(Plugin &master);
    map<string, function<void*(VA_ARGS...)>> hooks;
    
    virtual void init_plugin(void);
    
  public:
    bool hook(string, function<void*(VA_ARGS... args));
    bool pwn(Plugin &slave);
    
    Plugin(void);
    Plugin(int);
    Plugin(Plugin &master);
    ~Plugin();
};

}
#endif /* __CC_PLUGIN_H__ */
