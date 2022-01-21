//
// Created by root on 1/17/22.
//

#ifndef RADIUS_SPECTRUMS_SOFTWARE_NEXT_GETSPECTRUM_HPP
#define RADIUS_SPECTRUMS_SOFTWARE_NEXT_GETSPECTRUM_HPP
#include "IFunctions.hpp"
#include "../ServiceResponse/ServiceResponse.hpp"

namespace rs {
    class GetSpectrum final : public IFunctions
    {
    public:
        void work(std::optional<ServiceResponse> &serv) override
        {
            serv->set_result() = "spec";
        }
    };
}

#endif //RADIUS_SPECTRUMS_SOFTWARE_NEXT_GETSPECTRUM_HPP
