#ifndef SON8_OVERGLAD_HXX
#define SON8_OVERGLAD_HXX
// NOTE: Always check for compatibility profile
// \ as not defined SON8_OVERGLAD_CORE because
// \ there are also none profile (versions 1.1, 1.5, and 2.1)
#ifndef          SON8_OVERGLAD_DEFINED
#define          SON8_OVERGLAD_DEFINED
#define          SON8_OVERGLAD_INCLUDE
#define      SON8_OVERGLAD_VERSION_1_1
#define      SON8_OVERGLAD_VERSION_1_5
#define      SON8_OVERGLAD_VERSION_2_1
#define      SON8_OVERGLAD_VERSION_3_3
#define      SON8_OVERGLAD_VERSION_4_3
#define      SON8_OVERGLAD_VERSION_4_6
#define     SON8_OVERGLAD_PROFILE_CORE
#define SON8_OVERGLAD_VERSION 0x0406CEu
#endif                      // defined

#include <glad/son8/gl/source.h>

#ifdef SON8_OVERGLAD_INCLUDE_DEPRECATED
#include <glad/son8/gl/define.h>
#endif

// for v functions
#include <array>
// for info log and maybe string related calls
#include <cassert>
#include <cstring>
#include <string_view>

#include <type_traits>

namespace son8::overglad::field {

#ifdef SON8_OVERGLAD_VERSION_4_3
    // `MemoryBarrier`
    enum class Barrier : GLbitfield {
        Attrib      = 0x00000001,
        Element     = 0x00000002,
        Uniform     = 0x00000004,
        Fetch       = 0x00000008,
        Image       = 0x00000020,
        Command     = 0x00000040,
        Pixel       = 0x00000080,
        Texture     = 0x00000100,
        Buffer      = 0x00000200,
        Frame       = 0x00000400,
        Feedback    = 0x00000800,
        Counter     = 0x00001000,
        Storage     = 0x00002000,
        All         = 0xFFFFFFFF,
    }; // enum class `Barrier`
#endif // version 4.3
    // `Clear`
    enum class Clear : GLbitfield {
        Depth   = 0x00000100,
        Stencil = 0x00000400,
        Color   = 0x00004000,
#ifdef SON8_OVERGLAD_PROFILE_CORE
        All     = Depth | Stencil | Color,
#else
        Accum   = 0x00000200,
        All     = Depth | Accum | Stencil | Color,
#endif // core
    }; // enum class `Clear`

    constexpr Clear operator|( Clear a, Clear b ) noexcept
    { return static_cast< Clear >( static_cast< GLbitfield >( a ) | static_cast< GLbitfield >( b ) ); }

#ifndef SON8_OVERGLAD_PROFILE_CORE
    // `PushClientAttrib`
    enum class Client : GLbitfield {
        Pixel   = 0x00000001,
        Vertex  = 0x00000002,
        All     = 0xFFFFFFFF,
    };
#endif // not core

#ifndef SON8_OVERGLAD_PROFILE_CORE
    enum class Server : GLbitfield {
        Current     = 0x00000001,
        Point       = 0x00000002,
        Line        = 0x00000004,
        Polygon     = 0x00000008,
        Stipple     = 0x00000010,
        Pixel       = 0x00000020,
        Lightning   = 0x00000040,
        Fog         = 0x00000080,
        Depth       = 0x00000100,
        Accum       = 0x00000200,
        Stencil     = 0x00000400,
        Viewport    = 0x00000800,
        Transform   = 0x00001000,
        Enable      = 0x00002000,
        Color       = 0x00004000,
        Hint        = 0x00008000,
        Eval        = 0x00010000,
        List        = 0x00020000,
        Texture     = 0x00040000,
        Scissor     = 0x00080000,
#   ifdef SON8_OVERGLAD_VERSION_1_5
        Multisample = 0x20000000,
#   endif // version 1.5
        All         = 0xFFFFFFFF,
    }; // enum class `Server`
#endif // not core

} // namespace `son8::overglad::field`

namespace son8::overglad::enums {
#ifdef SON8_OVERGLAD_VERSION_1_5
    // `MapBuffer`
    enum class Access : GLenum {
        Read_Only   = 0x88B8,
        Write_Only  = 0x88B9,
        Read_Write  = 0x88BA,
    }; // enum class `Access`
#endif// version 1.5

    // Boolean
    enum class Boolean : GLboolean {
        False   = 0x0,
        True    = 0x1,
    }; // enum class `Boolean`
#ifdef SON8_OVERGLAD_VERSION_1_5
    enum class Buffer : GLenum {
        Array   = 0x8892,
        Element = 0x8893,
    }; // enum class `Buffer`
#endif // version 1.5
    // `Enable, Disable, IsEnabled`
    enum class Capability : GLenum {
        Polygon_Smooth          = 0x0B41,
        Cull_Face               = 0x0B44,
        Depth_Test              = 0x0B71,
        Stencil_Test            = 0x0B90,
        Blend                   = 0x0BE2,
        Color_Logic_Op          = 0x0BF2,
        Scissor_Test            = 0x0C11,
        Polygon_Offset_Point    = 0x2A01,
        Polygon_Offset_Line     = 0x2A02,
        Polygon_Offset_Fill     = 0x8037,
#ifdef SON8_OVERGLAD_VERSION_1_5
        Multisample             = 0x809D,
#endif // version 1.5
#ifndef SON8_OVERGLAD_PROFILE_CORE
        Point_Smooth            = 0x0B10,
        Fog                     = 0x0B60,
        Line_Stipple            = 0x0B24,
        Polygon_Stipple         = 0x0B42,
        Lighting                = 0x0B50,
        Color_Material          = 0x0B57,
        Normalize               = 0x0BA1,
        Alpha_Test              = 0x0BC0,
        Index_Logic_Op          = 0x0BF1,
        Texture_Gen_S           = 0x0C60,
        Texture_Gen_T           = 0x0C61,
        Texture_Gen_P           = 0x0C62,
        Texture_Gen_R           = 0x0C62,
        Texture_Gen_Q           = 0x0C63,
        Auto_Normal             = 0x0D80,
        Map_1_Color_4           = 0x0D90,
        Map_1_Index             = 0x0D91,
        Map_1_Normal            = 0x0D92,
        Map_1_Texture_Coord_1   = 0x0D93,
        Map_1_Texture_Coord_2   = 0x0D94,
        Map_1_Texture_Coord_3   = 0x0D95,
        Map_1_Texture_Coord_4   = 0x0D96,
        Map_1_Vertex_3          = 0x0D97,
        Map_1_Vertex_4          = 0x0D98,
        Map_2_Color_4           = 0x0DB0,
        Map_2_Index             = 0x0DB1,
        Map_2_Normal            = 0x0DB2,
        Map_2_Texture_Coord_1   = 0x0DB3,
        Map_2_Texture_Coord_2   = 0x0DB4,
        Map_2_Texture_Coord_3   = 0x0DB5,
        Map_2_Texture_Coord_4   = 0x0DB6,
        Map_2_Vertex_3          = 0x0DB7,
        Map_2_Vertex_4          = 0x0DB8,
        Texture_1D              = 0x0DE0,
        Texture_2D              = 0x0DE1,
        Clip_Plane_0            = 0x3000,
        Clip_Plane_1            = 0x3001,
        Clip_Plane_2            = 0x3002,
        Clip_Plane_3            = 0x3003,
        Clip_Plane_4            = 0x3004,
        Clip_Plane_5            = 0x3005,
        Light_0                 = 0x4000,
        Light_1                 = 0x4001,
        Light_2                 = 0x4002,
        Light_3                 = 0x4003,
        Light_4                 = 0x4004,
        Light_5                 = 0x4005,
        Light_6                 = 0x4006,
        Light_7                 = 0x4007,
        Vertex_Array            = 0x8074,
        Normal_Array            = 0x8075,
        Color_Array             = 0x8076,
        Index_Array             = 0x8077,
        Texture_Coord_Array     = 0x8078,
        Edge_Flag_Array         = 0x8079,
#endif// not core
    }; // enum class `Capability`

#ifdef SON8_OVERGLAD_VERSION_3_3
    // `Enablei, Disablei, IsEnabledi`
    enum class Capi : GLenum {
        Blend = 0x0BE2,
#   ifdef SON8_OVERGLAD_VERSION_4_3
        Scissor = 0x0C11,
#   endif // version 4.3
    }; // enum class `Capi`

    template< bool IsEnable >
    class Capi_ {
        struct Impl {
            Capi value;
        };
        Impl impl;
    public:
        static constexpr Capi_::Impl Blend{ Capi::Blend };
#   ifdef SON8_OVERGLAD_VERSION_4_3
        static constexpr Capi_::Impl Scissor{ Capi::Scissor };
#   endif
        constexpr Capi value( ) const noexcept { return impl.value; }
    };
    using Enablei = Capi_< true >;
    using Disablei = Capi_< false >;
#endif // version 3.3

    // `Hint`
    enum class Care : GLenum {
        Dont    = 0x1100,
        Fast    = 0x1101,
        Nice    = 0x1102,
    }; // enum class `Care`

#ifdef SON8_OVERGLAD_VERSION_3_3
    // ClampColor
    enum class Clamp : GLenum {
        False   = 0x0000,
        True    = 0x0001,
        Fixed   = 0x891D,
    }; // enum class `Clamp`
#   ifndef SON8_OVERGLAD_PROFILE_CORE
    enum class ClampColor : GLenum {
        Vertex      = 0x891A,
        Fragment    = 0x891B,
        Read        = 0x891C, // Only this target are available in core profile
    }; // enum class `ClampColor`
#   endif
#endif//SON8_OVERGLAD_VERSION_3_3

#ifndef SON8_OVERGLAD_PROFILE_CORE
    // `EnableClientState, DisableClientState`
    enum class ClientState : GLenum {
        Vertex  = 0x8074,
        Normal  = 0x8075,
        Color   = 0x8076,
        Index   = 0x8077,
        Texture = 0x8078,
        Edge    = 0x8079,
#   ifdef SON8_OVERGLAD_VERSION_1_5
        Fog     = 0x8457,
        Color2  = 0x845E,
#   endif // version 1.5
    }; // enum class ClientState
#endif// not core
    // `FrontFace`
    enum class Dir : GLenum {
        CW  = 0x0900,
        CCW = 0x0901,
    }; // enum class `Dir`
    // Begin
    enum class Draw : GLenum {
        Points          = 0x0000,
        Lines           = 0x0001,
        Lines_L         = 0x0002,
        Lines_S         = 0x0003,
        Default         = 0x0004,
        Triangles       = 0x0004,
        Triangles_S     = 0x0005,
        Triangles_F     = 0x0006,
#ifndef SON8_OVERGLAD_PROFILE_CORE
        Quads           = 0x0007,
        Quad_S          = 0x0008,
        Polygon         = 0x0009,
#endif // not core
#ifdef SON8_OVERGLAD_VERSION_3_3
        Lines_A         = 0x000A,
        Lines_SA        = 0x000B,
        Triangles_A     = 0x000C,
        Triangles_SA    = 0x000D,
#endif // version 3.3
#ifdef SON8_OVERGLAD_VERSION_4_3
        Patches         = 0x000E,
#endif // version 4.3
    }; // enum class Draw

#ifdef SON8_OVERGLAD_VERSION_1_5
    // `BlendEquation`
    enum class Equation : GLenum {
        Add         = 0x8006,
        Subtract    = 0x800A,
        Reverse     = 0x800B,
        Min         = 0x8007,
        Max         = 0x8008,
    }; // enum class Equation
#endif // version 1.5

