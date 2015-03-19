#ifndef __CC_WDOMAIN_H__
#define __CC_WDOMAIN_H__

#include <cc/objtracker.h>
#include <cc/types.h>

namespace CC {

// http://en.wikipedia.org/wiki/Trapezo-rhombic_dodecahedron
class WDomain {
  private:
    vector3 pos;
    float32_t radius;
    WDomain &parent;
    WDomain &neighbours[12];
    WDomain &children[13];
    ObjectTracker &objtracker;
    bool init();
    bool tick();
    bool fini();
    bool posTracker(TrackedObject& obj);
    
  public:
    WDomain();
    WDomain(WDomain &parent, float32_t radius, uint8_t innerID);
    ~WDomain();
    
    uint64_t addObject(cc_object &obj, bool track_pos,
                       function<bool(TrackedObject&)> fn_tracker);
    bool updObject(uint64_t obj_id, bool track_pos,
                   function<bool(TrackedObject&)> fn_tracker);
    bool delObject(uint64_t obj_id);
    
};

}
#endif /* __CC_WDOMAIN_H__ */
