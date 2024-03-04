#ifndef M_MD_BASE_H
#define M_MD_BASE_H

#include "../CORE/normaliser_core.h"
#include "../CORE/core_types.h"
#include "../MODELS/functions/function_base.h"
#include "../MODELS/m_predict.h"

class M_MD_Base: public M_Predict {

    public:
        Normaliser_Core norm;    // TODO?
        virtual ~M_MD_Base() {};
};
// c++17 solution...
//template<> inline Registry<M_MD_Base,Function_Base&,Config&>::Map Registry<M_MD_Base,Function_Base&,Config&>::registry{};
#endif
