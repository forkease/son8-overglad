#ifndef SON8_TEMP_HXX
#define SON8_TEMP_HXX

#include <glad/son8/gl/header.h>

namespace son8::overglad::state {
// version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_1
#   ifndef SON8_OVERGLAD_PROFILE_CORE
    // -- compatibility
    // TODO table 8.3 from 4.6 comp profile spec `?_SIZE (0x0C70)`
    // TODO `MAP_1 (0x0D90-8)` and `MAP_2 (0x0DB0-8)`
#   endif // not core profile
#endif // version 1.1 states
    // `IsEnabled`
    template< unsigned Tag >
    struct Capability_ {
        static_assert( Tag < 3
            , "son8::overglad implementation details IsState_ Tag requires to be 0,1, or 2" );
        // NOTE: must be not scoped
        enum Enum : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
            Polygon_Smooth               = 0x0B41,
            Cull_Face                    = 0x0B44,
            Depth_Test                   = 0x0B71,
            Stencil_Test                 = 0x0B90,
            Dither                      = 0x0BD0,
            Color_Logic_Op                = 0x0BF2,
            Polygon_Offset_Point          = 0x2A01,
            Polygon_Offset_Line           = 0x2A02,
            Polygon_Offset_Fill           = 0x8037,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
            Point_Smooth                 = 0x0B10,
            Line_Smooth                  = 0x0B20,
            Line_Stipple                 = 0x0B24,
            Polygon_Stipple              = 0x0B42,
            Lighting                    = 0x0B50,
            Color_Material               = 0x0B57,
            Fog                         = 0x0B60,
            Normalize                   = 0x0BA1,
            Alpha_Test                   = 0x0BC0,
            Index_Logic_Op                = 0x0BF1,
            Texture_Gen_S                 = 0x0C60,
            Texture_Gen_T                 = 0x0C61,
            Texture_Gen_R                 = 0x0C62,
            Texture_Gen_Q                 = 0x0C63,
            Auto_Normal                  = 0x0D80,
            Texture_1D                   = 0x0DE0,
            Texture_2D                   = 0x0DE1,
            Clip_Distance_0                  = 0x3000,
            Clip_Distance_1                  = 0x3001,
            Clip_Distance_2                  = 0x3002,
            Clip_Distance_3                  = 0x3003,
            Clip_Distance_4                  = 0x3004,
            Clip_Distance_5                  = 0x3005,
            Clip_Distance_6                  = 0x3006,
            Clip_Distance_7                  = 0x3007,
            Light_0                      = 0x4000,
            Light_1                      = 0x4001,
            Light_2                      = 0x4002,
            Light_3                      = 0x4003,
            Light_4                      = 0x4004,
            Light_5                      = 0x4005,
            Light_6                      = 0x4006,
            Light_7                      = 0x4007,
            Vertex_Array            = 0x8074,
            Normal_Array            = 0x8075,
            Color_Array             = 0x8076,
            Index_Array             = 0x8077,
            Texture_Coord_Array     = 0x8078,
            Edge_Flag_Array         = 0x8079,
#   endif // not core profile
#endif // version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_5
#   ifndef SON8_OVERGLAD_PROFILE_CORE
            Rescale_Normal               = 0x803A,
            Texture_3D                   = 0x806F,
            Multisample                 = 0x809D,
            Sample_Alpha_To_Coverage       = 0x809E,
            Sample_Alpha_To_One            = 0x809F,
            Sample_Coverage              = 0x80A0,
            Fog_Coord_Array         = 0x8457,
            Color_Sum                    = 0x8458,
            Secondary_Color_Array   = 0x845E,
            Texture_Cube_Map              = 0x8513,
#   endif // not core profile
#endif // version 1.5 states
#ifdef SON8_OVERGLAD_VERSION_2_1
            Vertex_Program_Point_Size      = 0x8642,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
            Vertex_Program_Two_Side        = 0x8643,
            Point_Sprite                 = 0x8861,
#   endif // not core profile
#endif // version 2.1 states
#ifdef SON8_OVERGLAD_VERSION_3_3
            Depth_Clamp                  = 0x864F,
            Texture_Cube_Map_Seamless      = 0x884F,
            Framebuffer_SRGB             = 0x8DB9,
            Sample_Mask                  = 0x8E51,
            Primitive_Restart            = 0x8F9D,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 3.3 states
#ifdef SON8_OVERGLAD_VERSION_4_3
            Debug_Output_Synchronous                      = 0x8242,
            Sample_Shading               = 0x8C36,
            Rasterizer_Discard           = 0x8C89,
            Debug_Output                 = 0x92E0,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 4.3 states
#ifdef SON8_OVERGLAD_VERSION_4_6
            Primitive_Restart_Fixed_Index = 0x8D69,
            Texture_Rectangle = 0x84F5
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 4.6 states
        };
        constexpr Capability_( ) = delete;
        constexpr Capability_( Enum init ) : value_{ init } { }
        constexpr explicit operator GLenum( ) const noexcept { return value_; }
        constexpr auto value( ) const noexcept -> GLenum { return value_; }
        constexpr bool operator==( Capability_ other ) const noexcept { return value_ == other.value_; }
        constexpr bool operator!=( Capability_ other ) const noexcept { return value_ != other.value_; }
        constexpr bool operator==( GLenum value ) const noexcept { return value_ == value; }
        constexpr bool operator!=( GLenum value ) const noexcept { return value_ != value; }
    private:
        Enum value_;
    };
    using Disable   = Capability_< 0 >;
    using Enable    = Capability_< 1 >;
    using Is        = Capability_< 2 >;
    // static Is a{ };
    // `GetBoolean`
    enum class Boolean : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
        Depth_Writemask              = 0x0B72,
        Blend                       = 0x0BE2,
        ScissorTest                 = 0x0C11,
        Doublebuffer                = 0x0C32,
        Stereo                      = 0x0C33,
        Unpack_Swap_Bytes             = 0x0CF0,
        Unpack_LSB_First              = 0x0CF1,
        Pack_Swap_Bytes               = 0x0D00,
        Pack_LSB_First                = 0x0D01,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Current_Raster_Position_Valid   = 0x0B08,
        Edge_Flag                    = 0x0B43,
        Light_Model_Local_Viewer       = 0x0B51,
        Light_Model_Two_Side           = 0x0B52,
        Index_Mode                   = 0x0C30,
        RGBA_Mode                    = 0x0C31,
        Map_Color                    = 0x0D10,
        Map_Stencil                  = 0x0D11,