    // `GetError`
    enum class Error : GLenum {
        No          = 0x0,
        Enum        = 0x0500,
        Value       = 0x0501,
        Operation   = 0x0502,
#if 0x0303CE != SON8_OVERGLAD_VERSION
        Overflow    = 0x0503,
        Underflow   = 0x0504,
#endif // not version 3.3 core
        Memory      = 0x0505,
#ifdef SON8_OVERGLAD_VERSION_4_3
        Framebuffer = 0x0506,
#endif // version 4.3
#ifdef SON8_OVERGLAD_VERSION_4_6
        Context     = 0x0507,
#endif // version 4.6
    }; // enum class Error
    // `CullFace, PolygonMode`
    enum class Face : GLenum {
        Front       = 0x0404,
        Back        = 0x0405,
        Front_Back  = 0x0408,
    }; // enum class `Face`
    // Func
    enum class Func : GLenum {
        Never       = 0x0200,
        Less        = 0x0201,
        Equal       = 0x0202,
        Lequal      = 0x0203,
        Greater     = 0x0204,
        Notequal    = 0x0205,
        Gequal      = 0x0206,
        Always      = 0x0207,
    }; // enum class `Func`
    // `Hint`
    enum class Hint : GLenum {
        Line        = 0x0C52,
        Polygon     = 0x0C53,
#ifdef SON8_OVERGLAD_VERSION_1_5
        Texture     = 0x84EF,
#endif // version 1.5
#ifdef SON8_OVERGLAD_VERSION_2_1
        Fragment    = 0x8B8B,
#endif // version 2.1
#ifndef SON8_OVERGLAD_PROFILE_CORE
        Perspective = 0x0C50,
        Point       = 0x0C51,
        Fog         = 0x0C54,
#   ifdef SON8_OVERGLAD_VERSION_1_5
        Mipmap      = 0x8192,
#   endif // version 1.5
#endif// not core
    }; // enum class Hint
#ifndef SON8_OVERGLAD_PROFILE_CORE
    // `MatrixMode`
    enum class Matrix : GLenum {
        Modelview   = 0x1700,
        Projection  = 0x1701,
        Texture     = 0x1702,
    }; // enum class `Matrix`
#endif//!CORE

#ifdef SON8_OVERGLAD_VERSION_1_5
    // `ActiveTexture,ClientActiveTexture,MultTexCoord`
    enum class Multi : GLenum {
        Texture_0   = 0x84C0,
        Texture_1   = 0x84C1,
        Texture_2   = 0x84C2,
        Texture_3   = 0x84C3,
        Texture_4   = 0x84C4,
        Texture_5   = 0x84C5,
        Texture_6   = 0x84C6,
        Texture_7   = 0x84C7,
        Texture_8   = 0x84C8,
        Texture_9   = 0x84C9,
        Texture_10  = 0x84CA,
        Texture_11  = 0x84CB,
        Texture_12  = 0x84CC,
        Texture_13  = 0x84CD,
        Texture_14  = 0x84CE,
        Texture_15  = 0x84CF,
        Texture_16  = 0x84D0,
        Texture_17  = 0x84D1,
        Texture_18  = 0x84D2,
        Texture_19  = 0x84D3,
        Texture_20  = 0x84D4,
        Texture_21  = 0x84D5,
        Texture_22  = 0x84D6,
        Texture_23  = 0x84D7,
        Texture_24  = 0x84D8,
        Texture_25  = 0x84D9,
        Texture_26  = 0x84DA,
        Texture_27  = 0x84DB,
        Texture_28  = 0x84DC,
        Texture_29  = 0x84DD,
        Texture_30  = 0x84DE,
        Texture_31  = 0x84DF,
    }; // enum class `Multi`
#endif // version 1.5

    // `LogicOp`
    enum class Op : GLenum {
        Clear           = 0x1500,
        And             = 0x1501,
        And_Reverse     = 0x1502,
        Copy            = 0x1503,
        And_Inverted    = 0x1504,
        Noop            = 0x1505,
        Xor             = 0x1506,
        Or              = 0x1507,
        Nor             = 0x1508,
        Equiv           = 0x1509,
        Invert          = 0x150A,
        Or_Reverse      = 0x150B,
        Copy_Inverted   = 0x150C,
        Or_Inverted     = 0x150D,
        Nand            = 0x150E,
        Set             = 0x150F,
    }; // enum class `Op`

#ifdef SON8_OVERGLAD_VERSION_3_3
    // `VertexAttribP*,VetexP*,TexCoordP*,NormalP*,ColorP*,SecondaryColorP*`
    enum class Packed : GLenum {
        Unsign  = 0x8368,
        Signed  = 0x8D9F,
    }; // enum class `Packed`
    // TODO rename function
    constexpr bool Packed_is_enum( GLenum packed ) noexcept
    {
        return packed == static_cast< GLenum >( Packed::Unsign )
            || packed == static_cast< GLenum >( Packed::Signed );
    }
#endif // version 3.3

#ifndef SON8_OVERGLAD_PROFILE_CORE
    // `ClipPlane`
    enum class Plane : GLenum {
        Num_0   = 0x3000,
        Num_1   = 0x3001,
        Num_2   = 0x3002,
        Num_3   = 0x3003,
        Num_4   = 0x3004,
        Num_5   = 0x3005,
    }; // enum class `Plane`
#endif//SON8_OVERGLAD_PROFILE_CORE

    // `PolygonMode`
    enum class Polygon : GLenum {
        Point   = 0x1B00,
        Line    = 0x1B01,
        Fill    = 0x1B02,
    }; // enum class `Polygon`

#ifdef SON8_OVERGLAD_VERSION_3_3
    // TODO: add what `gl` functions use this comment
    enum class Provoke : GLenum {
        First   = 0x8E4D,
        Last    = 0x8E4E,
    };
#endif // version 3.3

#ifndef SON8_OVERGLAD_PROFILE_CORE
    // `RenderMode`
    enum class Render : GLenum {
        Render      = 0x1C00,
        Feedback    = 0x1C01,
        Select      = 0x1C02,
    }; // enum class `Render`
#endif // not core

#ifdef SON8_OVERGLAD_VERSION_2_1
    // `CreateShader`
    enum class Shader : GLenum {
        Fragment    = 0x8B30,
        Vertex      = 0x8B31,
    }; // enum class `Shader`
#endif // version 2.1

#ifdef SON8_OVERGLAD_VERSION_1_5
    // `BufferData`
    // -- TODO: rename Dynamic to similar six character word
    enum class Usage : GLenum {
        Stream_Draw     = 0x88E0,
        Stream_Read     = 0x88E1,
        Stream_Copy     = 0x88E2,
        Static_Draw     = 0x88E4,
        Static_Read     = 0x88E5,
        Static_Copy     = 0x88E6,
        Dynamic_Draw    = 0x88E8,
        Dynamic_Read    = 0x88E9,
        Dynamic_Copy    = 0x88EA,
    }; // enum class `Usage`
#endif // version 1.5
} // namespace son8::overglad::enums
namespace son8::overglad::types {
    using View       = std::string_view;
    // `size 1`
    using Array1i    = std::array< GLint, 1 >;
    using Array1i64  = std::array< GLint64, 1 >;
    using Array1s    = std::array< GLshort, 1 >;
    using Array1f    = std::array< GLfloat, 1 >;
    using Array1d    = std::array< GLdouble, 1 >;
    using Array1ub   = std::array< GLubyte, 1 >;
    using Array1bool = std::array< GLboolean, 1 >;
    // `size 2`
    using Array2i    = std::array< GLint, 2 >;
    using Array2s    = std::array< GLshort, 2 >;
    using Array2f    = std::array< GLfloat, 2 >;

    using Array2d    = std::array< GLdouble, 2 >;
    // `size 3`
    using Array3i    = std::array< GLint, 3 >;
    using Array3b    = std::array< GLbyte, 3 >;
    using Array3s    = std::array< GLshort, 3 >;
    using Array3f    = std::array< GLfloat, 3 >;

    using Array3d    = std::array< GLdouble, 3 >;
    using Array3ui   = std::array< GLuint, 3 >;
    using Array3ub   = std::array< GLubyte, 3 >;
    using Array3us   = std::array< GLushort, 3 >;
    // `size 4`
    using Array4i    = std::array< GLint, 4 >;
    using Array4b    = std::array< GLbyte, 4 >;
    using Array4s    = std::array< GLshort, 4 >;
    using Array4f    = std::array< GLfloat, 4 >;
    using Array4d    = std::array< GLdouble, 4 >;
    using Array4ui   = std::array< GLuint, 4 >;
    using Array4ub   = std::array< GLubyte, 4 >;
    using Array4us   = std::array< GLushort, 4 >;
    using Array4bool = std::array< GLboolean, 4 >;
    // `size 16`
    using Array16f   = std::array< GLfloat, 16 >;
    using Array16d   = std::array< GLdouble, 16 >;
#ifndef SON8_OVERGLAD_PROFILE_CORE
    // deprecated renamed aliases
    // `size 1`
    using array1i    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLint, 1 >;
    using array1s    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLshort, 1 >;
    using array1f    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLfloat, 1 >;
    using array1d    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLdouble, 1 >;
    using array1ub   [[deprecated( "renamed to start with capital letter" )]] = std::array< GLubyte, 1 >;
    using array1bool [[deprecated( "renamed to start with capital letter" )]] = std::array< GLboolean, 1 >;
    // `size 2`
    using array2i    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLint, 2 >;
    using array2s    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLshort, 2 >;
    using array2f    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLfloat, 2 >;
    using array2d    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLdouble, 2 >;
    // `size 3`
    using array3i    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLint, 3 >;
    using array3b    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLbyte, 3 >;
    using array3s    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLshort, 3 >;
    using array3f    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLfloat, 3 >;
    using array3d    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLdouble, 3 >;
    using array3ui   [[deprecated( "renamed to start with capital letter" )]] = std::array< GLuint, 3 >;
    using array3ub   [[deprecated( "renamed to start with capital letter" )]] = std::array< GLubyte, 3 >;
    using array3us   [[deprecated( "renamed to start with capital letter" )]] = std::array< GLushort, 3 >;
    // `size 4`
    using array4i    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLint, 4 >;
    using array4b    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLbyte, 4 >;
    using array4s    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLshort, 4 >;
    using array4f    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLfloat, 4 >;
    using array4d    [[deprecated( "renamed to start with capital letter" )]] = std::array< GLdouble, 4 >;
    using array4ui   [[deprecated( "renamed to start with capital letter" )]] = std::array< GLuint, 4 >;
    using array4ub   [[deprecated( "renamed to start with capital letter" )]] = std::array< GLubyte, 4 >;
    using array4us   [[deprecated( "renamed to start with capital letter" )]] = std::array< GLushort, 4 >;
    // `size 16`
    using array16f   [[deprecated( "renamed to start with capital letter" )]] = std::array< GLfloat, 16 >;
    using array16d   [[deprecated( "renamed to start with capital letter" )]] = std::array< GLdouble, 16 >;
#   ifdef SON8_OVERGLAD_VERSION_3_3
    using Array1ui   = std::array< GLuint, 1 >;
    // deprecated renamed aliases
    using array1ui   [[deprecated( "renamed to start with capital letter" )]] = std::array< GLuint, 1 >;
#   endif // version 3.3
#endif// not core

    // object
    struct Object_ final {
        enum class Type : GLenum {
            None       = 0x0u,
            Texture_1D = 0x0DE0,
            Texture_2D = 0x0DE1,
#ifdef SON8_OVERGLAD_VERSION_1_5
            Buffer_Array = static_cast< GLenum >( enums::Buffer::Array ),
            Buffer_Element = static_cast< GLenum >( enums::Buffer::Element ),
#endif // version 1.5
#ifdef SON8_OVERGLAD_VERSION_3_3
            Vertex_Array,
#endif // version 3.3
#ifdef SON8_OVERGLAD_VERSION_4_3
            Program_Pipeline,
#endif // version 4.3
        };

        static constexpr auto is_texture( Type type ) noexcept {
            return type == Type::Texture_1D || type == Type::Texture_2D;
        }

        static constexpr auto is_buffer( Type type ) noexcept {
#ifdef SON8_OVERGLAD_VERSION_1_5
            return type == Type::Buffer_Array || type == Type::Buffer_Element;
#else
            return type == Type::None;
#endif
        } // is_buffer

        static constexpr auto is_vertex( Type type ) noexcept {
#ifdef SON8_OVERGLAD_VERSION_3_3
            return type == Type::Vertex_Array;
#else
            return type == Type::None;
#endif
        } // is_vertex

        static constexpr auto is_pipeline( Type type ) noexcept
        {
#ifdef SON8_OVERGLAD_VERSION_4_3
            return type == Type::Program_Pipeline;
#else
            return type == Type::None;
#endif
        } // is_pipeline

        static constexpr auto validate( Type type ) noexcept {
            return is_texture( type ) || is_buffer( type ) || is_vertex( type ) || is_pipeline( type );
        }
    }; // class `Object_`

