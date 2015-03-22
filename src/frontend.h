#ifndef __CC_FRONTEND_H__
#define __CC_FRONTEND_H__

#include <map>
#include <cstring>
#include <unistd.h>
#include <iostream>
using namespace std;

#include <cc/error.h>
#include <cc/config.h>
#include <cc/types.h>
#include <cc/object.h>
#include <cc/object_tracker.h>
#include <cc/thread.h>

#if CC_FRONTEND_MODE == EMBED_CLIENT
 #define CCF_EMBED
 #include <cc/client.h>
#elseif CC_FRONTEND_MODE == STANDALONE
 #define CCF_STA
 #include <cc/clientproxy.h>
#endif
namespace CC {

class CCFrontend { // Plugin {
  protected:
    /* Singleton */ ///TODO: do we need it?
    //~ static CCFrontEnd singleton;
    map<int, Thread*> thr_pool;
    map<int, Sock*> sockets;
    map<int, stream*> streams[];
    Time time_frontend;
    Time time_client;
    ObjectTracker *objtrak;
    Client *client;
    map<string, string> config;
    
    // all of these must be hookable
    void *GUI;
    void *G3D;
    void *audio_in;
    void *audio_out;
    void *video_in;
    void *video_out;
    void *kbd_in;
    void *mouse_in;
    void *joystick_in;
    void *gaypad_in;
    void *steeringwheel_in;
    
    /* must have */
    virtual bool init(void);
    bool tick(void);
    virtual bool fini(void);
    
    /* Insert (register) resources  */
    virtual void* insert_object(cc_object *obj,Err *error=NULL);
    virtual void* insert_mesh(mesh *mesh, Err *error=NULL);
    virtual void* insert_physbox(physbox *pb, Err *error=NULL);
    virtual void* insert_texture(tex *texture, Err *error=NULL);
    virtual void* insert_uv(uv *uv, Err *error=NULL);
    virtual void* insert_material(mat *material, Err *error=NULL);
    virtual void* insert_shader(shdr *material, Err *error=NULL);
    virtual void* insert_animation(anim *animation, Err *error=NULL);
    virtual void* insert_audio(audio *audio, Err *error=NULL);
    virtual void* insert_video(video *video, Err *error=NULL);
    virtual void* insert_stream(stream *stream, Err *error=NULL); // AV
    
    /* Delete resources no longer required */
    virtual void* delete_object(uint64_t id, Err *error=NULL);
    virtual void* delete_mesh(uint64_t id, Err *error=NULL);
    virtual void* delete_physbox(uint64_t id, Err *error=NULL);
    virtual void* delete_texture(uint64_t id, Err *error=NULL);
    virtual void* delete_uv(uint64_t id, Err *error=NULL);
    virtual void* delete_material(uint64_t id, Err *error=NULL);
    virtual void* delete_shader(uint64_t id, Err *error=NULL);
    virtual void* delete_animation(uint64_t id, Err *error=NULL);
    virtual void* delete_audio(uint64_t id, Err *error=NULL);
    virtual void* delete_video(uint64_t id, Err *error=NULL);
    virtual void* delete_stream(uint64_t id, Err *error=NULL);
    
    /* Actions to perform when client says to */
    
    
    /* Provide resources for the client */
    virtual void* send_stream(stream *stream, Err *error=NULL);
    virtual void* kill_stream(uint64_t id, Err *error=NULL);

  public:
    //~ virtual bool attachPlugin(Plugin &plugin);
    //~ virtual bool bind_key(uint16_t scancode, Callback &callback);
    //~ virtual bool bind_keys(map<uint16_t, Callback &callback> keybindings);
    
    /* constructor/destructor */
    virtual void mainLoop(void);
    CCFrontend(void);
    ~CCFrontend(void);
};

}
#endif /*__CC_FRONTEND_H__*/
