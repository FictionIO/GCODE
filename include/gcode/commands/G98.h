//
//  G98.h
//  ofApp
//
//  Created by Ali Nakipoglu on 7/10/13.
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
    
    class G98: public ICommand
    {
        
    public:
        
        G98()
        {};
        
        ~G98()
        {};
        
    public:
        
        virtual std::string getSource()
        {
            return "G98";
        };
        
    };    
    
}