cmake_minimum_required(VERSION 3.18)
project(HotNCold
        CUDA
        CXX
)

set(CMAKE_CUDA_STANDARD 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
        ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
)


#--- FETCH Raylib ---
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES OFF CACHE BOOL "" FORCE) # don't build the supplied example games
FetchContent_Declare(
        raylib
        GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
        GIT_TAG "master"
        GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(raylib)
#--- END ---

# --- ADD PROJECT SOURCE ---
target_sources(${PROJECT_NAME}
        PRIVATE
        src/Grid.cpp
)
target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/include
)
# --- END ---

# --- ADD EXTERNAL LIBRARIES ---
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        raylib
)
# --- END ---

# --- SET ASSET_PATH ---
target_compile_definitions(${PROJECT_NAME}
        PUBLIC
        ASSETS_PATH="./assets"
)
# --- END ---


set_target_properties(HotNCold PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON
        LINKER_LANGUAGE CXX
)
