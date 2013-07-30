//
//  StringUtils.h
//  ofApp
//
//  Created by Ali Nakipoglu on 7/6/13.
//
//

#pragma once

#include <string>
#include <sstream>
#include <iomanip>

namespace gcode {
 
    class StringUtils
    {
        
    public:
        
        static std::string lSpaceStr( const std::string & value, const int spaceCount )
        {
            std::ostringstream stream;
            
            for ( int i = 0 ; i < spaceCount; ++i )
            {
                stream << " ";
            }
            
            stream << value;
            
            return stream.str();
        }
        
        static std::string rSpaceStr( const std::string & value, const int spaceCount )
        {
            std::ostringstream stream;
            
            stream << value;
            
            for ( int i = 0 ; i < spaceCount; ++i )
            {
                stream << " ";
            }
            
            return stream.str();
        }
        
        static std::string lrSpaceStr( const std::string & value, const int spaceCount )
        {
            std::ostringstream stream;
            
            for ( int i = 0 ; i < spaceCount; ++i )
            {
                stream << " ";
            }
            
            stream << value;
            
            for ( int i = 0 ; i < spaceCount; ++i )
            {
                stream << " ";
            }
            
            return stream.str();
        }
        
        template<typename T>
        static std::string toString(const T& value )
        {
            std::ostringstream stream;
            
            stream << value;
            
            return stream.str();
        }
        
        template<typename T>
        static std::string toString(const T& value, int precision)
        {
            std::ostringstream stream;
            
            stream << std::fixed << std::setprecision(precision) << value;
            
            return stream.str();
        }
    };
    
}
