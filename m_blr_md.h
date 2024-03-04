#ifndef M_BLR_MD_H
#define M_BLR_MD_H

#include "m_md_base.h"
#include "../MODELS/m_blr_core.h"
#include "../CORE/config/config.h"
#include "../CORE/normaliser_core.h"
#include "../MODELS/functions/function_base.h"

#include <iostream>

template
<class BF=Function_Base&>
class M_BLR_MD: private M_BLR_Core<BF>, public M_MD_Base {

    public:
        M_BLR_MD(BF &bf, Config &c):
            M_BLR_Core<BF>(bf,c)
    {
        norm = Normaliser_Core(c);
    }
        M_BLR_MD(Config &c):
            M_BLR_Core<BF>(c)
    {
        norm = Normaliser_Core(c);
    }

        double epredict(const aed_type2 &aed) const{
            return M_BLR_Core<BF>::bf.epredict(M_BLR_Core<BF>::weights,aed);
        };

        double fpredict(const fd_type &fdij, const aed_type2 &aedi, const size_t k) const {
            return M_BLR_Core<BF>::bf.fpredict(M_BLR_Core<BF>::weights,fdij,aedi,k);
        }

        force_type fpredict(const fd_type &fdij, const aed_type2 &aedi) const {
            return M_BLR_Core<BF>::bf.fpredict(M_BLR_Core<BF>::weights,fdij,aedi);
        }
};
#endif

