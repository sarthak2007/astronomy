#ifndef BOOST_ASTRONOMY_IO_ASCII_TABLE_HPP
#define BOOST_ASTRONOMY_IO_ASCII_TABLE_HPP


#include <valarray>
#include <fstream>
#include <cstddef>
#include <algorithm>
#include <iterator>
#include <cstdint>
#include <string>
#include <cmath>
#include <numeric>

#include <boost/astronomy/io/bitpix.hpp>
#include <boost/astronomy/io/table_extension.hpp>
#include <boost/endian/conversion.hpp>
#include <boost/cstdfloat.hpp>


namespace boost
{
    namespace astronomy
    {
        namespace io
        {
            struct ascii_table : public boost::astronomy::io::table_extension
            {
            public:
                ascii_table() {}

                ascii_table(std::string const& file, hdu const& other, std::streamoff start) :
                    table_extension(this->naxis(1), this->naxis(2), this->cards[key_index["TFIELDS"]].value<std::size_t>())
                {
                    std::fstream ascii_table_file(file);
                    ascii_table_file.seekg(start);
                    read_ascii_table_logic(ascii_table_file);
                    ascii_table_file.close();
                }

                ascii_table(std::string const& file, hdu const& other) :
                    table_extension(this->naxis(1), this->naxis(2), this->cards[key_index["TFIELDS"]].value<std::size_t>())
                {
                    std::fstream ascii_table_file(file);
                    read_ascii_table_logic(ascii_table_file);
                    ascii_table_file.close();
                }

                ascii_table(std::fstream &file, hdu const& other, std::streamoff start) :
                    table_extension(this->naxis(1), this->naxis(2), this->cards[key_index["TFIELDS"]].value<std::size_t>())
                {
                    read_ascii_table(file, this->naxis(1), this->naxis(2), this->cards[key_index["TFIELDS"]].value<std::size_t>(), start);
                }

                ascii_table(std::fstream &file, hdu const& other) :
                    table_extension(this->naxis(1), this->naxis(2), this->cards[key_index["TFIELDS"]].value<std::size_t>())
                {
                    read_ascii_table(file, this->naxis(1), this->naxis(2), this->cards[key_index["TFIELDS"]].value<std::size_t>());
                }

                void read_ascii_table_logic(std::fstream &ascii_table_file)
                {
                    char tmp[height][width];
                    for (std::size_t i = 0; i < height; i++)
                    {
                        ascii_table_file.read((char*)tmp[i], width);
                    }

                    for (std::size_t i = 0; i < height; i++)
                    {
                        for (std::size_t j = 0; j < fields; j++)
                        {
                            std::size_t start = this->cards[key_index["TBCOL" + 
                                boost::lexical_cast<std::string>(j+1)]].value<std::size_t>(); //! stores the start position of field j+1
                            std::size_t w = 0, d = 0;          //! stores width and decimal
                            std::string w1 = "", d1 = "";     //! stores width and decimal in string format
                            std::string temp_data = "", tform = 
                                this->cards[key_index["TFORM" + boost::lexical_cast<std::string>(j+1)]].value<std::string>();
                            //! temp_data stores the string present in field (j+1) at height (i+1)

                            if(tform[0] == 'A' || tform[0] == 'I')
                            {
                                for (std::size_t k = 1; k < tform.length(); k++)
                                {
                                    if(tform[k] == ' ')
                                    {
                                        break;
                                    }
                                    w1 += tform[k];
                                }
                                w = std::stoi(w1);
                            }
                            else if(tform[0] == 'F' || tform[0] == 'E' || tform[0] == 'D')
                            {
                                std::size_t k = 1;
                                for (k = 1; k < tform.length(); k++)
                                {
                                    if(tform[k] == ' ' || tform[k] == '.')
                                    {
                                        break;
                                    }
                                    w1 += tform[k];
                                }
                                w = std::stoi(w1);

                                for (k = k + 1; k < tform.length(); k++)
                                {
                                    if(tform[k] == ' ')
                                    {
                                        break;
                                    }
                                    d1 += tform[k];
                                }

                                if(d1 != "")
                                {
                                    d = std::stoi(d1);
                                }
                            }

                            for (std::size_t k = start - 1; k < w + start - 1; k++)
                            {
                                temp_data += tmp[i][k];
                            }

                            data.insert({this->cards[key_index["TTYPE" + boost::lexical_cast<std::string>(j+1)]].value<std::string>(), temp_data});
                        }
                    }
                }

                void read_ascii_table(std::string const& file, std::size_t width, std::size_t height,
                    std::size_t fields, std::streamoff start)
                {
                    std::fstream ascii_table_file(file);
                    // data.resize(width*height);
                    ascii_table_file.seekg(start);

                    read_ascii_table_logic(ascii_table_file);
                    ascii_table_file.close();
                }

                void read_ascii_table(std::string const& file, std::size_t width, std::size_t height,
                    std::size_t fields)
                {
                    read_ascii_table(file, width, height, fields, 0);
                }

                void read_ascii_table(std::fstream &file, std::size_t width, std::size_t height, 
                    std::size_t fields, std::streamoff start)
                {
                    // data.resize(width*height);
                    file.seekg(start);

                    read_ascii_table_logic(file);
                }

                void read_ascii_table(std::fstream &file, std::size_t width, std::size_t height,
                    std::size_t fields)
                {
                    read_ascii_table(file, width, height, fields, file.tellg());
                }
            };

        } //namespace io
    } //namespace astronomy
} //namespace boost

#endif // !BOOST_ASTRONOMY_IO_ASCII_TABLE_HPP
