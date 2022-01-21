//
// Created by root on 12/22/21.
//

#ifndef RADIUS_SPECTRUMS_SOFTWARE_NEXT_API_HPP
#define RADIUS_SPECTRUMS_SOFTWARE_NEXT_API_HPP
#include "../IApi/IApi.hpp"

namespace rs {

    class Api : public IApi {
    public:
        Api(const std::shared_ptr<sw::redis::Redis>& redis, std::optional<std::string> mQ);

        std::string exchange(const nlohmann::json &j_obj) override;

        [[nodiscard]] std::optional<std::string> get_uuid() override;
        [[nodiscard]] std::optional<std::string> get_mQ_name() override;

        ~Api() noexcept override = default;
    };
}

#endif //RADIUS_SPECTRUMS_SOFTWARE_NEXT_API_HPP
