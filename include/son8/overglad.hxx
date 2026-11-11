#ifndef SON8_OVERGLAD_HXX
#define SON8_OVERGLAD_HXX

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
#define SON8_OVERGLAD_VERSION 0x0406CE
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
#ifndef SON8_OVERGLAD_PROFILE_CORE
    // `size 1`
    using Array1i    = std::array< GLint, 1 >;
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
    // `size 16`
    using Array16f   = std::array< GLfloat, 16 >;
    using Array16d   = std::array< GLdouble, 16 >;
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
            commit_Unchecked( view.size( ));

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

    template< GLenum Param, typename Type, unsigned Count = 1u >
    class Get_ final {
        static_assert( Count, "Getter required to have at least 1 value" );
        using Flat_ = std::array< Type, Count >;
        Flat_ values_;
    public:
        // NOTE: intentionally uninitialized on default construction
        // \ as 0 is not a universal default state value,
        // \ so zero-initializing does not provides any benefits
        Get_( ) noexcept { }
        // templated accessors
        template< unsigned count = Count >
        auto value( ) & noexcept -> Type & {
            static_assert( 1u == count
                , "state value() call requires parameter with only one value" );
            return values_[0];
        }
        template< unsigned count = Count >
        auto value( ) const & noexcept -> Type const & {
            static_assert( 1u == count
                , "state value() call requires parameter with only one value" );
            return values_[0];
        }
        template< unsigned count = Count >
        auto operator[]( unsigned i ) & noexcept -> Type & {
            static_assert( 2u <= count
                , "state array subscript operator requires parameter with two or more values" );
            return values_[i];
        }
        template< unsigned count = Count >
        auto operator[]( unsigned i ) const & noexcept -> Type const & {
            static_assert( 2u <= count
                , "state array subscript operator requires parameter with two or more values" );
            return values_[i];
        }
        constexpr
        auto param( ) const noexcept -> GLenum { return Param; }
        constexpr
        auto size( ) const noexcept -> std::size_t { return Count; }
        // const accessors
        auto array( ) const & noexcept -> Flat_ const & { return values_; }
        auto data( ) const & noexcept -> Type const * { return values_.data( ); }
        auto begin( ) const & noexcept -> Type const * { return data( ); }
        auto end( ) const & noexcept -> Type const * { return data( ) + Count; }
        // mutable accessors
        auto array( ) & noexcept -> Flat_ & { return values_; }
        auto data( ) & noexcept -> Type * { return values_.data( ); }
        auto begin( ) & noexcept -> Type * { return data( ); }
        auto end( ) & noexcept -> Type * { return data( ) + Count; }
    }; // class `Getter_`
    // version 1.1 states
    using Renderer = Get_< 0x1F01u, std::string_view >;
    using Version = Get_< 0x1F02, std::string_view >;
    using Extensions = Get_< 0x1F03u, std::string_view >;
    // temp






