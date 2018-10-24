cmake_minimum_required(VERSION 3.10)
project(bitms-cpp-api-ws)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-pthread")
add_definitions(-D_WEBSOCKETPP_CPP11_FUNCTIONAL_)
add_definitions(-D_WEBSOCKETPP_CPP11_THREAD_)
add_definitions(-D_WEBSOCKETPP_CPP11_SYSTEM_ERROR_)
add_definitions(-D_WEBSOCKETPP_CPP11_MEMORY_)

include_directories(lib/websocket/include)

set(INC_DIR_OPENSSL lib/openssl/include)
set(LINK_DIR_OPENSSL lib/openssl/lib)
include_directories(${INC_DIR_OPENSSL})
link_directories(${LINK_DIR_OPENSSL})
link_libraries(ssl crypto)

set(INC_DIR_BOOST lib/boost/include)
set(LINK_DIR_OPENSSL lib/boost/lib)
include_directories(${INC_DIR_BOOST})
link_directories(${LINK_DIR_BOOST})
link_libraries(boost_system)

add_executable(bitms-cpp-api-ws
        WebSocket_tls.h
        WebSocket.h
        TestWebsocket.cpp)

target_link_libraries(bitms-cpp-api-ws boost_system)
target_link_libraries(bitms-cpp-api-ws ssl)