#   endif // not core profile
#endif // version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_5
        Sample_Coverage_Invert        = 0x80AB,
#endif // version 1.5 states
#ifdef SON8_OVERGLAD_VERSION_2_1
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 2.1 states
#ifdef SON8_OVERGLAD_VERSION_3_3

#endif // version 3.3 states
#ifdef SON8_OVERGLAD_VERSION_4_3
#endif // version 4.3 states
#ifdef SON8_OVERGLAD_VERSION_4_6
        Primitive_Restart_For_Patches_Supported = 0x8221,
        Shader_Compiler = 0x8DFA,
        Transform_Feedback_Paused = 0x8E23,
        Transform_Feedback_Active = 0x8E24,
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
        Point_Size                       = 0x0B11,
        Point_Size_Granularity            = 0x0B13,
        Line_Width                       = 0x0B21,
        Smooth_Line_Width_Granularity      = 0x0B23,
        Depth_Clear_Value                 = 0x0B73,
        Polygon_Offset_Units              = 0x2A00,
        Polygon_Offset_Factor             = 0x8038,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Current_Raster_Distance         = 0x0B09,
        Fog_Index                        = 0x0B61,
        Fog_Density                      = 0x0B62,
        Fog_Start                        = 0x0B63,
        Fog_End                          = 0x0B64,
        Alpha_Test_Ref                    = 0x0BC2,
        Index_Clear_Value                 = 0x0C20,
        Red_Scale                        = 0x0D14,
        Red_Bias                         = 0x0D15,
        Zoom_X                           = 0x0D16,
        Zoom_Y                           = 0x0D17,
        Green_Scale                      = 0x0D18,
        Green_Bias                       = 0x0D19,
        Blue_Scale                       = 0x0D1A,
        Blue_Bias                        = 0x0D1B,
        Alpha_Scale                      = 0x0D1C,
        Alpha_Bias                       = 0x0D1D,
        Depth_Scale                      = 0x0D1E,
        Depth_Bias                       = 0x0D1F,
#   endif // not core profile
#endif // version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_5
        Sample_Coverage_Value                         = 0x80AA,
        Max_Texture_LOD_Bias               = 0x84FD,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Point_Size_Min                    = 0x8126,
        Point_Size_Max                    = 0x8127,
        Current_Fog_Coord               = 0x8453,
