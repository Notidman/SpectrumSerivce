#include <iostream>
#include "lib/rs.hpp"
#include <thread>
#include <chrono>

#define debug_mode 0

#if debug_mode

#endif

int main() {
    std::cout << "+-------------------------- Start --------------------------+" << std::endl;
    decltype(auto) connect{std::make_shared<sw::redis::ConnectionOptions>()};
    connect->host = "127.0.0.1";
    connect->port = 6379;
    //connect->password = "irz..475";
    decltype(auto) redis{std::make_shared<sw::redis::Redis>(*connect)};
    decltype(auto) base{std::make_shared<rs::Base>("First", redis)};
    decltype(auto) spec{std::make_shared<rs::Spectrum<float>>("First", redis)};

//-------------------------------------------------------------------------
#if debug_mode
    auto ws{[score = 1] (const char *str) mutable  {
        std::cout << "[" << score++ << "] wait 4 sec" << " | " << str << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(4));
    }};
#endif
//-------------------------------------------------------------------------

    __loop__
    {
//-------------------------------------------------------------------------
#if debug_mode
    ws("part1");
#endif
//-------------------------------------------------------------------------

        decltype(auto) request{base->listen()};
        if( request.has_value())
        {
            request->print_status("Request");
            base->execute_request(request);
            base->submit_reply();
        }

//-------------------------------------------------------------------------
#if debug_mode
    ws("part2");
#endif
//-------------------------------------------------------------------------


//-------------------------------------------------------------------------
#if debug_mode
    ws("part3");
#endif
//-------------------------------------------------------------------------
    };
}
