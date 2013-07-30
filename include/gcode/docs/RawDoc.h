//
//  RawDoc.h
//  ofApp
//
//  Created by Ali Nakipoglu on 7/8/13.
//
//

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>

#include <gcode/commands/ICommand.h>

#include <gcode/commands/G0.h>
#include <gcode/commands/G0Sequence.h>
#include <gcode/commands/G1.h>
#include <gcode/commands/G1_M14M4.h>
#include <gcode/commands/G1Sequence.h>
#include <gcode/commands/G1Sequence_M5M15.h>
#include <gcode/commands/G4.h>
#include <gcode/commands/G5_1.h>
#include <gcode/commands/G5_2_G5_3.h>

#include <gcode/commands/G17.h>
#include <gcode/commands/G18.h>
#include <gcode/commands/G19.h>

#include <gcode/commands/G17_1.h>
#include <gcode/commands/G18_1.h>
#include <gcode/commands/G19_1.h>

#include <gcode/commands/G20.h>
#include <gcode/commands/G21.h>

#include <gcode/commands/G28.h>
#include <gcode/commands/G29.h>

#include <gcode/commands/G40.h>
#include <gcode/commands/G41.h>
#include <gcode/commands/G42.h>

#include <gcode/commands/G43.h>

#include <gcode/commands/G49.h>

#include <gcode/commands/G53.h>

#include <gcode/commands/G80.h>

#include <gcode/commands/G90.h>
#include <gcode/commands/G91.h>

#include <gcode/commands/G93.h>
#include <gcode/commands/G94.h>
#include <gcode/commands/G95.h>

#include <gcode/commands/G98.h>
#include <gcode/commands/G99.h>

#include <gcode/commands/F.h>
#include <gcode/commands/S.h>

#include <gcode/commands/M2.h>
#include <gcode/commands/M4.h>
#include <gcode/commands/M5.h>
#include <gcode/commands/M14.h>
#include <gcode/commands/M15.h>
#include <gcode/commands/M30.h>

#include <gcode/commands/Comment.h>
#include <gcode/commands/Custom.h>

#include <gcode/math/Vector.h>
#include <gcode/utils/StringUtils.h>

#include <gcode/Config.h>

namespace gcode {
    
    //////////////////////////////////////
    ////////////RawDoc INTERFACE/////////////
    //////////////////////////////////////
    
    class RawDoc
    {
        
    public:
        
        RawDoc()
        {};
        
        ~RawDoc()
        {
            clear();
        };
        
    public:
        
        // Commands
        
        void g0( const Vec3_F & position_, const Vec3_B & enabledComponents_ )
        {
            commands.push_back( new G0( position_, enabledComponents_ ) );
        }
        
        void g0( const std::vector<Vec3_F> & positions_, const std::vector<Vec3_B> & enabledComponents_ )
        {
            commands.push_back( new G0Sequence( positions_, enabledComponents_ ) );
        }
        
        void g0( const std::vector<Vec3_F> & positions_, const Vec3_B & enabledComponents_ )
        {
            std::vector<Vec3_B> enabledComponentsVector;
            
            enabledComponentsVector.push_back( enabledComponents_ );
            
            commands.push_back( new G0Sequence( positions_, enabledComponentsVector ) );
        }
        
        void g1( const Vec3_F & position_, const Vec3_B & enabledComponents_ )
        {
            commands.push_back( new G1( position_, enabledComponents_ ) );
        }
        
        void g1M14M4( const Vec3_F & position_, const Vec3_B & enabledComponents_ )
        {
            commands.push_back( new G1_M14M4( position_, enabledComponents_ ) );
        }
        
        void g1( const std::vector<Vec3_F> & positions_, const std::vector<Vec3_B> & enabledComponents_ )
        {
            commands.push_back( new G1Sequence( positions_, enabledComponents_ ) );
        }
        
        void g1( const std::vector<Vec3_F> & positions_, const Vec3_B & enabledComponents_ )
        {
            std::vector<Vec3_B> enabledComponentsVector;
            
            enabledComponentsVector.push_back( enabledComponents_ );
            
            commands.push_back( new G1Sequence( positions_, enabledComponentsVector ) );
        }
        
        void g1M5M15( const std::vector<Vec3_F> & positions_, const std::vector<Vec3_B> & enabledComponents_ )
        {
            commands.push_back( new G1Sequence_M5M15( positions_, enabledComponents_ ) );
        }
        
        void g1M5M15( const std::vector<Vec3_F> & positions_, const Vec3_B & enabledComponents_ )
        {
            std::vector<Vec3_B> enabledComponentsVector;
            
            enabledComponentsVector.push_back( enabledComponents_ );
            
            commands.push_back( new G1Sequence_M5M15( positions_, enabledComponentsVector ) );
        }
        
        void g4( const float value_ )
        {
            commands.push_back( new G4( value_ ) );
        }
        
        void g5_1( const Vec2_F & position_, Vec2_F & offset_ )
        {
            commands.push_back( new G5_1( position_, offset_ ) );
        }
        
        void g5_2_G5_3( const std::vector<Vec2_F> & positions_, const std::vector<float> & weights_, const int degree_ )
        {
            commands.push_back( new G5_2_G5_3( positions_, weights_, degree_ ) );
        }
        
