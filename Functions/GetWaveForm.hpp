//
// Created by root on 1/17/22.
//

#ifndef RADIUS_SPECTRUMS_SOFTWARE_NEXT_GETWAVEFORM_HPP
#define RADIUS_SPECTRUMS_SOFTWARE_NEXT_GETWAVEFORM_HPP
#include "IFunctions.hpp"
#include "../ServiceResponse/ServiceResponse.hpp"

namespace rs {
    class GetWaveForm final : public IFunctions
    {
    public:
        void work(std::optional<ServiceResponse> &serv) override
        {
            serv->set_result() = "form";
        }
    };
}

#endif //RADIUS_SPECTRUMS_SOFTWARE_NEXT_GETWAVEFORM_HPP
