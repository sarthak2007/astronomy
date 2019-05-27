# Euclidean Coordinate

Astronomy is a field which often deals with mathematics and especially when we are talking about the observations geometry is used for keeping the data of the object's position.

In geometry Euclidean space has a really important part. It allows us to represent a points position of a vector. There are many different representations of it. (e.g: cartesian, cylindrical, spherical etc..)

All the representation classes use [boost::geometry::model::point](https://www.boost.org/doc/libs/1_67_0/libs/geometry/doc/html/geometry/reference/models/model_point.html) as their underlying classes to store the component data. These representation classes are only wrappers around boost.geometry. In the next version [boost::geometry::model::point](https://www.boost.org/doc/libs/1_67_0/libs/geometry/doc/html/geometry/reference/models/model_point.html) will not be used as an underlying storage for component as it does not support boost.units integration at this time. But APIs will not change and will still support [boost::geometry::model::point](https://www.boost.org/doc/libs/1_67_0/libs/geometry/doc/html/geometry/reference/models/model_point.html).

## Supported Representation in this libarary:
1. Cartesian Representation
2. Spherical Representation
3. Equatorial Representation

>**Note:** While using this library we insist you use Equatorial Representation only when you are using it for locations on earth with longitude and latitude.

To import all the representation class required header is as follows:

```c++
#include <boost/astronomy/coordinate/representation.hpp>
```

### Refrences:
* https://en.wikipedia.org/wiki/Coordinate_system
* https://en.wikipedia.org/wiki/Euclidean_space

[Privous](../index.md) | [next](coordinate_point.md)