#ifdef SON8_OVERGLAD_VERSION_1_1
    // -- core
    using PointSize                     = Get_< 0x0B11, GLfloat >;
    using PointSizeRange                = Get_< 0x0B12, GLfloat, 2u >;
    using PointSizeGranularity          = Get_< 0x0B13, GLfloat >;
    using LineSmooth                    = Get_< 0x0B20, GLboolean >;
    using LineWidth                     = Get_< 0x0B21, GLfloat >;
    using LineWidthRange                = Get_< 0x0B22, GLfloat, 2 >;
    using LineWidthGranularity          = Get_< 0x0B23, GLfloat >;
    using PolygonMode                   = Get_< 0x0B40, GLint, 2u >;
    using PolygonSmooth                 = Get_< 0x0B41, GLboolean >;
    using CullFace                      = Get_< 0x0B44, GLboolean >;
    using CullFaceMode                  = Get_< 0x0B45, GLint >;
    using FrontFace                     = Get_< 0x0B46, GLint >;
    using DepthRange                    = Get_< 0x0B70, GLfloat, 2u >;
    using DepthTest                     = Get_< 0x0B71, GLboolean >;
    using DepthWritemask                = Get_< 0x0B72, GLboolean >;
    using DepthClearValue               = Get_< 0x0B73, GLfloat >;
    using DepthFunc                     = Get_< 0x0B74, GLint >;
    using StencilTest                   = Get_< 0x0B90, GLboolean >;
    using StencilClearValue             = Get_< 0x0B91, GLint >;
    using StencilFunc                   = Get_< 0x0B92, GLint >;
    using StencilValueMask              = Get_< 0x0B93, GLint >;
    using StencilFail                   = Get_< 0x0B94, GLint >;
    using StencilPassDepthFail          = Get_< 0x0B95, GLint >;
    using StencilPassDepthPass          = Get_< 0x0B96, GLint >;
    using StencilRef                    = Get_< 0x0B97, GLint >;
    using StencilWritemask              = Get_< 0x0B98, GLint >;
    using Viewport                      = Get_< 0x0BA2, GLint, 4u >;
    using Dither                        = Get_< 0x0BD0, GLboolean >;
    using BlendDst                      = Get_< 0x0BE0, GLint >;
    using BlendSrc                      = Get_< 0x0BE1, GLint >;
    using Blend                         = Get_< 0x0BE2, GLboolean >;
    using LogicOpMode                   = Get_< 0x0BF0, GLint >;
    using ColorLogicOp                  = Get_< 0x0BF2, GLboolean >;
    using DrawBuffer                    = Get_< 0x0C01, GLint >;
    using ReadBuffer                    = Get_< 0x0C02, GLint >;
    using ScissorBox                    = Get_< 0x0C10, GLint, 4u >;
    using ScissorTest                   = Get_< 0x0C11, GLboolean >;
    using ColorClearValue               = Get_< 0x0C22, GLfloat, 4u >;
    using ColorWritemask                = Get_< 0x0C23, GLboolean, 4u >;
    using Doublebuffer                  = Get_< 0x0C32, GLboolean >;
    using Stereo                        = Get_< 0x0C33, GLboolean >;
    using LineSmoothHint                = Get_< 0x0C52, GLint >;
    using PolygonSmoothHint             = Get_< 0x0C53, GLint >;
    using UnpackSwapBytes               = Get_< 0x0CF0, GLboolean >;
    using UnpackLSBfirst                = Get_< 0x0CF1, GLboolean >;
    using UnpackRowLength               = Get_< 0x0CF2, GLint >;
    using UnpackSkipRows                = Get_< 0x0CF3, GLint >;
    using UnpackSkipPixels              = Get_< 0x0CF4, GLint >;
    using UnpackAlignment               = Get_< 0x0CF5, GLint >;
    using PackSwapBytes                 = Get_< 0x0D00, GLboolean >;
    using PackLSBfirst                  = Get_< 0x0D01, GLboolean >;
    using PackRowLength                 = Get_< 0x0D02, GLint >;
    using PackSkipRows                  = Get_< 0x0D03, GLint >;
    using PackSkipPixels                = Get_< 0x0D04, GLint >;
    using PackAlignment                 = Get_< 0x0D05, GLint >;
    using MaxClipPlanes                 = Get_< 0x0D32, GLint >;
    using MaxTextureSize                = Get_< 0x0D33, GLint >;
    using MaxViewportDims               = Get_< 0x0D3A, GLint, 2u >;
    using SubpixelBits                  = Get_< 0x0D50, GLint >;
    using PolygonOffsetUnits            = Get_< 0x2A00, GLfloat >;
    using PolygonOffsetPoint            = Get_< 0x2A01, GLboolean >;
    using PolygonOffsetLine             = Get_< 0x2A02, GLboolean >;
    using ClipPlane0                    = Get_< 0x3000, GLboolean >;
    using ClipPlane1                    = Get_< 0x3001, GLboolean >;
    using ClipPlane2                    = Get_< 0x3002, GLboolean >;
    using ClipPlane3                    = Get_< 0x3003, GLboolean >;
    using ClipPlane4                    = Get_< 0x3004, GLboolean >;
    using ClipPlane5                    = Get_< 0x3005, GLboolean >;
    using PolygonOffsetFill             = Get_< 0x8037, GLboolean >;
    using PolygonOffsetFactor           = Get_< 0x8038, GLfloat >;
    using TextureBinding1D              = Get_< 0x8068, GLint >;
    using TextureBinding2D              = Get_< 0x8069, GLint >;
    // -- comp
