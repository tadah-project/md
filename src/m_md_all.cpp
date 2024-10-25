#include <tadah/core/registry.h>
#include <tadah/md/m_md_base.h>
#include <tadah/md/m_blr_md.h>
#include <tadah/md/m_krr_md.h>

template<> CONFIG::Registry<M_MD_Base,Function_Base&,Config&>::Map CONFIG::Registry<M_MD_Base,Function_Base&,Config&>::registry{};

CONFIG::Registry<M_MD_Base,Function_Base&,Config&>::Register<M_BLR_MD<>> M_BLR_MD_1("M_BLR");
CONFIG::Registry<M_MD_Base,Function_Base&,Config&>::Register<M_KRR_MD<>> M_KRR_MD_1("M_KRR");
