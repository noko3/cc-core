#ifndef __CC_OBJECT_H__
#define __CC_OBJECT_H__

#include <cc/types.h>
#include <stdint.h>
#include <vector>

using namespace std;

namespace CC {
#define X_TYPE_LIQUID   0
#define X_TYPE_VAPOUR   1
#define X_TYPE_MOMENTUM 2
#define X_TYPE_TORQUE   3
#define X_TYPE_ELECTRO  4
#define X_TYPE_HEAT     5
#define X_TYPE_PRESSURE 6
#define X_TYPE_FIELD    7

class cc_object {
  protected:
    uint64_t obj_id;
    vector3 loc;
    quat rot;
    vector3 scale;
    vector<mat> *materials;
    vector<mesh> *meshes;
    bool visible;
  public:
    cc_object();
    ~cc_object();
    // getters
    uint64_t get_id();
    vector3 get_loc();
    vector3 get_scale();
    quat get_rot();
    // setters
    void set_id(uint64_t obj_id);
    void set_loc(vector3 loc);
    void set_scale(vector3 scale);
    void set_rot(quat rot);
};

class movable : cc_object {
  protected:
    vector3 speed;
    float64_t velocity;
    quat accel_dir;
    float64_t accel;
    quat rot_dir;
    float64_t rot_speed;
  public:
    movable();
    ~movable();
    // getters
    // setters
};

class composite : cc_object {
  protected:
    vector<cc_object*> attached;
  public:
    composite();
    ~composite();
    size_t attach(cc_object *obj);
    int detach(size_t id);
    cc_object *get(size_t id);
};

class solid : cc_object {
  protected:
    float64_t mass;
    physbox pb;
  public:
    solid();
    ~solid();
};

class rigid : solid {
  protected:
    collisionmodel cmodel;
  public:
    rigid();
    ~rigid();
};

class rope : cc_object {
    //can be cut and torn, could use simplified math and physics
}

class frag_voronoi {
  protected:
    float32_t hardness;
    float32_t durability;
    float32_t viscosity;
    float32_t plasticity;
  public:
    frag_voronoi();
    ~frag_voronoi();
}

class frag_decompose : composite {};
class frag_chobj {};

class input_source {
  protected:
    // bindings
  public:
    input_source();
    ~input_source();
};

class output_sink {
  protected:
    // bindings
  public:
    output_sink();
    ~output_sink();
};

class interactive : input_source, output_sink {
  public:
    interactive();
    ~interactive();
};

class emitter : output_sink {
    //
};

class detector : input_source {
    //
};

class x_source {};
class x_sink {};
class x_transformer : x_source, x_sink {};
class x_accumulator : x_source, x_sink {};
class x_conductor : x_source, x_sink {};


class resource_friendly {};
class resource_expensive {};

class unreliable {};
class expendable {};

class hollow {
  protected:
    float64_t volume;
  public:
    hollow();
    ~hollow();
};

class liquid {};

class animated {};

class animate {};
}

#endif
