#ifndef __CC_ERROR_H__
#define __CC_ERROR_H__

#include <cstring>

namespace CC {

/*! \brief Error handling
 */
class Err {
    int errno;
    string errstr;
};

}

#endif /* __CC_ERROR_H__ */
