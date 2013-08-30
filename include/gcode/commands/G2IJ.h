//
//  G2IJ.h
//  ofApp
//
//  Created by Ali Nakipoglu on 7/7/13.
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
    
    class G2IJ: public ICommand
    {
        
    public:
        
        G2IJ( const Vec2_F & center_, const Vec2_F & startPos_, const Vec2_B & enabledComponents_ )
        
        :center( center_ )
        ,startPos( startPos_ )
        ,enabledComponents( enabledComponents_ )
        
        {};
        
        ~G2IJ()
        {};
        
    public:
        
        virtual std::string getSource()
        {
            std::string result  = "G2";
            
            if( enabledComponents.x() )
            {
                result  += StringUtils::lrSpaceStr( "X", GCODE_SPACES ) + StringUtils::toString( startPos.x(), GCODE_FLOAT_PRECISION );
            }
            
            if( enabledComponents.y() )
            {
                result  += StringUtils::lrSpaceStr( "Y", GCODE_SPACES ) + StringUtils::toString( startPos.y(), GCODE_FLOAT_PRECISION );
            }
            
            if( enabledComponents.x() )
            {
                result  += StringUtils::lrSpaceStr( "I", GCODE_SPACES ) + StringUtils::toString( center.x(), GCODE_FLOAT_PRECISION );
            }
            
            if( enabledComponents.y() )
            {
                result  += StringUtils::lrSpaceStr( "J", GCODE_SPACES ) + StringUtils::toString( center.y(), GCODE_FLOAT_PRECISION );
            }
            
            return result;
        };
        
    private:
        
        Vec2_F  center;
        Vec2_F  startPos;
        Vec2_B  enabledComponents;
        
    };
    
    
    
}