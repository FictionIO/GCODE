//
//  Vector.h
//  ofApp
//
//  Created by Ali Nakipoglu on 7/6/13.
//
//

#pragma once

namespace gcode {
    
    //////////////////////////////////////
    ////////BASE VECTOR INTERFACE/////////
    //////////////////////////////////////
    
    template<typename TypeT, int ComponentsT>
    class VecT
    {
        
    public:
        
        TypeT ptr[ComponentsT];
        
    public:
    
        VecT()
        {
            for (int i = 0; i < ComponentsT; ++i )
            {
                ptr[i]  = TypeT(0);
            }
        }
        
        VecT( const VecT<TypeT, ComponentsT> &other )
        {
            for (int i = 0; i < ComponentsT; ++i )
            {
                ptr[i]  = other[i];
            }
        };
        
        template<typename TypeT2, int ComponentsT2>
        VecT( const VecT<TypeT2, ComponentsT2> &other )
        {
            int min = ComponentsT < ComponentsT2 ? ComponentsT : ComponentsT2;
            
            for (int i = 0; i < min; ++i )
            {
                ptr[i]  = other[i];
            }
        };
        
        float & operator[]( int n )
        {
            return ptr[n];
        };
        
        
        float operator[]( int n ) const
        {
            return ptr[n];
        };
        
        
        VecT<TypeT, ComponentsT> operator+( const VecT<TypeT, ComponentsT> &other ) const
        {
            VecT<TypeT, ComponentsT> result;
            
            for (int i = 0; i < ComponentsT; ++i )
            {
                result[i]   += other.ptr[i];
            }
            
            return result;
        }
        
        
        VecT<TypeT, ComponentsT> & operator+=( const VecT<TypeT, ComponentsT> &other )
        {
            for (int i = 0; i < ComponentsT; ++i )
            {
                ptr[i]   += other.ptr[i];
            }
            
            return *this;
        }
        
        
        VecT<TypeT, ComponentsT> operator-( const VecT<TypeT, ComponentsT> &other ) const
        {
            VecT<TypeT, ComponentsT> result;
            
            for (int i = 0; i < ComponentsT; ++i )
            {
                result[i]   -= other.ptr[i];
            }
            
            return result;
        }
        
        
        VecT<TypeT, ComponentsT> & operator-=( const VecT<TypeT, ComponentsT> &other )
        {
            for (int i = 0; i < ComponentsT; ++i )
            {
                ptr[i]  -= other.ptr[i];
            }
            
            return *this;
        }
        
        
        VecT<TypeT, ComponentsT> operator*( const VecT<TypeT, ComponentsT> &other ) const
        {
            VecT<TypeT, ComponentsT> result;
            
            for (int i = 0; i < ComponentsT; ++i )
            {
                result[i]   *= other.ptr[i];
            }
            
            return result;
        }
        
        
        VecT<TypeT, ComponentsT> & operator*=( const VecT<TypeT, ComponentsT> &other )
        {
            for (int i = 0; i < ComponentsT; ++i )
            {
                ptr[i]  *= other.ptr[i];
            }
            
            return *this;
        }
        
        
        VecT<TypeT, ComponentsT> operator/( const VecT<TypeT, ComponentsT> &other ) const
        {
            VecT<TypeT, ComponentsT> result;
            
            for (int i = 0; i < ComponentsT; ++i )
            {
                if( other[i] != 0 )
                {
                    result[i]   /= other.ptr[i];
                };
            }
            
            return result;
        }
        
        
        VecT<TypeT, ComponentsT> & operator/=( const VecT<TypeT, ComponentsT> &other )
        {
            for (int i = 0; i < ComponentsT; ++i )
            {
                if( other[i] != 0 )
                {
                    ptr[i]   /= other.ptr[i];
                };
            }
            
            return *this;
        }
        
        
        VecT<TypeT, ComponentsT> operator-() const
        {
            VecT<TypeT, ComponentsT> result;
            
            for (int i = 0; i < ComponentsT; ++i )
            {
                result[i]   = -ptr[i];
            }
            
            return result;
        }
        
        
        
        VecT<TypeT, ComponentsT> operator+( const float value ) const
        {
            VecT<TypeT, ComponentsT> result;
            
            for (int i = 0; i < ComponentsT; ++i )
            {
                result[i]   = ptr[i] + value;
            }
            
            return result;
        }
        
        
        VecT<TypeT, ComponentsT> & operator+=( const float value )
        {
            for (int i = 0; i < ComponentsT; ++i )
            {
                ptr[i]  += value;
            }
            
            return *this;
        }
        
        
        VecT<TypeT, ComponentsT> operator-( const float value ) const
        {
            VecT<TypeT, ComponentsT> result;
            
            for (int i = 0; i < ComponentsT; ++i )
            {
                result[i]   = ptr[i] - value;
            }
            
            return result;
        }
        
        
        VecT<TypeT, ComponentsT> & operator-=( const float value )
        {
            for (int i = 0; i < ComponentsT; ++i )
            {
                ptr[i]  += value;
            }
            
            return *this;
        }
        
        
        VecT<TypeT, ComponentsT> operator*( const float value ) const
        {
            VecT<TypeT, ComponentsT> result;
            
            for (int i = 0; i < ComponentsT; ++i )
            {
                result[i]   = ptr[i] * value;
            }
            
            return result;
        }
        
        
        VecT<TypeT, ComponentsT> & operator*=( const float value )
        {
            for (int i = 0; i < ComponentsT; ++i )
            {
                ptr[i]  *= value;
            }
            
            return *this;
        }
        
        
        VecT<TypeT, ComponentsT> operator/( const float value ) const
        {
            VecT<TypeT, ComponentsT> result;
            
            if( value == 0 )
            {
                for (int i = 0; i < ComponentsT; ++i )
                {
                    result[i]   = ptr[i];
                }
            } else {
                for (int i = 0; i < ComponentsT; ++i )
                {
                    result[i]   = ptr[i] / value;
                }
            }
            
            return result;
        }
        
        
        VecT<TypeT, ComponentsT> & operator/=( const float value )
        {
            if( value == 0)
            {
                return *this;
            }
            
            for (int i = 0; i < ComponentsT; ++i )
            {
                ptr[i]  /= value;
            }
            
            return *this;
        }
    };
    
