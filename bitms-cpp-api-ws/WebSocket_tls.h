//
// Created by parallels on 9/30/18.
//

#ifndef BITMS_CPP_API_WS_WEBSOCKET_TLS_H
#define BITMS_CPP_API_WS_WEBSOCKET_TLS_H

#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/config/asio.hpp>
#include <websocketpp/client.hpp>

#include <iostream>

typedef websocketpp::client<websocketpp::config::asio_tls_client> clients;//differ from client
typedef websocketpp::lib::shared_ptr<boost::asio::ssl::context> context_ptr;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

class WebSocket_tls {
private:
    clients c;
    std::string hostname = "api.bitms.com/ws/v1";
    std::string uri = "wss://" + hostname ;
public:
    void static on_message( clients *c, websocketpp::connection_hdl hdl, clients::message_ptr msg ) {
        c->get_alog().write( websocketpp::log::alevel::message_payload,  msg->get_payload());
        //std::cout<<msg->get_payload<<std::endl;

        // close the connect to quit the loop
        // c->close( hdl, websocketpp::close::status::normal, "" );
    }
    void static on_open( clients *c, websocketpp::connection_hdl hdl ) {
        std::string msg1 = "{\"channel\":\"depth.btc2usd\"}";
        std::string msg2 = "{\"channel\":\"tickder.btc2usd\"}";
        std::string msg3 = "{\"channel\": \"trade.btc2usd\"}";
        std::string msg4 = "{\"channel\": \"kline.1m.btc2usd\"}";
        // send the message
        c->send( hdl, msg1, websocketpp::frame::opcode::text );
        c->get_alog().write( websocketpp::log::alevel::app,"Tx: " + msg1 );
        c->send( hdl, msg2, websocketpp::frame::opcode::text );
        c->get_alog().write( websocketpp::log::alevel::app, "Tx: " + msg2 );
        c->send( hdl, msg3, websocketpp::frame::opcode::text );
        c->get_alog().write( websocketpp::log::alevel::app,"Tx: " + msg3 );
        c->send( hdl, msg4, websocketpp::frame::opcode::text );
        c->get_alog().write( websocketpp::log::alevel::app, "Tx: " + msg4 );
    }

    void static on_fail( clients *c, websocketpp::connection_hdl hdl ) {
        c->get_alog().write( websocketpp::log::alevel::app, "Connection Failed" );
    }
    void static on_close( clients *c, websocketpp::connection_hdl hdl ) {
    }
/// TLS Initialization handler
/**
 * WebSocket++ core and the Asio Transport do not handle TLS context creation
 * and setup. This callback is provided so that the end user can set up their
 * TLS context using whatever settings make sense for their application.
 *
 * As Asio and OpenSSL do not provide great documentation for the very common
 * case of connect and actually perform basic verification of server certs this
 * example includes a basic implementation (using Asio and OpenSSL) of the
 * following reasonable default settings and verification steps:
 *
 * - Disable SSLv2 and SSLv3
 * - Load trusted CA certificates and verify the server cert is trusted.
 * - Verify that the hostname matches either the common name or one of the
 *   subject alternative names on the certificate.
 *
 * This is not meant to be an exhaustive reference implimentation of a perfect
 * TLS client, but rather a reasonable starting point for building a secure
 * TLS encrypted WebSocket client.
 *
 */
    context_ptr static on_tls_init( websocketpp::connection_hdl) {
        context_ptr ctx = websocketpp::lib::make_shared<boost::asio::ssl::context>(boost::asio::ssl::context::sslv23);

        try {
            ctx->set_options(boost::asio::ssl::context::default_workarounds |
                             boost::asio::ssl::context::no_sslv2 |
                             boost::asio::ssl::context::no_sslv3 |
                             boost::asio::ssl::context::single_dh_use);

        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        return ctx;
    }

    WebSocket_tls(){
        c.set_access_channels(websocketpp::log::alevel::all);
        c.clear_access_channels(websocketpp::log::alevel::frame_payload);
        c.set_error_channels(websocketpp::log::elevel::all);
        // Initialize ASIO
        c.init_asio();

        // Register handlers
        c.set_open_handler(std::bind(&on_open, &c, ::_1 ));
        c.set_message_handler( std::bind( &on_message, &c, ::_1, ::_2 ));
        c.set_fail_handler( std::bind( &on_fail, &c, ::_1 ));
        c.set_close_handler( std::bind( &on_close, &c, ::_1 ));
        c.set_tls_init_handler(bind(&on_tls_init, ::_1));
    }
    void start(){
        try{
            websocketpp::lib::error_code ec;
            clients::connection_ptr con = c.get_connection(uri, ec);
            if (ec) {
                std::cout << "could not create connection because: " << ec.message() << std::endl;
                return;
            }

            // Note that connect here only requests a connection. No network messages are
            // exchanged until the event loop starts running in the next line.
            c.connect(con);

            c.get_alog().write(websocketpp::log::alevel::app, "Connecting to " + uri);

            // Start the ASIO io_service run loop
            // this will cause a single connection to be made to the server. c.run()
            // will exit when this connection is closed.
            c.run();
        }catch (websocketpp::exception const & e) {
            std::cout << e.what() << std::endl;
        }
    }
    ~WebSocket_tls(){}
    void seturi(std::string uri){
        this->uri.clear();
        this->uri=uri;
    }

};


#endif //BITMS_CPP_API_WS_WEBSOCKET_TLS_H
