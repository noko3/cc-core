#include "event.h"

using namespace CC;

EventDispatcher::EventDispatcher() {}
EventDispatcher::~EventDispatcher() {}
EventSubscription* EventDispatcher::subscribe(evt_t evtID,EventSubscriber *sub){
    // TODO lock objects prior to doing stuff
    EventSubscription *es = new EventSubscription(*this);
    size_t id;
    if (vacant[evtID].size()) {
        id = vacant[evtID].top();
        vacant[evtID].pop();
        subscribers[evtID].at(id) = sub;
    } else {
        subscribers[evtID].push_back(sub);
        id = subscribers[evtID].size() - 1;
    }
    es->id = id;
    return es;
}
void EventDispatcher::unsubscribe(EventSubscription *es) {
    vacant[s->evtID].push(s->id);
    subscribers[s->evtID].at(s->id) = NULL;
    delete es;
}


EventPublisher::EventPublisher() {}
EventPublisher::~EventPublisher() {}
void EventPublisher::yield(evt_t evtID, EventArgs args) {
    Event *evt = new Event;
    evt.pub = *this;
    evt.evtID = evtID;
    evt.args = args;
    this.ed->insertEvent(evt);
}


EventSubscriber::EventSubscriber() {}
EventSubscriber::~EventSubscriber() {}
EventSubscriber::subscribe(evt_t evtID);
EventSubscriber::unsubscribe(evt_t evtID);
EventSubscriber::handle(evt_t evtID, function<void(Event)> handler);
EventSubscriber::unhandle(evt_t evtID, function<void(Event)> handler);
EventSubscriber::processEvt(Event *evt);
