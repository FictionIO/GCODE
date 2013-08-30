//
//  G1Sequence_M5_M5M15.h
//  ofApp
//
//  Created by Ali Nakipoglu on 7/12/13.
//
//

#pragma once

#include <vector>
#include <sstream>

#include <gcode/commands/ICommand.h>
#include <gcode/math/Vector.h>
#include <gcode/utils/StringUtils.h>
#include <gcode/Config.h>

#ifndef MIN

#define MIN( x, y ) ( x < y ? x : y )

#endif

namespace gcode {
    
    //////////////////////////////////////
    //////////COMMAND INTERFACE///////////
    //////////////////////////////////////
    
    class G1Sequence_M5: public ICommand
    {
        
    public:
        
        G1Sequence_M5( const std::vector<Vec3_F> & positions_, const std::vector<Vec3_B> & enabledComponents_ )
        
        :positions( positions_ )
        ,enabledComponents( enabledComponents_ )
        
        {};
        
        ~G1Sequence_M5()
        {};
        
    public:
        
        virtual std::string getSource()
        {
            if( positions.size() > 0 && enabledComponents.size() > 0 )
            {
                std::ostringstream stream;
                
                if( enabledComponents[0].x() )
                {
                    stream << StringUtils::lrSpaceStr( "X", GCODE_SPACES ) + StringUtils::toString( positions[0].x(), GCODE_FLOAT_PRECISION );
                }
                
                if( enabledComponents[0].y() )
                {
                    stream << StringUtils::lrSpaceStr( "Y", GCODE_SPACES ) + StringUtils::toString( positions[0].y(), GCODE_FLOAT_PRECISION );
                }
                
                if( enabledComponents[0].z() )
                {
                    stream << StringUtils::lrSpaceStr( "Z", GCODE_SPACES ) + StringUtils::toString( positions[0].z(), GCODE_FLOAT_PRECISION );
                }
                
                for ( int i = 1; i < positions.size(); ++i )
                {
                    stream << std::endl;
                    
                    if( enabledComponents[ MIN( i , enabledComponents.size() - 1 ) ].x() )
                    {
                        stream << StringUtils::rSpaceStr( "X", GCODE_SPACES ) + StringUtils::toString( positions[i].x(), GCODE_FLOAT_PRECISION );
                    }
                    
                    if( enabledComponents[ MIN( i , enabledComponents.size() - 1 ) ].y() )
                    {
                        stream << StringUtils::lrSpaceStr( "Y", GCODE_SPACES ) + StringUtils::toString( positions[i].y(), GCODE_FLOAT_PRECISION );
                    }
                    
                    if( enabledComponents[ MIN( i , enabledComponents.size() - 1 ) ].z() )
                    {
                        stream << StringUtils::lrSpaceStr( "Z", GCODE_SPACES ) + StringUtils::toString( positions[i].z(), GCODE_FLOAT_PRECISION );
                    }
                }
                
                stream << StringUtils::lSpaceStr( "M5", GCODE_SPACES );
                
                return stream.str();;
            }
            
            return "";
        };
        
        
    private:
        
        std::vector<Vec3_F>  positions;
        std::vector<Vec3_B>  enabledComponents;
        
    };
    
    
    
}