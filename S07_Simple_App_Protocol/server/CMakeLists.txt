add_executable(server src/main.cc src/session.cc src/server.cc)
set_target_properties(server PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
target_compile_options(server PRIVATE -pthread -g)
target_link_libraries(server PRIVATE pthread)