cmake_minimum_required(VERSION 2.8)
project(BIOS_BCI)

# build options
#option(BUILD_EPOC_GYROGLUT "Build Epoc's Gyro and drawing in Glut Window" OFF)
#option(BUILD_EPOC_GYRORAW "Build Epoc's Gyro Raw Data and printing in Console" OFF)
#option(BUILD_EPOC_OSCBRIDGE "Build Epoc's bridge to Mind Your OSC program" OFF)

add_subdirectory(apps/EPOC_GYRO_GUI)

#if(BUILD_EPOC_GYROGLUT)
#	add_subdirectory(apps/EPOC_GYROGLUT)
#endif()

#if(BUILD_EPOC_GYRORAW)
#	add_subdirectory(apps/EPOC_GYRORAW)
#endif()

#if(BUILD_EPOC_OSCBRIDGE)
#	add_subdirectory(apps/EPOC_OSCBRIDGE)
#endif()

