# - Config file for the XavierSDK package
# It defines the following variables
#  XAVIERSDK_INCLUDE_DIRS - include directories for XavierSDK
#  XAVIERSDK_LIBRARIES    - libraries to link against


# Compute paths
get_filename_component(XAVIERSDK_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(XAVIERSDK_INCLUDE_DIRS "${XAVIERSDK_CMAKE_DIR}/include")


if(CMAKE_SIZEOF_VOID_P EQUAL 8)
		set(XAVIERSDK_LINK_DIRS "${XAVIERSDK_CMAKE_DIR}/lib/x64")
else()
		set(XAVIERSDK_LINK_DIRS "${XAVIERSDK_CMAKE_DIR}/lib/x86")
endif()


# Our library dependencies (contains definitions for IMPORTED targets)
include("${XAVIERSDK_CMAKE_DIR}/XavierSDKTargets.cmake")

# These are IMPORTED targets created by XavierSDKTargets.cmake
set(XAVIERSDK_LIBRARIES XavierSDK)
