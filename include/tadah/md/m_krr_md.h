#ifndef M_KRR_MD_H
#define M_KRR_MD_H

#include <tadah/md/m_md_base.h>
#include <tadah/core/config.h>
#include <tadah/core/normaliser_core.h>
#include <tadah/models/m_krr_core.h>
#include <tadah/models/functions/function_base.h>

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

        double epredict(const aed_type &aed) const {
            return M_KRR_Core<K>::kernel.epredict(M_KRR_Core<K>::weights,aed);
        };

        double fpredict(const fd_type &fdij, const aed_type &aedi, const size_t k) const {
            return M_KRR_Core<K>::kernel.fpredict(M_KRR_Core<K>::weights,fdij,aedi,k);
        }

        force_type fpredict(const fd_type &fdij, const aed_type &aedi) const {
            return M_KRR_Core<K>::kernel.fpredict(M_KRR_Core<K>::weights,fdij,aedi);
        }
};
#endif