#   endif // not core profile
#endif // version 1.5 states
#ifdef SON8_OVERGLAD_VERSION_4_3
        Min_Shading_Sample_Value           = 0x8C37,
        Min_Fragment_Interpolation_Offset  = 0x8E5B,
        Max_Fragment_Interpolation_Offset  = 0x8E5C,
#endif // version 4.3 states
#ifdef SON8_OVERGLAD_VERSION_4_6
        Point_Fade_Threashold_Size      = 0x8128,
        Max_Texture_Max_Anisotropy = 0x84FF,
        Polygon_Offset_Clamp = 0x8E1B,
#endif // version 4.6 states
    }; // enum class `Float`

    enum class Float2 : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
        Point_Size_Range          = 0x0B12,
        Smooth_Line_Width_Range    = 0x0B22,
        DepthRange              = 0x0B70,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Map1GridDomain          = 0x0DD0,
#   endif // not core profile
#endif // version 1.1 states
    // version 1.5 states
#ifdef SON8_OVERGLAD_VERSION_1_5
        Aliased_Line_Width_Range   = 0x846E,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Aliased_Point_Size_Range   = 0x846D,
#   endif // not core profile
#endif // version 1.5 states
#ifdef SON8_OVERGLAD_VERSION_4_3
        Viewport_Bounds_Range                         = 0x825D,
        Patch_Default_Inner_Level  = 0x8E73,
#endif // version 4.3 states
    }; // enum class `Float2`

    enum class Float3 : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Current_Normal              = 0x0B02,
#   endif // not core profile
#endif // version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_5
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Point_Distance_Attenuation    = 0x8129,
#   endif // not core profile
#endif // version 1.5 states
    }; // enum class `Float3`

    enum class Float4 : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
        Color_Clear_Value                 = 0x0C22,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Current_Color                   = 0x0B00,
        Current_Texture_Coords          = 0x0B03,
        Current_Raster_Color            = 0x0B04,
        Current_Raster_Texture_Coords   = 0x0B06,
        Current_Raster_Position         = 0x0B07,
        Light_Model_Ambient               = 0x0B53,
        Fog_Color                        = 0x0B66,
        Accum_Clear_Value                 = 0x0B80,
        Map2GridDomain                  = 0x0DD2,
#   endif // not core profile
#endif // version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_5
        Blend_Color                      = 0x8005,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Current_Secondary_Color         = 0x8459,
        Current_Raster_Secondary_Color  = 0x845F, // TODO: not sure if 1.5
#   endif // not core profile
#endif // version 1.5 states
#ifdef SON8_OVERGLAD_VERSION_4_3
        Patch_Default_Outer_Level          = 0x8E74,
#endif // version 4.3 states
    }; // enum class `Float4`

    enum class Float16 : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Modelview_Matrix           = 0x0BA6,
        Projection_Matrix          = 0x0BA7,
        Texture_Matrix             = 0x0BA8,
#   endif // not core profile
#endif // version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_5
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Transpose_Modelview_Matrix  = 0x84E3,
        Transpose_Projection_Matrix = 0x84E4,
        Transpose_Texture_Matrix    = 0x84E5,
