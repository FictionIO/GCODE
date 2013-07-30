//
//  ICommand.h
//  ofApp
//
//  Created by Ali Nakipoglu on 7/7/13.
//
//

#pragma once

#include <string>

namespace gcode {
 
    //////////////////////////////////////
    //////////COMMAND INTERFACE///////////
    //////////////////////////////////////
    
    class ICommand
    {
        
    public:
        
        ICommand()
        {
            
        };
        
        virtual ~ICommand()
        {};
        
    public:
        
        virtual std::string getSource()
        {
            return "";
        };
    };
}