        void g17()
        {
            commands.push_back( new G17() );
        }
        
        void g18()
        {
            commands.push_back( new G18() );
        }
        
        void g19()
        {
            commands.push_back( new G19() );
        }
        
        void g17_1()
        {
            commands.push_back( new G17_1() );
        }
        
        void g18_1()
        {
            commands.push_back( new G18_1() );
        }
        
        void g19_1()
        {
            commands.push_back( new G19_1() );
        }
        
        void g20()
        {
            commands.push_back( new G20() );
        }
        
        void g21()
        {
            commands.push_back( new G21() );
        }
        
        void g28( const Vec3_F & position_, const Vec3_B & enabledComponents_ )
        {
            commands.push_back( new G28( position_, enabledComponents_ ) );
        }
        
        void g29( const Vec3_F & position_, const Vec3_B & enabledComponents_ )
        {
            commands.push_back( new G29( position_, enabledComponents_ ) );
        }
        
        void g40()
        {
            commands.push_back( new G40() );
        }
        
        void g41()
        {
            commands.push_back( new G41() );
        }
        
        void g42()
        {
            commands.push_back( new G42() );
        }
        
        void g43( int value )
        {
            commands.push_back( new G43( value ) );
        }
        
        void g49()
        {
            commands.push_back( new G49() );
        }
        
        void g53()
        {
            commands.push_back( new G53() );
        }
        
        void g80()
        {
            commands.push_back( new G80() );
        }
        
        void g90()
        {
            commands.push_back( new G90() );
        }
        
        void g91()
        {
            commands.push_back( new G91() );
        }
        
        void g93()
        {
            commands.push_back( new G93() );
        }
        
        void g94()
        {
            commands.push_back( new G94() );
        }
        
        void g95()
        {
            commands.push_back( new G95() );
        }
        
        void g98()
        {
            commands.push_back( new G98() );
        }
        
        void g99()
        {
            commands.push_back( new G99() );
        }
        
        void f( int value )
        {
            commands.push_back( new F( value ) );
        }
        
        void s( int value )
        {
            commands.push_back( new S( value ) );
        }
        
        void m2()
        {
            commands.push_back( new M2() );
        }
        
        void m4()
        {
            commands.push_back( new M4() );
        }
        
        void m5()
        {
            commands.push_back( new M5() );
        }
        
        void m14()
        {
            commands.push_back( new M14() );
        }
        
        void m15()
        {
            commands.push_back( new M15() );
        }
        
        void m30()
        {
            commands.push_back( new M30() );
        }
        
        void comment( const std::string & value )
        {
            commands.push_back( new gcode::Comment( value ) );
            
            lineNumbersDisabledCommands[ commands.back() ]  = true;
        }
        
        void custom( const std::string & value, bool disableLineNumbers = false )
        {
            commands.push_back( new Custom( value ) );
            
            if( disableLineNumbers )
            {
                lineNumbersDisabledCommands[ commands.back() ]  = true;

            }
        }
        
        // IO
        
        void save( const std::string & filePath, bool omitLineNumbers = false, bool omitStartAndEndSymbols = false )
        {
            std::ofstream       file;
            
            std::string         commandsSource  = getCommandsSource( omitLineNumbers );
            
            file.open( filePath.c_str() );
            
            if( !omitStartAndEndSymbols )
            {
                file << GCODE_FILE_START_SYMBOL << std::endl;
            }
            
            file << commandsSource;
            
            if( !omitStartAndEndSymbols )
            {
                file << GCODE_FILE_END_SYMBOL << std::endl;
            }
            
            file.close(); 
        }
        
        // Misc
        
        void clear()
        {
            for ( std::vector<ICommand*>::iterator it = commands.begin(); it != commands.end(); ++it )
            {
                delete *it;
            }
            
            commands.clear();
            lineNumbersDisabledCommands.clear();
        }
        
    private:
        
        std::string getCommandsSource( bool omitLineNumbers )
        {
            std::ostringstream stream;
            
            int lineNumber  = 1;
            
            for ( std::vector<ICommand *>::iterator it = commands.begin(); it != commands.end(); ++it )
            {
                std::string source  = (*it)->getSource();
                
                if( source.length() > 0 )
                {
                    if( !omitLineNumbers && lineNumbersDisabledCommands.count( (*it) ) == 0 )
                    {
                        insertLineNumbers( source, lineNumber );
                        stream << source;
                    } else {
                        stream << source << std::endl;
                    }
                }
            }
                        
            return stream.str();
        }
        
        void insertLineNumbers( std::string & str, int & index )
        {
            std::istringstream inputstream(str);
            std::ostringstream outputstream;
            
            for (std::string line; std::getline(inputstream, line); )
            {
                outputstream << "N" << StringUtils::toString( index ) << StringUtils::lSpaceStr( "", GCODE_SPACES ) << line << std::endl;
                
                ++index;
            }
            
            str = outputstream.str();
        }
        
    private:
       
        std::vector<ICommand *>     commands;
        std::map<ICommand *, bool>  lineNumbersDisabledCommands;
        
    };

}