#   endif // not core profile
#endif // version 1.5 states
    }; // enum class `Float16`
    // `GetInteger`
    enum class Integer : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
        Cull_Face_Mode                                = 0x0B45,
        Front_Face                                   = 0x0B46,
        Depth_Func                                   = 0x0B74,
        Stencil_Clear_Value                           = 0x0B91,
        Stencil_Func                                 = 0x0B92,
        Stencil_Value_Mask                            = 0x0B93,
        Stencil_Fail                                 = 0x0B94,
        Stencil_Pass_Depth_Fail                        = 0x0B95,
        Stencil_Pass_Depth_Pass                        = 0x0B96,
        Stencil_Ref                                  = 0x0B97,
        Stencil_Writemask                            = 0x0B98,
        BlendDst                                    = 0x0BE0,
        BlendSrc                                    = 0x0BE1,
        Logic_Op_Mode                                 = 0x0BF0,
        Draw_Buffer                                  = 0x0C01,
        Read_Buffer                                  = 0x0C02,
        Line_Smooth_Hint                              = 0x0C52,
        Polygon_Smooth_Hint                           = 0x0C53,
        Unpack_Row_Length                             = 0x0CF2,
        Unpack_Skip_Rows                              = 0x0CF3,
        UnpackSkipPixels                            = 0x0CF4,
        Unpack_Alignment                             = 0x0CF5,
        Pack_Row_Length                               = 0x0D02,
        Pack_Skip_Rows                                = 0x0D03,
        Pack_Skip_Pixels                              = 0x0D04,
        Pack_Alignment                               = 0x0D05,
        Max_Clip_Planes                               = 0x0D32,
        Max_Texture_Size                              = 0x0D33,
        Subpixel_Bits                                = 0x0D50,
        Texture_Binding_1D                            = 0x8068,
        Texture_Binding_2D                            = 0x8069,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Current_Index                               = 0x0B01,
        Current_Raster_Index                        = 0x0B05,
        Line_Stipple_Pattern                          = 0x0B25,
        Line_Stipple_Repeat                           = 0x0B26,
        List_Mode                                    = 0x0B30,
        Max_List_Nesting                              = 0x0B31,
        List_Base                                    = 0x0B32,
        List_Index                                   = 0x0B33,
        Shade_Model                                  = 0x0B54,
        Color_Material_Face                           = 0x0B55,
        Color_Material_Parameter                      = 0x0B56,
        Fog_Mode                                     = 0x0B65,
        Matrix_Mode                                  = 0x0BA0,
        Modelview_Stack_Depth                         = 0x0BA3,
        Projection_Stack_Depth                        = 0x0BA4,
        Texture_Stack_Depth                           = 0x0BA5,
        Attrib_Stack_Depth                            = 0x0BB0,
        Client_Attrib_Stack_Depth                      = 0x0BB1,
        Alpha_Test_Func                               = 0x0BC1,
        Aux_Buffers                                  = 0x0C00,
        Index_Writemask                              = 0x0C21,
        Render_Mode                                  = 0x0C40,
        Perspective_Correction_Hint                   = 0x0C50,
        Point_Smooth_Hint                             = 0x0C51,
        Fog_Hint                                     = 0x0C54,
        Index_Shift                                  = 0x0D12,
        Index_Offset                                 = 0x0D13,
        Max_Eval_Order                                = 0x0D30,
        Max_Lights                                   = 0x0D31,
        Max_Pixel_Map_Table                            = 0x0D34,
        Max_Attrib_Stack_Depth                         = 0x0D35,
        Max_Modelview_Stack_Depth                      = 0x0D36,
        Max_Name_Stack_Depth                           = 0x0D37,
        Max_Projection_Stack_Depth                     = 0x0D38,
        Max_Texture_Stack_Depth                        = 0x0D39,
        Max_Client_Attrib_Stack_Depth                   = 0x0D3B,
        Index_Bits                                   = 0x0D51,
        Red_Bits                                     = 0x0D52,
        Green_Bits                                   = 0x0D53,
        Blue_Bits                                    = 0x0D54,
        Alpha_Bits                                   = 0x0D55,
        Depth_Bits                                   = 0x0D56,
        Stencil_Bits                                 = 0x0D57,
        Accum_Red_Bits                                = 0x0D58,
        Accum_Green_Bits                              = 0x0D59,
        Accum_Blue_Bits                               = 0x0D5A,
        Accum_Alpha_Bits                              = 0x0D5B,
        Name_Stack_Depth                              = 0x0D70,
        Map1GridSegments                            = 0x0DD1,
        Feedback_Buffer_Size                          = 0x0DF1,
        Feedback_Buffer_Type                          = 0x0DF2,
        Selection_Buffer_Size                         = 0x0DF4,
        Vertex_Array_Size                             = 0x807A,
        Vertex_Array_Type                             = 0x807B,
        Vertex_Array_Stride                           = 0x807C,
        Normal_Array_Type                             = 0x807E,
        Normal_Array_Stride                           = 0x807F,
        Color_Array_Size                              = 0x8081,
        Color_Array_Type                              = 0x8082,
        Color_Array_Stride                            = 0x8083,
        Index_Array_Type                              = 0x8085,
        Index_Array_Stride                            = 0x8086,
        Texture_Coord_Array_Size                       = 0x8088,
        Texture_Coord_Array_Type                       = 0x8089,
        Texture_Coord_Array_Stride                     = 0x808A,
        Edge_Flag_Array_Stride                         = 0x808C,
