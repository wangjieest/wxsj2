CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set(CMAKE_USER_MAKE_RULES_OVERRIDE
   ${CMAKE_CURRENT_SOURCE_DIR}/c_flag_overrides.cmake)
set(CMAKE_USER_MAKE_RULES_OVERRIDE_CXX
   ${CMAKE_CURRENT_SOURCE_DIR}/cxx_flag_overrides.cmake)

PROJECT (WXSJ2)

SET(TF_CURRENT_BINARY_PATH         ${PROJECT_BINARY_DIR}/build)
SET(TF_CURRENT_BINARY_PATH_BIN     ${TF_CURRENT_BINARY_PATH}/bin)
SET(TF_CURRENT_BINARY_PATH_DLL     ${TF_CURRENT_BINARY_PATH_BIN})
SET(TF_CURRENT_BINARY_PATH_LIB     ${TF_CURRENT_BINARY_PATH}/lib)

# SET(CMAKE_BUILD_TYPE Release)
MESSAGE(STATUS "CMAKE_BUILD_TYPE is " ${CMAKE_BUILD_TYPE})

INCLUDE_DIRECTORIES(ShareMemory)
ADD_SUBDIRECTORY(ShareMemory)

INCLUDE_DIRECTORIES(World)
ADD_SUBDIRECTORY(World)

INCLUDE_DIRECTORIES(Server)
ADD_SUBDIRECTORY(Server)

INCLUDE_DIRECTORIES(Billing)
ADD_SUBDIRECTORY(Billing)

INCLUDE_DIRECTORIES(Login)
ADD_SUBDIRECTORY(Login)