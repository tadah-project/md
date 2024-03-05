#include "m_md_base.h"
M_MD_Base::~M_MD_Base() {}
double M_MD_Dummy::epredict(const aed_type2 &aed) const
{ return 0.0; }
double M_MD_Dummy::fpredict(const fd_type &fdij, const aed_type2 &aedi, size_t k) const
{return 0.0; }
force_type M_MD_Dummy::fpredict(const fd_type &fdij,
        const aed_type2 &aedi) const 
{return force_type(); }
