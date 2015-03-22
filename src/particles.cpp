#include "particles.h"

namespace CC {

void Particles::render() {
    this.render(this.settings);
}

void Particles::render(particleSettings *settings) {
    this.renderers[settings.type](settings);
}

Particles::Particles(particleSettings *settings=NULL) {
    if (settings == NULL) {
        this.mysettings = true;
        this.settings = new particleSettings();
    } else {
        this.mysettings = false;
        this.settings = settings;
    }
}

Particles::~Particles() {
    if (this.mysettings) {
        delete this.settings;
    }
}

}
