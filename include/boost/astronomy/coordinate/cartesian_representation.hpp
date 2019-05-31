#ifndef BOOST_ASTRONOMY_COORDINATE_CARTESIAN_REPRESENTATION_HPP
#define BOOST_ASTRONOMY_COORDINATE_CARTESIAN_REPRESENTATION_HPP


#include <tuple>

#include <boost/geometry/core/cs.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/algorithms/transform.hpp>
#include <boost/geometry/algorithms/equals.hpp>
#include <boost/static_assert.hpp>

#include <boost/astronomy/detail/is_base_template_of.hpp>
#include <boost/astronomy/coordinate/base_representation.hpp>
#include <boost/astronomy/coordinate/cartesian_differential.hpp>

#include <boost/units/io.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/systems/cgs.hpp>
#include <boost/units/systems/si.hpp>

#include <boost/astronomy/coordinate/ex8.hpp>


namespace boost
{
    namespace astronomy
    {
        namespace coordinate
        {
            //!Represents the coordinate in cartesian representation
            //!Uses three components to represent a point/vector (x, y, z)
            struct cartesian_representation : public boost::astronomy::coordinate::base_representation
                <3, boost::geometry::cs::cartesian>
            {
            public:
                //default constructoer no initialization
                cartesian_representation(){}

                //!constructs object from provided value of coordinates
                // using namespace boost::units;
                template <typename unit_x,typename unit_y,typename unit_z>
                cartesian_representation(boost::units::quantity<unit_x> x, boost::units::quantity<unit_y> y,boost::units::quantity<unit_z> z)
                {
                    boost::geometry::set<0>(this->point, boost::units::quantity<boost::units::si::length>(x).value());
                    boost::geometry::set<1>(this->point, boost::units::quantity<boost::units::si::length>(y).value());
                    boost::geometry::set<2>(this->point, boost::units::quantity<boost::units::si::length>(z).value());
                }

                //!constructs object from boost::geometry::model::point object
                template <std::size_t DimensionCount, typename System>
                cartesian_representation(boost::geometry::model::point<double, DimensionCount, System> const& pointObject)
                {
                    boost::geometry::transform(pointObject, this->point);

                }

                //copy constructor
                cartesian_representation(cartesian_representation const& object)
                {
                    this->point = object.get_point();
                }

                //!constructs object from any type of representation
                template <typename Representation>
                cartesian_representation(Representation const& other)
                {
                    BOOST_STATIC_ASSERT_MSG((boost::astronomy::detail::is_base_template_of
                        <boost::astronomy::coordinate::base_representation, Representation>::value),
                        "No constructor found with given argument type");

                    boost::geometry::transform(other.get_point(), this->point);
                }

                //! returns the (x, y, z) in the form of tuple
                template <typename unit_x,typename unit_y,typename unit_z>
                std::tuple<boost::units::quantity<unit_x>, boost::units::quantity<unit_y>,boost::units::quantity<unit_z>> get_xyz() const
                {
                    return std::make_tuple(boost::units::quantity<unit_x>(boost::geometry::get<0>(this->point)*boost::units::si::meters),
                        boost::units::quantity<unit_y>(boost::geometry::get<1>(this->point)*boost::units::si::meters), boost::units::quantity<unit_z>(boost::geometry::get<2>(this->point)*boost::units::si::meters));
                }

                //!returns the x component of point in desired units
                template <typename ReturnType>
                boost::units::quantity<ReturnType> get_x() const
                {
                    return boost::units::quantity<ReturnType>(boost::geometry::get<0>(this->point)*boost::units::si::meters);
                }

                //!returns the y component of point in desired units
                template <typename ReturnType>
                boost::units::quantity<ReturnType> get_y() const
                {
                    return boost::units::quantity<ReturnType>(boost::geometry::get<1>(this->point)*boost::units::si::meters);
                }

                //!returns the z component of point in desired units
                template <typename ReturnType>
                boost::units::quantity<ReturnType> get_z() const
                {
                    return boost::units::quantity<ReturnType>(boost::geometry::get<2>(this->point)*boost::units::si::meters);
                }

                //!set value of (x, y, z) in current object
                template <typename unit_x,typename unit_y,typename unit_z> 
                void set_xyz(boost::units::quantity<unit_x> x, boost::units::quantity<unit_y> y,boost::units::quantity<unit_z> z)
                {
                    boost::geometry::set<0>(this->point, boost::units::quantity<boost::units::si::length>(x).value());
                    boost::geometry::set<1>(this->point, boost::units::quantity<boost::units::si::length>(y).value());
                    boost::geometry::set<2>(this->point, boost::units::quantity<boost::units::si::length>(z).value());
                }

                //!set value of x component of point in desired units
                template <typename unit_x>
                void set_x(boost::units::quantity<unit_x> x)
                {
                    boost::geometry::set<0>(this->point, boost::units::quantity<boost::units::si::length>(x).value());
                }

                //!set value of y component of point in desired units
                template <typename unit_y>
                void set_y(boost::units::quantity<unit_y> y)
                {
                    boost::geometry::set<1>(this->point, boost::units::quantity<boost::units::si::length>(y).value());
                }

                //!set value of z component of point in desired units
                template <typename unit_z>
                void set_z(boost::units::quantity<unit_z> z)
                {
                    boost::geometry::set<2>(this->point, boost::units::quantity<boost::units::si::length>(z).value());
                }

                // boost::astronomy::coordinate::cartesian_representation 
                //     operator +(boost::astronomy::coordinate::cartesian_differential const& diff) const 
                // {
                //     boost::astronomy::coordinate::cartesian_representation temp(this->point);

                //     temp.set_x(temp.get_x() + diff.get_dx());
                //     temp.set_y(temp.get_y() + diff.get_dy());
                //     temp.set_z(temp.get_z() + diff.get_dz());

                //     return temp;
                // }

            }; //cartesian_representation
        } //namespace coordinate
    } //namespace astronomy
} //namespace boost

#endif // !BOOST_ASTRONOMY_COORDINATE_CARTESIAN_REPRESENTATION_HPP
