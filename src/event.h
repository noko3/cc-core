#ifndef __CC_EVENT_H__
#define __CC_EVENT_H__

#include <stdint.h>
#include <functional>
#include <vector>
#include <map>
using namespace std;

namespace CC {

typedef uint32_t evt_t;

class EventSubscription {
  friend class EventDispatcher;
  private:
    EventDispatcher *ed;
    evt_t evtID;
    size_t id;
};

class EventDispatcher {
  private:
    // TODO map locks
    map<evt_t, vector<EventSubscriber*>> subscribers;
    map<evt_t, stack<size_t>> vacant;
  public:
    EventDispatcher* getInstance();
    EventSubscription* subscribe(evt_t evtID, EventSubscriber *sub);
    void unsubscribe(EventSubscription *es);
    void insertEvent(Event *evt);
    void addPublisher(EventPublisher *pub);
    void delPublisher(EventPublisher *pub);
    EventDispatcher()
    ~EventDispatcher();
};

class EventPublisher {
  protected:
    EventDispatcher *ed;
    void yield(Event &evt);
  public:
    EventPublisher();
    ~EventPublisher();
};

class EventSubscriber {
  protected:
    //
};

class EventArgs {
  public:
    int errno;
};

struct Event {
    evt_t evtID;
    EventPublisher *pub;
    EventArgs *args;
};

}

#endif /* __CC_EVENT_H__ */
