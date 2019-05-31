#include <iostream>
#include <boost/astronomy/coordinate/cartesian_representation.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/core/cs.hpp>
#include <tuple>

#include<boost/units/io.hpp>
#include<boost/units/quantity.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/systems/cgs.hpp>
#include <boost/units/systems/si.hpp>


// typedef boost::astronomy::coordinate::cartesian_representation cartesian;
typedef boost::geometry::model::point<double, 3, boost::geometry::cs::spherical<boost::geometry::degree>> geometry_point;

int main()
{
    //creating point without any value
    // using namespace boost::units;
    using namespace boost::units::si;
    using namespace boost::units::us;
    using namespace boost::units;
    using namespace boost::astronomy::coordinate;
    quantity<inch_length> si1(3.5* inchs);
    quantity<length> si2(3* centi*meters);
    quantity<length> si3(3* kilo*meters);
    cartesian_representation point1(si1,si2,si3);

    std::cout << "point1_x = " <<  point1.get_x<length>() << std::endl;

    std::cout << std::endl;

    quantity<length> si4(3* centi*meters);

    point1.set_x<length>(si4);

    std::cout << "point1_x = " <<  point1.get_x<length>() << std::endl;

    std::cout << std::endl;

    quantity<length> a(1*meters);
    quantity<foot_length> b(1*foots);
    quantity<length> c(150*centi*meters);
    point1.set_xyz(a,b,c);

    std::cout << "point1_x = " <<  point1.get_x<foot_length>() << std::endl;
    std::cout << "point1_y = " <<  point1.get_y<length>() << std::endl;
    std::cout << "point1_z = " <<  point1.get_z<length>() << std::endl;    

    std::cout << std::endl;

    // //creating a point from another point
    cartesian_representation point2(point1); //or point2 = point1

    std::cout << "point2_x = " <<  point2.get_x<length>() << std::endl;    

    std::cout << std::endl;

    //using tuple
    std::tuple<quantity<length>, quantity<foot_length>, quantity<length>> components = point2.get_xyz<length,foot_length,length>();

    std::cout << "x_tuple = " << std::get<0>(components) << std::endl;
    std::cout << "y_tuple = " << std::get<1>(components) << std::endl;
    std::cout << "z_tuple = " << std::get<2>(components) << std::endl;
    return 0;
}