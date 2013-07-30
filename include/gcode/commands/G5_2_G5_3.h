//
//  G5_2_G5_3.h
//  ofApp
//
//  Created by Ali Nakipoglu on 7/8/13.
//
//

#pragma once

#include <sstream>

#include <gcode/commands/ICommand.h>
#include <gcode/math/Vector.h>
#include <gcode/utils/StringUtils.h>
#include <gcode/Config.h>

namespace gcode {
    
    //////////////////////////////////////
    //////////COMMAND INTERFACE///////////
    //////////////////////////////////////
    
    class G5_2_G5_3: public ICommand
    {
        
    public:
        
        G5_2_G5_3( const std::vector<Vec2_F> & positions_, const std::vector<float> & weights_, const int degree_ )
        
        :positions( positions_ )
        ,weights( weights_ )
        ,degree( degree_ )
        
        {};
        
        ~G5_2_G5_3()
        {};
        
    public:
        
        virtual std::string getSource()
        {
            if( positions.size() > 0 && positions.size() == weights.size() )
            {
                std::ostringstream stream;
                
                stream  << "G5.2"
                        << StringUtils::lrSpaceStr( "X", GCODE_SPACES ) << StringUtils::toString( positions[0].x(), GCODE_FLOAT_PRECISION )
                        << StringUtils::lrSpaceStr( "Y", GCODE_SPACES ) << StringUtils::toString( positions[0].y(), GCODE_FLOAT_PRECISION )
                        << StringUtils::lrSpaceStr( "P", GCODE_SPACES ) << StringUtils::toString( weights[0], GCODE_FLOAT_PRECISION )
                        << StringUtils::lrSpaceStr( "L", GCODE_SPACES ) << StringUtils::toString( degree );
                
                for ( int i = 1; i < positions.size(); ++i )
                {
                    stream << std::endl;
                    
                    stream  << "     "
                    << StringUtils::rSpaceStr( "X", GCODE_SPACES ) << StringUtils::toString( positions[i].x(), GCODE_FLOAT_PRECISION )
                    << StringUtils::lrSpaceStr( "Y", GCODE_SPACES ) << StringUtils::toString( positions[i].y(), GCODE_FLOAT_PRECISION )
                    << StringUtils::lrSpaceStr( "P", GCODE_SPACES )<< StringUtils::toString( weights[i], GCODE_FLOAT_PRECISION );
                }
                
                stream << std::endl;
                
                stream << "G5.3";
                
                return stream.str();
            }
            
            return "";
        };
        
    private:
        
        std::vector<Vec2_F>     positions;
        std::vector<float>      weights;
        
        int                     degree;
    };
    
}