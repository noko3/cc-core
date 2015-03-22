#include "object.h"

namespace CC {

{ /* cc_object */

cc_object::cc_object() {
    //
}

cc_object::~cc_object() {
    //
}

// getters
uint64_t cc_object::get_id();
vector3 cc_object::get_loc();
vector3 cc_object::get_scale();
quat cc_object::get_rot();
// setters
void cc_object::set_id(uint64_t obj_id);
void cc_object::set_loc(vector3 loc);
void cc_object::set_scale(vector3 scale);
void cc_object::set_rot(quat rot);

} /* cc_object */

{ /* movable */

movable::movable() : cc_object() {
    //
}

movable::~movable() : ~cc_object() {
    //
}

} /* movable */

}