#   endif // not core profile
#endif // version 1.1 states
#ifdef SON8_OVERGLAD_VERSION_1_5
        BlendEquationRGB                            = 0x8009,
        Texture_Binding_3D                            = 0x806A,
        Pack_Skip_Images                              = 0x806B,
        Pack_Image_Height                             = 0x806C,
        Unpack_Skip_Images                            = 0x806D,
        Unpack_Image_Height                           = 0x806E,
        BlendDstRGB                                 = 0x80C8,
        BlendSrcRGB                                 = 0x80C9,
        BlendDstAlpha                               = 0x80CA,
        BlendSrcAlpha                               = 0x80CB,
        Sample_Buffers                               = 0x80A8,
        Samples                                     = 0x80A9,
        Max_Elements_Vertices                         = 0x80E8,
        Max_Elements_Indices                          = 0x80E9,
        Active_Texture                               = 0x84E0,
        Texture_Compression_Hint                      = 0x84EF,
        Texture_Binding_Cube_Map                       = 0x8514,
        Max_Cube_Map_Texture_Size                       = 0x851C,
        Num_Compressed_Texture_Formats                 = 0x86A2,
        CompressedTextureFormats                    = 0x86A3,
        Element_Array_Buffer_Binding                   = 0x8895,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Generate_Mipmap_Hint                          = 0x8192,
        Light_Model_Color_Control                      = 0x81F8,
        Client_Active_Texture                         = 0x84E1,
        Fog_Coord_Src                                 = 0x8450,
        Fog_Coord_Array_Type                           = 0x8454,
        Fog_Coord_Array_Stride                         = 0x8455,
        Secondary_Color_Array_Size                     = 0x845A,
        Secondary_Color_Array_Type                     = 0x845B,
        Secondary_Color_Array_Stride                   = 0x845C,
        Max_Texture_Units                             = 0x84E2,
        Vertex_Array_Buffer_Binding                    = 0x8896,
        Normal_Array_Buffer_Binding                    = 0x8897,
        Color_Array_Buffer_Binding                     = 0x8898,
        Index_Array_Buffer_Binding                     = 0x8899,
        Texture_Coord_Array_Buffer_Binding              = 0x889A,
        Edge_Flag_Array_Buffer_Binding                  = 0x889B,
        Secondary_Color_Array_Buffer_Binding            = 0x889C,
        Fog_Coord_Array_Buffer_Binding                  = 0x889D,
#   endif // not core profile
#endif // version 1.5 states
#ifdef SON8_OVERGLAD_VERSION_2_1
        Stencil_Back_Func                             = 0x8800,
        Stencil_Back_Fail                             = 0x8801,
        Stencil_Back_Pass_Depth_Fail                    = 0x8802,
        Stencil_Back_Pass_Depth_Pass                    = 0x8803,
        Max_Draw_Buffers                              = 0x8824,
        Draw_Buffer_0 = 0x8825,
        Draw_Buffer_1 = 0x8826,
        Draw_Buffer_2 = 0x8827,
        Draw_Buffer_3 = 0x8828,
        Draw_Buffer_4 = 0x8829,
        Draw_Buffer_5 = 0x882A,
        Draw_Buffer_6 = 0x882B,
        Draw_Buffer_7 = 0x882C,
        Draw_Buffer_8 = 0x882D,
        Draw_Buffer_9 = 0x882E,
        Draw_Buffer_10 = 0x882F,
        Draw_Buffer_11 = 0x8830,
        Draw_Buffer_12 = 0x8831,
        Draw_Buffer_13 = 0x8832,
        Draw_Buffer_14 = 0x8833,
        Draw_Buffer_15 = 0x8834,
        BlendEquationAlpha                          = 0x883D,
        Max_Vertex_Attribs                            = 0x8869,
        Max_Texture_Image_Units                        = 0x8872,
        Pixel_Pack_Buffer_Binding                      = 0x88ED,
        Pixel_Unpack_Buffer_Binding                    = 0x88EF,
        Max_Fragment_Uniform_Components                = 0x8B49,
        Max_Vertex_Uniform_Components                  = 0x8B4A,
        MaxVaryingFloats                            = 0x8B4B,
        Max_Vertex_Texture_Image_Units                  = 0x8B4C,
        Max_Combined_Texture_Image_Units                = 0x8B4D,
        Fragment_Shader_Derivative_Hint                = 0x8B8B,
        Current_Program                              = 0x8B8D,
        Point_Sprite_Color_Origin                      = 0x8CA0,
        Stencil_Back_Ref                              = 0x8CA3,
        Stencil_Back_Value_Mask                        = 0x8CA4,
        Stencil_Back_Writemask                        = 0x8CA5,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Max_Texture_Coords                            = 0x8871,
