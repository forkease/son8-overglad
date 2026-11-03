#ifndef SON8_OVERGLAD_V3_3_HXX
#define SON8_OVERGLAD_V3_3_HXX

#ifndef          SON8_OVERGLAD_DEFINED
#define          SON8_OVERGLAD_DEFINED
#define      SON8_OVERGLAD_VERSION_1_1
#define      SON8_OVERGLAD_VERSION_1_5
#define      SON8_OVERGLAD_VERSION_2_1
#define      SON8_OVERGLAD_VERSION_3_3
#define     SON8_OVERGLAD_PROFILE_CORE
#define SON8_OVERGLAD_VERSION 0x0303CE
#include      <son8/overglad/v1_1.hxx>
#include      <son8/overglad/v1_5.hxx>
#include      <son8/overglad/v2_1.hxx>
#endif         //SON8_OVERGLAD_DEFINED

namespace son8::overglad {
    // CORE

    // Chapter 2: OpenGL Operation

    // TODO: VertexAttribI*,VertexAttribP*,VertexAttribIPointer,VertexAttribDivisor,PrimitiveRestartIndex
    // ,DrawArraysInstanced,DrawElementsInstanced,DrawElementsBaseVertex,DrawRangeElementsBaseVertex,DrawElementsInstancedBaseVertex
    // ,MultiDrawElementsBaseVertex,BindBufferRange,BindBufferBase,MapBufferRange,FlushMappedBufferRange,CopyBufferSubData
    // ,GetUniformBlockIndex,GetActiveUniformBlockName,GetActiveUniformBlockiv
    // ,GetUniformIndices,GetActiveUniformName,GetActiveUniformsiv,Uniform*,UniformBlockBinding,TransformFeedbackVaryings
    // ,GetTransformFeedbackVarying,BeginConditionalRender,EndConditionalRender,BeginTransformFeedback,EndTransformFeedback

    // ProvokingVertex
    SON8_OVERGLAD_PROC mode( enums::Provoke provoke )
    { glad_glProvokingVertex( static_cast< GLenum >( provoke ) ); }

    // Chapter 3: Rasterization

    // TODO: GetMultisamplefv,GenSamplers,BindSampler,SamplerParameter*,DeleteSamplers,TexImage2DMultisample,TexImage3DMultisample,TexBuffer,TexParameterI*,GenerateMipmap,BindFragDataLocationIndexed,BindFragDataLocation,GetFragDataLocation,GetFragDataIndex

    // Chapter 4: Per-Fragment Operations and the Framebuffer

    // TODO: SampleMaski

    // Enablei
    SON8_OVERGLAD_PROC mode( enums::Enablei enablei, GLuint index )
    { glad_glEnablei( static_cast< GLenum >( enablei.value( ) ), index ); }
    // Disablei
    SON8_OVERGLAD_PROC mode( enums::Disablei disablei, GLuint index )
    { glad_glDisablei( static_cast< GLenum >( disablei.value( ) ), index ); }

    // TODO: ColorMaski,ClearBuffer*

    // glClampColor: in core has only one target (use compatibility for multiple targets)
    SON8_OVERGLAD_PROC mode( enums::Clamp clamp )
    { glad_glClampColor( static_cast< GLenum >( 0x891C ), static_cast< GLenum >( clamp ) ); }

    // TODO: BlitFramebuffer,BindFramebuffer,DeleteFramebuffers,GenFramebuffers
    // ,BindRenderbuffer,DeleteRenderbuffers,GenRenderbuffers,RenderbufferStorageMultisample,RenderbufferStorage
    // ,FramebufferRenderbuffer,FramebufferTexture,FramebufferTexture1D,FramebufferTexture2D,FramebufferTexture3D
    // ,FramebufferTextureLayer,CheckFramebufferStatus

    // Chapter 5: Special Functions

    // TODO: QueryCounter,FenceSync,DeleteSync,ClientWaitSync,WaitSync

    // Chapter 6: State and State Requests

    // TODO: GetInteger64v,GetBooleani_v,GetIntegeri_v,GetInteger64i_v

    // IsEnabledi
    SON8_OVERGLAD_FUNC get( enums::Capi target, GLuint index )
    { return glad_glIsEnabledi( static_cast< GLenum >( target ), index ); }

    // TODO: GetTexParameterI*

    SON8_OVERGLAD_FUNC is_sampler( GLuint sampler )
    { return glad_glIsSampler( sampler ); }

    // TODO: GetSamplerParameter,GetStringi,GetQueryObjecti64v,GetQueryObjectui64v,GetSynciv

    SON8_OVERGLAD_FUNC is_sync( GLsync sync )
    { return glad_glIsSync( sync ); }

    // TODO: GetBufferParameteri64v

    SON8_OVERGLAD_FUNC is_vertex_array( GLuint array )
    { return glad_glIsVertexArray( array ); }

    // TODO: GetVertexAttribI*

    SON8_OVERGLAD_FUNC is_framebuffer( GLuint framebuffer )
    { return glad_glIsFramebuffer( framebuffer ); }

    // TODO: GetFramebufferAttachmentParameteriv

    SON8_OVERGLAD_FUNC is_renderbuffer( GLuint renderbuffer )
    { return glad_glIsRenderbuffer( renderbuffer ); }

