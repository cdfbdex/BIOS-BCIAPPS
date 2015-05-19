# - Config file for the OSCPACKLib package
# It defines the following variables
#  OSC_INCLUDE_DIRS - include directories for OSCPACKLib
#  OSC_LIBRARIES    - libraries to link against
#  OSC_LINK_DIRS    - libraries to link against


# Compute paths
get_filename_component(OSC_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(OSC_INCLUDE_DIRS "${OSC_CMAKE_DIR}/include")
set(OSC_LINK_DIRS "${OSC_CMAKE_DIR}/lib")
# Our library dependencies (contains definitions for IMPORTED targets)
include("${OSC_CMAKE_DIR}/oscTargets.cmake")

# These are IMPORTED targets created by oscTargets.cmake
set(OSC_LIBRARIES osc)