#   endif // not core profile
#endif // version 2.1 states
#ifdef SON8_OVERGLAD_VERSION_3_3
        Major_Version                                = 0x821B,
        Minor_Version                                = 0x821C,
        Num_Extensions                               = 0x821D,
        Max_Renderbuffer_Size                         = 0x84E8,
        Texture_Binding_Rectangle                     = 0x84F6,
        Max_Rectangle_Texture_Size                     = 0x84F8,
        Vertex_Array_Binding                          = 0x85B5,
        Array_Buffer_Binding                          = 0x8894,
        Max_Dual_Source_Draw_Buffers                    = 0x88FC,
        Max_Array_Texture_Layers                       = 0x88FF,
        Min_Program_Texel_Offset                       = 0x8904,
        Max_Program_Texel_Offset                       = 0x8905,
        Sampler_Binding                              = 0x8919,
        Clamp_Read_Color                              = 0x891C,
        Uniform_Buffer_Binding                        = 0x8A28,
        Max_Vertex_Uniform_Blocks                      = 0x8A2B,
        Max_Geometry_Uniform_Blocks                    = 0x8A2C,
        Max_Fragment_Uniform_Blocks                    = 0x8A2D,
        Max_Combined_Uniform_Blocks                    = 0x8A2E,
        Max_Uniform_Buffer_Bindings                    = 0x8A2F,
        Max_Uniform_Block_Size                         = 0x8A30,
        Max_Combined_Vertex_Uniform_Components          = 0x8A31,
        Max_Combined_Geometry_Uniform_Components        = 0x8A32,
        Max_Combined_Fragment_Uniform_Components        = 0x8A33,
        Uniform_Buffer_Offset_Alignment                = 0x8A34,
        Max_Varying_Components                         = 0x8B4B,
        Texture_Binding_1D_Array                       = 0x8C1C,
        Texture_Binding_2D_Array                       = 0x8C1D,
        Max_Geometry_Texture_Image_Units                = 0x8C29,
        Max_Texture_Buffer_Size                        = 0x8C2B,
        Texture_Binding_Buffer                        = 0x8C2C,
        Max_Transform_Feedback_Separate_Components      = 0x8C80,
        Max_Transform_Feedback_Interleaved_Components   = 0x8C8A,
        Max_Transform_Feedback_Separate_Attribs         = 0x8C8B,
        Transform_Feedback_Buffer_Binding              = 0x8C8F,
        Draw_Framebuffer_Binding                      = 0x8CA6,
        Renderbuffer_Binding                         = 0x8CA7,
        Read_Framebuffer_Binding                      = 0x8CAA,
        Max_Color_Attachments                         = 0x8CDF,
        Max_Samples                                  = 0x8D57,
        Max_Geometry_Output_Vertices                   = 0x8DE0,
        Max_Geometry_Total_Output_Components            = 0x8DE1,
        Provoking_Vertex                             = 0x8E4F,
        Max_Sample_Mask_Words                          = 0x8E59,
        Copy_Read_Buffer_Binding                       = 0x8F36,
        Copy_Write_Buffer_Binding                      = 0x8F37,
        Primitive_Restart_Index                       = 0x8F9E,
        Texture_Binding_2D_Multisample                 = 0x9104,
        Texture_Binding_2D_Multisample_Array            = 0x9105,
        MaxColorTextureSamples                      = 0x910E,
        MaxDepthTextureSamples                      = 0x910F,
        MaxIntegerSamples                           = 0x9110,
        Max_Geometry_Input_Components                  = 0x9123,
        Max_Geometry_Output_Components                 = 0x9124,
        Max_Fragment_Input_Components                  = 0x9125,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Clamp_Vertex_Color                            = 0x891A,
        Clamp_Fragment_Color                          = 0x891B,
        Quads_Follow_Provoking_Vertex_Convention        = 0x8E4C,
