#!/bin/bash

# Echo usage information
case $1 in
   -h|-help)
      cat <<EOF
      -d|--debug:        debug mode
      -r|--release:      release mode
      -o|--openmp:       OpenMP support
EOF
      exit
      ;;
esac

DEBUG="no"
OPENMP="no"
while [ "$*" ]; do
   case $1 in
      -d|--debug)
         DEBUG="yes"; shift
         ;;
      -r|--release)
         DEBUG="no"; shift
         ;;
      -o|--openmp)
         OPENMP="yes"; shift
         ;;
      *)
         echo $1
	 shift
         ;;
   esac
done

ZFP_DIR=$(pwd)
ZFP_BUILD=${ZFP_DIR}/build
ZFP_INSTALL=${ZFP_DIR}/install
if [ ${DEBUG} == "yes" ]; then
    ZFP_INSTALL=${ZFP_INSTALL}/debug
    BUILD_TYPE=Debug
    VERBOSE=ON
else
    ZFP_INSTALL=${ZFP_INSTALL}/release
    BUILD_TYPE=RelWithDebInfo
    VERBOSE=OFF
fi

if [ ${OPENMP} == "yes" ]; then
    WITH_OPENMP=ON
else
    WITH_OPENMP=OFF
fi

rm -rf ${ZFP_BUILD}
mkdir ${ZFP_BUILD}
cd ${ZFP_BUILD}
cmake -S ${ZFP_DIR} \
      -B ${ZFP_BUILD} \
      -DCMAKE_INSTALL_PREFIX=${ZFP_INSTALL} \
      -DCMAKE_VERBOSE_MAKEFILE=${VERBOSE} \
      -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
      -DZFP_WITH_OPENMP=${WITH_OPENMP}
make -j
make install
