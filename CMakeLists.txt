cmake_minimum_required(VERSION 3.28)
project(jsquick)

set(CMAKE_CXX_STANDARD 17)

add_executable(jsquick main.cpp
        color.hpp
        inquirer.h
        Log/Log.cpp
        Log/Log.h
        Input/Input.cpp
        Input/Input.h
        Create/Create.cpp
        Create/Create.h
        json.hpp
        json.hpp
        New/New.cpp
        New/New.h
        List/List.cpp
        List/List.h)
# Specify the source and destination directories
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/api)
set(DEST_DIR ${CMAKE_BINARY_DIR}/api)
set(SOURCE_DIR1 ${CMAKE_SOURCE_DIR}/react)
set(DEST_DIR1 ${CMAKE_BINARY_DIR}/react)
set(SOURCE_DIR3 ${CMAKE_SOURCE_DIR}/dbot)
set(DEST_DIR3 ${CMAKE_BINARY_DIR}/dbot)
set(CMAKE_EXE_LINKER_FLAGS "-static")

# Add a custom command to copy the entire directory after the target is built
add_custom_command(
        TARGET jsquick  # Use the created target name
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${DEST_DIR}  # Create destination directory if not exists
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${SOURCE_DIR} ${DEST_DIR}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${DEST_DIR1}  # Create destination directory if not exists
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${SOURCE_DIR1} ${DEST_DIR1}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${DEST_DIR3}  # Create destination directory if not exists
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${SOURCE_DIR3} ${DEST_DIR3}
)
install(TARGETS jsquick DESTINATION bin)
install(FILES
        color.hpp
        inquirer.h
        Log/Log.cpp
        Log/Log.h
        Input/Input.cpp
        Input/Input.h
        Create/Create.cpp
        Create/Create.h
        json.hpp
        json.hpp
        New/New.cpp
        New/New.h
        List/List.cpp
        List/List.h
        DESTINATION src
)
install(DIRECTORY ${CMAKE_BINARY_DIR}/api/ DESTINATION api/)
install(DIRECTORY ${CMAKE_BINARY_DIR}/dbot/ DESTINATION dbot/)
install(DIRECTORY ${CMAKE_BINARY_DIR}/react/ DESTINATION react/)

## CPack configuration
include(CPack)

set(CPACK_PACKAGE_NAME "jsquick")
set(CPACK_PACKAGE_VERSION "1.0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "jsquick - A CLI Program To Easily Generate NodeJS Projects")
set(CPACK_PACKAGE_VENDOR "George Tskitishvili")
set(CPACK_PACKAGE_CONTACT "contact@georgeckito.xyz")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "jsquick")
#
## Specify the type of installer you want to create
    set(CPACK_GENERATOR "NSIS")

#
## Additional NSIS configuration for Windows
if(WIN32)
    set(CPACK_NSIS_DISPLAY_NAME "${CPACK_PACKAGE_NAME} ${CPACK_PACKAGE_VERSION}")
    set(CPACK_NSIS_CONTACT "contact@georgeckito.xyz")
    set(CPACK_NSIS_MODIFY_PATH ON)
endif()