#ifndef M_BLR_MD_H
#define M_BLR_MD_H

#include <tadah/md/m_md_base.h>
#include <tadah/core/config.h>
#include <tadah/core/normaliser_core.h>
#include <tadah/models/m_blr_core.h>
#include <tadah/models/functions/function_base.h>

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

        double epredict(const aed_type &aed) const{
            return M_BLR_Core<BF>::bf.epredict(M_BLR_Core<BF>::weights,aed);
        };

        double fpredict(const fd_type &fdij, const aed_type &aedi, const size_t k) const {
            return M_BLR_Core<BF>::bf.fpredict(M_BLR_Core<BF>::weights,fdij,aedi,k);
        }

        force_type fpredict(const fd_type &fdij, const aed_type &aedi) const {
            return M_BLR_Core<BF>::bf.fpredict(M_BLR_Core<BF>::weights,fdij,aedi);
        }
};
#endif

