#include <iostream>
#include <boost/astronomy/coordinate/cartesian_differential.hpp>
#include <boost/astronomy/coordinate/spherical_differential.hpp>
#include <boost/astronomy/coordinate/spherical_equatorial_differential.hpp>
// #include <boost/astronomy/coordinate/spherical_coslat_differential.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/core/cs.hpp>
#include <tuple>

#include<boost/units/io.hpp>
#include<boost/units/quantity.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/systems/cgs.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/angle/degrees.hpp>

#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/algorithms/transform.hpp>
#include <boost/geometry/core/cs.hpp>

#include <ex8.hpp>
// typedef boost::astronomy::coordinate::cartesian_representation cartesian;
// typedef boost::geometry::model::point<double, 3, boost::geometry::cs::spherical<boost::geometry::degree>> geometry_point;

int main()
{
    //creating point without any value
    // using namespace boost::units;
    using namespace boost::units::si;
    using namespace boost::units::us;
    using namespace boost::units;
    using namespace boost::astronomy::coordinate;
    using namespace boost::units::metric;
    using namespace boost::units::angle;
    using namespace std;
    quantity<degree_plane_angle> a1(10.0* degrees);
    quantity<plane_angle> b1(1.5* radians);
    quantity<velocity> c1(70.0* meters/seconds);

    auto motion5 = make_spherical_equatorial_differential(a1,b1,c1);
    auto motion7 = make_cartesian_differential(motion5);

    auto motion6 = make_spherical_differential
        <double,quantity<degree_plane_angle>,quantity<plane_angle>,quantity<velocity>>(motion7);

    std::cout  <<  motion6.get_dlat() << std::endl;
    std::cout  <<  motion6.get_dlon() << std::endl;
    std::cout  <<  motion6.get_ddist() << std::endl;
    std::cout << std::endl;
    return 0;
}