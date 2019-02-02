PROJECT(vsss-erus)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11 -pthread")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
find_package(PkgConfig)
INCLUDE(FindProtobuf)
FIND_PACKAGE(Protobuf REQUIRED)


file(GLOB_RECURSE SRCS_CPP src/*.cpp)
file(GLOB_RECURSE SRCS_CC src/*.cc)
file(GLOB_RECURSE INCLUDE src/*.h)
file(GLOB_RECURSE INCLUDE include/*.h)

set (VSS_CORE libvss-core.so)
link_directories(usr/lib)
include_directories(usr/local/include)

ADD_EXECUTABLE(vsss-erus ${SRCS_CPP} ${SRCS_CC} ${INCLUDE})

target_include_directories(vsss-erus PUBLIC ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(vsss-erus PUBLIC ${ZeroMQ_LIBRARY})

TARGET_LINK_LIBRARIES(vsss-erus ${VSS_CORE} ${PROTOBUF_LIBRARY})

INSTALL(TARGETS vsss-erus DESTINATION bin)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_NAME "vsss-erus")
SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "all")
SET(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

INCLUDE(CPack)
