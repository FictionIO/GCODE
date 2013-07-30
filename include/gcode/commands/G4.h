//
//  G4.h
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
    
    class G4: public ICommand
    {
        
    public:
        
        G4( const float value_ )
        
        :value( value_ )
        
        {};
        
        ~G4()
        {};
        
    public:
        
        virtual std::string getSource()
        {
            return StringUtils::rSpaceStr( "G4" , GCODE_SPACES ) + StringUtils::lrSpaceStr( "P", GCODE_SPACES ) + StringUtils::toString( value );
        };
        
    private:
        
        float value;
        
    };
    
}