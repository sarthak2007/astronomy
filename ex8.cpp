#include<iostream>
#include<boost/units/io.hpp>
#include<boost/units/quantity.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/systems/cgs.hpp>
#include <boost/units/systems/si.hpp>

#include <ex8.hpp>

int main(){
	using namespace boost::units;
	{
	using namespace boost::units::astronomical;
        
        quantity<light_year_length>            ly(1.0*light_years);
        quantity<parsec_length>                ps(1.0*parsecs);
        
        std::cout << ly << " = " << quantity<si::length>(ly) << std::endl
                  << ps << " = " << quantity<si::length>(ps) << std::endl
                  << std::endl;
   }
   {
   	using namespace boost::units::us;
   	    quantity<inch_length>            iml2(1.0*inchs);
        quantity<foot_length>            iml3(1.0*foots);
        std::cout << iml2 << " = " << quantity<si::length>(iml2) << std::endl
                  << iml3 << " = " << quantity<si::length>(iml3) << std::endl
                  << std::endl;        
   }
   {
   	using namespace boost::units::si;	
   		quantity<length> si1(3.5* meters);
   		quantity<length> si2(3* centi*meters);
   		quantity<length> si3(3* kilo*meters);


   		std::cout << si1 << " = " << quantity<si::length>(si1) << std::endl
   				  << si2 << " = " << quantity<si::length>(si2) << std::endl
   				  << si3 << " = " << quantity<si::length>(si3) << std::endl
   				  << std::endl;
   }
}
