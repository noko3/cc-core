#ifndef __CC_TYPES_H__
#define __CC_TYPES_H__

typedef float   float32_t;
typedef double  float64_t;

namespace CC {
    class vector2n {
      public:
        int x;
        int y;
    };
    class vector2f {
      public:
        float64_t x;
        float64_t y;
    };
    class vector3 {
      public:
        float64_t x;
        float64_t y;
        float64_t z;
    };
    class quat {
      public:
        float64_t y;
        float64_t p;
        float64_t r;
        float64_t e;
    };
    
    class tex {
        
    };
    class uv {
        
    };
    class shdr {
        
    };
    class mat {
        
    };
    class anim {
        
    };
    
    class audio {
        
    };
    class video {
        
    };
    class stream {
        
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
    class mesh {
        
    };
    class physbox : mesh {
        
    };
    class dmgmodel {
        
    };
}

#endif
