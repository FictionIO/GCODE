//
//  F.h
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
    
    class F: public ICommand
    {
        
    public:
        
        F( const int value_ )
        
        :value( value_ )
        
        {};
        
        ~F()
        {};
        
    public:
        
        virtual std::string getSource()
        {
            return StringUtils::rSpaceStr( "F" , GCODE_SPACES) + StringUtils::toString( value );
        };
        
    private:
        
        int value;
        
    };
    
}