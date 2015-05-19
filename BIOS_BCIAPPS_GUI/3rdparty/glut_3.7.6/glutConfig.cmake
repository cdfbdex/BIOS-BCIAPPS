# - Config file for the glut package
# It defines the following variables
#  GLUT_INCLUDE_DIRS - include directories for glut
#  GLUT_LIBRARIES    - libraries to link against


# Compute paths
get_filename_component(GLUT_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(GLUT_INCLUDE_DIRS "${GLUT_CMAKE_DIR}/include")
set(GLUT_LINK_DIRS "${GLUT_CMAKE_DIR}/lib")

# Our library dependencies (contains definitions for IMPORTED targets)
include("${GLUT_CMAKE_DIR}/glutTargets.cmake")

# These are IMPORTED targets created by glutTargets.cmake
set(GLUT_LIBRARIES glut)
