//
//  G53.h
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
    
    class G53: public ICommand
    {
        
    public:
        
        G53()
        {};
        
        ~G53()
        {};
        
    public:
        
        virtual std::string getSource()
        {
            return "G53";
        };
        
    };
    
}