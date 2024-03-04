#ifndef M_KRR_MD_H
#define M_KRR_MD_H

#include "m_md_base.h"
#include "../MODELS/m_krr_core.h"
#include "../CORE/config/config.h"
#include "../CORE/normaliser_core.h"
#include "../MODELS/functions/function_base.h"

#include <iostream>

template
<class K=Function_Base&>
class M_KRR_MD: private M_KRR_Core<K>, public M_MD_Base {

    public:
        M_KRR_MD(K &kernel, Config &c):
            M_KRR_Core<K>(kernel,c)
    {
        norm = Normaliser_Core(c);
    }
        M_KRR_MD(Config &c):
            M_KRR_Core<K>(c)
    {
        norm = Normaliser_Core(c);
    }

        double epredict(const aed_type2 &aed) const {
            return M_KRR_Core<K>::kernel.epredict(M_KRR_Core<K>::weights,aed);
        };

        double fpredict(const fd_type &fdij, const aed_type2 &aedi, const size_t k) const {
            return M_KRR_Core<K>::kernel.fpredict(M_KRR_Core<K>::weights,fdij,aedi,k);
        }

        force_type fpredict(const fd_type &fdij, const aed_type2 &aedi) const {
            return M_KRR_Core<K>::kernel.fpredict(M_KRR_Core<K>::weights,fdij,aedi);
        }
};
#endif

