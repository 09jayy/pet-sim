add_executable(${PROJECT_NAME} main.cpp
        ../include/Pet.h
        ../include/Cat.h
        ../include/Dog.h
        Cat.cpp
        Dog.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