    template< Object_::Type Type, bool Name = false >
    class Object final {
#ifndef SON8_OVERGLAD_VERSION_4_6
        static_assert( Name == false, "Named object only available from OpenGL 4.5" );
#endif
        GLuint index_;
    public:
        explicit Object( GLuint index = 0 ) : index_{ index } { }
        operator GLuint( ) const { return index_; }
        auto index( ) const { return index_; }
        auto data( ) -> GLuint * { return &index_; }
        constexpr auto type( ) const { return static_cast< GLenum >( Type ); }
        constexpr auto is_named( ) const noexcept { return Name; }
        void zero( ) { index_ = 0; }
    }; // class Object

    template< Object_::Type Type, bool Name = false >
    class Objects final {
        GLuint *data_;
        GLsizei size_;
    public:
        explicit Objects( GLsizei size ) : data_{ new GLuint[size] }, size_{ size } { zero( ); }
        ~Objects( ) { delete [] data_; }
        Objects( Objects && ) = delete;
        Objects( Objects const & ) = delete;
        Objects &operator=( Objects && ) = delete;
        Objects &operator=( Objects const & ) = delete;
        auto operator[]( GLsizei index ) const { return Object< Type, Name >{ data_[index] }; }
        auto data( ) -> GLuint * { return data_; }
        auto data( ) const -> GLuint const * { return data_; }
        auto size( ) const { return size_; }
        void zero( ) { for ( GLsizei i = 0u; i < size_; ++i ) data_[i] = 0; }
        constexpr auto type( ) const { return static_cast< GLenum >( Type ); }
        constexpr auto is_named( ) const noexcept { return Name; }
    }; // class `Objects`

    using Texture1D = Object< Object_::Type::Texture_1D >;
    using Texture2D = Object< Object_::Type::Texture_2D >;
    using Textures1D = Objects< Object_::Type::Texture_1D >;
    using Textures2D = Objects< Object_::Type::Texture_2D >;

#ifdef SON8_OVERGLAD_VERSION_1_5
    using BufferArray = Object< Object_::Type::Buffer_Array >;
    using BufferElement = Object< Object_::Type::Buffer_Element >;
    using BuffersArray = Objects< Object_::Type::Buffer_Array >;
    using BuffersElement = Objects< Object_::Type::Buffer_Element >;
#endif // version 1.5

#ifdef SON8_OVERGLAD_VERSION_3_3
    using VertexArray = Object< Object_::Type::Vertex_Array >;
    using VertexArrays = Objects< Object_::Type::Vertex_Array >;
#endif // version 3.3

#ifdef SON8_OVERGLAD_VERSION_4_3
    using ProgramPipeline = Object< Object_::Type::Program_Pipeline >;
    using ProgramPipelines = Objects< Object_::Type::Program_Pipeline >;
#endif // version 4.3
#ifdef SON8_OVERGLAD_VERSION_4_6
    using NamedTexture1D = Object< Object_::Type::Texture_1D, true >;
    using NamedTexture2D = Object< Object_::Type::Texture_2D, true >;
    using NamedBufferArray = Object< Object_::Type::Buffer_Array, true >;
    using NamedBufferElement = Object< Object_::Type::Buffer_Element, true >;
    using NamedVertexArray = Object< Object_::Type::Vertex_Array, true >;
    using NamedProgramPipeline = Object< Object_::Type::Program_Pipeline, true >;

