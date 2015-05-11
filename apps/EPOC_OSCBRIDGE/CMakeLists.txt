find_package(osc REQUIRED)

if(NOT osc_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT osc_FOUND)

include_directories(${OSC_INCLUDE_DIRS})
include_directories(${OSC_INCLUDE_DIR})

link_directories(${OSC_LINK_DIRS})


add_executable(EPOC_OSCBRIDGE main.cpp)

IF (WIN32)
	target_link_libraries(EPOC_OSCBRIDGE ${OSC_LIBRARIES} Ws2_32 winmm)
ELSE()
	target_link_libraries(EPOC_OSCBRIDGE ${OSC_LIBRARIES} )
ENDIF()

