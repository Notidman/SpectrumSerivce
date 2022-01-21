//
// Created by root on 12/21/21.
//

#ifndef RADIUS_SPECTRUMS_SOFTWARE_NEXT_IAPI_HPP
#define RADIUS_SPECTRUMS_SOFTWARE_NEXT_IAPI_HPP
#include "sw/redis++/redis++.h"
#include "nlohmann/json.hpp"
#include <boost/uuid/uuid.hpp>
#include <string>

namespace rs {

    class IApi {
    protected:
        std::shared_ptr<sw::redis::Redis> connector;
        std::optional<std::pair<std::string, std::string>> response;
        boost::uuids::uuid id;
        std::optional<std::string> mQ;

    public:
        virtual std::string exchange(const nlohmann::json &j_obj) = 0;

        [[nodiscard]] virtual std::optional<std::string> get_uuid() = 0;

        [[nodiscard]] virtual std::optional<std::string> get_mQ_name() = 0;

        virtual ~IApi() = default;

    };

}

#endif //RADIUS_SPECTRUMS_SOFTWARE_NEXT_IAPI_HPP
