#ifndef __CC_PARTICLES__
#define __CC_PARTICLES__

#include <map>
#include <functional>
#include <stdit.h>
#include <time.h>
#include <cc/types.h>
#include "defs.h"

namespace CC {

/*! \struct particleSettings particles.h "src/particles.h"
 *  \brief Common settings for various particle types
 */
struct particleSettings {
    uint8_t type;       /// see defs.h PARTICLE_TYPE_*
    uint8_t attrs;      /// see defs.h PARTICLE_ATTR_*
    bool OSD;           /// If true, render on screen surface rather than in 3D
    vector2n posOSD;    /// 2D on-screen position
    vector3 pos;        /// 3D position
    vector3 scale;      /// Base size
    quat dir;           /// direction
    float32_t intensity;/// new pieces/s
    float32_t density;  /// pieces/m³
    float32_t speed;    /// pieces moving speed
    uint32_t colour;    /// RRGGBBAA format
    clock_t lifetime;   /// How long until the particle expires
};

struct extParticleSettings : particleSettings {
    float32_t mass;
};

struct uiParticleSettings : particleSettings {
    uint32_t colours[4];
    uint32_t border_colours[4];
    uint32_t fx_colours[4];
    
    uint32_t str_len;
    char *str;
};

struct customParticleSettings : particleSettings {
    map<string, void*> x;
};

/*! \class Particles particles.h "src/particles.h"
 *  \brief CC Particle system
 * 
 * Pure virtual renderers
 * 1. Inherit from the Particles class
 * 2a. Either override YourClass::init_renderers():
 *     2a.1. For each particle type (see defs.h), write a renderer:
 *           void particle_renderer_type(particleSettings *settings) {...}
 *     2a.2. For each renderer, append to init_renderers():
 *           this.renderers[PARTICLE_TYPE_type] = particle_renderer_type;
 * 2b. Or override render(particleSettings*)
 */
class Particles {
  protected:
    bool mysettings;
    particleSettings *settings;
    array<function<void(particleSettings*)>, 256> renderers;
    virtual void init_renderers();
    
  public;
    /// for persistent particles
    void render();
    /// render-and-die
    virtual void render(particleSettings*);
    Particles(particleSettings *settings);
    ~Particles();
};

}

#endif /* __CC_PARTICLES__ */
