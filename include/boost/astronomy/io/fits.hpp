#ifndef BOOST_ASTRONOMY_IO_FITS_HPP
#define BOOST_ASTRONOMY_IO_FITS_HPP

#include <fstream>
#include <string>
#include <vector>
#include <memory>

#include <boost/astronomy/io/primary_hdu.hpp>
#include <boost/astronomy/io/extension_hdu.hpp>
#include <boost/astronomy/io/image_extension.hpp>
#include <boost/astronomy/io/ascii_table.hpp>
#include <boost/astronomy/exception/fits_exception.hpp>
#include <iostream>

namespace boost
{
    namespace astronomy
    {
        namespace io
        {
            struct fits 
            {
            public:
                std::fstream fits_file; //!FITS to be processed
                std::vector<std::shared_ptr<hdu>> hdu_; //!Stores all th HDU in file

            public:
                fits() {}

                fits(std::string file_path, std::ios_base::openmode mode = std::ios_base::in | std::ios_base::binary)
                {
                    fits_file.open(file_path, std::ios_base::in | std::ios_base::binary | mode);
                    read_primary_hdu();
                    std::string line;
                    while (fits_file) { 
  
                        // Read a Line from File 
                        getline(fits_file, line); 
                  
                        // Print line in Console 
                        std::cout << line << std::endl; 
                    } 
                    // read_extensions();
                }

                void read_primary_hdu()
                {
                    hdu_.emplace_back(std::make_shared<hdu>(fits_file));
                    
                    switch (hdu_[0]->value_of<int>(std::string("BITPIX")))
                    {
                    case 8:
                        hdu_[0] = std::make_shared<primary_hdu<B8>>(fits_file, *hdu_[0]);
                        break;
                    case 16:
                        hdu_[0] = std::make_shared<primary_hdu<B16>>(fits_file, *hdu_[0]);
                        break;
                    case 32:
                        hdu_[0] = std::make_shared<primary_hdu<B32>>(fits_file, *hdu_[0]);
                        break;
                    case -32:
                        hdu_[0] = std::make_shared<primary_hdu<_B32>>(fits_file, *hdu_[0]);
                        break;
                    case -64:
                        hdu_[0] = std::make_shared<primary_hdu<_B64>>(fits_file, *hdu_[0]);
                        break;
                    default:
                        throw fits_exception();
                    }
                }

                void read_extensions()
                {
                    //if no extension then return
                    if (!hdu_[0]->value_of<bool>("EXTEND"))
                    {
                        return;
                    }

                    while (!fits_file.eof())
                    {
                        //this statement allows up to read all the cards stored
                        //It gives us the benefit of knowing which kind of data we need to store
                        hdu_.emplace_back(std::make_shared<hdu>(fits_file));

                        if (hdu_.back()->value_of<std::string>("XTENSION") == "'IMAGE   '")
                        {
                            switch (hdu_.back()->value_of<int>(std::string("BITPIX")))
                            {
                            case 8:
                                hdu_.back() = std::make_shared<image_extension<B8>>(fits_file, *hdu_.back());
                                break;
                            case 16:
                                hdu_.back() = std::make_shared<image_extension<B16>>(fits_file, *hdu_.back());
                                break;
                            case 32:
                                hdu_.back() = std::make_shared<image_extension<B32>>(fits_file, *hdu_.back());
                                break;
                            case -32:
                                hdu_.back() = std::make_shared<image_extension<_B32>>(fits_file, *hdu_.back());
                                break;
                            case -64:
                                hdu_.back() = std::make_shared<image_extension<_B64>>(fits_file, *hdu_.back());
                                break;
                            default:
                                throw fits_exception();
                                break;
                            }
                        }
                        else if (hdu_.back()->value_of<std::string>("XTENSION") == "'TABLE   '")
                        {
                            hdu_.back() = std::make_shared<ascii_table>(fits_file, *hdu_.back());
                        }
                        
                    }
                }
            };
        } //namespace io
    } //namespace astronomy
} //namespace boost

#endif // !BOOST_ASTRONOMY_IO_FITS_HPP

