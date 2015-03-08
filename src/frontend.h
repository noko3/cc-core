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

class CCFrontEnd { // CC::Plugin {
  protected:
    /* Singleton */ ///TODO: do we need it?
    //~ static CCFrontEnd singleton;
    map<int, CC::Thread&> thr_pool;
    map<int, CC::Sock&> sockets;
    map<int, CC::stream&> streams[];
    CC::Time time_frontend;
    CC::Time time_client;
    CC::ObjectTracker &objtrak;
    CC::Client &client;
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
    virtual void* insert_object(CC::cc_object_generic &obj,CC::Err &error=NULL);
    virtual void* insert_mesh(CC::mesh &mesh, CC::Err &error=NULL);
    virtual void* insert_physbox(CC::physbox &pb, CC::Err &error=NULL);
    virtual void* insert_texture(CC::tex &texture, CC::Err &error=NULL);
    virtual void* insert_uv(CC::uv &uv, CC::Err &error=NULL);
    virtual void* insert_material(CC::mat &material, CC::Err &error=NULL);
    virtual void* insert_shader(CC::shdr &material, CC::Err &error=NULL);
    virtual void* insert_animation(CC::anim &animation, CC::Err &error=NULL);
    virtual void* insert_audio(CC::audio &audio, CC::Err &error=NULL);
    virtual void* insert_video(CC::video &video, CC::Err &error=NULL);
    virtual void* insert_stream(CC::stream &stream, CC::Err &error=NULL); // AV
    
    /* Delete resources no longer required */
    virtual void* delete_object(uint64_t id, CC::Err &error=NULL);
    virtual void* delete_mesh(uint64_t id, CC::Err &error=NULL);
    virtual void* delete_physbox(uint64_t id, CC::Err &error=NULL);
    virtual void* delete_texture(uint64_t id, CC::Err &error=NULL);
    virtual void* delete_uv(uint64_t id, CC::Err &error=NULL);
    virtual void* delete_material(uint64_t id, CC::Err &error=NULL);
    virtual void* delete_shader(uint64_t id, CC::Err &error=NULL);
    virtual void* delete_animation(uint64_t id, CC::Err &error=NULL);
    virtual void* delete_audio(uint64_t id, CC::Err &error=NULL);
    virtual void* delete_video(uint64_t id, CC::Err &error=NULL);
    virtual void* delete_stream(uint64_t id, CC::Err &error=NULL);
    
    /* Actions to perform when client says to */
    
    
    /* Provide resources for the client */
    virtual void* send_stream(CC::stream &stream, CC::Err &error=NULL);
    virtual void* kill_stream(uint64_t id, CC::Err &error=NULL);

  public:
    /* we are hookable!~~ */
    //~ virtual bool dig_in(CC::Plugin &plugin);
    //~ virtual bool bind_key(uint16_t scancode, CC::Callback &callback);
    //~ virtual bool bind_keys(map<uint16_t, CC::Callback &callback> keybindings);
    
    /* constructor/destructor */
    CCFrontEnd(void);
    ~CCFrontEnd(void);
};

#endif /*__CC_FRONTEND_H__*/
