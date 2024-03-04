#include "../CORE/registry.h"
#include "m_md_base.h"
#include "m_blr_md.h"
#include "m_krr_md.h"

template<> Registry<M_MD_Base,Function_Base&,Config&>::Map Registry<M_MD_Base,Function_Base&,Config&>::registry{};

Registry<M_MD_Base,Function_Base&,Config&>::Register<M_BLR_MD<>> M_BLR_MD_1("M_BLR");
Registry<M_MD_Base,Function_Base&,Config&>::Register<M_KRR_MD<>> M_KRR_MD_1("M_KRR");