#   ifndef SON8_OVERGLAD_PROFILE_CORE
    using CurrentColor                  = Get_< 0x0B00, GLfloat, 4u >;
    using CurrentIndex                  = Get_< 0x0B01, GLint >;
    using CurrentNormal                 = Get_< 0x0B02, GLfloat, 3u >;
    using CurrentTextureCoords          = Get_< 0x0B03, GLfloat, 4u >;
    using CurrentRasterColor            = Get_< 0x0B04, GLfloat, 4u >;
    using CurrentRasterIndex            = Get_< 0x0B05, GLint >;
    using CurrentRasterTextureCoords    = Get_< 0x0B06, GLfloat, 4u >;
    using CurrentRasterPosition         = Get_< 0x0B07, GLfloat, 4u >;
    using CurrentRasterPositionValid    = Get_< 0x0B08, GLboolean >;
    using CurrentRasterDistance         = Get_< 0x0B09, GLfloat >;
    using PointSmooth                   = Get_< 0x0B10, GLboolean >;
    using LineStipple                   = Get_< 0x0B24, GLboolean >;
    using LineStipplePattern            = Get_< 0x0B25, GLint >;
    using LineStippleRepeat             = Get_< 0x0B26, GLint >;
    using ListMode                      = Get_< 0x0B30, GLint >;
    using MaxListNesting                = Get_< 0x0B31, GLint >;
    using ListBase                      = Get_< 0x0B32, GLint >;
    using ListIndex                     = Get_< 0x0B33, GLint >;
    using PolygonStipple                = Get_< 0x0B42, GLboolean >;
    using EdgeFlag                      = Get_< 0x0B43, GLboolean >;
    using Lighting                      = Get_< 0x0B50, GLboolean >;
    using LightModelLocalViewer         = Get_< 0x0B51, GLboolean >;
    using LightModelTwoSide             = Get_< 0x0B52, GLboolean >;
    using LightModelAmbient             = Get_< 0x0B53, GLfloat, 4u >;
    using ShadeModel                    = Get_< 0x0B54, GLint >;
    using ColorMaterialFace             = Get_< 0x0B55, GLint >;
    using ColorMaterialParameter        = Get_< 0x0B56, GLint >;
    using ColorMaterial                 = Get_< 0x0B57, GLboolean >;
    using Fog                           = Get_< 0x0B60, GLboolean >;
    using FogIndex                      = Get_< 0x0B61, GLfloat >;
    using FogDensity                    = Get_< 0x0B62, GLfloat >;
    using FogStart                      = Get_< 0x0B63, GLfloat >;
    using FogEnd                        = Get_< 0x0B64, GLfloat >;
    using FogMode                       = Get_< 0x0B65, GLint >;
    using FogColor                      = Get_< 0x0B66, GLfloat, 4u >;
    using AccumClearValue               = Get_< 0x0B80, GLfloat, 4u >;
    using MatrixMode                    = Get_< 0x0BA0, GLint >;
    using Normalize                     = Get_< 0x0BA1, GLboolean >;
    using ModelviewStackDepth           = Get_< 0x0BA3, GLint >;
    using ProjectionStackDepth          = Get_< 0x0BA4, GLint >;
    using TextureStackDepth             = Get_< 0x0BA5, GLint >;
    using ModelviewMatrix               = Get_< 0x0BA6, GLfloat, 16u >;
    using ProjectionMatrix              = Get_< 0x0BA7, GLfloat, 16u >;
    using TextureMatrix                 = Get_< 0x0BA8, GLfloat, 16u >;
    using AttribStackDepth              = Get_< 0x0BB0, GLint >;
    using ClientAttribStackDepth        = Get_< 0x0BB1, GLint >;
    using AlphaTest                     = Get_< 0x0BC0, GLboolean >;
    using AlphaTestFunc                 = Get_< 0x0BC1, GLint >;
    using AlphaTestRef                  = Get_< 0x0BC2, GLfloat >;
    using IndexLogicOp                  = Get_< 0x0BF1, GLboolean >;
    using AuxBuffers                    = Get_< 0x0C00, GLint >;
    using IndexClearValue               = Get_< 0x0C20, GLfloat >;
    using IndexWritemask                = Get_< 0x0C21, GLint >;
    using IndexMode                     = Get_< 0x0C30, GLboolean >;
    using RGBAmode                      = Get_< 0x0C31, GLboolean >;
    using RenderMode                    = Get_< 0x0C40, GLint >;
    using PerspectiveCorrectionHint     = Get_< 0x0C50, GLint >;
    using PointSmoothHint               = Get_< 0x0C51, GLint >;
    using FogHint                       = Get_< 0x0C54, GLint >;
    using TextureGenS                   = Get_< 0x0C60, GLboolean >;
    using TextureGenT                   = Get_< 0x0C61, GLboolean >;
    using TextureGenR                   = Get_< 0x0C62, GLboolean >;
    using TextureGenQ                   = Get_< 0x0C63, GLboolean >;

    // TODO table 8.3 from 4.6 comp profile spec `?_SIZE (0x0C70)`

    using MapColor                      = Get_< 0x0D10, GLboolean >;
    using MapStencil                    = Get_< 0x0D11, GLboolean >;
    using IndexShift                    = Get_< 0x0D12, GLint >;
    using IndexOffset                   = Get_< 0x0D13, GLint >;
    using RedScale                      = Get_< 0x0D14, GLfloat >;
    using RedBias                       = Get_< 0x0D15, GLfloat >;
    using ZoomX                         = Get_< 0x0D16, GLfloat >;
    using ZoomY                         = Get_< 0x0D17, GLfloat >;
    using GreenScale                    = Get_< 0x0D18, GLfloat >;
    using GreenBias                     = Get_< 0x0D19, GLfloat >;
    using BlueScale                     = Get_< 0x0D1A, GLfloat >;
    using BlueBias                      = Get_< 0x0D1B, GLfloat >;
    using AlphaScale                    = Get_< 0x0D1C, GLfloat >;
    using AlphaBias                     = Get_< 0x0D1D, GLfloat >;
    using DepthScale                    = Get_< 0x0D1E, GLfloat >;
    using DepthBias                     = Get_< 0x0D1F, GLfloat >;
    using MaxEvalOrder                  = Get_< 0x0D30, GLint >;
    using MaxLights                     = Get_< 0x0D31, GLint >;
    using MaxPixelMapTable              = Get_< 0x0D34, GLint >;
    using MaxAttribStackDepth           = Get_< 0x0D35, GLint >;
    using MaxModelviewStackDepth        = Get_< 0x0D36, GLint >;
    using MaxNameStackDepth             = Get_< 0x0D37, GLint >;
    using MaxProjectionStackDepth       = Get_< 0x0D38, GLint >;
    using MaxTextureStackDepth          = Get_< 0x0D39, GLint >;
    using MaxClientAttribStackDepth     = Get_< 0x0D3B, GLint >;
    using IndexBits                     = Get_< 0x0D51, GLint >;
    using RedBits                       = Get_< 0x0D52, GLint >;
    using GreenBits                     = Get_< 0x0D53, GLint >;
    using BlueBits                      = Get_< 0x0D54, GLint >;
    using AlphaBits                     = Get_< 0x0D55, GLint >;
    using DepthBits                     = Get_< 0x0D56, GLint >;
    using StencilBits                   = Get_< 0x0D57, GLint >;
    using AccumRedBits                  = Get_< 0x0D58, GLint >;
    using AccumGreenBits                = Get_< 0x0D59, GLint >;
    using AccumBlueBits                 = Get_< 0x0D5A, GLint >;
    using AccumAlphaBits                = Get_< 0x0D5B, GLint >;
    using NameStackDepth                = Get_< 0x0D70, GLint >;
    using AutoNormal                    = Get_< 0x0D80, GLboolean >;

    // TODO `MAP_1 (0x0D90-8)` and `MAP_2 (0x0DB0-8)`

    using Map1GridDomain                = Get_< 0x0DD0, GLfloat, 2u >;
    using Map1GridSegments              = Get_< 0x0DD1, GLint >;
    using Map2GridDomain                = Get_< 0x0DD2, GLfloat, 4u >;
    using Map2GridSegments              = Get_< 0x0DD3, GLint, 2u >;
    using Texture1D                     = Get_< 0x0DE0, GLboolean >;
    using Texture2D                     = Get_< 0x0DE1, GLboolean >;
    using FeedbackBufferSize            = Get_< 0x0DF1, GLint >;
    using FeedbackBufferType            = Get_< 0x0DF2, GLint >;
    using SelectionBufferSize           = Get_< 0x0DF4, GLint >;
    using Light0                        = Get_< 0x4000, GLboolean >;
    using Light1                        = Get_< 0x4001, GLboolean >;
    using Light2                        = Get_< 0x4002, GLboolean >;
    using Light3                        = Get_< 0x4003, GLboolean >;
    using Light4                        = Get_< 0x4004, GLboolean >;
    using Light5                        = Get_< 0x4005, GLboolean >;
    using Light6                        = Get_< 0x4006, GLboolean >;
    using Light7                        = Get_< 0x4007, GLboolean >;
    using VertexArray                   = Get_< 0x8074, GLboolean >;
    using NormalArray                   = Get_< 0x8075, GLboolean >;
    using ColorArray                    = Get_< 0x8076, GLboolean >;
    using IndexArray                    = Get_< 0x8077, GLboolean >;
    using TextureCoordArray             = Get_< 0x8078, GLboolean >;
    using EdgeFlagArray                 = Get_< 0x8079, GLboolean >;
    using VertexArraySize               = Get_< 0x807A, GLint >;
    using VertexArrayType               = Get_< 0x807B, GLint >;
    using VertexArrayStride             = Get_< 0x807C, GLint >;
    using NormalArrayType               = Get_< 0x807E, GLint >;
    using NormalArrayStride             = Get_< 0x807F, GLint >;
    using ColorArraySize                = Get_< 0x8081, GLint >;
    using ColorArrayType                = Get_< 0x8082, GLint >;
    using ColorArrayStride              = Get_< 0x8083, GLint >;
    using IndexArrayType                = Get_< 0x8085, GLint >;
    using IndexArrayStride              = Get_< 0x8086, GLint >;
    using TextureCoordArraySize         = Get_< 0x8088, GLint >;
    using TextureCoordArrayType         = Get_< 0x8089, GLint >;
    using TextureCoordArrayStride       = Get_< 0x808A, GLint >;
    using EdgeFlagArrayStride           = Get_< 0x808C, GLint >;
#   endif // not core profile
#endif // version 1.1 states

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
    SON8_OVERGLAD_DEPR multi_draw_arrays_indirect_count( GLenum mode, GLvoid const *indirect, GLintptr drawcount, GLintptr maxdrawcount, GLsizei stride )
    { glMultiDrawArraysIndirectCount( mode, indirect, drawcount, maxdrawcount, stride ); }
    SON8_OVERGLAD_DEPR multi_draw_elements_indirect_count( GLenum mode, GLenum type, GLvoid const *indirect, GLintptr drawcount, GLintptr maxdrawcount, GLsizei stride )
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
