
find_package(XAVIERSDK REQUIRED)

if(NOT XAVIERSDK_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT XAVIERSDK_FOUND)

include_directories(${XAVIERSDK_INCLUDE_DIRS})
include_directories(${XAVIERSDK_INCLUDE_DIR})
link_directories(${XAVIERSDK_LINK_DIRS})

add_executable(EPOC_GYRORAW main.cpp)
target_link_libraries(EPOC_GYRORAW ${XAVIERSDK_LIBRARIES})