    // TODO: GetRenderbufferParameteriv

    // COMPATIBILITY
#ifndef SON8_OVERGLAD_PROFILE_CORE

    // Chapter 2: OpenGL Operation

    template< enums::Packed Pack, unsigned Size >
    SON8_OVERGLAD_PROC vertex( types::Packed< Pack, Size > type, GLuint coords ) {
        static_assert( 2 <= Size && Size <= 4, "Invalid Size for Packed vertex" );
        if/*_*/ constexpr ( Size == 2 ) glad_glVertexP2ui( static_cast< GLenum >( type.pack( ) ), coords );
        else if constexpr ( Size == 3 ) glad_glVertexP3ui( static_cast< GLenum >( type.pack( ) ), coords );
        else if constexpr ( Size == 4 ) glad_glVertexP4ui( static_cast< GLenum >( type.pack( ) ), coords );
    }
    template< enums::Packed Pack, unsigned Size >
    SON8_OVERGLAD_PROC vertex( types::Packed< Pack, Size > type, types::array1ui const &coords ) {
        static_assert( 2 <= Size && Size <= 4, "Invalid Size for Packed vertex" );
        if/*_*/ constexpr ( Size == 2 ) glad_glVertexP2uiv( static_cast< GLenum >( type.pack( ) ), coords.data( ) );
        else if constexpr ( Size == 3 ) glad_glVertexP3uiv( static_cast< GLenum >( type.pack( ) ), coords.data( ) );
        else if constexpr ( Size == 4 ) glad_glVertexP4uiv( static_cast< GLenum >( type.pack( ) ), coords.data( ) );
    }
    template< enums::Packed Pack, unsigned Size >
    SON8_OVERGLAD_PROC tex_coord( types::Packed< Pack, Size > type, GLuint coords ) {
        static_assert( 1 <= Size && Size <= 4, "Invalid Size for Packed tex_coord" );
        if/*_*/ constexpr ( Size == 1 ) glad_glTexCoordP1ui( static_cast< GLenum >( type.pack( ) ), coords );
        else if constexpr ( Size == 2 ) glad_glTexCoordP2ui( static_cast< GLenum >( type.pack( ) ), coords );
        else if constexpr ( Size == 3 ) glad_glTexCoordP3ui( static_cast< GLenum >( type.pack( ) ), coords );
        else if constexpr ( Size == 4 ) glad_glTexCoordP4ui( static_cast< GLenum >( type.pack( ) ), coords );
    }
    template< enums::Packed Pack, unsigned Size >
    SON8_OVERGLAD_PROC tex_coord( types::Packed< Pack, Size > type, types::array1ui const &coords ) {
        static_assert( 1 <= Size && Size <= 4, "Invalid Size for Packed tex_coord" );
        if/*_*/ constexpr ( Size == 1 ) glad_glTexCoordP1uiv( static_cast< GLenum >( type.pack( ) ), coords.data( ) );
        else if constexpr ( Size == 2 ) glad_glTexCoordP2uiv( static_cast< GLenum >( type.pack( ) ), coords.data( ) );
        else if constexpr ( Size == 3 ) glad_glTexCoordP3uiv( static_cast< GLenum >( type.pack( ) ), coords.data( ) );
        else if constexpr ( Size == 4 ) glad_glTexCoordP4uiv( static_cast< GLenum >( type.pack( ) ), coords.data( ) );
    }
    template< enums::Packed Pack, unsigned Size >
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::Packed< Pack, Size > type, GLuint coords ) {
        static_assert( 1 <= Size && Size <= 4, "Invalid Size for Packed Multi tex_coord" );
        if/*_*/ constexpr ( Size == 1 ) glad_glMultiTexCoordP1ui( static_cast< GLenum >( texture ), static_cast< GLenum >( type.pack( ) ), coords );
        else if constexpr ( Size == 2 ) glad_glMultiTexCoordP2ui( static_cast< GLenum >( texture ), static_cast< GLenum >( type.pack( ) ), coords );
        else if constexpr ( Size == 3 ) glad_glMultiTexCoordP3ui( static_cast< GLenum >( texture ), static_cast< GLenum >( type.pack( ) ), coords );
        else if constexpr ( Size == 4 ) glad_glMultiTexCoordP4ui( static_cast< GLenum >( texture ), static_cast< GLenum >( type.pack( ) ), coords );
    }
    template< enums::Packed Pack, unsigned Size >
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::Packed< Pack, Size > type, types::array1ui const &coords ) {
        static_assert( 1 <= Size && Size <= 4, "Invalid Size for Packed Multi tex_coord" );
        if/*_*/ constexpr ( Size == 1 ) glad_glMultiTexCoordP1uiv( static_cast< GLenum >( texture ), static_cast< GLenum >( type.pack( ) ), coords.data( ) );
        else if constexpr ( Size == 2 ) glad_glMultiTexCoordP2uiv( static_cast< GLenum >( texture ), static_cast< GLenum >( type.pack( ) ), coords.data( ) );
        else if constexpr ( Size == 3 ) glad_glMultiTexCoordP3uiv( static_cast< GLenum >( texture ), static_cast< GLenum >( type.pack( ) ), coords.data( ) );
        else if constexpr ( Size == 4 ) glad_glMultiTexCoordP4uiv( static_cast< GLenum >( texture ), static_cast< GLenum >( type.pack( ) ), coords.data( ) );
    }
    template< enums::Packed Pack, unsigned Size >
    SON8_OVERGLAD_PROC normal( types::Packed< Pack, Size > type, GLuint coords ) {
        static_assert( Size == 3, "Invalid Size for Packed normal" );
        glad_glNormalP3ui( static_cast< GLenum >( type.pack( ) ), coords );
    }
    template< enums::Packed Pack, unsigned Size >
    SON8_OVERGLAD_PROC normal( types::Packed< Pack, Size > type, types::array1ui const &coords ) {
        static_assert( Size == 3, "Invalid Size for Packed normal" );
        if constexpr ( Size == 3 ) glad_glNormalP3uiv( static_cast< GLenum >( type.pack( ) ), coords.data( ) );
    }
    template< enums::Packed Pack, unsigned Size >
    SON8_OVERGLAD_PROC color( types::Packed< Pack, Size > type, GLuint coords ) {
        static_assert( 3 <= Size && Size <= 4, "Invalid Size for Packed color" );
        if/*_*/ constexpr ( Size == 3 ) glad_glColorP3ui( static_cast< GLenum >( type.pack( ) ), coords );
        else if constexpr ( Size == 4 ) glad_glColorP4ui( static_cast< GLenum >( type.pack( ) ), coords );
    }
    template< enums::Packed Pack, unsigned Size >
    SON8_OVERGLAD_PROC color( types::Packed< Pack, Size > type, types::array1ui const &coords ) {
        static_assert( 3 <= Size && Size <= 4, "Invalid Size for Packed color" );
        if/*_*/ constexpr ( Size == 3 ) glad_glColorP3uiv( static_cast< GLenum >( type.pack( ) ), coords.data( ) );
        else if constexpr ( Size == 4 ) glad_glColorP4uiv( static_cast< GLenum >( type.pack( ) ), coords.data( ) );
    }
    template< enums::Packed Pack, unsigned Size >
    SON8_OVERGLAD_PROC secondary_color( types::Packed< Pack, Size > type, GLuint coords ) {
        static_assert( Size == 3, "Invalid Size for Packed secondary_color" );
        glad_glSecondaryColorP3ui( static_cast< GLenum >( type.pack( ) ), coords );
    }
    template< enums::Packed Pack, unsigned Size >
    SON8_OVERGLAD_PROC secondary_color( types::Packed< Pack, Size > type, types::array1ui const &coords ) {
        static_assert( Size == 3, "Invalid Size for Packed secondary_color" );
        glad_glSecondaryColorP3uiv( static_cast< GLenum >( type.pack( ) ), coords.data( ) );
    }
    // Chapter 3: Rasterization

    // glClampColor
    SON8_OVERGLAD_PROC mode( enums::ClampColor target, enums::Clamp clamp )
    { glad_glClampColor( static_cast< GLenum >( target ), static_cast< GLenum >( clamp ) ); }
