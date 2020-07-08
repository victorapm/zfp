#ifndef ZFPY_ARRAY2_H
#define ZFPY_ARRAY2_H

#include "zfparray2.h"

namespace zfp {

// zfpy interface (required because of current cython limitations)
template < typename Scalar, class Codec = zfp::codec<Scalar> >
class py_array2 : public array2<Scalar, Codec> {
public:
  py_array2(uint nx, uint ny, double rate, const Scalar* p = 0, size_t csize = 0) :
    array2<Scalar, Codec>(nx, ny, rate, p, csize) {}

  // inspector
  Scalar get(uint i, uint j) const {
    return array2<Scalar, Codec>::get(i, j);
  }

  // mutator
  void set(uint i, uint j, Scalar val) {
    array2<Scalar, Codec>::set(i, j, val);
  }
};

}

#endif
