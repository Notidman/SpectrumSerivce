#include <iostream>
#include "lib/rs.hpp"
#include <thread>
#include <chrono>

int main() {
    std::cout << "+-------------------------- Start --------------------------+" << std::endl;
    decltype(auto) connect{std::make_shared<sw::redis::ConnectionOptions>()};
    connect->host = "127.0.0.1";
    connect->port = 6379;
    //connect->password = "irz..475";
    decltype(auto) redis{std::make_shared<sw::redis::Redis>(*connect)};
    decltype(auto) base{std::make_shared<rs::Base>("First", redis)};
    decltype(auto) spec{std::make_shared<rs::Spectrum<float>>("First", redis)};

    __loop__ // while(1)
    {
        decltype(auto) request{base->listen()};
        if( request.has_value())
        {
            request->print_status("Request");
            base->execute_request(request);
            base->submit_reply();
        }
    };
}
