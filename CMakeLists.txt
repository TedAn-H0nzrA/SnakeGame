cmake_minimum_required(VERSION 3.16)

set(CMAKE_BUILD_TYPE Debug)

project(Snake_Game)

# Répertoires
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_SOURCE_DIR}/inc)
set(FONTS_DIR ${CMAKE_SOURCE_DIR}/font)

# Où sera placé l'exécutable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)

# Fichiers sources
file(GLOB_RECURSE SOURCES
    "${SRC_DIR}/Entity/*.cpp"
    "${SRC_DIR}/Core/*.cpp"
    "${SRC_DIR}/Utils/*.cpp"
    "${SRC_DIR}/AI/*.cpp"
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# Création de l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_definitions(${PROJECT_NAME} PRIVATE
    FONTS_DIR="${FONTS_DIR}"
)

# Copie des assets dans le dossier de build
file(COPY ${FONTS_DIR} DESTINATION ${CMAKE_BINARY_DIR})

# Dossiers d'include
target_include_directories(${PROJECT_NAME} PRIVATE
    ${INC_DIR}/Core
    ${INC_DIR}/Entity
    ${INC_DIR}/Utils
    ${INC_DIR}/AI
)

# Lien avec SFML
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)