//
// Created by root on 12/22/21.
//

#include "Api.hpp"
#include <utility>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace rs{

    Api::Api(const std::shared_ptr<sw::redis::Redis>& redis, std::optional<std::string> mQ) {
        this->connector = redis;
        this->response = std::nullopt;
        this->id = boost::uuids::random_generator_pure{}();
        this->mQ = std::move(mQ);
    }

    std::string Api::exchange(const nlohmann::json &j_obj) {
        this->connector->lpush( mQ.value(), j_obj.dump());

        this->response = std::nullopt;
        this->response = this->connector->brpop(boost::uuids::to_string(this->id));
        return this->response.value().second;
    }

    std::optional<std::string> Api::get_uuid() {
        return std::make_optional(boost::uuids::to_string(this->id));
    }

    std::optional<std::string> Api::get_mQ_name() {
        return this->mQ;
    }
}