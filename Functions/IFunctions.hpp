//
// Created by root on 1/17/22.
//

#ifndef RADIUS_SPECTRUMS_SOFTWARE_NEXT_IFUNCTIONS_HPP
#define RADIUS_SPECTRUMS_SOFTWARE_NEXT_IFUNCTIONS_HPP
#include "../ServiceResponse/ServiceResponse.hpp"

namespace rs
{
    class IFunctions
    {
    public:
        virtual void work(std::optional<ServiceResponse> &serv) = 0;
        virtual ~IFunctions() = 0;
    };

}

#endif //RADIUS_SPECTRUMS_SOFTWARE_NEXT_IFUNCTIONS_HPP
