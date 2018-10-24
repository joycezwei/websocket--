//
// Created by parallels on 9/30/18.
//

#ifndef BITMS_CPP_API_WS_WEBSOCKET_H
#define BITMS_CPP_API_WS_WEBSOCKET_H

#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

#include <iostream>

typedef websocketpp::client<websocketpp::config::asio_client> client;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

class WebSocket {
private:
    std::string uri="";
    client c;
public:
    void static on_message( client *c, websocketpp::connection_hdl hdl, client::message_ptr msg ) {
        c->get_alog().write( websocketpp::log::alevel::message_payload,  msg->get_payload());
        // close the connect to quit the loop
        // c->close( hdl, websocketpp::close::status::normal, "" );
    }
    void static on_open( client *c, websocketpp::connection_hdl hdl ) {
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

    void static on_fail( client *c, websocketpp::connection_hdl hdl ) {
        c->get_alog().write( websocketpp::log::alevel::app, "Connection Failed" );
    }
    void static on_close( client *c, websocketpp::connection_hdl hdl ) {
    }
    WebSocket(){
        // Set logging to be pretty verbose (everything except message payloads)
        c.set_access_channels(websocketpp::log::alevel::all);
        c.clear_access_channels(websocketpp::log::alevel::frame_payload);
        c.set_error_channels(websocketpp::log::elevel::all);

        // Initialize ASIO
        c.init_asio();

        // Register our handlers
        c.set_open_handler(std::bind(&on_open, &c, ::_1 ));
        c.set_message_handler( std::bind( &on_message, &c, ::_1, ::_2 ));
        c.set_fail_handler( std::bind( &on_fail, &c, ::_1 ));
        c.set_close_handler( std::bind( &on_close, &c, ::_1 ));
    }
    ~WebSocket(){}
    void start(){
        try{
            websocketpp::lib::error_code ec;
            client::connection_ptr con = c.get_connection(uri, ec);
            if (ec) {
                std::cout << "could not create connection because: " << ec.message() << std::endl;
                return ;
            }

            // Note that connect here only requests a connection. No network messages are
            // exchanged until the event loop starts running in the next line.
            c.connect(con);

            // Start the ASIO io_service run loop
            // this will cause a single connection to be made to the server. c.run()
            // will exit when this connection is closed.
            c.run();
        } catch (websocketpp::exception const & e) {
            std::cout << e.what() << std::endl;
        }
    }
    void seturi(std::string uri){
        this->uri.clear();
        this->uri=uri;
    }
};


#endif //BITMS_CPP_API_WS_WEBSOCKET_H
