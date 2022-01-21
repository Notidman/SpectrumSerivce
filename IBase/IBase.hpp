//
// Created by root on 12/21/21.
//

#ifndef RADIUS_SPECTRUMS_SOFTWARE_NEXT_IBASE_HPP
#define RADIUS_SPECTRUMS_SOFTWARE_NEXT_IBASE_HPP
#include "string"
#include "memory"
#include <sw/redis++/redis++.h>
#include <nlohmann/json.hpp>
#include "../ServiceResponse/ServiceResponse.hpp"
#include "../Functions/IFunctions.hpp"

namespace rs {

    class IBase {
    protected:
        std::string mQ; // Queue name
        std::optional<ServiceResponse> request; //  Request from api
        std::shared_ptr<sw::redis::Redis> redis; // pointer to radish
    public:
        // listening queue
        virtual std::optional<ServiceResponse> listen() = 0;

        // Sending a response to api
        virtual void submit_reply() = 0;

        [[nodiscard]] virtual std::string get_mQ() const = 0;

        virtual ~IBase() noexcept = default;
    };
}

#endif //RADIUS_SPECTRUMS_SOFTWARE_NEXT_IBASE_HPP