    //////////////////////////////////////
    ///////////SHORTCUT TYPES/////////////
    //////////////////////////////////////
    
    template<typename TypeT>
    class Vec2T: public VecT<TypeT, 2>
    {
        
    public:
        
        Vec2T()
        
        :VecT<TypeT, 2>()
        
        {
            x() = TypeT(0);
            y() = TypeT(0);
        };
        
        Vec2T( float value )
        
        :VecT<TypeT, 2>()
        
        {
            x() = TypeT(value);
            y() = TypeT(value);
        };
        
        Vec2T( float x_, float y_ )
        
        :VecT<TypeT, 2>()
        
        {
            x() = x_;
            y() = y_;
        };
        
        const TypeT & x() const
        {
            return VecT<TypeT, 2>::ptr[0];
        };
        
        const TypeT & y() const
        {
            return VecT<TypeT, 2>::ptr[1];
        };
        
        TypeT & x()
        {
            return VecT<TypeT, 2>::ptr[0];
        };
        
        TypeT & y()
        {
            return VecT<TypeT, 2>::ptr[1];
        };
    };
    
    template<typename TypeT>
    class Vec3T: public VecT<TypeT, 3>
    {
        
    public:
        
        Vec3T()
        
        :VecT<TypeT, 3>()
        
        {
            x() = TypeT(0);
            y() = TypeT(0);
            z() = TypeT(0);
        };
        
        Vec3T( float value )
        
        :VecT<TypeT, 3>()
        
        {
            x() = TypeT(value);
            y() = TypeT(value);
            z() = TypeT(value);
        };
        
        Vec3T( float x_, float y_, float z_ = 0.0f )
        
        :VecT<TypeT, 3>()
        
        {
            x() = x_;
            y() = y_;
            z() = z_;
        };
        
        const TypeT & x() const
        {
            return VecT<TypeT, 3>::ptr[0];
        };
        
        const TypeT & y() const
        {
            return VecT<TypeT, 3>::ptr[1];
        };
        
        const TypeT & z() const
        {
            return VecT<TypeT, 3>::ptr[2];
        };
        
        TypeT & x()
        {
            return VecT<TypeT, 3>::ptr[0];
        };
        
        TypeT & y()
        {
            return VecT<TypeT, 3>::ptr[1];
        };
        
        TypeT & z()
        {
            return VecT<TypeT, 3>::ptr[2];
        };
    };
    
    template<typename TypeT>
    class Vec4T: public VecT<TypeT, 4>
    {
        
    public:
        
        Vec4T()
        
        :VecT<TypeT, 4>()
        
        {
            x() = TypeT(0);
            y() = TypeT(0);
            z() = TypeT(0);
            w() = TypeT(0);
        };
        
        Vec4T( float value )
        
        :VecT<TypeT, 4>()
        
        {
            x() = TypeT(value);
            y() = TypeT(value);
            z() = TypeT(value);
            w() = TypeT(value);
        };
        
        Vec4T( float x_, float y_, float z_ = 0.0f, float w_ = 0.0f )
        
        :VecT<TypeT, 4>()
        
        {
            x() = x_;
            y() = y_;
            z() = z_;
            w() = w_;
        };
        
        const TypeT & x() const
        {
            return VecT<TypeT, 4>::ptr[0];
        };
        
        const TypeT & y() const
        {
            return VecT<TypeT, 4>::ptr[1];
        };
        
        const TypeT & z() const
        {
            return VecT<TypeT, 4>::ptr[2];
        };
        
        const TypeT & w() const
        {
            return VecT<TypeT, 4>::ptr[3];
        };
        
        TypeT & x()
        {
            return VecT<TypeT, 4>::ptr[0];
        };
        
        TypeT & y()
        {
            return VecT<TypeT, 4>::ptr[1];
        };
        
        TypeT & z()
        {
            return VecT<TypeT, 4>::ptr[2];
        };
        
        TypeT & w()
        {
            return VecT<TypeT, 4>::ptr[3];
        };
    };
    
    //////////////////////////////////////
    //////////////TYPEDEFS////////////////
    //////////////////////////////////////
    
    typedef Vec2T<bool>      Vec2_B;
    typedef Vec2T<int>       Vec2_I;
    typedef Vec2T<float>     Vec2_F;
    typedef Vec2T<double>    Vec2_D;
    
    typedef Vec3T<bool>      Vec3_B;
    typedef Vec3T<int>       Vec3_I;
    typedef Vec3T<float>     Vec3_F;
    typedef Vec3T<double>    Vec3_D;
    
    typedef Vec4T<bool>      Vec4_B;
    typedef Vec4T<int>       Vec4_I;
    typedef Vec4T<float>     Vec4_F;
    typedef Vec4T<double>    Vec4_D;
    
}


