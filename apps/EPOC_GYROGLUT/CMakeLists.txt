find_package(GLUT REQUIRED)
find_package(XAVIERSDK REQUIRED)

if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

if(NOT XAVIERSDK_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT XAVIERSDK_FOUND)

include_directories(${GLUT_INCLUDE_DIRS})
include_directories(${GLUT_INCLUDE_DIR})
link_directories(${GLUT_LINK_DIRS})

include_directories(${XAVIERSDK_INCLUDE_DIRS})
include_directories(${XAVIERSDK_INCLUDE_DIR})
link_directories(${XAVIERSDK_LINK_DIRS})

add_executable(EPOC_GYROGLUT main.cpp)
target_link_libraries(EPOC_GYROGLUT ${GLUT_LIBRARIES} ${XAVIERSDK_LIBRARIES})

