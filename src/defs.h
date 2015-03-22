namespace CC {

{ /* particles.h */

{ /* particle types */
/* 0x00~0x0f: generic particles */
#define PARTICLE_TYPE_PIXEL         0x00    // Coluored pixel in 3D space
#define PARTICLE_TYPE_SEGMENT       0x01    // 2-point line
#define PARTICLE_TYPE_POLYLINE      0x02    // N-point line
#define PARTICLE_TYPE_POLYGON       0x03    // Flat N-gon
#define PARTICLE_TYPE_TEXT          0x04    // Flying text
#define PARTICLE_TYPE_WIREFRAME     0x05    // Single-coloured wireframe
#define PARTICLE_TYPE_DOT           0x06    // Like pixel, but with radius
#define PARTICLE_TYPE_07            0x07    //
#define PARTICLE_TYPE_08            0x08    //
#define PARTICLE_TYPE_09            0x09    //
#define PARTICLE_TYPE_0A            0x0a    //
#define PARTICLE_TYPE_0B            0x0b    //
#define PARTICLE_TYPE_0C            0x0c    //
#define PARTICLE_TYPE_0D            0x0d    //
#define PARTICLE_TYPE_0E            0x0e    //
#define PARTICLE_TYPE_SPRITE        0x0f    // 2D texture sprire

// flying leaves, pieces of paper
/* 0x10~0x2f: "the four elements" */
/* fire */
#define PARTICLE_TYPE_FLAME         0x10    // Colourful bright flame(s)
#define PARTICLE_TYPE_SMOKE         0x11    // Semi-transparent smoke
#define PARTICLE_TYPE_SPARKLE       0x12    // Colourful sparkle
#define PARTICLE_TYPE_SPARKLES      0x13    // Sparkle group (another renderer)
#define PARTICLE_TYPE_HOTAIR        0x14    // Hot air effect
#define PARTICLE_TYPE_EXPLOSION     0x15    // Cinematic explosion
#define PARTICLE_TYPE_FLASH         0x16    // Very short, very bright
#define PARTICLE_TYPE_17            0x17    // 
/* water */
#define PARTICLE_TYPE_STREAM        0x18    // Liquid stream
#define PARTICLE_TYPE_WATERFALL     0x19    // Falling liquid
#define PARTICLE_TYPE_SPILL         0x1a    // Spilled liquid in the air
#define PARTICLE_TYPE_SPRAY         0x1b    // Thin sparkling drops in air
#define PARTICLE_TYPE_FOG           0x1c    // Fog particles (volumetric fog)
#define PARTICLE_TYPE_SPLASH        0x1d    // Sth falls in the liquid
#define PARTICLE_TYPE_DROP          0x1e    // Drop (highly detailed)
#define PARTICLE_TYPE_RAIN          0x1f    // Raindrops
#define PARTICLE_TYPE_HAIL          0x20    // Hail
#define PARTICLE_TYPE_SNOW          0x21    // Snow
/* air */
#define PARTICLE_TYPE_CLOUD         0x22    // Cloud particle(s)
#define PARTICLE_TYPE_AIRSTREAM     0x23    // Wind stream
#define PARTICLE_TYPE_WHIRLWIND     0x24    // Up to tornado
#define PARTICLE_TYPE_25            0x25    // 
#define PARTICLE_TYPE_26            0x26    // 
#define PARTICLE_TYPE_27            0x27    // 
/* earth */
#define PARTICLE_TYPE_DUST          0x28    // Volumetric dust
#define PARTICLE_TYPE_CLODS         0x29    // Scattered dirt/wet sand lumps
#define PARTICLE_TYPE_GRAVEL        0x2a    // Gravels
#define PARTICLE_TYPE_SAND          0x2b    // Pulverized or falling sand
#define PARTICLE_TYPE_2C            0x2c    // 
#define PARTICLE_TYPE_2D            0x2d    // 
#define PARTICLE_TYPE_2E            0x2e    // 
#define PARTICLE_TYPE_2F            0x2f    // 

/* 0x40~0x5f: Generic nice stuff */
#define PARTICLE_TYPE_HALO          0x40    // From nymbus to sun halo
#define PARTICLE_TYPE_LINE          0x41    // Cute line
#define PARTICLE_TYPE_RECT          0x42    // Rectangle/border/rect segment
#define PARTICLE_TYPE_ELLIPSE       0x43    // Any circular segment
#define PARTICLE_TYPE_BEZIER        0x44    // Bezier curve
#define PARTICLE_TYPE_GLOW          0x45    // Glowing aura
#define PARTICLE_TYPE_46            0x46    // 
#define PARTICLE_TYPE_47            0x47    // 
#define PARTICLE_TYPE_48            0x48    // 
#define PARTICLE_TYPE_49            0x49    // 
#define PARTICLE_TYPE_4a            0x4a    // 
#define PARTICLE_TYPE_4b            0x4b    // 
#define PARTICLE_TYPE_4c            0x4c    // 
#define PARTICLE_TYPE_4d            0x4d    // 
#define PARTICLE_TYPE_4e            0x4e    // 
#define PARTICLE_TYPE_4f            0x4f    // 

/* 0x60~0x6f: More generic stuff */
#define PARTICLE_TYPE_ROPE          0x60    // Rope/wire
#define PARTICLE_TYPE_61            0x61    //
#define PARTICLE_TYPE_62            0x62    //
#define PARTICLE_TYPE_63            0x63    //
#define PARTICLE_TYPE_64            0x64    //
#define PARTICLE_TYPE_65            0x65    //
#define PARTICLE_TYPE_66            0x66    //
#define PARTICLE_TYPE_67            0x67    //
#define PARTICLE_TYPE_68            0x68    //
#define PARTICLE_TYPE_69            0x69    //
#define PARTICLE_TYPE_6a            0x6a    //
#define PARTICLE_TYPE_6b            0x6b    //
#define PARTICLE_TYPE_6c            0x6c    //
#define PARTICLE_TYPE_6d            0x6d    //
#define PARTICLE_TYPE_6e            0x6e    //
#define PARTICLE_TYPE_6f            0x6f    //

/* 0xf0~0xff: Special particle types */
#define PARTICLE_TYPE_GUI           0xfe    // Surface for the GUI renderer
#define PARTICLE_TYPE_OBJECT        0xff    // Any cc_object instance
} /* particle types */

{ /* particle attributes */
#define PARTICLE_ATTRS_NONE         0b00000000 // Empty attributes
#define PARTICLE_ATTR_HEAVY         0b00000001 // The particle has mass
#define PARTICLE_ATTR_TANGIBLE      0b00000010 // The particle is tangible
#define PARTICLE_ATTR_3             0b00000100 // 
#define PARTICLE_ATTR_4             0b00001000 // 
#define PARTICLE_ATTR_WIND          0b00010000 // Liable to wind
#define PARTICLE_ATTR_HUMIDITY      0b00100000 // Liable to humidity
#define PARTICLE_ATTR_7             0b01000000 // 
#define PARTICLE_ATTR_8             0b10000000 // 
#define PARTICLE_ATTRS_PHYSICAL     0b00000011 // 
#define PARTICLE_ATTRS_WEATHER      0b00110000 // 
#define PARTICLE_ATTRS_ALL          0b11111111 // 
} /* particle attributes */

{ /* particle rendering prefs */
// No need to implement ALL of them, say, 1 2 and 3 may be the same
#define PARTICLE_RENDER_NONE    0 // Don't render these particles
#define PARTICLE_RENDER_CHEAP   1 // The cheapest renderer (no calculations)
#define PARTICLE_RENDER_FASTEST 2 // The fastest renderer
#define PARTICLE_RENDER_FAST    3 // A fast renderer
#define PARTICLE_RENDER_MEDIUM  4 // Balanced speed/eyecandy
#define PARTICLE_RENDER_GOOD    5 // Good picture
#define PARTICLE_RENDER_BETTER  6 // Better picture
#define PARTICLE_RENDER_BEST    7 // ULTRA
} /* particle rendering prefs */

} /* particles.h */

} /* namespace CC */
