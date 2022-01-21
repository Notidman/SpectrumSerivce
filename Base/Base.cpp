// Created by root on 12/21/21.
//

#include <iostream>
#include "thread"
#include "Base.hpp"
#include "../ServiceResponse/ServiceResponse.hpp"

namespace rs {

    Base::Base(const std::string &queue_name, const std::shared_ptr<sw::redis::Redis> &redis) {
        this->mQ = queue_name;
        this->request = std::nullopt;
        this->redis = redis;
    }

    std::optional<ServiceResponse> Base::listen() {
        decltype(auto) check{redis->lpop(this->mQ)};
        if(check.has_value())
        {
            request = std::make_optional(ServiceResponse(nlohmann::json::parse(check.value())));
            return request;
        }
        else
        {
            return std::nullopt;
        }
    }

    void Base::submit_reply()
    {
        request->print_status("Reply");

        redis->lpush(request->get_rQ(), nlohmann::json{
            {"function_name", request->get_function_name()},
            {"status_message", request->get_status_message()},
            {"status_code", request->get_status_code()},
            {"result", request->get_result()}
        }.dump());

        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << request->get_rQ() << " was be delete" << std::endl;
        redis->del(request->get_rQ());
    }

    std::unordered_map<std::string, std::shared_ptr<IFunctions>> list_funcs { 
    {
            {"get_spectrum", std::make_shared<GetSpectrum>()},
            {"get_spectrums", std::make_shared<GetSpectrums>()},
            {"get_waveform", std::make_shared<GetWaveForm>()},
            {"None", std::make_shared<GetNoneFunc>()}
    }};

    void Base::execute_request(std::optional<ServiceResponse> &request) {
        get_value_map(list_funcs, request->get_function_name())->work(request);
        this->request = request;
    }

    std::string Base::get_mQ() const {
        return mQ;
    }

}
