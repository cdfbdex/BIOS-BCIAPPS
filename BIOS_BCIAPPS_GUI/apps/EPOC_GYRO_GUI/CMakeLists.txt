project(BIOS-BCI)

find_package(Qt4 COMPONENTS QtCore QtGui Phonon QtNetwork QtMultimedia QtOpenGL REQUIRED)
include(${QT_USE_FILE})

find_package(GLUT REQUIRED)

if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

include_directories(${GLUT_INCLUDE_DIRS})
include_directories(${GLUT_INCLUDE_DIR})
link_directories(${GLUT_LINK_DIRS})

find_package(XAVIERSDK REQUIRED)

if(NOT XAVIERSDK_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT XAVIERSDK_FOUND)

include_directories(${XAVIERSDK_INCLUDE_DIRS})
include_directories(${XAVIERSDK_INCLUDE_DIR})
link_directories(${XAVIERSDK_LINK_DIRS})


IF(WIN32)
	SET(QT_USE_MAIN true)
ENDIF(WIN32)


set(BCI_HEADERS BCI_mainWindow.h glwidget.h)
set(BCI_SOURCES BCI_mainWindow.cpp glwidget.cpp main.cpp BCI_setIcon.rc)
set(BCI_UIS BCI_mainWindow.ui)
set(BCI_RESOURCES qplayer.qrc)

qt4_wrap_cpp(BCI_MOC ${BCI_HEADERS})
qt4_wrap_ui(BCI_UIS_H ${BCI_UIS})
qt4_add_resources(BCI_RESOURCES_CPP ${BCI_RESOURCES})

include_directories(${CMAKE_CURRENT_BINARY_DIR})


add_executable(BCI_GUI ${BCI_SOURCES} ${BCI_MOC} ${BCI_UIS_H} ${BCI_RESOURCES_CPP})

IF(WIN32)
	target_link_libraries(BCI_GUI ${QT_LIBRARIES} ${GLUT_LIBRARIES} ${XAVIERSDK_LIBRARIES} ${QT_QTMAIN_LIBRARY})
ELSE()
	target_link_libraries(BCI_GUI ${QT_LIBRARIES} ${GLUT_LIBRARIES} ${XAVIERSDK_LIBRARIES})
ENDIF()


IF(WIN32) # Check if we are on Windows
 if(MSVC) # Check if we are using the Visual Studio compiler
   set_target_properties(BCI_GUI PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
 elseif(CMAKE_COMPILER_IS_GNUCXX)
   # SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows") # Not tested
 else()
   message(SEND_ERROR "You are using an unsupported Windows compiler! (Not MSVC or GCC)")
 endif()
elseif(UNIX)
 # Nothing special required
else()
 message(SEND_ERROR "You are on an unsupported platform! (Not Win32 or Unix)")
ENDIF()


install(TARGETS BCI_GUI RUNTIME DESTINATION bin COMPONENT Runtime BUNDLE DESTINATION . COMPONENT Runtime)