#   endif // not core profile
#endif // version 3.3 states
#ifdef SON8_OVERGLAD_VERSION_4_3
        Debug_Next_Logged_Message_Length                = 0x8243,
        Program_Pipeline_Binding                      = 0x825A,
        Max_Viewports                                = 0x825B,
        Viewport_Subpixel_Bits                        = 0x825C,
        Max_Debug_Group_Stack_Depth                     = 0x826C,
        Debug_Group_Stack_Depth                        = 0x826D,
        Layer_Provoking_Vertex                        = 0x825E,
        ViewportIndexProvokingVertex                = 0x825F,
        Max_Label_Length                              = 0x82E8,
        Num_Shading_Language_Versions                  = 0x82E9,
        Max_Tess_Control_Input_Components               = 0x886C,
        Max_Tess_Evaluation_Input_Components            = 0x886D,
        Implementation_Color_Read_Type                 = 0x8B9A,
        Implementation_Color_Read_Format               = 0x8B9B,
        Max_Vertex_Uniform_Vectors                     = 0x8DFB,
        Max_Combined_Tess_Control_Uniform_Components     = 0x8E1E,
        Max_Combined_Tess_Evaluation_Uniform_Components  = 0x8E1F,
        Transform_Feedback_Binding                    = 0x8E25,
        Fragment_Interpolation_Offset_Bits             = 0x8E5D,
        Max_Transform_Feedback_Buffers                 = 0x8E70,
        Patch_Vertices                               = 0x8E72,
        Max_Patch_Vertices                            = 0x8E7D,
        Max_Tess_Gen_Level                             = 0x8E7E,
        Max_Tess_Control_Uniform_Components             = 0x8E7F,
        Max_Tess_Evaluation_Uniform_Components          = 0x8E80,
        Max_Tess_Control_Texture_Image_Units             = 0x8E81,
        Max_Tess_Evaluation_Texture_Image_Units          = 0x8E82,
        Max_Tess_Control_Output_Components              = 0x8E83,
        MaxTessPatchComponents                      = 0x8E84,
        MaxTessControlOutputTotalComponents         = 0x8E85,
        Max_Tess_Evaluation_Output_Components           = 0x8E86,
        Max_Tess_Control_Uniform_Blocks                 = 0x8E89,
        Max_Tess_Evaluation_Uniform_Blocks              = 0x8E8A,
        Max_Image_Units                               = 0x8F38,
        Max_Combined_Shader_Output_Resources            = 0x8F39,
        Draw_Indirect_Buffer_Binding                   = 0x8F43,
        Texture_Binding_Cube_Map_Array                  = 0x900A,
        Max_Image_Samples                             = 0x906D,
        Max_Vertex_Image_Uniforms                      = 0x90CA,
        Max_Tess_Control_Image_Uniforms                 = 0x90CB,
        Max_Tess_Evaluation_Image_Uniforms              = 0x90CC,
        Max_Geometry_Image_Uniforms                    = 0x90CD,
        Max_Fragment_Image_Uniforms                    = 0x90CE,
        Max_Combined_Image_Uniforms                    = 0x90CF,
        Shader_Storage_Buffer_Binding                  = 0x90D3,
        Max_Vertex_Shader_Storage_Blocks                = 0x90D6,
        Max_Tess_Control_Shader_Storage_Blocks           = 0x90D8,
        Max_Tess_Evaluation_Shader_Storage_Blocks        = 0x90D9,
        Dispatch_Indirect_Buffer_Binding               = 0x90EF,
        Unpack_Compressed_Block_Width                  = 0x9127,
        Unpack_Compressed_Block_Height                 = 0x9128,
        Unpack_Compressed_Block_Depth                  = 0x9129,
        Unpack_Compressed_Block_Size                   = 0x912A,
        Pack_Compressed_Block_Width                    = 0x912B,
        Pack_Compressed_Block_Height                   = 0x912C,
        Pack_Compressed_Block_Depth                    = 0x912D,
        Pack_Compressed_Block_Size                     = 0x912E,
        Max_Debug_Message_Length                       = 0x9143,
        Max_Debug_Log_Messages                         = 0x9144,
        Debug_Loggged_Messages                        = 0x9145,
        Atomic_Counter_Buffer_Binding                  = 0x92C1,
        Max_Vertex_Atomic_Counter_Buffers               = 0x92CC,
        Max_Tess_Control_Atomic_Counter_Buffers          = 0x92CD,
        Max_Tess_Evaluation_Atomic_Counter_Buffers       = 0x92CE,
        Max_Vertex_Atomic_Counters                     = 0x92D2,
        Max_Tess_Control_Atomic_Counters = 0x92D3,
        Max_Tess_Evaluation_Atomic_Counters                = 0x92D4,
        MaxSampleCounts                             = 0x9380,
