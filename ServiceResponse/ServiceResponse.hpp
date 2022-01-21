//
// Created by root on 1/16/22.
//

#ifndef RADIUS_SPECTRUMS_SOFTWARE_NEXT_SERVICERESPONSE_HPP
#define RADIUS_SPECTRUMS_SOFTWARE_NEXT_SERVICERESPONSE_HPP

#include <string>
#include <optional>
#include <iostream>
#include "nlohmann/json.hpp"

namespace rs {

    class ServiceResponse {
    private:
        std::optional<std::string> function_name = std::nullopt;
        std::optional<std::string> status_message = std::nullopt;
        int status_code = 0;
        std::optional<std::string> result = std::nullopt;
        std::string rQ;
    public:
        explicit ServiceResponse(const nlohmann::json &json);

        [[nodiscard]] std::string get_function_name() const
        { return function_name.value_or("null_name_function"); }

        [[nodiscard]] std::string get_status_message() const
        { return status_message.value_or("null_status_message"); }

        [[nodiscard]] int get_status_code() const
        { return status_code; }

        [[nodiscard]] std::string get_result() const
        { return result.value_or("null_result"); }

        [[nodiscard]] std::string get_rQ() const
        { return rQ; }

        [[nodiscard]]  std::optional<std::string>& set_result()
        { return this->result; }

        friend std::ostream& operator<<(std::ostream& out, const ServiceResponse &sR)
        {
            return out <<
            "Message queue: " << sR.get_rQ() << '\n' <<
            "Function name: " << sR.get_function_name() << '\n' <<
            "Status message: " << sR.get_status_message() << '\n' <<
            "Status code: " << sR.get_status_code() << '\n' <<
            "Result: " << sR.get_result() << '\n' <<
            "+-----------------------------------+";
        }

        void print_status(const char *str)
        {
            std::cout << 
            "+------------- " << str << " -------------+\n" <<
            *this << std::endl;
        }
    };

}
#endif //RADIUS_SPECTRUMS_SOFTWARE_NEXT_SERVICERESPONSE_HPP
