cmake_minimum_required(VERSION 3.16.3)

project(GameOfLife C)

set(SRC main.c)

include_directories(console)
include_directories(game)

link_directories(console)
link_directories(game)

add_subdirectory(console)
add_subdirectory(game)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries( ${PROJECT_NAME} console )
target_link_libraries( ${PROJECT_NAME} game )

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/libdraw.a)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/libgame.a)

add_custom_target(
    dist
    COMMAND "${CMAKE_COMMAND}" -E tar zcvf "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.tar.gz" -- ${_make_dist_sources}
    COMMENT "Make distribution ${PROJECT_NAME}.tar.gz"
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

add_custom_target( doc_doxygen ALL
COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
COMMENT "Generating API documentation with Doxygen"
VERBATIM )