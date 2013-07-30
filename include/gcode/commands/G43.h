//
//  G43.h
//  ofApp
//
//  Created by Ali Nakipoglu on 7/8/13.
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
    
    class G43: public ICommand
    {
        
    public:
        
        G43( const int value_ )
        
        :value( value_ )
        
        {};
        
        ~G43()
        {};
        
    public:
        
        virtual std::string getSource()
        {
            return StringUtils::rSpaceStr( "G3" , GCODE_SPACES ) + StringUtils::lrSpaceStr( "H", GCODE_SPACES ) + StringUtils::toString( value );
        };
        
    private:
        
        int value;
        
    };
}