//
//  G19_1.h
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
    
    class G19_1: public ICommand
    {
        
    public:
        
        G19_1()
        {};
        
        ~G19_1()
        {};
        
    public:
        
        virtual std::string getSource()
        {
            return "G19.1";
        };
        
    };
    
}