    using NamedTextures1D = Objects< Object_::Type::Texture_1D, true >;
    using NamedTextures2D = Objects< Object_::Type::Texture_2D, true >;
    using NamedBuffersArray = Objects< Object_::Type::Buffer_Array, true >;
    using NamedBuffersElement = Objects< Object_::Type::Buffer_Element, true >;
    using NamedVertexArrays = Objects< Object_::Type::Vertex_Array, true >;
    using NamedProgramPipelines = Objects< Object_::Type::Program_Pipeline, true >;
#endif // version 4.6

#ifdef SON8_OVERGLAD_VERSION_2_1
    template< typename Type, unsigned Size = 0u, bool Norm = false >
    class Attrib final {
        static_assert( Size < 5, "Attrib Size must be less than 5" );
        GLuint index_;
    public:
        using type = Type;
        constexpr explicit Attrib( GLuint index = 0 ) : index_{ index } { };
        constexpr auto size( ) const noexcept { return Size; }
        constexpr bool norm( ) const noexcept { return Norm; }
        constexpr auto index( ) const noexcept { return index_; }
        static constexpr auto validate( ) {
            if constexpr ( Norm == false && Size <= 3 ) {
                return std::is_same_v< Type, GLshort >
                    || std::is_same_v< Type, GLfloat >
                    || std::is_same_v< Type, GLdouble >;
            } else if constexpr ( Norm == false && Size == 4 ) {
                return std::is_same_v< Type, GLbyte >
                    || std::is_same_v< Type, GLint >
                    || std::is_same_v< Type, GLshort >
                    || std::is_same_v< Type, GLfloat >
                    || std::is_same_v< Type, GLdouble >
                    || std::is_same_v< Type, GLubyte >
                    || std::is_same_v< Type, GLushort >
                    || std::is_same_v< Type, GLuint >;
            } else if constexpr ( Norm == true && Size == 4 ) {
                return std::is_same_v< Type, GLbyte >
                    || std::is_same_v< Type, GLint >
                    || std::is_same_v< Type, GLshort >
                    || std::is_same_v< Type, GLubyte >
                    || std::is_same_v< Type, GLushort >
                    || std::is_same_v< Type, GLuint >;
            }
            return false;
        };
    }; // class `Attrib`
    // `coord attribs`
    using Attrib0s      = Attrib< GLshort >;
    using Attrib0f      = Attrib< GLfloat >;
    using Attrib0d      = Attrib< GLdouble >;
    // `array attribs`
    using Attrib1s      = Attrib< GLshort, 1 >;
    using Attrib2s      = Attrib< GLshort, 2 >;
    using Attrib3s      = Attrib< GLshort, 3 >;
    using Attrib4s      = Attrib< GLshort, 4 >;
    using Attrib1f      = Attrib< GLfloat, 1 >;
    using Attrib2f      = Attrib< GLfloat, 2 >;
    using Attrib3f      = Attrib< GLfloat, 3 >;
    using Attrib4f      = Attrib< GLfloat, 4 >;
    using Attrib1d      = Attrib< GLdouble, 1 >;
    using Attrib2d      = Attrib< GLdouble, 2 >;
    using Attrib3d      = Attrib< GLdouble, 3 >;
    using Attrib4d      = Attrib< GLdouble, 4 >;
    using Attrib4b      = Attrib< GLbyte, 4 >;
    using Attrib4i      = Attrib< GLint, 4 >;
    using Attrib4ub     = Attrib< GLubyte, 4 >;
    using Attrib4us     = Attrib< GLushort, 4 >;
    using Attrib4ui     = Attrib< GLuint, 4 >;
    // `coord attribs normalized`
    using Attrib0Nub    = Attrib< GLubyte, 0, true >;
    // `array attribs normalized`
    using Attrib4Ni     = Attrib< GLint, 4, true >;
    using Attrib4Nb     = Attrib< GLbyte, 4, true >;
    using Attrib4Ns     = Attrib< GLshort, 4, true >;
    using Attrib4Nui    = Attrib< GLuint, 4, true >;
    using Attrib4Nub    = Attrib< GLubyte, 4, true >;
    using Attrib4Nus    = Attrib< GLushort, 4, true >;
    // deprecated (renamed)
    // `coord attribs`
    using attrib0s   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLshort >;
    using attrib0f   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLfloat >;
    using attrib0d   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLdouble >;
    // `array attribs`
    using attrib1s   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLshort, 1 >;
    using attrib2s   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLshort, 2 >;
    using attrib3s   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLshort, 3 >;
    using attrib4s   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLshort, 4 >;
    using attrib1f   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLfloat, 1 >;
    using attrib2f   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLfloat, 2 >;
    using attrib3f   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLfloat, 3 >;
    using attrib4f   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLfloat, 4 >;
    using attrib1d   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLdouble, 1 >;
    using attrib2d   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLdouble, 2 >;
    using attrib3d   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLdouble, 3 >;
    using attrib4d   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLdouble, 4 >;
    using attrib4b   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLbyte, 4 >;
    using attrib4i   [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLint, 4 >;
    using attrib4ub  [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLubyte, 4 >;
    using attrib4us  [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLushort, 4 >;
    using attrib4ui  [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLuint, 4 >;
    // `coord attribs normalized`
    using attrib0Nub [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLubyte, 0, true >;
    // `array attribs normalized`
    using attrib4Ni  [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLint, 4, true >;
    using attrib4Nb  [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLbyte, 4, true >;
    using attrib4Ns  [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLshort, 4, true >;
    using attrib4Nui [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLuint, 4, true >;
    using attrib4Nub [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLubyte, 4, true >;
    using attrib4Nus [[deprecated( "renamed to start with capital letter" )]] = Attrib< GLushort, 4, true >;

    class Shader final {
        GLuint index_;
    public:
        explicit Shader( GLuint index = 0 ) : index_{ index } { };
        operator GLuint( ) const noexcept { return index_; }
        auto index( ) const noexcept { return index_; }
    }; // class `Shader`

    class Program final {
        GLuint index_;
    public:
        explicit Program( GLuint index = 0 ) : index_{ index } { };
        operator GLuint( ) const noexcept { return index_; }
        auto index( ) const noexcept { return index_; }
    }; // class `Program`

    using Source = std::string_view;
    // Possibly just a temporary solution to simplify querying info logs
    template< unsigned Capacity = 1u << 10u >
    class Info final {
        static_assert( 1u << 6 <= Capacity and Capacity <= 1u << 13u
            , "son8::overglad: Info Capacity required to be in range [ 64 ; 8'192 ]" );
        using View_ = std::string_view;
        using Size_ = decltype( Capacity );
        using Char_ = GLchar;
        Char_ buffer_[Capacity] = { };
        Size_ cursor_{ };
        auto last_Index( ) const noexcept { return Capacity - 1u; }
        auto cursor_Size( ) const noexcept { return cursor_ + 1u; }
        auto commit_Unchecked( Size_ written ) {
            cursor_ += written;
            buffer_[cursor_] = '\0';
        }
    public:
        Info( ) = default;
        Info( Info const &copy ) noexcept : cursor_{ copy.cursor_ } {
            std::memcpy( buffer_, copy.buffer_, cursor_Size( ));
        }
        auto operator=( Info const &copy ) noexcept -> Info & {
            if ( this != &copy ) {
                cursor_ = copy.cursor_;
                std::memcpy( buffer_, copy.buffer_, cursor_Size( ));
            }

            return *this;
        }
        constexpr
        auto capacity( ) const noexcept { return Capacity; }
        auto size( ) const noexcept { return cursor_; }
        auto left( ) const noexcept { return last_Index( ) - cursor_; }
        bool is_empty( ) const noexcept { return 0u == size( ); }
        bool is_full( ) const noexcept { return 0u == left( ); }
        auto view( ) const noexcept { return View_{ buffer_, cursor_ }; }
        auto c_reader( ) const noexcept  -> Char_ const * { return buffer_; }
        void clear( ) noexcept {
            std::memset( buffer_, 0, Capacity );
            cursor_ = 0u;
        }
        bool truncate( Size_ toSize ) noexcept {
            if ( size( ) < toSize) { return false; }

            std::memset( buffer_ + toSize, 0, cursor_ - toSize );
            cursor_ = toSize;

            return true;
        }
        auto c_writer( ) noexcept -> Char_ *  { return buffer_ + cursor_; }
        bool commit( Size_ written ) noexcept {
            bool const isCompleteWrite = ( written <= left( ));
            commit_Unchecked( isCompleteWrite ? written : left( ));

            return isCompleteWrite;
        }
        bool append( View_ view ) noexcept {
            if ( not left( )) { return false; }

            bool const isFullFit = ( view.size( ) <= left( ));

            if ( not isFullFit ) { view.remove_suffix( view.size( ) - left( )); }

            std::memcpy( c_writer( ), view.data( ), view.size( ));
            commit_Unchecked( static_cast< Size_ >( view.size( )));

            return isFullFit;
        }
    }; // `class Info`
    // `Info aliases`
    using InfoTiny = Info< 1u << 6u >; // ----  `64B`
    using InfoSmall = Info< 1u << 7u >; // --- `128B`
    using InfoMedium = Info< 1u << 8u >; // -- `256B`
    using InfoAverage = Info< 1u << 9u >; // - `512B`
    using InfoDefault = Info< 1u << 10u >; //  `1KiB`
    using InfoCommon = Info< 1u << 11u >; // - `2KiB`
    using InfoLarge = Info< 1u << 12u >; // -- `4KiB`
    using InfoHuge = Info< 1u << 13u >; // --- `8KiB`

#endif// version 2.1

#ifdef SON8_OVERGLAD_VERSION_3_3
    template< enums::Packed Pack, unsigned Size >
    struct Packed final {
        static_assert( 0 < Size && Size < 5, "Packed Size must be in range [1,4]" );
        static_assert( enums::Packed_is_enum( static_cast< GLenum >( Pack ) ), "Packed Type must be Packed::Unsign or Packed::Signed" );
        constexpr auto size( ) const noexcept { return Size; }
        constexpr auto pack( ) const noexcept { return Pack; }
    }; // struct `Packed`

    using Packed1u = Packed< enums::Packed::Unsign, 1 >;
    using Packed1s = Packed< enums::Packed::Signed, 1 >;
    using Packed2u = Packed< enums::Packed::Unsign, 2 >;
    using Packed2s = Packed< enums::Packed::Signed, 2 >;
    using Packed3u = Packed< enums::Packed::Unsign, 3 >;
    using Packed3s = Packed< enums::Packed::Signed, 3 >;
    using Packed4u = Packed< enums::Packed::Unsign, 4 >;
    using Packed4s = Packed< enums::Packed::Signed, 4 >;

    using packed1u [[deprecated( "renamed to start with capital letter" )]] = Packed< enums::Packed::Unsign, 1 >;
    using packed1s [[deprecated( "renamed to start with capital letter" )]] = Packed< enums::Packed::Signed, 1 >;
    using packed2u [[deprecated( "renamed to start with capital letter" )]] = Packed< enums::Packed::Unsign, 2 >;
    using packed2s [[deprecated( "renamed to start with capital letter" )]] = Packed< enums::Packed::Signed, 2 >;
    using packed3u [[deprecated( "renamed to start with capital letter" )]] = Packed< enums::Packed::Unsign, 3 >;
    using packed3s [[deprecated( "renamed to start with capital letter" )]] = Packed< enums::Packed::Signed, 3 >;
    using packed4u [[deprecated( "renamed to start with capital letter" )]] = Packed< enums::Packed::Unsign, 4 >;
    using packed4s [[deprecated( "renamed to start with capital letter" )]] = Packed< enums::Packed::Signed, 4 >;

#endif // version 3.3

} // namespace son8::overglad::types


namespace son8::overglad::state {
// version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_1
#   ifndef SON8_OVERGLAD_PROFILE_CORE
    // -- compatibility
    // TODO table 8.3 from 4.6 comp profile spec `?_SIZE (0x0C70)`
    // TODO `MAP_1 (0x0D90-8)` and `MAP_2 (0x0DB0-8)`
#   endif // not core profile
#endif // version 1.1 states
// version 2.1 states
#ifdef SON8_OVERGLAD_VERSION_2_1
    // core
    // TODO: `DRAW_BUFFER_i (0-15) 0x8825-0x8834`
#endif // version 2.1 states
    // TODO: `IsEnabled`, should use macro to list all `IsEnabled` related enums
    // \ and use that macro to create Is, Enable, and Disable enum classes
    // \ usage `::mode( state::Enable:: ), ::mode( state::Disable:: ), ::get( state::Is ) -> bool`
    enum class Is : GLenum {};
    // `GetBoolean`
    enum class Boolean : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
        LineSmooth                  = 0x0B20,
        PolygonSmooth               = 0x0B41,
        CullFace                    = 0x0B44,
        DepthTest                   = 0x0B71,
        DepthWritemask              = 0x0B72,
        StencilTest                 = 0x0B90,
        Dither                      = 0x0BD0,
        Blend                       = 0x0BE2,
        ColorLogicOp                = 0x0BF2,
        ScissorTest                 = 0x0C11,
        Doublebuffer                = 0x0C32,
        Stereo                      = 0x0C33,
        UnpackSwapBytes             = 0x0CF0,
        UnpackLSBfirst              = 0x0CF1,
        PackSwapBytes               = 0x0D00,
        PackLSBfirst                = 0x0D01,
        PolygonOffsetPoint          = 0x2A01,
        PolygonOffsetLine           = 0x2A02,
        ClipPlane0                  = 0x3000,
        ClipPlane1                  = 0x3001,
        ClipPlane2                  = 0x3002,
        ClipPlane3                  = 0x3003,
        ClipPlane4                  = 0x3004,
        ClipPlane5                  = 0x3005,
        PolygonOffsetFill           = 0x8037,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        CurrentRasterPositionValid  = 0x0B08,
        PointSmooth                 = 0x0B10,
        LineStipple                 = 0x0B24,
        PolygonStipple              = 0x0B42,
        EdgeFlag                    = 0x0B43,
        Lighting                    = 0x0B50,
        LightModelLocalViewer       = 0x0B51,
        LightModelTwoSide           = 0x0B52,
        ColorMaterial               = 0x0B57,
        Fog                         = 0x0B60,
        Normalize                   = 0x0BA1,
        AlphaTest                   = 0x0BC0,
        IndexLogicOp                = 0x0BF1,
        IndexMode                   = 0x0C30,
        RGBAmode                    = 0x0C31,
        TextureGenS                 = 0x0C60,
        TextureGenT                 = 0x0C61,
        TextureGenR                 = 0x0C62,
        TextureGenQ                 = 0x0C63,
        MapColor                    = 0x0D10,
        MapStencil                  = 0x0D11,
        AutoNormal                  = 0x0D80,
        Texture1D                   = 0x0DE0,
        Texture2D                   = 0x0DE1,
        Light0                      = 0x4000,
        Light1                      = 0x4001,
        Light2                      = 0x4002,
        Light3                      = 0x4003,
        Light4                      = 0x4004,
        Light5                      = 0x4005,
        Light6                      = 0x4006,
        Light7                      = 0x4007,
        VertexArray                 = 0x8074,
        NormalArray                 = 0x8075,
        ColorArray                  = 0x8076,
        IndexArray                  = 0x8077,
        TextureCoordArray           = 0x8078,
        EdgeFlagArray               = 0x8079,
#   endif // not core profile
#endif // version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_5
        Multisample                 = 0x809D,
        SampleAlphaToCoverage       = 0x809E,
        SampleAlphaToOne            = 0x809F,
        SampleCoverage              = 0x80A0,
        SampleCoverageInvert        = 0x80AB,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        RescaleNormal               = 0x803A,
        Texture3D                   = 0x806F,
        FogCoordArray               = 0x8457,
        ColorSum                    = 0x8458,
        SecondaryColorArray         = 0x845E,
        TextureCubeMap              = 0x8513,
#   endif // not core profile
#endif // version 1.5 states
#ifdef SON8_OVERGLAD_VERSION_2_1
        VertexProgramPointSize      = 0x8642,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        VertexProgramTwoSide        = 0x8643,
        PointSprite                 = 0x8861,
#   endif // not core profile
#endif // version 2.1 states
#ifdef SON8_OVERGLAD_VERSION_3_3
        DepthClamp                  = 0x864F,
        TextureCubeMapSeamless      = 0x884F,
        FramebufferSRGB             = 0x8DB9,
        SampleMask                  = 0x8E51,
        PrimitiveRestart            = 0x8F9D,
#endif // version 3.3 states
#ifdef SON8_OVERGLAD_VERSION_4_3
        SampleShading               = 0x8C36,
        RasterizerDiscard           = 0x8C89,
        DebugOutput                 = 0x92E0,
#endif // version 4.3 states
#ifdef SON8_OVERGLAD_VERSION_4_6
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 4.6 states
    };
    enum class Boolean4 : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
        ColorWritemask  = 0x0C23,
#endif // version 1.1 states
    };
    // `GetFloat`
    enum class Float : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
        PointSize                       = 0x0B11,
        PointSizeGranularity            = 0x0B13,
        LineWidth                       = 0x0B21,
        SmoothLineWidthGranularity      = 0x0B23,
        DepthClearValue                 = 0x0B73,
        PolygonOffsetUnits              = 0x2A00,
        PolygonOffsetFactor             = 0x8038,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        CurrentRasterDistance           = 0x0B09,
        FogIndex                        = 0x0B61,
        FogDensity                      = 0x0B62,
        FogStart                        = 0x0B63,
        FogEnd                          = 0x0B64,
        AlphaTestRef                    = 0x0BC2,
        IndexClearValue                 = 0x0C20,
        RedScale                        = 0x0D14,
        RedBias                         = 0x0D15,
        ZoomX                           = 0x0D16,
        ZoomY                           = 0x0D17,
        GreenScale                      = 0x0D18,
        GreenBias                       = 0x0D19,
        BlueScale                       = 0x0D1A,
        BlueBias                        = 0x0D1B,
        AlphaScale                      = 0x0D1C,
        AlphaBias                       = 0x0D1D,
        DepthScale                      = 0x0D1E,
        DepthBias                       = 0x0D1F,
#   endif // not core profile
#endif // version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_5
        MaxTextureLODbias          = 0x84FD,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        PointSizeMin                    = 0x8126,
        PointSizeMax                    = 0x8127,
        CurrentSecondaryColor           = 0x8459,
#   endif // not core profile
#endif // version 1.5 states
#ifdef SON8_OVERGLAD_VERSION_4_3
        MinShadingSampleValue           = 0x8C37,
        MinFragmentInterpolationOffset  = 0x8E5B,
        MaxFragmentInterpolationOffset  = 0x8E5C,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 4.3 states
    };
    enum class Float2 : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
        PointSizeRange          = 0x0B12,
        SmoothLineWidthRange    = 0x0B22,
        DepthRange              = 0x0B70,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Map1GridDomain          = 0x0DD0,
#   endif // not core profile
#endif // version 1.1 states
    // version 1.5 states
#ifdef SON8_OVERGLAD_VERSION_1_5
        AliasedLineWidthRange   = 0x846E,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        AliasedPointSizeRange   = 0x846D,
#   endif // not core profile
#endif // version 1.5 states
#ifdef SON8_OVERGLAD_VERSION_4_3
        PatchDefaultInnerLevel  = 0x8E73,
#endif // version 4.3 states
    };
    enum class Float3 : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        CurrentNormal               = 0x0B02,
#   endif // not core profile
#endif // version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_5
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        PointDistanceAttenuation    = 0x8129,
        CurrentFogCoord             = 0x8453,
#   endif // not core profile
#endif // version 1.5 states
    };
    enum class Float4 : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
        ColorClearValue               = 0x0C22,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        CurrentColor                  = 0x0B00,
        CurrentTextureCoords          = 0x0B03,
        CurrentRasterColor            = 0x0B04,
        CurrentRasterTextureCoords    = 0x0B06,
        CurrentRasterPosition         = 0x0B07,
        LightModelAmbient             = 0x0B53,
        FogColor                      = 0x0B66,
        AccumClearValue               = 0x0B80,
        Map2GridDomain                = 0x0DD2,
#   endif // not core profile
#endif // version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_5
        BlendColor                    = 0x8005,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        CurrentRasterSecondaryColor   = 0x845F,
#   endif // not core profile
#endif // version 1.5 states
#ifdef SON8_OVERGLAD_VERSION_4_3
        PatchDefaultOuterLevel         = 0x8E74,
#endif // version 4.3 states
    };
    enum class Float16 : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        ModelviewMatrix           = 0x0BA6,
        ProjectionMatrix          = 0x0BA7,
        TextureMatrix             = 0x0BA8,
#   endif // not core profile
#endif // version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_5
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        TransposeModelviewMatrix  = 0x84E3,
        TransposeProjectionMatrix = 0x84E4,
        TransposeTextureMatrix    = 0x84E5,
#   endif // not core profile
#endif // version 1.5 states
    };
    // `GetInteger`
    enum class Integer : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
        CullFaceMode                                = 0x0B45,
        FrontFace                                   = 0x0B46,
        DepthFunc                                   = 0x0B74,
        StencilClearValue                           = 0x0B91,
        StencilFunc                                 = 0x0B92,
        StencilValueMask                            = 0x0B93,
        StencilFail                                 = 0x0B94,
        StencilPassDepthFail                        = 0x0B95,
        StencilPassDepthPass                        = 0x0B96,
        StencilRef                                  = 0x0B97,
        StencilWritemask                            = 0x0B98,
        BlendDst                                    = 0x0BE0,
        BlendSrc                                    = 0x0BE1,
        LogicOpMode                                 = 0x0BF0,
        DrawBuffer                                  = 0x0C01,
        ReadBuffer                                  = 0x0C02,
        LineSmoothHint                              = 0x0C52,
        PolygonSmoothHint                           = 0x0C53,
        UnpackRowLength                             = 0x0CF2,
        UnpackSkipRows                              = 0x0CF3,
        UnpackSkipPixels                            = 0x0CF4,
        UnpackAlignment                             = 0x0CF5,
        PackRowLength                               = 0x0D02,
        PackSkipRows                                = 0x0D03,
        PackSkipPixels                              = 0x0D04,
        PackAlignment                               = 0x0D05,
        MaxClipPlanes                               = 0x0D32,
        MaxTextureSize                              = 0x0D33,
        SubpixelBits                                = 0x0D50,
        TextureBinding1D                            = 0x8068,
        TextureBinding2D                            = 0x8069,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        CurrentIndex                                = 0x0B01,
        CurrentRasterIndex                          = 0x0B05,
        LineStipplePattern                          = 0x0B25,
        LineStippleRepeat                           = 0x0B26,
        ListMode                                    = 0x0B30,
        MaxListNesting                              = 0x0B31,
        ListBase                                    = 0x0B32,
        ListIndex                                   = 0x0B33,
        ShadeModel                                  = 0x0B54,
        ColorMaterialFace                           = 0x0B55,
        ColorMaterialParameter                      = 0x0B56,
        FogMode                                     = 0x0B65,
        MatrixMode                                  = 0x0BA0,
        ModelviewStackDepth                         = 0x0BA3,
        ProjectionStackDepth                        = 0x0BA4,
        TextureStackDepth                           = 0x0BA5,
        AttribStackDepth                            = 0x0BB0,
        ClientAttribStackDepth                      = 0x0BB1,
        AlphaTestFunc                               = 0x0BC1,
        AuxBuffers                                  = 0x0C00,
        IndexWritemask                              = 0x0C21,
        RenderMode                                  = 0x0C40,
        PerspectiveCorrectionHint                   = 0x0C50,
        PointSmoothHint                             = 0x0C51,
        FogHint                                     = 0x0C54,
        IndexShift                                  = 0x0D12,
        IndexOffset                                 = 0x0D13,
        MaxEvalOrder                                = 0x0D30,
        MaxLights                                   = 0x0D31,
        MaxPixelMapTable                            = 0x0D34,
        MaxAttribStackDepth                         = 0x0D35,
        MaxModelviewStackDepth                      = 0x0D36,
        MaxNameStackDepth                           = 0x0D37,
        MaxProjectionStackDepth                     = 0x0D38,
        MaxTextureStackDepth                        = 0x0D39,
        MaxClientAttribStackDepth                   = 0x0D3B,
        IndexBits                                   = 0x0D51,
        RedBits                                     = 0x0D52,
        GreenBits                                   = 0x0D53,
        BlueBits                                    = 0x0D54,
        AlphaBits                                   = 0x0D55,
        DepthBits                                   = 0x0D56,
        StencilBits                                 = 0x0D57,
        AccumRedBits                                = 0x0D58,
        AccumGreenBits                              = 0x0D59,
        AccumBlueBits                               = 0x0D5A,
        AccumAlphaBits                              = 0x0D5B,
        NameStackDepth                              = 0x0D70,
        Map1GridSegments                            = 0x0DD1,
        FeedbackBufferSize                          = 0x0DF1,
        FeedbackBufferType                          = 0x0DF2,
        SelectionBufferSize                         = 0x0DF4,
        VertexArraySize                             = 0x807A,
        VertexArrayType                             = 0x807B,
        VertexArrayStride                           = 0x807C,
        NormalArrayType                             = 0x807E,
        NormalArrayStride                           = 0x807F,
        ColorArraySize                              = 0x8081,
        ColorArrayType                              = 0x8082,
        ColorArrayStride                            = 0x8083,
        IndexArrayType                              = 0x8085,
        IndexArrayStride                            = 0x8086,
        TextureCoordArraySize                       = 0x8088,
        TextureCoordArrayType                       = 0x8089,
        TextureCoordArrayStride                     = 0x808A,
        EdgeFlagArrayStride                         = 0x808C,
#   endif // not core profile
#endif // version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_5
        BlendEquationRGB                            = 0x8009,
        TextureBinding3D                            = 0x806A,
        PackSkipImages                              = 0x806B,
        PackImageHeight                             = 0x806C,
        UnpackSkipImages                            = 0x806D,
        UnpackImageHeight                           = 0x806E,
        BlendDstRGB                                 = 0x80C8,
        BlendSrcRGB                                 = 0x80C9,
        BlendDstAlpha                               = 0x80CA,
        BlendSrcAlpha                               = 0x80CB,
        SampleBuffers                               = 0x80A8,
        Samples                                     = 0x80A9,
        SampleCoverageValue                         = 0x80AA,
        MaxElementsVertices                         = 0x80E8,
        MaxElementsIndices                          = 0x80E9,
        ActiveTexture                               = 0x84E0,
        TextureBindingCubeMap                       = 0x8514,
        MaxCubeMapTextureSize                       = 0x8514,
        NumCompressedTextureFormats                 = 0x86A2,
        CompressedTextureFormats                    = 0x86A3,
        ElementArrayBufferBinding                   = 0x8895,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        GenerateMipmapHint                          = 0x81F8,
        LightModelColorControl                      = 0x81F8,
        ClientActiveTexture                         = 0x84E1,
        TextureCompressionHint                      = 0x84EF,
        FogCoordSrc                                 = 0x8450,
        FogCoordArrayType                           = 0x8454,
        FogCoordArrayStride                         = 0x8455,
        SecondaryColorArraySize                     = 0x845A,
        SecondaryColorArrayType                     = 0x845B,
        SecondaryColorArrayStride                   = 0x845C,
        MaxTextureUnits                             = 0x84E2,
        VertexArrayBufferBinding                    = 0x8896,
        NormalArrayBufferBinding                    = 0x8897,
        ColorArrayBufferBinding                     = 0x8898,
        IndexArrayBufferBinding                     = 0x8899,
        TextureCoordArrayBufferBinding              = 0x889A,
        EdgeFlagArrayBufferBinding                  = 0x889B,
        SecondaryColorArrayBufferBinding            = 0x889C,
        FogCoordArrayBufferBinding                  = 0x889D,
#   endif // not core profile
#endif // version 1.5 states
#ifdef SON8_OVERGLAD_VERSION_2_1
        StencilBackFunc                             = 0x8800,
        StencilBackFail                             = 0x8801,
        StencilBackPassDepthFail                    = 0x8802,
        StencilBackPassDepthPass                    = 0x8803,
        MaxDrawBuffers                              = 0x8824,
        BlendEquationAlpha                          = 0x883D,
        MaxVertexAttribs                            = 0x8869,
        MaxTextureImageUnits                        = 0x8872,
        PixelPackBufferBinding                      = 0x88ED,
        PixelUnpackBufferBinding                    = 0x88EF,
        MaxFragmentUniformComponents                = 0x8B49,
        MaxVertexUniformComponents                  = 0x8B4A,
        MaxVaryingFloats                            = 0x8B4B,
        MaxVertexTextureImageUnits                  = 0x8B4C,
        MaxCombinedTextureImageUnits                = 0x8B4D,
        FragmentShaderDerivativeHint                = 0x8B8B,
        CurrentProgram                              = 0x8B8D,
        PointSpriteColorOrigin                      = 0x8CA0,
        StencilBackRef                              = 0x8CA3,
        StencilBackValueMask                        = 0x8CA4,
        StencilBackWriteMask                        = 0x8CA5,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        MaxTextureCoords                            = 0x8871,
#   endif // not core profile
#endif // version 2.1 states
#ifdef SON8_OVERGLAD_VERSION_3_3
        MajorVersion                                = 0x821B,
        MinorVersion                                = 0x821C,
        NumExtensions                               = 0x821D,
        MaxRenderBufferSize                         = 0x84E8,
        TextureBindingRectangle                     = 0x84F6,
        MaxRectangleTextureSize                     = 0x84F8,
        VertexArrayBinding                          = 0x85B5,
        ArrayBufferBinding                          = 0x8894,
        MaxDualSourceDrawBuffers                    = 0x88FC,
        MaxArrayTextureLayers                       = 0x88FF,
        MinProgramTexelOffset                       = 0x8904,
        MaxProgramTexelOffset                       = 0x8905,
        SamplerBinding                              = 0x8919,
        ClampReadColor                              = 0x891C,
        UniformBufferBinding                        = 0x8A28,
        MaxVertexUniformBlocks                      = 0x8A2B,
        MaxGeometryUniformBlocks                    = 0x8A2C,
        MaxFragmentUniformBlocks                    = 0x8A2D,
        MaxCombinedUniformBlocks                    = 0x8A2E,
        MaxUniformBufferBindings                    = 0x8A2F,
        MaxUniformBlockSize                         = 0x8A30,
        MaxCombinedVertexUniformComponents          = 0x8A31,
        MaxCombinedGeometryUniformComponents        = 0x8A32,
        MaxCombinedFragmentUniformComponents        = 0x8A33,
        UniformBufferOffsetAlignment                = 0x8A34,
        MaxVaryingComponets                         = 0x8B4B,
        TextureBinding1Darray                       = 0x8C1C,
        TextureBinding2Darray                       = 0x8C1D,
        MaxGeometryTextureImageUnits                = 0x8C29,
        MaxTextureBufferSize                        = 0x8C2B,
        TextureBindingBuffer                        = 0x8C2C,
        MaxTransformFeedbackSeparateComponents      = 0x8C80,
        MaxTransformFeedbackInterleavedComponents   = 0x8C8A,
        MaxTransformFeedbackSeparateAttribs         = 0x8C8B,
        TransformFeedbackBufferBinding              = 0x8C8F,
        DrawFramebufferBinding                      = 0x8CA6,
        RenderbufferBinding                         = 0x8CA7,
        ReadFramebufferBinding                      = 0x8CAA,
        MaxColorAttachments                         = 0x8CDF,
        MaxSamples                                  = 0x8D57,
        MaxGeometryOutputVertices                   = 0x8DE0,
        MaxGeometryTotalOutputComponents            = 0x8DE1,
        QuadsFollowProvokingVertexConvention        = 0x8E4C,
        ProvokingVertex                             = 0x8E4F,
        MaxSampleMaskWords                          = 0x8E59,
        CopyReadBufferBinding                       = 0x8F36,
        CopyWriteBufferBinding                      = 0x8F37,
        PrimitiveRestartIndex                       = 0x8F9E,
        TextureBinding2Dmultisample                 = 0x9104,
        TextureBinding2DmultisampleArray            = 0x9105,
        MaxColorTextureSamples                      = 0x910E,
        MaxDepthTextureSamples                      = 0x910F,
        MaxIntegerSamples                           = 0x9110,
        MaxGeometryInputComponents                  = 0x9123,
        MaxGeometryOutputComponents                 = 0x9124,
        MaxFragmentInputComponents                  = 0x9125,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        ClampVertexColor                            = 0x891A,
        ClampFragmentColor                          = 0x891B,
#   endif // not core profile
#endif // version 3.3 states
#ifdef SON8_OVERGLAD_VERSION_4_3
        DebugOutputSynchronous                      = 0x8242,
        DebugNextLoggedMessageLength                = 0x8243,
        ProgramPipelineBinding                      = 0x825A,
        MaxViewports                                = 0x825B,
        ViewportSubpixelBits                        = 0x825C,
        ViewportBoundsRange                         = 0x825D,
        MaxDebugGroupStackDepth                     = 0x826C,
        DebugGroupStackDepth                        = 0x826D,
        LayerProvokingVertex                        = 0x825E,
        ViewportIndexProvokingVertex                = 0x825F,
        MaxLabelLength                              = 0x82E8,
        NumShadingLanguageVersions                  = 0x82E9,
        MaxTessControlInputComponents               = 0x886C,
        MaxTessEvaluationInputComponents            = 0x886D,
        ImplementationColorReadType                 = 0x8B9A,
        ImplementationColorReadFormat               = 0x8B9B,
        MaxVertexUniformVectors                     = 0x8DFB,
        MaxCombinedTessControlUniformComponents     = 0x8E1E,
        MaxCombinedTessEvaluationUniformComponents  = 0x8E1F,
        TransformFeedbackBinding                    = 0x8E25,
        FragmentInterpolationOffsetBits             = 0x8E5D,
        MaxTransformFeedbackBuffers                 = 0x8E70,
        PatchVertices                               = 0x8E72,
        MaxPatchVertices                            = 0x8E7D,
        MaxTessGenLevel                             = 0x8E7E,
        MaxTessControlUniformComponents             = 0x8E7F,
        MaxTessEvaluationUniformComponents          = 0x8E80,
        MaxTessControlTextureImageUnits             = 0x8E81,
        MaxTessEvaluationTextureImageUnits          = 0x8E82,
        MaxTessControlOutputComponents              = 0x8E83,
        MaxTessPatchComponents                      = 0x8E84,
        MaxTessControlOutputTotalComponents         = 0x8E85,
        MaxTessEvaluationOutputComponents           = 0x8E86,
        MaxTessControlUniformBlocks                 = 0x8E89,
        MaxTessEvaluationUniformBlocks              = 0x8E8A,
        MaxImageUnits                               = 0x8F38,
        MaxCombinedShaderOutputResources            = 0x8F39,
        DrawIndirectBufferBinding                   = 0x8F43,
        TextureBindingCubeMapArray                  = 0x900A,
        MaxImageSamples                             = 0x906D,
        MaxVertexImageUniforms                      = 0x90CA,
        MaxTessControlImageUniforms                 = 0x90CB,
        MaxTessEvaluationImageUniforms              = 0x90CC,
        MaxGeometryImageUniforms                    = 0x90CD,
        MaxFragmentImageUniforms                    = 0x90CE,
        MaxCombinedImageUniforms                    = 0x90CF,
        ShaderStorageBufferBinding                  = 0x90D3,
        MaxVertexShaderStorageBlocks                = 0x90D6,
        MaxTessControlShaderStorageBlocks           = 0x90D8,
        MaxTessEvaluationShaderStorageBlocks        = 0x90D9,
        DispatchIndirectBufferBinding               = 0x90EF,
        UnpackCompressedBlockWidth                  = 0x9127,
        UnpackCompressedBlockHeight                 = 0x9128,
        UnpackCompressedBlockDepth                  = 0x9129,
        UnpackCompressedBlockSize                   = 0x912A,
        PackCompressedBlockWidth                    = 0x912B,
        PackCompressedBlockHeight                   = 0x912C,
        PackCompressedBlockDepth                    = 0x912D,
        PackCompressedBlockSize                     = 0x912E,
        MaxDebugMessageLength                       = 0x9143,
        MaxDebugLogMessages                         = 0x9144,
        DebugLogggedMessages                        = 0x9145,
        AtomicCounterBufferBinding                  = 0x92C1,
        MaxVertexAtomicCounterBuffers               = 0x92CC,
        MaxTessControlAtomicCounterBuffers          = 0x92CD,
        MaxTessEvaluationAtomicCounterBuffers       = 0x92CE,
        MaxVertexAtomicCounters                     = 0x92D2,
        MaxTessControlAtomicCounters                = 0x92D4,
        MaxSampleCounts                             = 0x9380,
#endif // version 4.3 states
#ifdef SON8_OVERGLAD_VERSION_4_6
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 4.6 states
    };
    enum class Integer2 : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
        PolygonMode         = 0x0B40,
        MaxViewportDims     = 0x0D3A,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Map2GridSegments    = 0x0DD3,
#   endif // not core profile
#endif // version 1.1 states
    };
    enum class Integer4 : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
        Viewport    = 0x0BA2,
        ScissorBox  = 0x0C10,
#endif // version 1.1 states
    };
    // `GetInteger64`
    enum class Long : GLenum {
#ifdef SON8_OVERGLAD_VERSION_3_3
        MaxServerWaitTimeout    = 0x9111,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 3.3 states
#ifdef SON8_OVERGLAD_VERSION_4_3
        MaxElementIndex         = 0x8D6B,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 4.3 states
    };
    // `GetString`
    enum class String : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
        Vendor                  = 0x1F00,
        Renderer                = 0x1F01,
        Version                 = 0x1F02,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Extensions              = 0x1F03,
#   endif // not core profile
#endif // version 1.1 states
#   ifdef SON8_OVERGLAD_VERSION_2_1
        ShadingLanguageVersion  = 0x8B8C,
#endif // version 2.1 states
    };




