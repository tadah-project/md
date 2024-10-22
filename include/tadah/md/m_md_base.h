#ifndef M_MD_BASE_H
#define M_MD_BASE_H

#include <tadah/core/core_types.h>
#include <tadah/core/normaliser_core.h>
#include <tadah/models/functions/function_base.h>
#include <tadah/models/m_predict.h>

class M_MD_Base: public M_Predict {

    public:
        Normaliser_Core norm;    // TODO?
        virtual ~M_MD_Base();
};

struct M_MD_Dummy: public M_MD_Base {
    double epredict(const aed_type2 &) const;
    double fpredict(const fd_type &, const aed_type2 &, size_t ) const;
    force_type fpredict(const fd_type &,
            const aed_type2 &) const;
};
// c++17 solution...
//template<> inline Registry<M_MD_Base,Function_Base&,Config&>::Map Registry<M_MD_Base,Function_Base&,Config&>::registry{};
#endif