#endif // version 4.3 states
#ifdef SON8_OVERGLAD_VERSION_4_6
        Max_3D_Texture_Size = 0x8073,
        Parameter_Buffer_Binding = 0x80EF,
        Context_Flags = 0x821E,
        Reset_Notification_Strategy = 0x8256,
        Max_Compute_Shared_Memory_Size = 0x8262,
        Max_Compute_Uniform_Components = 0x8263,
        Max_Compute_Atomic_Counter_Buffers = 0x8264,
        Max_Compute_Atomic_Counters = 0x8265,
        Max_Combined_Compute_Uniform_Components = 0x8266,
        Max_Uniform_Locations = 0x826E,
        Max_Vertex_Attrib_Relative_Offset = 0x82D9,
        Max_Vertex_Attrib_Bindings = 0x82DA,
        Max_Vertex_Attrib_Stride = 0x82E5,
        Max_Cull_Distances = 0x82F9,
        Max_Combined_Clip_And_Cull_Distances = 0x82FA,
        Context_Release_Behavior = 0x82FB,
        Num_Program_Binary_Formats = 0x87FE,
        Program_Binary_Formats = 0x87FF,
        Texture_Buffer_Binding = 0x8C2A,
        Max_Geometry_Uniform_Components = 0x8DDF,
        Max_Subroutines = 0x8DE7,
        Max_Subroutine_Uniform_Locations = 0x8DE8,
        Shader_Binary_Formats = 0x8DF8,
        Num_Shader_Binary_Formats = 0x8DF9,
        Max_Varying_Vectors = 0x8DFC,
        Max_Fragment_Uniform_Vectors = 0x8DFD,
        Max_Geometry_Shader_Invocations = 0x8E5A,
        Min_Program_Texture_Gather_Offset = 0x8E5E,
        Max_Program_Texture_Gather_Offset = 0x8E5F,
        Max_Vertex_Streams = 0x8E71,
        Min_Map_Buffer_Alignment = 0x90BC,
        Max_Geometry_Shader_Storage_Blocks = 0x90D7,
        Max_Fragment_Shader_Storage_Blocks = 0x90DA,
        Max_Compute_Shader_Storage_Blocks = 0x90DB,
        Max_Combined_Shader_Storage_Blocks = 0x90DC,
        Max_Shader_Storage_Buffer_Bindings = 0x90DD,
        Shader_Storage_Buffer_Offset_Alignment = 0x90DF,
        Max_Compute_Work_Group_Invocations = 0x90EB,
        Max_Vertex_Output_Components = 0x9122,
        Context_Profile_Mask = 0x9126,
        Query_Buffer_Bidning = 0x9193,
        Texture_Buffer_Offset_Alignment = 0x919F,
        Max_Compute_Uniform_Blocks = 0x91BB,
        Max_Compute_Texture_Image_Units = 0x91BC,
        Max_Compute_Image_Uniforms = 0x91BD,
        Max_Geometry_Atomic_Counter_Buffers = 0x92CF,
        Max_Fragment_Atomic_Counter_Buffers = 0x92D0,
        Max_Combined_Atomic_Counter_Buffers = 0x92D1,
        Max_Geometry_Atomic_Counters = 0x92D5,
        Max_Fragment_Atomic_Counters = 0x92D6,
        Max_Combined_Atomic_Counters = 0x92D7,
        Max_Atomic_Counter_Buffer_Size = 0x92D8,
        Max_Atomic_Counter_Buffer_Bindings = 0x92DC,
        Max_Framebuffer_Width = 0x9315,
        Max_Framebuffer_Height = 0x9316,
        Max_Framebuffer_Layers = 0x9317,
        Max_Framebuffer_Samples = 0x9318,
        Clip_Origin = 0x935C,
        Clip_Depth_Mode = 0x935D,
        Num_Spir_V_Extensions = 0x9554,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 4.6 states
    }; // enum class `Integer`

    enum class Integer2 : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
        Polygon_Mode         = 0x0B40,
        Max_Viewport_Dims     = 0x0D3A,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
        Map2GridSegments    = 0x0DD3,
#   endif // not core profile
#endif // version 1.1 states
    }; // enum class `Integer2`

    enum class Integer4 : GLenum {
#ifdef SON8_OVERGLAD_VERSION_1_1
        Viewport    = 0x0BA2,
        ScissorBox  = 0x0C10,
#endif // version 1.1 states
    };
    // `GetInteger64`
    enum class Long : GLenum {
#ifdef SON8_OVERGLAD_VERSION_3_3
        Max_Server_Wait_Timeout    = 0x9111,
#   ifndef SON8_OVERGLAD_PROFILE_CORE
#   endif // not core profile
#endif // version 3.3 states
#ifdef SON8_OVERGLAD_VERSION_4_3
        Max_Element_Index         = 0x8D6B,
#endif // version 4.3 states
#ifdef SON8_OVERGLAD_VERSION_4_6
        Max_Shader_Storage_Block_Size = 0x90DE,
#endif // version 4.3 states
    }; // enum class `Long`
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
        Shading_Language_Version  = 0x8B8C,
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

#endif
