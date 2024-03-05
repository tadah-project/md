#include "catch2/catch.hpp"
#include "../../CORE/core_types.h"
#include "../m_md_base.h"

TEST_CASE( "Testing M_MD_Base Constructor 1", "[M_MD_Base()]" ) {
    M_MD_Dummy m;
}
TEST_CASE( "Testing M_MD_Base epredict", "[epredict]" ) {
    M_MD_Dummy m;
    aed_type2 a;
    REQUIRE(m.epredict(a)==0.0);
}
TEST_CASE( "Testing M_MD_Base fpredict", "[fpredict]" ) {
    // must be tested by external project which links MD and CORE
    //M_MD_Dummy m;
    //aed_type2 a;
    //fd_type fd; // cannot find symbol as it is in math.cpp so must link libtadah.core
    //REQUIRE(m.fpredict(fd,a,0)==0.0);
    //REQUIRE(m.fpredict(fd,a,1)==0.0);
    //REQUIRE(m.fpredict(fd,a,2)==0.0);
}
