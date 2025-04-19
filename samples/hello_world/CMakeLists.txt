add_executable(hello_world main.cpp
)

target_link_libraries(hello_world PRIVATE no_name_engine)
target_include_directories(hello_world PRIVATE ${PROJECT_SOURCE_DIR}/no_name_engine)
