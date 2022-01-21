//
// Created by root on 1/19/22.
//

#ifndef RADIUS_SPECTRUMS_SOFTWARE_NEXT_GETNONEFUNC_H
#define RADIUS_SPECTRUMS_SOFTWARE_NEXT_GETNONEFUNC_H
#include "IFunctions.hpp"

namespace rs {
    class GetNoneFunc final : public IFunctions
    {
    public:
        void work(std::optional<ServiceResponse> &serv) override
        {
            serv->set_result() = "none_function";
        }
    };
}

#endif //RADIUS_SPECTRUMS_SOFTWARE_NEXT_GETNONEFUNC_H
