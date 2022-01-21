//
// Created by root on 1/17/22.
//

#ifndef RADIUS_SPECTRUMS_SOFTWARE_NEXT_GETSPECTRUMS_HPP
#define RADIUS_SPECTRUMS_SOFTWARE_NEXT_GETSPECTRUMS_HPP
#include "IFunctions.hpp"
#include "../ServiceResponse/ServiceResponse.hpp"

namespace rs {
    class GetSpectrums final : public IFunctions
    {
    public:
        void work(std::optional<ServiceResponse> &serv) override
        {
            serv->set_result() = "specs";
        }
    };
}

#endif //RADIUS_SPECTRUMS_SOFTWARE_NEXT_GETSPECTRUMS_HPP
