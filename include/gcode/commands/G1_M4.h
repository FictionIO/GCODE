//
//  G1_M4.h
//  ofApp
//
//  Created by Ali Nakipoglu on 7/12/13.
//
//

#pragma once

#include <gcode/commands/ICommand.h>
#include <gcode/math/Vector.h>
#include <gcode/utils/StringUtils.h>
#include <gcode/Config.h>

namespace gcode {
    
    //////////////////////////////////////
    //////////COMMAND INTERFACE///////////
    //////////////////////////////////////
    
    class G1_M4: public ICommand
    {
        
    public:
        
        G1_M4( const Vec3_F & position_, const Vec3_B & enabledComponents_ )
        
        :position( position_ )
        ,enabledComponents( enabledComponents_ )
        
        {};
        
        ~G1_M4()
        {};
        
    public:
        
        virtual std::string getSource()
        {
            std::string result  = "G1";
            
            if( enabledComponents.x() )
            {
                result  += StringUtils::lrSpaceStr( "X", GCODE_SPACES ) + StringUtils::toString( position.x(), GCODE_FLOAT_PRECISION );
            }
            
            if( enabledComponents.y() )
            {
                result  += StringUtils::lrSpaceStr( "Y", GCODE_SPACES ) + StringUtils::toString( position.y(), GCODE_FLOAT_PRECISION );
            }
            
            if( enabledComponents.z() )
            {
                result  += StringUtils::lrSpaceStr( "Z", GCODE_SPACES ) + StringUtils::toString( position.z(), GCODE_FLOAT_PRECISION );
            }
            
            result      += StringUtils::lSpaceStr( "M4", GCODE_SPACES );
            
            return result;
        };
        
    private:
        
        Vec3_F  position;
        Vec3_B  enabledComponents;
        
    };
}