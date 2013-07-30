//
//  G5_1.h
//  ofApp
//
//  Created by Ali Nakipoglu on 7/8/13.
//
//

#pragma once

#include <gcode/commands/ICommand.h>
#include <gcode/math/Vector.h>
#include <gcode/utils/StringUtils.h>

namespace gcode {
    
    //////////////////////////////////////
    //////////COMMAND INTERFACE///////////
    //////////////////////////////////////
    
    class G5_1: public ICommand
    {
        
    public:
        
        G5_1( const Vec2_F & position_, Vec2_F & offset_ )
        
        :position( position_ )
        ,offset( offset_ )
        
        {};
        
        ~G5_1()
        {};
        
    public:
        
        virtual std::string getSource()
        {
            std::string result  = "G5.1";
            
            result      += StringUtils::lrSpaceStr( "X", GCODE_SPACES ) + StringUtils::toString( position.x() );
            result      += StringUtils::lrSpaceStr( "Y", GCODE_SPACES ) + StringUtils::toString( position.y() );
            result      += StringUtils::lrSpaceStr( "I", GCODE_SPACES ) + StringUtils::toString( offset.x() );
            result      += StringUtils::lrSpaceStr( "J", GCODE_SPACES ) + StringUtils::toString( offset.y() );
            
            return result;
        };
        
    private:
        
        Vec2_F  position;
        Vec2_F  offset;
    };
    
}