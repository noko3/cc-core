#ifndef __CC_WDOMAIN_H__
#define __CC_WDOMAIN_H__

#include <cc/objtracker.h>
#include <cc/types.h>

namespace CC {

// https://en.wikipedia.org/wiki/Elongated_dodecahedron
class WDomain {
  private:
    vector3 pos;
    float32_t radius;
    WDomain &neighbours[12];
    ObjectTracker &objtracker;
    bool init();
    bool tick();
    bool fini();
    bool posTracker(TrackedObject& obj);
    
  public:
    WDomain();
    ~WDomain();
    
    uint64_t addObject(cc_object &obj, bool track_pos,
                       function<bool(TrackedObject&)> fn_tracker);
    bool updObject(uint64_t obj_id, bool track_pos,
                   function<bool(TrackedObject&)> fn_tracker);
    bool delObject(uint64_t obj_id);
    
};

}
#endif /* __CC_WDOMAIN_H__ */
