#ifndef __CC_OBJTRACKER_H__
#define __CC_OBJTRACKER_H__

#include <unistd.h>
#include <map>
#include <functional>
using namespace std;

#include <cc/object.h>


namespace CC {
class ObjectTracker;

class TrackedObject { // : cc_object {
  protected:
    /// called every ObjectTracker's tick()
    cc_object &tracked;
    function<void(TrackedObject&)> tracker_fn;
  public:
    TrackedObject(cc_object &obj, function<void(TrackedObject&)> tracker_fn);
    ~TrackedObject();
};

class ObjectTracker {
  private:
    map<uint64_t, TrackedObject&> objects;
    bool init();
    bool tick();
    bool fini();
    
  public:
    ObjectTracker();
    ~ObjectTracker();
    
    bool track(TrackedObject &obj);
    bool track(cc_object &obj, function<void(TrackedObject&)> tracker_fn);
    bool update(uint64_t obj_id, function<void(TrackedObject&)> tracker_fn);
    uint64_t fork(uint64_t obj_id, function<void(TrackedObject&)> tracker_fn);
    bool move(uint64_t obj_id, ObjectTracker &tracker);
    bool lose(uint64_t obj_id);
};

}
#endif /* __CC_OBJTRACKER_H__ */
