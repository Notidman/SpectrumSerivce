//
// Created by root on 12/21/21.
//

#ifndef RADIUS_SPECTRUMS_SOFTWARE_NEXT_BASE_HPP
#define RADIUS_SPECTRUMS_SOFTWARE_NEXT_BASE_HPP
#include "../IBase/IBase.hpp"
#include "nlohmann/json.hpp"
#include "unordered_map"
#include "../Functions/GetSpectrum.hpp"
#include "../Functions/GetSpectrums.hpp"
#include "../Functions/GetWaveForm.hpp"
#include "../Functions/GetNoneFunc.hpp"

namespace rs {

    class Base : public IBase {
    public:
        Base(const std::string &queue_name, const std::shared_ptr<sw::redis::Redis> &redis);

        std::optional<ServiceResponse> listen() override;

        void submit_reply() override;

        void execute_request(std::optional<ServiceResponse> &request);

        [[nodiscard]] std::string get_mQ() const override;

        ~Base() noexcept override = default;

    };

    template<typename K, typename V>
    V get_value_map(const std::unordered_map<K,V>& map, const K& key)
    {
        decltype(auto) it{map.find(key)};
        if( it == map.cend()) { return std::make_shared<GetNoneFunc>(); }
        else { return it->second; }
    }
}

#endif //RADIUS_SPECTRUMS_SOFTWARE_NEXT_BASE_HPP
