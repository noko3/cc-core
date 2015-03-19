#ifndef __CC_TYPES_H__
#define __CC_TYPES_H__

#include <stdint.h>
#include <time.h>
#include <deque>

using namespace std;

namespace CC {
typedef float   float32_t;
typedef double  float64_t;
/*
#define MS        *1
#define S         *1000
#define M         *60 S
#define H         *60 M
#define DAY       *24 H
#define DAYS      DAY
#define WEEK      *7 DAYS
#define WEEKS     WEEK
#define FORTNIGHT *14 DAYS
#define MONTH     *61*12 H
#define MONTHS    MONTH
#define QUARTER   *3 MONTHS
#define YEAR      *365 DAYS
#define YEARS     YEAR
*/
enum IMAGETYPE {
    PNG = 0,
    JPEG,
    XPM,
    DDS
}

class vector2n {
  public:
    int x;
    int y;
    vector2n(int x, int y);
};
class vector2f {
  public:
    float64_t x;
    float64_t y;
    vector2f(float64_t x, float64_t y);
};
class vector3 {
  public:
    float64_t x;
    float64_t y;
    float64_t z;
    vector3(float64_t x, float64_t y, float64_t z);
};
class quat {
  public:
    float64_t y;
    float64_t p;
    float64_t r;
    float64_t e;
    quat(float64_t y, float64_t p, float64_t r, float64_t e);
};

class tex {
  public:
    uint32_t w;
    uint32_t h;
    uint32_t **data;
    tex(w, h, data = NULL);
    tex(string filename, IMAGETYPE type);
    ~tex();
};
class uv {
    
};
class shdr {
    
};
class mat {
  public:
    tex textures[];
    uv uvs[];
    shdr shaders[];
};

class bone {
  public:
    bone *parent;
    vector3 loc;
    quat rot;
    float32_t size;
    vector<struct{vertex *v, uint8_t a}> vertices;
};
class skeleton {
  public:
    map<string, bone> bones;
    skeleton interp(skeleton& skA, skeleton& skB, float32_t AB = 0.5);
};
class skelAniFrame {
  public:
    uint32_t pos;
    skeleton data;
    skelAniFrame interp(skelAniFrame& fA, skelAniFrame& fB, float32_t AB = 0.5);
};
class skelAnim {
  public:
    vector<skelAniFrame> frames;
    clock_t len;
};

class audioFrame {
  public:
    uint32_t len;
    uint16_t samples[];
    uint16_t sampleRate;
    clock_t pos;
    audioFrame *next;
    audioFrame *prev;
};
class audioStream {
  public:
    deque<audioFrame> frames;
    audioFrame *current;
};

class videoFrame {
  public:
    vector2n res;
    uint32_t data[][];
    clock_t pos;
    videoFrame &next;
    videoFrame &prev;
};
class videoStream {
  public:
    deque<videoFrame> frames;
    videoFrame *current;
};

class streamFrame {
  public:
    uint32_t size;
    uint64_t offset;
    clock_t len;
    clock_t pos;
    uint8_t payload[];
};
class stream {
  public:
    deque<streamFrame> frames;
    streamFrame *current;
};

class physmat {
  public:
    float32_t melting_point;
    float32_t boiling_point;
    float32_t viscosity;
    float32_t density;
    float32_t permittivity;
    float32_t heat_capacity;
    float32_t thermal_conduction;
    float32_t electric_conduction;
    float32_t absorption;
    vector3 colour;
    float32_t emission;
    float32_t inductance;
    
    physmat();
    ~physmat();
};
class vertex {
  public:
    vector3 pos;
    uint nNeighbours;
    vertex neighbours[];
};
class mesh {
  public:
    vertex vertices[];
};
class physbox : mesh {
    
};
class dmgmodel {
    
};
}

#endif
