//
// Created by root on 1/16/22.
//

#include "ServiceResponse.hpp"
#include "iostream"

namespace rs {
    ServiceResponse::ServiceResponse(const nlohmann::json &json) {
        function_name = json.value("name", "none_name");
        status_message = json.value("index", "none_index");
        status_code = 0;
        rQ = json.value("id", "none_id");
    }

}

