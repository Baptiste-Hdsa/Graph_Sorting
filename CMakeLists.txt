cmake_minimum_required(VERSION 3.28)
project(graphsorting C)
set(CMAKE_C_STANDARD 23)

find_package(SDL2 QUIET)
find_package(SDL2_image QUIET)
find_package(SDL2_mixer QUIET)
find_package(SDL2_ttf QUIET)

add_executable(graphsorting src/main.c
        src/sorting.c
        src/render.c
        src/utils.c
)

target_include_directories(graphsorting PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})


target_link_libraries(graphsorting PRIVATE SDL2::SDL2 SDL2_image::SDL2_image SDL2_mixer::SDL2_mixer SDL2_ttf::SDL2_ttf m)

