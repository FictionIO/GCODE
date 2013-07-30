//
//  G40.h
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
    
    class G40: public ICommand
    {
        
    public:
        
        G40()
        {};
        
        ~G40()
        {};
        
    public:
        
        virtual std::string getSource()
        {
            return "G40";
        };
        
    };
        
}