#ifdef SON8_OVERGLAD_VERSION_1_1
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_5
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 1.5 states
#ifdef SON8_OVERGLAD_VERSION_2_1
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 2.1 states
#ifdef SON8_OVERGLAD_VERSION_3_3
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 3.3 states
#ifdef SON8_OVERGLAD_VERSION_4_3
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 4.3 states
#ifdef SON8_OVERGLAD_VERSION_4_6
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 4.6 states





} // namespace `son8::overglad::state`

// TODO: check if it actually fix this garbage
// WHY `C++26` with it fake safety does this
#if __cplusplus > 202302L and defined(__has_cpp_attribute) and __has_cpp_attribute(indeterminate)
#define SON8_OVERGLAD_WHY [[indeterminate]];
#else
#define SON8_OVERGLAD_WHY
#endif

#define SON8_OVERGLAD_DEPR [[deprecated]] inline auto
#define SON8_OVERGLAD_DISC inline auto
#define SON8_OVERGLAD_FUNC [[nodiscard]] inline auto
#define SON8_OVERGLAD_PROC inline void

#ifdef      SON8_OVERGLAD_INCLUDE
#include <son8/overglad/v1_1.hxx>
#include <son8/overglad/v1_5.hxx>
#include <son8/overglad/v2_1.hxx>
#include <son8/overglad/v3_3.hxx>
#include <son8/overglad/v4_3.hxx>
#endif    //SON8_OVERGLAD_INCLUDE

