//
// Created by root on 12/23/21.
//

#ifndef RADIUS_SPECTRUMS_SOFTWARE_NEXT_SPECTRUM_HPP
#define RADIUS_SPECTRUMS_SOFTWARE_NEXT_SPECTRUM_HPP
#include "../Api/Api.hpp"
#include <vector>

namespace rs {

    template<typename T>
    class Spectrum {
    private:
        std::unique_ptr<Api> api;
    public:
        Spectrum(const std::string& mQ, const std::shared_ptr<sw::redis::Redis>& redis) {
            this->api = std::make_unique<Api>(redis, std::make_optional<std::string>(mQ));
        }

        std::vector<T> get_spectrum(int index) {
            nlohmann::json jobj;
            jobj =
                    {
                            {"name", "get_spectrum"},
                            {"index", index},
                            {"id", this->api->get_uuid().value()}
                    };
            auto x = nlohmann::json(this->api->exchange(jobj))
                    .value("spectrum", std::vector<T>());

            return std::vector<T>(index);
        }
        std::vector<std::vector<T>> get_spectrums() {
            nlohmann::json jobj;
            jobj =
                    {
                            {"name", "get_spectrums"},
                            {"id", this->api->get_uuid().value()}
                    };
            return nlohmann::json(this->api->exchange(jobj))
                    .value("spectrums", std::vector<std::vector<T>>());
        }

        void get_waveform(int index) {
            nlohmann::json jobj;
            jobj =
                    {
                            {"name", "get_wavefrom"},
                            {"index", index},
                            {"id", this->api->get_uuid().value()}
                    };
        }

        ~Spectrum() = default;

    };

}

#endif //RADIUS_SPECTRUMS_SOFTWARE_NEXT_SPECTRUM_HPP
