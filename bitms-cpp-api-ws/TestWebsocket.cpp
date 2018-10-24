//
// Created by parallels on 9/30/18.
//
#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>
#include "WebSocket.h"
#include "WebSocket_tls.h"

BOOST_AUTO_TEST_SUITE(test_suite1)

    BOOST_AUTO_TEST_CASE(test_websocket)
    {
        WebSocket websocket;
        websocket.seturi("ws://192.168.31.41:8088/ws/v1");
        websocket.start();
    }

    BOOST_AUTO_TEST_CASE(test_websocket_tls)
    {
        WebSocket_tls websocket_tls;
        websocket_tls.seturi("wss://api.bitms.com/ws/v1");
        websocket_tls.start();
    }

BOOST_AUTO_TEST_SUITE_END()