#ifdef  SON8_OVERGLAD_VERSION_4_6
namespace son8::overglad {
    // CORE

    // Chapter 2: OpenGL Fundamentals

    // TODO: `GetGraphicsResetStatus`

    // Chapter 4: Event Model

    // TODO: `CreateQueries,GetQueryBufferObject(i|ui|i64|ui64)v`

    // Chapter 6: Buffer Objects

    // TODO: `CreateBuffers,BindBuffersRange,BindBuffersBase,BufferStorage,NamedBufferStorage,NamedBufferData,NamedBufferSubData,ClearNamedBufferSubData,ClearNamedBufferData,MapNamedBufferRange,MapNamedBuffer,FlushMappedNamedBufferRange,UnmapNamedBuffer,CopyNamedBufferSubData,GetNamedBufferParameteriv,GetNamedBufferParameteri64v,GetNamedBufferSubData,GetNamedBufferPointerv`

    // Chapter 7: Programs and Shaders

    // TODO: `SpecializeShader,CreateProgramPipelines,MemoryBarrierByRegion`

    // Chapter 8: Textures and Samplers

    // TODO: `BindTextures,BindTextureUnit,CreateTextures,CreateSamplers,BindSamplers,SamplerParameter[if],TextureSubImage[123]D,CopyTextureSubImage[123]D,CompressedTextureSubImage[123]D,TextureBufferRange,TextureBuffer,TextureParameter[if]v?,TextureParameterI(i|ui)v,GetTextureParameter[if]v,GetTextureParameterI(i|ui)v,GetTextureLevelParameter[if]v,GetTextureImage,GetnTexImage,GetTextureSubImage,GetCompressedTextureImage,GetnCompressedTexImage,GetCompressedTextureSubImage,GenerateTextureMipmap,TextureStorage2DMultisample,TextureStorage3DMultisample,ClearTexSubImage,ClearTexImage,BindImageTextures`

    // Chapter 9: Framebuffers and Framebuffer Objects

    // TODO: `CreateFramebuffers,NamedFramebufferParameteri,GetNamedFramebufferParameteriv,GetNamedFramebufferAttachmentParameteriv,CreateRenderbuffers,NamedRenderbufferStorageMultisample,NamedRenderbufferStorage,GetNamedRenderbufferParameteriv,NamedFramebufferRenderbuffer,NamedFramebufferTexture,NamedFramebufferTextureLayer`

    SON8_OVERGLAD_PROC texture_barrier( ) noexcept
    { glad_glTextureBarrier( ); }

    // TODO: `CheckNamedFramebufferStatus`

    // Chapter 10: Vertex Specification and Drawing Commands

    // TODO: `CreateVertexArrays,VertexArrayElementBuffer,VertexArrayAttrib[IL]?Format,VertexArrayVertexBuffer,BindVertexBuffers,VertexArrayVertexBuffers,VertexArrayAttribBinding,EnableVertexArrayAttrib,DisableVertexArrayAttrib,VertexArrayBindingDivisor,MultiDrawArraysIndirectCount,MultiDrawElementsIndirectCount,GetVertexArrayiv,GetVertexArrayIndexediv,GetVertexArrayIndexed64iv`

    // Chapter 13: Fixed-Function Vertex Post - Processing

    // TODO: `CreateTransformFeedbacks,TransformFeedbackBufferRange,TransformFeedbackBufferBase,ClipControl`

    // Chapter 14: Fixed-Function Primitive Assembly and Rasterization

    SON8_OVERGLAD_PROC polygon_offset( GLfloat factor, GLfloat units, GLfloat clamp ) noexcept
    { glad_glPolygonOffsetClamp( factor, units, clamp ); }

    // Chapter 17: Writing Fragments and Samples to the Framebuffer

    // TODO: `NamedFramebufferDrawBuffer,NamedFramebufferDrawBuffers,ClearNamedFramebuffer([if]|ui)v,ClearNamedFramebufferfi,InvalidateNamedFramebufferSubData,InvalidateNamedFramebufferData`

    // Chapter 18: Drawing, Reading, and Copying Pixels

    // TODO: `NamedFramebufferReadBuffer,ReadnPixels,BlitNamedFramebuffer`
    // Chapter 21: Special Functions

    // TODO: `GetnMap`

    // COMPATIBILITY
#   ifndef SON8_OVERGLAD_PROFILE_CORE
    // Chapter 14: Fixed-Function Primitive Assembly and Rasterization
    // TODO: `GetnPolygonStipple`
#   endif // not core profile
    // deprecated
#   ifdef SON8_OVERGLAD_INCLUDE_DEPRECATED

// Chapter 2: OpenGL Fundamentals

    SON8_OVERGLAD_DEPR get_graphics_reset_status( )
    { return glGetGraphicsResetStatus( ); }

    // Chapter 4: Event Model

    SON8_OVERGLAD_DEPR create_queries( GLenum target, GLsizei n, GLuint *ids )
    { glCreateQueries( target, n, ids ); }
    SON8_OVERGLAD_DEPR get_query_buffer_object_i( GLuint id, GLuint buffer, GLenum pname, GLintptr offset )
    { glGetQueryBufferObjectiv( id, buffer, pname, offset ); }
    SON8_OVERGLAD_DEPR get_query_buffer_object_ui( GLuint id, GLuint buffer, GLenum pname, GLintptr offset )
    { glGetQueryBufferObjectuiv( id, buffer, pname, offset ); }
    SON8_OVERGLAD_DEPR get_query_buffer_object_i64( GLuint id, GLuint buffer, GLenum pname, GLintptr offset )
    { glGetQueryBufferObjecti64v( id, buffer, pname, offset ); }
    SON8_OVERGLAD_DEPR get_query_buffer_object_ui64( GLuint id, GLuint buffer, GLenum pname, GLintptr offset )
    { glGetQueryBufferObjectui64v( id, buffer, pname, offset ); }

    // Chapter 6: Buffer Objects

