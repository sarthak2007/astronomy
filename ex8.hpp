#define BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(namespace_,unit_name_,dimension_)              \
namespace boost {                                                                            \
namespace units {                                                                            \
namespace namespace_ {                                                                       \
typedef make_system<unit_name_ ## _base_unit>::type    unit_name_ ## system_;                \
typedef unit<dimension_ ## _dimension,unit_name_ ## system_> unit_name_ ## _ ## dimension_;  \
static constexpr unit_name_ ## _ ## dimension_    unit_name_ ## s;                           \
}                                                                                            \
}                                                                                            \
}


#include <boost/units/base_units/astronomical/astronomical_unit.hpp>
#include <boost/units/base_units/astronomical/light_second.hpp>
#include <boost/units/base_units/astronomical/light_minute.hpp>
#include <boost/units/base_units/astronomical/light_hour.hpp>
#include <boost/units/base_units/astronomical/light_day.hpp>
#include <boost/units/base_units/astronomical/light_year.hpp>
#include <boost/units/base_units/astronomical/parsec.hpp>

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(astronomical,astronomical_unit,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(astronomical,light_second,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(astronomical,light_minute,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(astronomical,light_hour,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(astronomical,light_day,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(astronomical,light_year,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(astronomical,parsec,length)

#include <boost/units/base_units/us/mil.hpp>
#include <boost/units/base_units/us/inch.hpp>
#include <boost/units/base_units/us/foot.hpp>
#include <boost/units/base_units/us/yard.hpp>
#include <boost/units/base_units/us/mile.hpp>

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(us,mil,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(us,inch,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(us,foot,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(us,yard,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(us,mile,length)

#include <boost/units/base_units/imperial/thou.hpp>
#include <boost/units/base_units/imperial/inch.hpp>
#include <boost/units/base_units/imperial/foot.hpp>
#include <boost/units/base_units/imperial/yard.hpp>
#include <boost/units/base_units/imperial/furlong.hpp>
#include <boost/units/base_units/imperial/mile.hpp>
#include <boost/units/base_units/imperial/league.hpp>

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,thou,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,inch,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,foot,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,yard,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,furlong,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,mile,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,league,length)


#include <boost/units/base_units/metric/angstrom.hpp>
#include <boost/units/base_units/metric/fermi.hpp>
#include <boost/units/base_units/metric/micron.hpp>
#include <boost/units/base_units/metric/nautical_mile.hpp>

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,angstrom,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,fermi,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,micron,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,nautical_mile,length)