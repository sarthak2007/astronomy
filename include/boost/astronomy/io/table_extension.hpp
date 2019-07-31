#ifndef BOOST_ASTRONOMY_IO_TABLE_EXTENSION_HPP
#define BOOST_ASTRONOMY_IO_TABLE_EXTENSION_HPP

#include <string>
#include <vector>
#include <cstddef>
#include <valarray>
#include <map>

#include <boost/astronomy/io/hdu.hpp>
#include <boost/astronomy/io/extension_hdu.hpp>

namespace boost
{
    namespace astronomy
    {
        namespace io
        {
            struct table_extension : public boost::astronomy::io::extension_hdu
            {
            protected:
                std::multimap<std::string, std::string> data; //! stores the table data
                std::size_t width; //! width of table 
                std::size_t height; //! height of table
                std::size_t fields; //! fields in table
                // ascii_table<DataType> data;

            public:
                table_extension() {}

                table_extension(std::size_t width, std::size_t height, std::size_t fields)
                    : width(width), height(height), fields(fields)
                {
                    // this->data.resize(width*height);
                }
                // table_extension(std::fstream &file) : extension_hdu(file)
                // {
                //     data.read_ascii(file, this->naxis(1), this->naxis(2));
                //     set_unit_end(file);
                // }

                // table_extension(std::fstream &file, hdu const& other) : extension_hdu(file, other)
                // {
                //     data.read_ascii(file, this->naxis(1), this->naxis(2));
                //     set_unit_end(file);
                // }

                // table_extension(std::fstream &file, std::streampos pos) : extension_hdu(file, pos)
                // {
                //     data.read_ascii(file, this->naxis(1), this->naxis(2));
                //     set_unit_end(file);
                // }
            };
        } //namespace io
    } //namespace astronomy
} //namespace boost

#endif // !BOOST_ASTRONOMY_IO_TABLE_EXTENSION_HPP