    SON8_OVERGLAD_DEPR create_buffers( GLsizei n, GLuint *buffers )
    { glCreateBuffers( n, buffers ); }
    SON8_OVERGLAD_DEPR bind_buffers_range( GLenum target, GLuint first, GLsizei count
        , GLuint const *buffers, GLintptr const *offsets, GLsizeiptr const *sizes )
    { glBindBuffersRange( target, first, count, buffers, offsets, sizes ); }
    SON8_OVERGLAD_DEPR bind_buffers_base( GLenum target, GLuint first, GLsizei count, GLuint const *buffers )
    { glBindBuffersBase( target, first, count, buffers ); }
    SON8_OVERGLAD_DEPR buffer_storage( GLenum target, GLsizeiptr size, GLvoid const *data, GLbitfield flags )
    { glBufferStorage( target, size, data, flags ); }
    SON8_OVERGLAD_DEPR named_buffer_storage( GLuint buffer, GLsizeiptr size, GLvoid const *data, GLbitfield flags )
    { glNamedBufferStorage( buffer, size, data, flags ); }
    SON8_OVERGLAD_DEPR named_buffer_data( GLuint buffer, GLsizeiptr size, GLvoid const *data, GLenum usage )
    { glNamedBufferData( buffer, size, data, usage ); }
    SON8_OVERGLAD_DEPR named_buffer_sub_data( GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid const *data )
    { glNamedBufferSubData( buffer, offset, size, data ); }
    SON8_OVERGLAD_DEPR clear_named_buffer_sub_data( GLuint buffer, GLenum internalformat
        , GLintptr offset, GLsizeiptr size
        , GLenum format, GLenum type, GLvoid const *data )
    { glClearNamedBufferSubData( buffer, internalformat, offset, size, format, type, data ); }
    SON8_OVERGLAD_DEPR clear_named_buffer_data( GLuint buffer, GLenum internalformat
        , GLenum format, GLenum type, GLvoid const *data )
    { glClearNamedBufferData( buffer, internalformat, format, type, data ); }
    SON8_OVERGLAD_DEPR map_named_buffer_range( GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access )
    { return glMapNamedBufferRange( buffer, offset, length, access ); }
    SON8_OVERGLAD_DEPR map_named_buffer( GLuint buffer, GLenum access )
    { return  glMapNamedBuffer( buffer, access ); }
    SON8_OVERGLAD_DEPR flush_mapped_named_buffer_range( GLuint buffer, GLintptr offset, GLsizeiptr length )
    { glFlushMappedNamedBufferRange( buffer, offset, length ); }
    SON8_OVERGLAD_DEPR unmap_named_buffer( GLuint buffer )
    { return glUnmapNamedBuffer( buffer ); }
    SON8_OVERGLAD_DEPR copy_named_buffer_sub_data( GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size )
    { glCopyNamedBufferSubData( readBuffer, writeBuffer, readOffset, writeOffset, size ); }
    SON8_OVERGLAD_DEPR get_named_buffer_parameter( GLuint buffer, GLenum pname, GLint *data )
    { glGetNamedBufferParameteriv( buffer, pname, data ); }
    SON8_OVERGLAD_DEPR get_named_buffer_parameter( GLuint buffer, GLenum pname, GLint64 *data )
    { glGetNamedBufferParameteri64v( buffer, pname, data ); }
    SON8_OVERGLAD_DEPR get_named_buffer_sub_data( GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid *data )
    { glGetNamedBufferSubData( buffer, offset, size, data ); }
    SON8_OVERGLAD_DEPR get_named_buffer_pointer( GLuint buffer, GLenum pname, GLvoid **data ) // TODO verify const ** in specification
    { glGetNamedBufferPointerv( buffer, pname, data ); }

    // Chapter 7: Programs and Shaders

    SON8_OVERGLAD_DEPR specialize_shader( GLuint shader, char const *pEntryPoint, GLuint numSpecializationConstants
        , GLuint const *pConstantIndex, GLuint const *pConstantValue )
    { glSpecializeShader( shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue ); }
    SON8_OVERGLAD_DEPR create_program_pipelines( GLsizei n, GLuint *pipelines )
    { glCreateProgramPipelines( n, pipelines ); }
    SON8_OVERGLAD_DEPR memory_barrier_by_region( GLbitfield barriers )
    { glMemoryBarrierByRegion( barriers ); }

    // Chapter 8: Textures and Samplers

    SON8_OVERGLAD_DEPR bind_textures( GLuint first, GLsizei count, GLuint const *textures )
    { glBindTextures( first, count, textures ); }
    SON8_OVERGLAD_DEPR bind_texture_unit( GLuint unit, GLuint texture )
    { glBindTextureUnit( unit, texture ); }
    SON8_OVERGLAD_DEPR create_textures( GLenum target, GLsizei n, GLuint *textures )
    { glCreateTextures( target, n, textures ); }
    SON8_OVERGLAD_DEPR create_samplers( GLsizei n, GLuint *samplers )
    { glCreateSamplers( n, samplers ); }
    SON8_OVERGLAD_DEPR bind_samplers( GLuint first, GLsizei count, GLuint const *samplers )
    { glBindSamplers( first, count, samplers ); }
    SON8_OVERGLAD_DEPR sampler_parameter( GLuint sampler, GLenum pname, GLint param )
    { glSamplerParameteri( sampler, pname, param ); }
    SON8_OVERGLAD_DEPR texture_sub_image( GLuint texture, GLint level
        , GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth
        , GLenum format, GLenum type, GLvoid const *pixels )
    { glTextureSubImage3D( texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels ); }
    SON8_OVERGLAD_DEPR texture_sub_image( GLuint texture, GLint level
        , GLint xoffset, GLint yoffset, GLsizei width, GLsizei height
        , GLenum format, GLenum type, GLvoid const *pixels )
    { glTextureSubImage2D( texture, level, xoffset, yoffset, width, height, format, type, pixels ); }
    SON8_OVERGLAD_DEPR texture_sub_image( GLuint texture, GLint level
        , GLint xoffset, GLsizei width
        , GLenum format, GLenum type, GLvoid const *pixels )
    { glTextureSubImage1D( texture, level, xoffset, width, format, type, pixels ); }
    SON8_OVERGLAD_DEPR copy_texture_sub_image( GLuint texture, GLint level
        , GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height )
    { glCopyTextureSubImage3D( texture, level, xoffset, yoffset, zoffset, x, y, width, height ); }
    SON8_OVERGLAD_DEPR copy_texture_sub_image( GLuint texture, GLint level
        , GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height )
    { glCopyTextureSubImage2D( texture, level, xoffset, yoffset, x, y, width, height ); }
    SON8_OVERGLAD_DEPR copy_texture_sub_image( GLuint texture, GLint level
        , GLint xoffset, GLint x, GLint y, GLsizei width )
    { glCopyTextureSubImage1D( texture, level, xoffset, x, y, width ); }
    SON8_OVERGLAD_DEPR compressed_texture_sub_image( GLuint texture, GLint level
        , GLint xoffset, GLsizei width
        , GLenum format, GLsizei imageSize, GLvoid const *data )
    { glCompressedTextureSubImage1D( texture, level, xoffset, width, format, imageSize, data ); }
    SON8_OVERGLAD_DEPR compressed_texture_sub_image( GLuint texture, GLint level
        , GLint xoffset, GLint yoffset, GLsizei width, GLsizei height
        , GLenum format, GLsizei imageSize, GLvoid const *data )
    { glCompressedTextureSubImage2D( texture, level, xoffset, yoffset, width, height, format, imageSize, data ); }
    SON8_OVERGLAD_DEPR compressed_texture_sub_image( GLuint texture, GLint level
        , GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth
        , GLenum format, GLsizei imageSize, GLvoid const *data )
    { glCompressedTextureSubImage3D( texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data ); }
    SON8_OVERGLAD_DEPR texture_buffer_range( GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size )
    { glTextureBufferRange( texture, internalformat, buffer, offset, size ); }
    SON8_OVERGLAD_DEPR texture_buffer( GLuint texture, GLenum internalformat, GLuint buffer )
    { glTextureBuffer( texture, internalformat, buffer ); }
    SON8_OVERGLAD_DEPR texture_parameter( GLuint texture, GLenum pname, GLint param )
    { glTextureParameteri(texture, pname, param ); }
    SON8_OVERGLAD_DEPR texture_parameter( GLuint texture, GLenum pname, GLfloat param )
    { glTextureParameterf(texture, pname, param ); }
    SON8_OVERGLAD_DEPR texture_parameter( GLuint texture, GLenum pname, GLint const *params )
    { glTextureParameteriv(texture, pname, params ); }
    SON8_OVERGLAD_DEPR texture_parameter( GLuint texture, GLenum pname, GLfloat const *params )
    { glTextureParameterfv(texture, pname, params ); }
    SON8_OVERGLAD_DEPR texture_parameter_I( GLuint texture, GLenum pname, GLint const *params )
    { glTextureParameterIiv(texture, pname, params ); }
    SON8_OVERGLAD_DEPR texture_parameter_I( GLuint texture, GLenum pname, GLuint const *params )
    { glTextureParameterIuiv(texture, pname, params ); }
    SON8_OVERGLAD_DEPR get_texture_parameter( GLuint texture, GLenum pname, GLint *data )
    { glGetTextureParameteriv( texture, pname, data ); }
    SON8_OVERGLAD_DEPR get_texture_parameter( GLuint texture, GLenum pname, GLfloat *data )
    { glGetTextureParameterfv( texture, pname, data ); }
    SON8_OVERGLAD_DEPR get_texture_parameter_I( GLuint texture, GLenum pname, GLint *data )
    { glGetTextureParameterIiv( texture, pname, data ); }
    SON8_OVERGLAD_DEPR get_texture_parameter_I( GLuint texture, GLenum pname, GLuint *data )
    { glGetTextureParameterIuiv( texture, pname, data ); }
    SON8_OVERGLAD_DEPR get_texture_level_parameter( GLuint texture, GLint level, GLenum pname, GLint *params )
    { glGetTextureLevelParameteriv( texture, level, pname, params ); }
    SON8_OVERGLAD_DEPR get_texture_level_parameter( GLuint texture, GLint level, GLenum pname, GLfloat *params )
    { glGetTextureLevelParameterfv( texture, level, pname, params ); }
    SON8_OVERGLAD_DEPR get_texture_image( GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid *pixels )
    { glGetTextureImage( texture, level, format, type, bufSize, pixels ); }
    SON8_OVERGLAD_DEPR get_tex_image( GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid *pixels )
    { glGetnTexImage( target, level, format, type, bufSize, pixels ); }
    SON8_OVERGLAD_DEPR get_texture_sub_image( GLuint texture, GLint level
        , GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth
        , GLenum format, GLenum type, GLsizei bufSize, GLvoid *pixels )
    { glGetTextureSubImage( texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels ); }
    SON8_OVERGLAD_DEPR get_compressed_texture_image( GLuint texture, GLint level, GLsizei bufSize, GLvoid *pixels )
    { glGetCompressedTextureImage( texture, level, bufSize, pixels ); }
    SON8_OVERGLAD_DEPR get_compressed_tex_image( GLenum target, GLint level, GLsizei bufSize, GLvoid *pixels )
    { glGetnCompressedTexImage( target, level, bufSize, pixels ); }
    SON8_OVERGLAD_DEPR get_compressed_texture_sub_image( GLuint texture, GLint level
        , GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth
        , GLsizei bufSize, GLvoid *pixels )
    { glGetCompressedTextureSubImage( texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels ); }
    SON8_OVERGLAD_DEPR generate_texture_mipmap( GLuint texture )
    { glGenerateTextureMipmap( texture ); }
    SON8_OVERGLAD_DEPR texture_storage( GLuint texture, GLsizei levels, GLenum internalformat
        , GLsizei width )
    { glTextureStorage1D( texture, levels, internalformat, width ); }
    SON8_OVERGLAD_DEPR texture_storage( GLuint texture, GLsizei levels, GLenum internalformat
        , GLsizei width, GLsizei height )
    { glTextureStorage2D( texture, levels, internalformat, width, height ); }
    SON8_OVERGLAD_DEPR texture_storage( GLuint texture, GLsizei levels, GLenum internalformat
        , GLsizei width, GLsizei height, GLsizei depth )
    { glTextureStorage3D( texture, levels, internalformat, width, height, depth ); }
    SON8_OVERGLAD_DEPR texture_storage_multisample( GLuint texture, GLsizei samples, GLenum internalformat
        , GLsizei width, GLsizei height
        , GLboolean fixedsamplelocations )
    { glTextureStorage2DMultisample( texture, samples, internalformat, width, height, fixedsamplelocations ); }
    SON8_OVERGLAD_DEPR texture_storage_multisample( GLuint texture, GLsizei samples, GLenum internalformat
        , GLsizei width, GLsizei height, GLsizei depth
        , GLboolean fixedsamplelocations )
    { glTextureStorage3DMultisample( texture, samples, internalformat, width, height, depth, fixedsamplelocations ); }
    SON8_OVERGLAD_DEPR clear_tex_sub_image( GLuint texture, GLint level
        , GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth
        , GLenum format, GLenum type, GLvoid const *data )
    { glClearTexSubImage( texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data ); }
    SON8_OVERGLAD_DEPR clear_sub_image( GLuint texture, GLint level, GLenum format, GLenum type, GLvoid const *data )
    { glClearTexImage( texture, level, format, type, data ); }
    SON8_OVERGLAD_DEPR bind_image_textures( GLuint first, GLsizei count, GLuint const *textures )
    { glBindImageTextures( first, count, textures ); }