#endif // not core profile functions
    // DEPRECATED
#ifdef SON8_OVERGLAD_INCLUDE_DEPRECATED

    // Chapter 2: OpenGL Operation

    SON8_OVERGLAD_DEPR vertex_P_2( GLenum type, GLuint coords )
    { glVertexP2ui( type, coords ); }
    SON8_OVERGLAD_DEPR vertex_P_3( GLenum type, GLuint coords )
    { glVertexP3ui( type, coords ); }
    SON8_OVERGLAD_DEPR vertex_P_4( GLenum type, GLuint coords )
    { glVertexP4ui( type, coords ); }
    SON8_OVERGLAD_DEPR vertex_P_2( GLenum type, GLuint const *coords )
    { glVertexP2uiv( type, coords ); }
    SON8_OVERGLAD_DEPR vertex_P_3( GLenum type, GLuint const *coords )
    { glVertexP3uiv( type, coords ); }
    SON8_OVERGLAD_DEPR vertex_P_4( GLenum type, GLuint const *coords )
    { glVertexP4uiv( type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_1( GLenum type, GLuint coords )
    { glTexCoordP1ui( type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_2( GLenum type, GLuint coords )
    { glTexCoordP2ui( type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_3( GLenum type, GLuint coords )
    { glTexCoordP3ui( type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_4( GLenum type, GLuint coords )
    { glTexCoordP4ui( type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_1( GLenum type, GLuint const *coords )
    { glTexCoordP1uiv( type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_2( GLenum type, GLuint const *coords )
    { glTexCoordP2uiv( type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_3( GLenum type, GLuint const *coords )
    { glTexCoordP3uiv( type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_4( GLenum type, GLuint const *coords )
    { glTexCoordP4uiv( type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_1( GLenum texture, GLenum type, GLuint coords )
    { glMultiTexCoordP1ui( texture, type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_2( GLenum texture, GLenum type, GLuint coords )
    { glMultiTexCoordP2ui( texture, type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_3( GLenum texture, GLenum type, GLuint coords )
    { glMultiTexCoordP3ui( texture, type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_4( GLenum texture, GLenum type, GLuint coords )
    { glMultiTexCoordP4ui( texture, type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_1( GLenum texture, GLenum type, GLuint const *coords )
    { glMultiTexCoordP1uiv( texture, type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_2( GLenum texture, GLenum type, GLuint const *coords )
    { glMultiTexCoordP2uiv( texture, type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_3( GLenum texture, GLenum type, GLuint const *coords )
    { glMultiTexCoordP3uiv( texture, type, coords ); }
    SON8_OVERGLAD_DEPR tex_coord_P_4( GLenum texture, GLenum type, GLuint const *coords )
    { glMultiTexCoordP4uiv( texture, type, coords ); }
    SON8_OVERGLAD_DEPR normal_P( GLenum type, GLuint coords )
    { glNormalP3ui( type, coords ); }
    SON8_OVERGLAD_DEPR normal_P( GLenum type, GLuint const *coords )
    { glNormalP3uiv( type, coords ); }
    SON8_OVERGLAD_DEPR color_P_3( GLenum type, GLuint coords )
    { glColorP3ui( type, coords ); }
    SON8_OVERGLAD_DEPR color_P_4( GLenum type, GLuint coords )
    { glColorP4ui( type, coords ); }
    SON8_OVERGLAD_DEPR color_P_3( GLenum type, GLuint const *coords )
    { glColorP3uiv( type, coords ); }
    SON8_OVERGLAD_DEPR color_P_4( GLenum type, GLuint const *coords )
    { glColorP4uiv( type, coords ); }
    SON8_OVERGLAD_DEPR secondary_color_P( GLenum type, GLuint coords )
    { glSecondaryColorP3ui( type, coords ); }
    SON8_OVERGLAD_DEPR secondary_color_P( GLenum type, GLuint const *coords )
    { glSecondaryColorP3uiv( type, coords ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I( GLuint index, GLint x )
    { glVertexAttribI1i( index, x ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I( GLuint index, GLuint x )
    { glVertexAttribI1ui( index, x ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I( GLuint index, GLint x, GLint y )
    { glVertexAttribI2i( index, x, y ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I( GLuint index, GLuint x, GLuint y )
    { glVertexAttribI2ui( index, x, y ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I( GLuint index, GLint x, GLint y, GLint z )
    { glVertexAttribI3i( index, x, y, z ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I( GLuint index, GLuint x, GLuint y, GLuint z )
    { glVertexAttribI3ui( index, x, y, z ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I( GLuint index, GLint x, GLint y, GLint z, GLint w )
    { glVertexAttribI4i( index, x, y, z, w ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I( GLuint index, GLuint x, GLuint y, GLuint z, GLuint w )
    { glVertexAttribI4ui( index, x, y, z, w ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I_1( GLuint index, GLint const *values )
    { glVertexAttribI1iv( index, values ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I_1( GLuint index, GLuint const *values )
    { glVertexAttribI1uiv( index, values ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I_2( GLuint index, GLint const *values )
    { glVertexAttribI2iv( index, values ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I_2( GLuint index, GLuint const *values )
    { glVertexAttribI2uiv( index, values ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I_3( GLuint index, GLint const *values )
    { glVertexAttribI3iv( index, values ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I_3( GLuint index, GLuint const *values )
    { glVertexAttribI3uiv( index, values ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I_4( GLuint index, GLint const *values )
    { glVertexAttribI4iv( index, values ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I_4( GLuint index, GLuint const *values )
    { glVertexAttribI4uiv( index, values ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I_4( GLuint index, GLbyte const *values )
    { glVertexAttribI4bv( index, values ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I_4( GLuint index, GLshort const *values )
    { glVertexAttribI4sv( index, values ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I_4( GLuint index, GLubyte const *values )
    { glVertexAttribI4ubv( index, values ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I_4( GLuint index, GLushort const *values )
    { glVertexAttribI4usv( index, values ); }
    SON8_OVERGLAD_DEPR vertex_attrib_P_1( GLuint index, GLenum type, GLboolean normalized, GLuint value )
    { glVertexAttribP1ui( index, type, normalized, value ); }
    SON8_OVERGLAD_DEPR vertex_attrib_P_2( GLuint index, GLenum type, GLboolean normalized, GLuint value )
    { glVertexAttribP2ui( index, type, normalized, value ); }
    SON8_OVERGLAD_DEPR vertex_attrib_P_3( GLuint index, GLenum type, GLboolean normalized, GLuint value )
    { glVertexAttribP3ui( index, type, normalized, value ); }
    SON8_OVERGLAD_DEPR vertex_attrib_P_4( GLuint index, GLenum type, GLboolean normalized, GLuint value )
    { glVertexAttribP4ui( index, type, normalized, value ); }
    SON8_OVERGLAD_DEPR vertex_attrib_P_1( GLuint index, GLenum type, GLboolean normalized, GLuint const *value )
    { glVertexAttribP1uiv( index, type, normalized, value ); }
    SON8_OVERGLAD_DEPR vertex_attrib_P_2( GLuint index, GLenum type, GLboolean normalized, GLuint const *value )
    { glVertexAttribP2uiv( index, type, normalized, value ); }
    SON8_OVERGLAD_DEPR vertex_attrib_P_3( GLuint index, GLenum type, GLboolean normalized, GLuint const *value )
    { glVertexAttribP3uiv( index, type, normalized, value ); }
    SON8_OVERGLAD_DEPR vertex_attrib_P_4( GLuint index, GLenum type, GLboolean normalized, GLuint const *value )
    { glVertexAttribP4uiv( index, type, normalized, value ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I_pointer( GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid const *pointer )
    { glVertexAttribIPointer( index, size, type, stride, pointer ); }
    SON8_OVERGLAD_DEPR vertex_attrib_divisor( GLuint index, GLuint divisor )
    { glVertexAttribDivisor( index, divisor ); }
    SON8_OVERGLAD_DEPR primitive_restart_index( GLuint index )
    { glPrimitiveRestartIndex( index ); }
    SON8_OVERGLAD_DEPR draw_arrays_instanced( GLenum mode, GLint first,
        GLsizei count, GLsizei primcount )
    { glDrawArraysInstanced( mode, first, count, primcount ); }
    SON8_OVERGLAD_DEPR draw_elements_instanced( GLenum mode,
        GLsizei count, GLenum type, GLvoid const *indices, GLsizei primcount )
    { glDrawElementsInstanced( mode, count, type, indices, primcount ); }
    SON8_OVERGLAD_DEPR draw_elements_base_vertex( GLenum mode,
        GLsizei count, GLenum type, GLvoid const *indices, GLint basevertex )
    { glDrawElementsBaseVertex( mode, count, type, indices, basevertex ); }
    SON8_OVERGLAD_DEPR draw_range_elements_base_vertex( GLenum mode, GLuint start, GLuint end,
        GLsizei count, GLenum type, GLvoid const *indices, GLint basevertex )
    { glDrawRangeElementsBaseVertex( mode, start, end, count, type, indices, basevertex ); }
    SON8_OVERGLAD_DEPR draw_elements_instanced_base_vertex( GLenum mode,
        GLsizei count, GLenum type, GLvoid const *indices, GLsizei primcount, GLint basevertex )
    { glDrawElementsInstancedBaseVertex( mode, count, type, indices, primcount, basevertex ); }
    SON8_OVERGLAD_DEPR multi_draw_elements_base_vertex( GLenum mode,
        GLsizei const *count, GLenum type, GLvoid const *const *indices, GLsizei primcount, GLint const *basevertex )
    { glMultiDrawElementsBaseVertex( mode, count, type, indices, primcount, basevertex ); }
    SON8_OVERGLAD_DEPR bind_buffer_range( GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size )
    { glBindBufferRange( target, index, buffer, offset, size ); }
    SON8_OVERGLAD_DEPR bind_buffer_base( GLenum target, GLuint index, GLuint buffer )
    { glBindBufferBase( target, index, buffer ); }
    SON8_OVERGLAD_DEPR map_buffer_range( GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access )
    { return glMapBufferRange( buffer, offset, length, access ); }
    SON8_OVERGLAD_DEPR flush_mapped_buffer_range( GLuint buffer, GLintptr offset, GLsizeiptr length )
    { glFlushMappedBufferRange( buffer, offset, length ); }
    SON8_OVERGLAD_DEPR copy_buffer_sub_data( GLenum readtarget, GLenum writetarget,
        GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size )
    { glCopyBufferSubData( readtarget, writetarget, readoffset, writeoffset, size ); }
    SON8_OVERGLAD_DEPR gen_vertex_arrays( GLsizei n, GLuint *arrays )
    { glGenVertexArrays( n, arrays ); }
    SON8_OVERGLAD_DEPR delete_vertex_arrays( GLsizei n, GLuint const *arrays )
    { glDeleteVertexArrays( n, arrays ); }
    SON8_OVERGLAD_DEPR bind_vertex_array( GLuint array )
    { glBindVertexArray( array ); }
    SON8_OVERGLAD_DEPR get_uniform_block_index( GLuint program, GLchar const *uniformBlockName )
    { return glGetUniformBlockIndex( program, uniformBlockName ); }
    SON8_OVERGLAD_DEPR get_active_uniform_block_name( GLuint program,
        GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName )
    { glGetActiveUniformBlockName( program, uniformBlockIndex, bufSize, length, uniformBlockName ); }
    SON8_OVERGLAD_DEPR get_active_uniform_block( GLuint program,
        GLuint uniformBlockIndex, GLenum pname, GLint *params )
    { glGetActiveUniformBlockiv( program, uniformBlockIndex, pname, params ); }
    SON8_OVERGLAD_DEPR get_uniform_indices( GLuint program,
        GLsizei uniformCount, GLchar const *const *uniformNames, GLuint *uniformIndices )
    { glGetUniformIndices( program, uniformCount, uniformNames, uniformIndices ); }
    SON8_OVERGLAD_DEPR get_active_uniform_name( GLuint program,
        GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName )
    { glGetActiveUniformName( program, uniformIndex, bufSize, length, uniformName ); }
    SON8_OVERGLAD_DEPR get_active_uniforms( GLuint program,
        GLsizei uniformCount, GLuint const *uniformIndices, GLenum pname, GLint *params )
    { glGetActiveUniformsiv( program, uniformCount, uniformIndices, pname, params ); }
    SON8_OVERGLAD_DEPR uniform( GLint location, GLuint x )
    { glUniform1ui( location, x ); }
    SON8_OVERGLAD_DEPR uniform( GLint location, GLuint x, GLuint y )
    { glUniform2ui( location, x, y ); }
    SON8_OVERGLAD_DEPR uniform( GLint location, GLuint x, GLuint y, GLuint z )
    { glUniform3ui( location, x, y, z ); }
    SON8_OVERGLAD_DEPR uniform( GLint location, GLuint x, GLuint y, GLuint z, GLuint w )
    { glUniform4ui( location, x, y, z, w ); }
    SON8_OVERGLAD_DEPR uniform_1( GLint location, GLsizei count, GLuint const *value )
    { glUniform1uiv( location, count, value ); }
    SON8_OVERGLAD_DEPR uniform_2( GLint location, GLsizei count, GLuint const *value )
    { glUniform2uiv( location, count, value ); }
    SON8_OVERGLAD_DEPR uniform_3( GLint location, GLsizei count, GLuint const *value )
    { glUniform3uiv( location, count, value ); }
    SON8_OVERGLAD_DEPR uniform_4( GLint location, GLsizei count, GLuint const *value )
    { glUniform4uiv( location, count, value ); }
    SON8_OVERGLAD_DEPR uniform_block_binding( GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding )
    { glUniformBlockBinding( program, uniformBlockIndex, uniformBlockBinding ); }
    SON8_OVERGLAD_DEPR transform_feedback_varyings( GLuint program, GLsizei count,
        GLchar const *const *varyings, GLenum bufferMode )
    { glTransformFeedbackVaryings( program, count, varyings, bufferMode ); }
    SON8_OVERGLAD_DEPR get_transform_feedback_varying( GLuint program, GLuint index,
        GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name )
    { glGetTransformFeedbackVarying( program, index, bufSize, length, size, type, name ); }
    SON8_OVERGLAD_DEPR begin_conditional_render( GLuint id, GLenum mode )
    { glBeginConditionalRender( id, mode ); }
    SON8_OVERGLAD_DEPR end_conditional_render( )
    { glEndConditionalRender( ); }
    SON8_OVERGLAD_DEPR begin_transform_feedback( GLenum primitiveMode )
    { glBeginTransformFeedback( primitiveMode ); }
    SON8_OVERGLAD_DEPR end_transform_feedback( )
    { glEndTransformFeedback( ); }
    SON8_OVERGLAD_DEPR provoking_vertex( GLenum provokeMode )
    { glProvokingVertex( provokeMode ); }

    // Chapter 3: Rasterization

    SON8_OVERGLAD_DEPR get_multisample( GLenum pname, GLuint index, GLfloat *val )
    { glGetMultisamplefv( pname, index, val ); }
    SON8_OVERGLAD_DEPR clamp_color( GLenum target, GLenum clamp )
    { glClampColor( target, clamp ); }
    SON8_OVERGLAD_DEPR gen_samplers( GLsizei count, GLuint *samplers )
    { glGenSamplers( count, samplers ); }
    SON8_OVERGLAD_DEPR bind_sampler( GLuint unit, GLuint sampler )
    { glBindSampler( unit, sampler ); }
    SON8_OVERGLAD_DEPR sampler_parameter( GLuint sampler, GLenum pname, GLint const *param )
    { glSamplerParameteriv( sampler, pname, param ); }
    SON8_OVERGLAD_DEPR sampler_parameter( GLuint sampler, GLenum pname, GLfloat const *param )
    { glSamplerParameterfv( sampler, pname, param ); }
    SON8_OVERGLAD_DEPR sampler_parameter_I( GLuint sampler, GLenum pname, GLint const *param )
    { glSamplerParameterIiv( sampler, pname, param ); }
    SON8_OVERGLAD_DEPR sampler_parameter_I( GLuint sampler, GLenum pname, GLuint const *param )
    { glSamplerParameterIuiv( sampler, pname, param ); }
    SON8_OVERGLAD_DEPR delete_samplers( GLsizei count, GLuint const *samplers )
    { glDeleteSamplers( count, samplers ); }
    SON8_OVERGLAD_DEPR tex_image_multisample( GLenum target, GLsizei samples,
        GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations )
    { glTexImage2DMultisample( target, samples, internalformat, width, height, fixedsamplelocations ); }
    SON8_OVERGLAD_DEPR tex_image_multisample( GLenum target, GLsizei samples,
        GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations )
    { glTexImage3DMultisample( target, samples, internalformat, width, height, depth, fixedsamplelocations ); }
    SON8_OVERGLAD_DEPR tex_buffer( GLenum target, GLenum internalformat, GLuint buffer )
    { glTexBuffer( target, internalformat, buffer ); }
    SON8_OVERGLAD_DEPR tex_parameter_I( GLenum target, GLenum pname, GLint const *params )
    { glTexParameterIiv( target, pname, params ); }
    SON8_OVERGLAD_DEPR tex_parameter_I( GLenum target, GLenum pname, GLuint const *params )
    { glTexParameterIuiv( target, pname, params ); }
    SON8_OVERGLAD_DEPR generate_mipmap( GLenum target )
    { glGenerateMipmap( target ); }
    SON8_OVERGLAD_DEPR bind_frag_data_location( GLuint program, GLuint colorNumber, GLint index, GLchar const *name )
    { glBindFragDataLocationIndexed( program, colorNumber, index, name ); }
    SON8_OVERGLAD_DEPR bind_frag_data_location( GLuint program, GLuint colorNumber, GLchar const *name )
    { glBindFragDataLocation( program, colorNumber, name ); }
    SON8_OVERGLAD_DEPR get_frag_data_location( GLuint program, GLchar const *name )
    { return glGetFragDataLocation( program, name ); }
    SON8_OVERGLAD_DEPR get_frag_data_index( GLuint program, GLchar const *name )
    { return glGetFragDataIndex( program, name ); }

    // Chapter 4: Per-Fragment Operations and the Framebuffer

    SON8_OVERGLAD_DEPR sample_mask( GLuint maskNumber, GLbitfield mask )
    { glSampleMaski( maskNumber, mask ); }
    SON8_OVERGLAD_DEPR enable( GLenum target, GLuint index )
    { glEnablei( target, index ); }
    SON8_OVERGLAD_DEPR disable( GLenum target, GLuint index )
    { glDisablei( target, index ); }
    SON8_OVERGLAD_DEPR color_mask( GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a )
    { glColorMaski( index, r, g, b, a ); }
    SON8_OVERGLAD_DEPR clear_buffer( GLenum buffer, GLint drawbuffer, GLint const *value )
    { glClearBufferiv( buffer, drawbuffer, value ); }
    SON8_OVERGLAD_DEPR clear_buffer( GLenum buffer, GLint drawbuffer, GLfloat const *value )
    { glClearBufferfv( buffer, drawbuffer, value ); }
    SON8_OVERGLAD_DEPR clear_buffer( GLenum buffer, GLint drawbuffer, GLuint const *value )
    { glClearBufferuiv( buffer, drawbuffer, value ); }
    SON8_OVERGLAD_DEPR clear_buffer( GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil )
    { glClearBufferfi( buffer, drawbuffer, depth, stencil ); }
    SON8_OVERGLAD_DEPR blit_framebuffer( GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1,
        GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1,
        GLbitfield mask, GLenum filter )
    { glBlitFramebuffer( srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter ); }
    SON8_OVERGLAD_DEPR bind_framebuffer( GLenum target, GLuint framebuffer )
    { glBindFramebuffer( target, framebuffer ); }
    SON8_OVERGLAD_DEPR delete_framebuffers( GLsizei n, GLuint const *framebuffers )
    { glDeleteFramebuffers( n, framebuffers ); }
    SON8_OVERGLAD_DEPR gen_framebuffers( GLsizei n, GLuint *framebuffers )
    { glGenFramebuffers( n, framebuffers ); }
    SON8_OVERGLAD_DEPR bind_renderbuffer( GLenum target, GLuint renderbuffer )
    { glBindRenderbuffer( target, renderbuffer ); }
    SON8_OVERGLAD_DEPR delete_renderbuffers( GLsizei n, GLuint const *renderbuffers )
    { glDeleteRenderbuffers( n, renderbuffers ); }
    SON8_OVERGLAD_DEPR gen_renderbuffers( GLsizei n, GLuint *renderbuffers )
    { glGenRenderbuffers( n, renderbuffers ); }
    SON8_OVERGLAD_DEPR renderbuffer_storage_multisample( GLenum target, GLsizei samples,
        GLenum internalformat, GLsizei width, GLsizei height )
    { glRenderbufferStorageMultisample( target, samples, internalformat, width, height ); }
    SON8_OVERGLAD_DEPR renderbuffer_storage( GLenum target, GLenum internalformat,
        GLsizei width, GLsizei height )
    { glRenderbufferStorage( target, internalformat, width, height ); }
    SON8_OVERGLAD_DEPR framebuffer_renderbuffer( GLenum target, GLenum attachment,
        GLenum renderbuffertarget, GLuint renderbuffer )
    { glFramebufferRenderbuffer( target, attachment, renderbuffertarget, renderbuffer ); }
    SON8_OVERGLAD_DEPR framebuffer_texture( GLenum target, GLenum attachment,
        GLuint texture, GLint level )
    { glFramebufferTexture( target, attachment, texture, level ); }
    SON8_OVERGLAD_DEPR framebuffer_texture_1D( GLenum target, GLenum attachment,
        GLenum textarget, GLuint texture, GLint level )
    { glFramebufferTexture1D( target, attachment, textarget, texture, level ); }
    SON8_OVERGLAD_DEPR framebuffer_texture_2D( GLenum target, GLenum attachment,
        GLenum textarget, GLuint texture, GLint level )
    { glFramebufferTexture2D( target, attachment, textarget, texture, level ); }
    SON8_OVERGLAD_DEPR framebuffer_texture_3D( GLenum target, GLenum attachment,
        GLenum textarget, GLuint texture, GLint level, GLint layer )
    { glFramebufferTexture3D( target, attachment, textarget, texture, level, layer ); }
    SON8_OVERGLAD_DEPR framebuffer_texture_layer( GLenum target, GLenum attachment,
        GLuint texture, GLint level, GLint layer )
    { glFramebufferTextureLayer( target, attachment, texture, level, layer ); }
    SON8_OVERGLAD_DEPR check_framebuffer_status( GLenum target )
    { return glCheckFramebufferStatus( target ); }

    // Chapter 5: Special Functions

    SON8_OVERGLAD_DEPR query_counter( GLuint id, GLenum target )
    { glQueryCounter( id, target ); }
    SON8_OVERGLAD_DEPR fence_sync( GLenum condition, GLbitfield flags )
    { return glFenceSync( condition, flags ); }
    SON8_OVERGLAD_DEPR delete_sync( GLsync sync )
    { glDeleteSync( sync ); }
    SON8_OVERGLAD_DEPR client_wait_sync( GLsync sync, GLbitfield flags, GLuint64 timeout )
    { return glClientWaitSync( sync, flags, timeout ); }
    SON8_OVERGLAD_DEPR wait_sync( GLsync sync, GLbitfield flags, GLuint64 timeout )
    { glWaitSync( sync, flags, timeout ); }

    // Chapter 6: State and State Requests

    SON8_OVERGLAD_DEPR get_integer( GLenum pname, GLint64 *data )
    { glGetInteger64v( pname, data ); }
    SON8_OVERGLAD_DEPR get_boolean( GLenum target, GLuint index, GLboolean *data )
    { glGetBooleani_v( target, index, data ); }
    SON8_OVERGLAD_DEPR get_integer( GLenum target, GLuint index, GLint *data )
    { glGetIntegeri_v( target, index, data ); }
    SON8_OVERGLAD_DEPR get_integer( GLenum target, GLuint index, GLint64 *data )
    { glGetInteger64i_v( target, index, data ); }
    SON8_OVERGLAD_DEPR is_enabled( GLenum target, GLuint index )
    { return glIsEnabledi( target, index ); }
    SON8_OVERGLAD_DEPR get_tex_parameter_I( GLenum target, GLenum pname, GLint *params )
    { glGetTexParameterIiv( target, pname, params ); }
    SON8_OVERGLAD_DEPR get_tex_parameter_I( GLenum target, GLenum pname, GLuint *params )
    { glGetTexParameterIuiv( target, pname, params ); }
    SON8_OVERGLAD_DEPR get_sampler_parameter( GLuint sampler, GLenum pname, GLint *params )
    { glGetSamplerParameteriv( sampler, pname, params ); }
    SON8_OVERGLAD_DEPR get_sampler_parameter( GLuint sampler, GLenum pname, GLfloat *params )
    { glGetSamplerParameterfv( sampler, pname, params ); }
    SON8_OVERGLAD_DEPR get_sampler_parameter_I( GLuint sampler, GLenum pname, GLint *params )
    { glGetSamplerParameterIiv( sampler, pname, params ); }
    SON8_OVERGLAD_DEPR get_sampler_parameter_I( GLuint sampler, GLenum pname, GLuint *params )
    { glGetSamplerParameterIuiv( sampler, pname, params ); }
    SON8_OVERGLAD_DEPR get_string( GLenum name, GLuint index )
    { return glGetStringi( name, index ); }
    SON8_OVERGLAD_DEPR get_query_object( GLuint id, GLenum pname, GLint64 *params )
    { glGetQueryObjecti64v( id, pname, params ); }
    SON8_OVERGLAD_DEPR get_query_object( GLuint id, GLenum pname, GLuint64 *params )
    { glGetQueryObjectui64v( id, pname, params ); }
    SON8_OVERGLAD_DEPR get_sync( GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values )
    { glGetSynciv( sync, pname, bufSize, length, values ); }
    SON8_OVERGLAD_DEPR get_buffer_parameter( GLenum target, GLenum pname, GLint64 *params )
    { glGetBufferParameteri64v( target, pname, params ); }
    SON8_OVERGLAD_DEPR get_vertex_attrib_I( GLuint index, GLenum pname, GLint *params )
    { glGetVertexAttribIiv( index, pname, params ); }
    SON8_OVERGLAD_DEPR get_vertex_attrib_I( GLuint index, GLenum pname, GLuint *params )
    { glGetVertexAttribIuiv( index, pname, params ); }
    SON8_OVERGLAD_DEPR get_uniform( GLuint program, GLint location, GLuint *params )
    { glGetUniformuiv( program, location, params ); }
    SON8_OVERGLAD_DEPR get_framebuffer_attachment_parameter( GLenum target, GLenum attachment, GLenum pname, GLint *params )
    { glGetFramebufferAttachmentParameteriv( target, attachment, pname, params ); }
    SON8_OVERGLAD_DEPR get_renderbuffer_parameter( GLenum target, GLenum pname, GLint *params )
    { glGetRenderbufferParameteriv( target, pname, params ); }
#endif // deprecated functions
} // namespace son8::overglad

#endif // INCLUDE GUARD

// Apache License 2.0
// NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
// SPDX-License-Identifier: Apache-2.0
// lib: `overglad` C++17 Wrapper Over GLAD Loader
// Ⓒ Copyright (c) 2025-2026 Oleg'Ease'Kharchuk ᦒ