    // Chapter 9: Framebuffers and Framebuffer Objects

    SON8_OVERGLAD_DEPR create_framebuffers( GLsizei n, GLuint *framebuffers )
    { glCreateFramebuffers( n, framebuffers ); }
    SON8_OVERGLAD_DEPR named_framebuffer_parameter( GLuint framebuffer, GLenum pname, GLint param )
    { glNamedFramebufferParameteri( framebuffer, pname, param ); }
    SON8_OVERGLAD_DEPR get_named_framebuffer_parameter( GLuint framebuffer, GLenum pname, GLint *params )
    { glGetNamedFramebufferParameteriv( framebuffer, pname, params ); }
    SON8_OVERGLAD_DEPR get_named_framebuffer_attachment_parameter( GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params )
    { glGetNamedFramebufferAttachmentParameteriv( framebuffer, attachment, pname, params ); }
    SON8_OVERGLAD_DEPR create_renderbuffers( GLsizei n, GLuint *renderbuffers )
    { glCreateRenderbuffers( n, renderbuffers ); }
    SON8_OVERGLAD_DEPR named_renderbuffer_storage_multisample( GLuint renderbuffer, GLsizei samples, GLenum internalformat
        , GLsizei width, GLsizei height )
    { glNamedRenderbufferStorageMultisample( renderbuffer, samples, internalformat, width, height ); }
    SON8_OVERGLAD_DEPR named_renderbuffer_storage( GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height )
    { glNamedRenderbufferStorage( renderbuffer, internalformat, width, height ); }
    SON8_OVERGLAD_DEPR get_named_renderbuffer_parameter( GLuint renderbuffer, GLenum pname, GLint *params )
    { glGetNamedRenderbufferParameteriv( renderbuffer, pname, params ); }
    SON8_OVERGLAD_DEPR named_framebuffer_renderbuffer( GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer )
    { glNamedFramebufferRenderbuffer( framebuffer, attachment, renderbuffertarget, renderbuffer ); }
    SON8_OVERGLAD_DEPR named_framebuffer_texture( GLuint framebuffer, GLenum attachment, GLuint texture, GLint level )
    { glNamedFramebufferTexture( framebuffer, attachment, texture, level ); }
    SON8_OVERGLAD_DEPR named_framebuffer_texture_layer( GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer )
    { glNamedFramebufferTextureLayer( framebuffer, attachment, texture, level, layer ); }
    SON8_OVERGLAD_DEPR check_named_framebuffer_status( GLuint framebuffer, GLenum target )
    { return glCheckNamedFramebufferStatus( framebuffer, target ); }

    // Chapter 10: Vertex Specification and Drawing Commands

    SON8_OVERGLAD_DEPR create_vertex_arrays( GLsizei n, GLuint *arrays )
    { glCreateVertexArrays( n, arrays ); }
    SON8_OVERGLAD_DEPR vertex_array_element_buffer( GLuint vaobj, GLuint buffer )
    { glVertexArrayElementBuffer( vaobj, buffer ); }
    SON8_OVERGLAD_DEPR vertex_array_attrib_format( GLuint vaobj, GLuint attribindex, GLint size, GLenum type
        , GLboolean normalized, GLuint relativeoffset )
    { glVertexArrayAttribFormat( vaobj, attribindex, size, type, normalized, relativeoffset ); }
    SON8_OVERGLAD_DEPR vertex_array_attrib_I_format( GLuint vaobj, GLuint attribindex, GLint size, GLenum type
        , GLuint relativeoffset )
    { glVertexArrayAttribIFormat( vaobj, attribindex, size, type, relativeoffset ); }
    SON8_OVERGLAD_DEPR vertex_array_attrib_L_format( GLuint vaobj, GLuint attribindex, GLint size, GLenum type
        , GLuint relativeoffset )
    { glVertexArrayAttribLFormat( vaobj, attribindex, size, type, relativeoffset ); }
    SON8_OVERGLAD_DEPR vertex_array_vertex_buffer( GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride )
    { glVertexArrayVertexBuffer( vaobj, bindingindex, buffer, offset, stride ); }
    SON8_OVERGLAD_DEPR bind_vertex_buffers( GLuint first, GLsizei count
        , GLuint const *buffers, GLintptr const *offsets, GLsizei const *strides )
    { glBindVertexBuffers( first, count, buffers, offsets, strides ); }
    SON8_OVERGLAD_DEPR vertex_array_vertex_buffers( GLuint vaobj, GLuint first, GLsizei count
        , GLuint const *buffers, GLintptr const *offsets, GLsizei const *strides )
    { glVertexArrayVertexBuffers( vaobj, first, count, buffers, offsets, strides ); }
    SON8_OVERGLAD_DEPR vertex_array_attrib_binding( GLuint vaobj, GLuint attribindex, GLuint bindingindex )
    { glVertexArrayAttribBinding( vaobj, attribindex, bindingindex ); }
    SON8_OVERGLAD_DEPR enable_vertex_array_attrib( GLuint vaobj, GLuint index )
    { glEnableVertexArrayAttrib( vaobj, index ); }
    SON8_OVERGLAD_DEPR disable_vertex_array_attrib( GLuint vaobj, GLuint index )
    { glDisableVertexArrayAttrib( vaobj, index ); }
    SON8_OVERGLAD_DEPR vertex_array_binding_divisor( GLuint vaobj, GLuint bindingindex, GLuint divisor )
    { glVertexArrayBindingDivisor(vaobj, bindingindex, divisor ); }
    SON8_OVERGLAD_DEPR multi_draw_arrays_indirect_count( GLenum mode, GLvoid const *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride )
    { glMultiDrawArraysIndirectCount( mode, indirect, drawcount, maxdrawcount, stride ); }
    SON8_OVERGLAD_DEPR multi_draw_elements_indirect_count( GLenum mode, GLenum type, GLvoid const *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride )
    { glMultiDrawElementsIndirectCount( mode, type, indirect, drawcount, maxdrawcount, stride ); }
    SON8_OVERGLAD_DEPR get_vertex_array( GLuint vaobj, GLenum pname, GLint *param )
    { glGetVertexArrayiv( vaobj, pname, param ); }
    SON8_OVERGLAD_DEPR get_vertex_array_indexed( GLuint vaobj, GLuint index, GLenum pname, GLint *param )
    { glGetVertexArrayIndexediv( vaobj, index, pname, param ); }
    SON8_OVERGLAD_DEPR get_vertex_array_indexed( GLuint vaobj, GLuint index, GLenum pname, GLint64 *param )
    { glGetVertexArrayIndexed64iv( vaobj, index, pname, param ); }

    // Chapter 13: Fixed-Function Vertex Post - Processing

    SON8_OVERGLAD_DEPR create_transform_feedbacks( GLsizei n, GLuint *ids )
    { glCreateTransformFeedbacks( n, ids ); }
    SON8_OVERGLAD_DEPR transform_feedback_buffer_range( GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size )
    { glTransformFeedbackBufferRange( xfb, index, buffer, offset, size ); }
    SON8_OVERGLAD_DEPR transform_feedback_buffer_base( GLuint xfb, GLuint index, GLuint buffer )
    { glTransformFeedbackBufferBase( xfb, index, buffer ); }
    SON8_OVERGLAD_DEPR clip_control( GLenum origin, GLenum depth )
    { glClipControl( origin, depth ); }

    // Chapter 14: Fixed-Function Primitive Assembly and Rasterization

    SON8_OVERGLAD_DEPR get_polygon_stipple( GLsizei bufSize, GLubyte *pattern ) // TODO: spec uses GLvoid * for pattern
    { glGetnPolygonStipple( bufSize, pattern ); }
    SON8_OVERGLAD_DEPR polygon_offset_clamp( GLfloat factor, GLfloat units, GLfloat clamp )
    { glPolygonOffsetClamp( factor, units, clamp ); }

    // Chapter 17: Writing Fragments and Samples to the Framebuffer

    SON8_OVERGLAD_DEPR named_framebuffer_draw_buffer( GLuint framebuffer, GLenum buf )
    { glNamedFramebufferDrawBuffer( framebuffer, buf ); }
    SON8_OVERGLAD_DEPR named_framebuffer_draw_buffers( GLuint framebuffer, GLsizei n, GLenum const *bufs )
    { glNamedFramebufferDrawBuffers( framebuffer, n, bufs ); }
    SON8_OVERGLAD_DEPR clear_named_framebuffer( GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLint const *value )
    { glClearNamedFramebufferiv( framebuffer, buffer, drawbuffer, value ); }
    SON8_OVERGLAD_DEPR clear_named_framebuffer( GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat const *value )
    { glClearNamedFramebufferfv( framebuffer, buffer, drawbuffer, value ); }
    SON8_OVERGLAD_DEPR clear_named_framebuffer( GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLuint const *value )
    { glClearNamedFramebufferuiv( framebuffer, buffer, drawbuffer, value ); }
    SON8_OVERGLAD_DEPR clear_named_framebuffer( GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil )
    { glClearNamedFramebufferfi( framebuffer, buffer, drawbuffer, depth, stencil ); }
    SON8_OVERGLAD_DEPR invalidate_named_framebuffer_sub_data( GLuint framebuffer, GLsizei numAttachments, GLenum const *attachments
        , GLint x, GLint y, GLsizei width, GLsizei height )
    { glInvalidateNamedFramebufferSubData( framebuffer, numAttachments, attachments, x, y, width, height ); }
    SON8_OVERGLAD_DEPR invalidate_named_framebuffer_data( GLuint framebuffer, GLsizei numAttachments, GLenum const *attachments )
    { glInvalidateNamedFramebufferData( framebuffer, numAttachments, attachments ); }

    // Chapter 18: Drawing, Reading, and Copying Pixels

    SON8_OVERGLAD_DEPR named_framebuffer_read_buffer( GLuint framebuffer, GLenum src )
    { glNamedFramebufferReadBuffer( framebuffer, src ); }
    SON8_OVERGLAD_DEPR read_pixels( GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid *data )
    { glReadnPixels( x, y, width, height, format, type, bufSize, data ); }
    SON8_OVERGLAD_DEPR blit_named_framebuffer( GLuint readFramebuffer, GLuint drawFramebuffer
        , GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1
        , GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1
        , GLbitfield mask, GLenum filter )
    { glBlitNamedFramebuffer( readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter ); }

    // Chapter 21: Special Functions

    SON8_OVERGLAD_DEPR get_map( GLenum map, GLenum value, GLsizei bufSize, GLint *data )
    { glGetnMapiv( map, value, bufSize, data ); }
    SON8_OVERGLAD_DEPR get_map( GLenum map, GLenum value, GLsizei bufSize, GLfloat *data )
    { glGetnMapfv( map, value, bufSize, data ); }
    SON8_OVERGLAD_DEPR get_map( GLenum map, GLenum value, GLsizei bufSize, GLdouble *data )
    { glGetnMapdv( map, value, bufSize, data ); }

    // Chapter 22

    SON8_OVERGLAD_DEPR get_transform_feedback( GLuint xfb, GLenum pname, GLint *param )
    { glGetTransformFeedbackiv( xfb, pname, param ); }
    SON8_OVERGLAD_DEPR get_transform_feedback( GLuint xfb, GLenum pname, GLuint index, GLint *param )
    { glGetTransformFeedbacki_v( xfb, pname, index, param ); }
    SON8_OVERGLAD_DEPR get_transform_feedback( GLuint xfb, GLenum pname, GLuint index, GLint64 *param )
    { glGetTransformFeedbacki64_v( xfb, pname, index, param ); }
#   endif // deprecated functions
} // namespace son8::overglad
#endif // version 4.6

#endif // INCLUDE GUARD

// Apache License 2.0
// NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
// SPDX-License-Identifier: Apache-2.0
// lib: `overglad` C++17 Wrapper Over GLAD Loader
// Ⓒ Copyright (c) 2025-2026 Oleg'Ease'Kharchuk ᦒ
