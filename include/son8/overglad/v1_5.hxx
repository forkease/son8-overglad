#ifndef SON8_OVERGLAD_V1_5_HXX
#define SON8_OVERGLAD_V1_5_HXX

#ifndef          SON8_OVERGLAD_DEFINED
#define          SON8_OVERGLAD_DEFINED
#define      SON8_OVERGLAD_VERSION_1_1
#define      SON8_OVERGLAD_VERSION_1_5
#define     SON8_OVERGLAD_PROFILE_NONE
#define SON8_OVERGLAD_VERSION 0x010500
#include      <son8/overglad/v1_1.hxx>
#endif         //SON8_OVERGLAD_DEFINED

namespace son8::overglad {
    // CORE

    // Chapter 2: OpenGL Operation

    // TODO: MultiDrawArrays,MultiDrawElements,DrawRangeElements
    // TODO: BufferData,BufferSubData,MapBuffer

    template< types::Object_::Type Type, bool Name >
    SON8_OVERGLAD_FUNC unmap( types::Object< Type, Name > buffer )
    {
        static_assert( types::Object_::is_buffer( Type ), "Unmapping is only available for buffer objects" );
        return glad_glUnmapBuffer( static_cast< GLenum >( buffer.type( ) ) );
    }
    SON8_OVERGLAD_PROC active_texture( enums::Multi texture )
    { glad_glActiveTexture( static_cast< GLenum >( texture ) ); }

    // Chapter 3: Rasterization

    // TODO: PointParameter,TexImage3D,TexSubImage3D,CopyTexSubImage3D,CompressedTexImage[123]D,CompressedTexSubImage[123]D

    // Chapter 4: Per-Fragment Operations and the Framebuffer

    SON8_OVERGLAD_FUNC sample_coverage( GLfloat value, GLboolean invert )
    { return glad_glSampleCoverage( value, invert ); }

    // TODO: BeginQuery,EndQuery,GenQueries,DeleteQueries

    SON8_OVERGLAD_PROC mode( enums::Equation equation )
    { glad_glBlendEquation( static_cast< GLenum >( equation ) ); }

    // TODO: BlendFuncSeparate

    SON8_OVERGLAD_PROC blend_color( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha )
    { glad_glBlendColor( red, green, blue, alpha ); }

    // Chapter 6: State and State Requests

    SON8_OVERGLAD_FUNC is_query( GLuint id )
    { return glad_glIsQuery( id ); }

    // TODO: GetQueryiv,GetQueryObjectiv,GetQueryObjectuiv

    SON8_OVERGLAD_FUNC is_buffer( GLuint buffer )
    { return glad_glIsBuffer( buffer ); }

    // COMPATIBILITY
#   ifndef SON8_OVERGLAD_PROFILE_CORE

    // Chapter 2: OpenGL Operation

    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLint s )
    { glad_glMultiTexCoord1i( static_cast< GLenum >( texture ), s ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLshort s )
    { glad_glMultiTexCoord1s( static_cast< GLenum >( texture ), s ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLfloat s )
    { glad_glMultiTexCoord1f( static_cast< GLenum >( texture ), s ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLdouble s )
    { glad_glMultiTexCoord1d( static_cast< GLenum >( texture ), s ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLint s, GLint t )
    { glad_glMultiTexCoord2i( static_cast< GLenum >( texture ), s, t ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLshort s, GLshort t )
    { glad_glMultiTexCoord2s( static_cast< GLenum >( texture ), s, t ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLfloat s, GLfloat t )
    { glad_glMultiTexCoord2f( static_cast< GLenum >( texture ), s, t ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLdouble s, GLdouble t )
    { glad_glMultiTexCoord2d( static_cast< GLenum >( texture ), s, t ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLint s, GLint t, GLint p )
    { glad_glMultiTexCoord3i( static_cast< GLenum >( texture ), s, t, p ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLshort s, GLshort t, GLshort p )
    { glad_glMultiTexCoord3s( static_cast< GLenum >( texture ), s, t, p ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLfloat s, GLfloat t, GLfloat p )
    { glad_glMultiTexCoord3f( static_cast< GLenum >( texture ), s, t, p ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLdouble s, GLdouble t, GLdouble p )
    { glad_glMultiTexCoord3d( static_cast< GLenum >( texture ), s, t, p ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLint s, GLint t, GLint p, GLint q )
    { glad_glMultiTexCoord4i( static_cast< GLenum >( texture ), s, t, p, q ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLshort s, GLshort t, GLshort p, GLshort q )
    { glad_glMultiTexCoord4s( static_cast< GLenum >( texture ), s, t, p, q ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLfloat s, GLfloat t, GLfloat p, GLfloat q )
    { glad_glMultiTexCoord4f( static_cast< GLenum >( texture ), s, t, p, q ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, GLdouble s, GLdouble t, GLdouble p, GLdouble q )
    { glad_glMultiTexCoord4d( static_cast< GLenum >( texture ), s, t, p, q ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array1i const &coords )
    { glad_glMultiTexCoord1iv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array1s const &coords )
    { glad_glMultiTexCoord1sv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array1f const &coords )
    { glad_glMultiTexCoord1fv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array1d const &coords )
    { glad_glMultiTexCoord1dv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array2i const &coords )
    { glad_glMultiTexCoord2iv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array2s const &coords )
    { glad_glMultiTexCoord2sv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array2f const &coords )
    { glad_glMultiTexCoord2fv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array2d const &coords )
    { glad_glMultiTexCoord2dv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array3i const &coords )
    { glad_glMultiTexCoord3iv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array3s const &coords )
    { glad_glMultiTexCoord3sv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array3f const &coords )
    { glad_glMultiTexCoord3fv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array3d const &coords )
    { glad_glMultiTexCoord3dv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array4i const &coords )
    { glad_glMultiTexCoord4iv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array4s const &coords )
    { glad_glMultiTexCoord4sv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array4f const &coords )
    { glad_glMultiTexCoord4fv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( enums::Multi texture, types::array4d const &coords )
    { glad_glMultiTexCoord4dv( static_cast< GLenum >( texture ), coords.data( ) ); }
    SON8_OVERGLAD_PROC fog_coord( GLfloat coord )
    { glad_glFogCoordf( coord ); }
    SON8_OVERGLAD_PROC fog_coord( GLdouble coord )
    { glad_glFogCoordd( coord ); }
    SON8_OVERGLAD_PROC fog_coord( types::array1f const &coord )
    { glad_glFogCoordfv( coord.data( ) ); }
    SON8_OVERGLAD_PROC fog_coord( types::array1d const &coord )
    { glad_glFogCoorddv( coord.data( ) ); }
    SON8_OVERGLAD_PROC secondary_color( GLint r, GLint g, GLint b )
    { glad_glSecondaryColor3i( r, g, b ); }
    SON8_OVERGLAD_PROC secondary_color( GLbyte r, GLbyte g, GLbyte b )
    { glad_glSecondaryColor3b( r, g, b ); }
    SON8_OVERGLAD_PROC secondary_color( GLshort r, GLshort g, GLshort b )
    { glad_glSecondaryColor3s( r, g, b ); }
    SON8_OVERGLAD_PROC secondary_color( GLfloat r, GLfloat g, GLfloat b )
    { glad_glSecondaryColor3f( r, g, b ); }
    SON8_OVERGLAD_PROC secondary_color( GLdouble r, GLdouble g, GLdouble b )
    { glad_glSecondaryColor3d( r, g, b ); }
    SON8_OVERGLAD_PROC secondary_color( GLuint r, GLuint g, GLuint b )
    { glad_glSecondaryColor3ui( r, g, b ); }
    SON8_OVERGLAD_PROC secondary_color( GLubyte r, GLubyte g, GLubyte b )
    { glad_glSecondaryColor3ub( r, g, b ); }
    SON8_OVERGLAD_PROC secondary_color( GLushort r, GLushort g, GLushort b )
    { glad_glSecondaryColor3us( r, g, b ); }
    SON8_OVERGLAD_PROC secondary_color( types::array3i const &components )
    { glad_glSecondaryColor3iv( components.data( ) ); }
    SON8_OVERGLAD_PROC secondary_color( types::array3b const &components )
    { glad_glSecondaryColor3bv( components.data( ) ); }
    SON8_OVERGLAD_PROC secondary_color( types::array3s const &components)
    { glad_glSecondaryColor3sv( components.data( ) ); }
    SON8_OVERGLAD_PROC secondary_color( types::array3f const &components )
    { glad_glSecondaryColor3fv( components.data( ) ); }
    SON8_OVERGLAD_PROC secondary_color( types::array3d const &components )
    { glad_glSecondaryColor3dv( components.data( ) ); }
    SON8_OVERGLAD_PROC secondary_color( types::array3ui const &components )
    { glad_glSecondaryColor3uiv( components.data( ) ); }
    SON8_OVERGLAD_PROC secondary_color( types::array3ub const &components )
    { glad_glSecondaryColor3ubv( components.data( ) ); }
    SON8_OVERGLAD_PROC secondary_color( types::array3us const &components )
    { glad_glSecondaryColor3usv( components.data( ) ); }

    // TODO: SecondaryColorPointer,FogCoordPointer

    SON8_OVERGLAD_PROC client_active_texture( enums::Multi texture )
    { glad_glClientActiveTexture( static_cast< GLenum >( texture ) ); }
    SON8_OVERGLAD_PROC load_transpose_matrix( types::array16f const &matrix )
    { glad_glLoadTransposeMatrixf( matrix.data( ) ); }
    SON8_OVERGLAD_PROC load_transpose_matrix( types::array16d const &matrix )
    { glad_glLoadTransposeMatrixd( matrix.data( ) ); }
    SON8_OVERGLAD_PROC mult_transpose_matrix( types::array16f const &matrix )
    { glad_glMultTransposeMatrixf( matrix.data( ) ); }
    SON8_OVERGLAD_PROC mult_transpose_matrix( types::array16d const &matrix )
    { glad_glMultTransposeMatrixd( matrix.data( ) ); }
    SON8_OVERGLAD_PROC window_pos( GLint x, GLint y )
    { glad_glWindowPos2i( x, y ); }
    SON8_OVERGLAD_PROC window_pos( GLshort x, GLshort y )
    { glad_glWindowPos2s( x, y ); }
    SON8_OVERGLAD_PROC window_pos( GLfloat x, GLfloat y )
    { glad_glWindowPos2f( x, y ); }
    SON8_OVERGLAD_PROC window_pos( GLdouble x, GLdouble y )
    { glad_glWindowPos2d( x, y ); }
    SON8_OVERGLAD_PROC window_pos( GLint x, GLint y, GLint z )
    { glad_glWindowPos3i( x, y, z ); }
    SON8_OVERGLAD_PROC window_pos( GLshort x, GLshort y, GLshort z )
    { glad_glWindowPos3s( x, y, z ); }
    SON8_OVERGLAD_PROC window_pos( GLfloat x, GLfloat y, GLfloat z )
    { glad_glWindowPos3f( x, y, z ); }
    SON8_OVERGLAD_PROC window_pos( GLdouble x, GLdouble y, GLdouble z )
    { glad_glWindowPos3d( x, y, z ); }
    SON8_OVERGLAD_PROC window_pos( types::array2i const &coords )
    { glad_glWindowPos2iv( coords.data( ) ); }
    SON8_OVERGLAD_PROC window_pos( types::array2s const &coords )
    { glad_glWindowPos2sv( coords.data( ) ); }
    SON8_OVERGLAD_PROC window_pos( types::array2f const &coords )
    { glad_glWindowPos2fv( coords.data( ) ); }
    SON8_OVERGLAD_PROC window_pos( types::array2d const &coords )
    { glad_glWindowPos2dv( coords.data( ) ); }
    SON8_OVERGLAD_PROC window_pos( types::array3i const &coords )
    { glad_glWindowPos3iv( coords.data( ) ); }
    SON8_OVERGLAD_PROC window_pos( types::array3s const &coords )
    { glad_glWindowPos3sv( coords.data( ) ); }
    SON8_OVERGLAD_PROC window_pos( types::array3f const &coords )
    { glad_glWindowPos3fv( coords.data( ) ); }
    SON8_OVERGLAD_PROC window_pos( types::array3d const &coords )
    { glad_glWindowPos3dv( coords.data( ) ); }
#endif // not core profile functions
    // DEPRECATED
#ifdef  SON8_OVERGLAD_INCLUDE_DEPRECATED

    // Chapter 2: OpenGL Operation

    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLint s )
    { glMultiTexCoord1i( texture, s ); }
    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLshort s )
    { glMultiTexCoord1s( texture, s ); }
    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLfloat s )
    { glMultiTexCoord1f( texture, s ); }
    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLdouble s )
    { glMultiTexCoord1d( texture, s ); }
    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLint s, GLint t )
    { glMultiTexCoord2i( texture, s, t ); }
    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLshort s, GLshort t )
    { glMultiTexCoord2s( texture, s, t ); }
    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLfloat s, GLfloat t )
    { glMultiTexCoord2f( texture, s, t ); }
    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLdouble s, GLdouble t )
    { glMultiTexCoord2d( texture, s, t ); }
    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLint s, GLint t, GLint p )
    { glMultiTexCoord3i( texture, s, t, p ); }
    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLshort s, GLshort t, GLshort p )
    { glMultiTexCoord3s( texture, s, t, p ); }
    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLfloat s, GLfloat t, GLfloat p )
    { glMultiTexCoord3f( texture, s, t, p ); }
    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLdouble s, GLdouble t, GLdouble p )
    { glMultiTexCoord3d( texture, s, t, p ); }
    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLint s, GLint t, GLint p, GLint q )
    { glMultiTexCoord4i( texture, s, t, p, q ); }
    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLshort s, GLshort t, GLshort p, GLshort q )
    { glMultiTexCoord4s( texture, s, t, p, q ); }
    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLfloat s, GLfloat t, GLfloat p, GLfloat q )
    { glMultiTexCoord4f( texture, s, t, p, q ); }
    SON8_OVERGLAD_DEPR multi_tex_coord( GLenum texture, GLdouble s, GLdouble t, GLdouble p, GLdouble q )
    { glMultiTexCoord4d( texture, s, t, p, q ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_1( GLenum texture, GLint const *coords )
    { glMultiTexCoord1iv( texture, coords ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_1( GLenum texture, GLshort const *coords )
    { glMultiTexCoord1sv( texture, coords ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_1( GLenum texture, GLfloat const *coords )
    { glMultiTexCoord1fv( texture, coords ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_1( GLenum texture, GLdouble const *coords )
    { glMultiTexCoord1dv( texture, coords ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_2( GLenum texture, GLint const *coords )
    { glMultiTexCoord2iv( texture, coords ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_2( GLenum texture, GLshort const *coords )
    { glMultiTexCoord2sv( texture, coords ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_2( GLenum texture, GLfloat const *coords )
    { glMultiTexCoord2fv( texture, coords ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_2( GLenum texture, GLdouble const *coords )
    { glMultiTexCoord2dv( texture, coords ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_3( GLenum texture, GLint const *coords )
    { glMultiTexCoord3iv( texture, coords ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_3( GLenum texture, GLshort const *coords )
    { glMultiTexCoord3sv( texture, coords ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_3( GLenum texture, GLfloat const *coords )
    { glMultiTexCoord3fv( texture, coords ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_3( GLenum texture, GLdouble const *coords )
    { glMultiTexCoord3dv( texture, coords ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_4( GLenum texture, GLint const *coords )
    { glMultiTexCoord4iv( texture, coords ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_4( GLenum texture, GLshort const *coords )
    { glMultiTexCoord4sv( texture, coords ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_4( GLenum texture, GLfloat const *coords )
    { glMultiTexCoord4fv( texture, coords ); }
    SON8_OVERGLAD_DEPR multi_tex_coord_4( GLenum texture, GLdouble const *coords )
    { glMultiTexCoord4dv( texture, coords ); }
    SON8_OVERGLAD_DEPR fog_coord( GLfloat const *coord )
    { glFogCoordfv( coord ); }
    SON8_OVERGLAD_DEPR fog_coord( GLdouble const *coord )
    { glFogCoorddv( coord ); }
    SON8_OVERGLAD_DEPR secondary_color( GLint const *components )
    { glSecondaryColor3iv( components ); }
    SON8_OVERGLAD_DEPR secondary_color( GLbyte const *components )
    { glSecondaryColor3bv( components ); }
    SON8_OVERGLAD_DEPR secondary_color( GLshort const *components)
    { glSecondaryColor3sv( components ); }
    SON8_OVERGLAD_DEPR secondary_color( GLfloat const *components )
    { glSecondaryColor3fv( components ); }
    SON8_OVERGLAD_DEPR secondary_color( GLdouble const *components )
    { glSecondaryColor3dv( components ); }
    SON8_OVERGLAD_DEPR secondary_color( GLuint const *components )
    { glSecondaryColor3uiv( components ); }
    SON8_OVERGLAD_DEPR secondary_color( GLubyte const *components )
    { glSecondaryColor3ubv( components ); }
    SON8_OVERGLAD_DEPR secondary_color( GLushort const *components )
    { glSecondaryColor3usv( components ); }
    SON8_OVERGLAD_DEPR secondary_color_pointer( GLint size, GLenum type, GLsizei stride, GLvoid const *pointer )
    { glSecondaryColorPointer( size, type, stride, pointer ); }
    SON8_OVERGLAD_DEPR fog_coord_pointer( GLenum type, GLsizei stride, GLvoid const *pointer )
    { glFogCoordPointer( type, stride, pointer ); }
    SON8_OVERGLAD_DEPR client_active_texture( GLenum texture )
    { glClientActiveTexture( texture ); }
    SON8_OVERGLAD_DEPR multi_draw_arrays( GLenum mode, GLint const *first, GLsizei const *count, GLsizei drawcount )
    { glMultiDrawArrays( mode, first, count, drawcount ); }
    SON8_OVERGLAD_DEPR multi_draw_elements( GLenum mode, GLsizei const *count, GLenum type, GLvoid *const *indices, GLsizei drawcount )
    { glMultiDrawElements( mode, count, type, indices, drawcount ); }
    SON8_OVERGLAD_DEPR draw_range_elements( GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid const *indices )
    { glDrawRangeElements( mode, start, end, count, type, indices ); }
    SON8_OVERGLAD_DEPR bind_buffer( GLenum target, GLuint buffer )
    { glBindBuffer( target, buffer ); }
    SON8_OVERGLAD_DEPR delete_buffers( GLsizei n, GLuint const *buffers )
    { glDeleteBuffers( n, buffers ); }
    SON8_OVERGLAD_DEPR gen_buffers( GLsizei n, GLuint *buffers )
    { glGenBuffers( n, buffers ); }
    SON8_OVERGLAD_DEPR buffer_data( GLenum target, GLsizeiptr size, GLvoid const *data, GLenum usage )
    { glBufferData( target, size, data, usage ); }
    SON8_OVERGLAD_DEPR buffer_sub_data( GLenum target, GLintptr offset, GLsizeiptr size, GLvoid const *data )
    { glBufferSubData( target, offset, size, data ); }
    SON8_OVERGLAD_DEPR map_buffer( GLenum target, GLenum access ) -> GLvoid *
    { return glMapBuffer( target, access ); }
    SON8_OVERGLAD_DEPR unmap_buffer( GLenum target )
    { return glUnmapBuffer( target ); }
    SON8_OVERGLAD_DEPR load_transpose_matrix( GLfloat const *m )
    { glLoadTransposeMatrixf( m ); }
    SON8_OVERGLAD_DEPR load_transpose_matrix( GLdouble const *m )
    { glLoadTransposeMatrixd( m ); }
    SON8_OVERGLAD_DEPR mult_transpose_matrix( GLfloat const *m )
    { glMultTransposeMatrixf( m ); }
    SON8_OVERGLAD_DEPR mult_transpose_matrix( GLdouble const *m )
    { glMultTransposeMatrixd( m ); }
    SON8_OVERGLAD_DEPR active_texture( GLenum texture )
    { glActiveTexture( texture ); }
    SON8_OVERGLAD_DEPR window_pos_2( GLint const *coords)
    { glWindowPos2iv( coords ); }
    SON8_OVERGLAD_DEPR window_pos_2( GLshort const *coords )
    { glWindowPos2sv( coords ); }
    SON8_OVERGLAD_DEPR window_pos_2( GLfloat const *coords )
    { glWindowPos2fv( coords ); }
    SON8_OVERGLAD_DEPR window_pos_2( GLdouble const *coords )
    { glWindowPos2dv( coords ); }
    SON8_OVERGLAD_DEPR window_pos_3( GLint const *coords )
    { glWindowPos3iv( coords ); }
    SON8_OVERGLAD_DEPR window_pos_3( GLshort const *coords )
    { glWindowPos3sv( coords ); }
    SON8_OVERGLAD_DEPR window_pos_3( GLfloat const *coords )
    { glWindowPos3fv( coords ); }
    SON8_OVERGLAD_DEPR window_pos_3( GLdouble const *coords )
    { glWindowPos3dv( coords ); }

    // Chapter 3: Rasterization

    SON8_OVERGLAD_DEPR point_parameter( GLenum pname, GLint param )
    { glPointParameteri( pname, param ); }
    SON8_OVERGLAD_DEPR point_parameter( GLenum pname, GLfloat param )
    { glPointParameterf( pname, param ); }
    SON8_OVERGLAD_DEPR point_parameter( GLenum pname, GLint const *params )
    { glPointParameteriv( pname, params ); }
    SON8_OVERGLAD_DEPR point_parameter( GLenum pname, GLfloat const *params )
    { glPointParameterfv( pname, params ); }
    SON8_OVERGLAD_DEPR tex_image( GLenum target, GLint level, GLint internalformat,
        GLsizei width, GLsizei height, GLsizei depth, GLint border,
        GLenum format, GLenum type, GLvoid const *data )
    { glTexImage3D( target, level, internalformat, width, height, depth, border, format, type, data ); }
    SON8_OVERGLAD_DEPR tex_sub_image( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
        GLsizei width, GLsizei height, GLsizei depth,
        GLenum format, GLenum type, GLvoid const *data )
    { glTexSubImage3D( target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data ); }
    SON8_OVERGLAD_DEPR copy_tex_sub_image( GLenum target, GLint level,
        GLint xoffset, GLint yoffset, GLint zoffset,
        GLint x, GLint y,
        GLsizei width, GLsizei height )
    { glCopyTexSubImage3D( target, level, xoffset, yoffset, zoffset, x, y, width, height ); }
    SON8_OVERGLAD_DEPR compressed_tex_image( GLenum target, GLint level, GLenum internalformat,
        GLsizei width, GLsizei height, GLsizei depth, GLint border,
        GLsizei imageSize, GLvoid const *data )
    { glCompressedTexImage3D( target, level, internalformat, width, height, depth, border, imageSize, data ); }
    SON8_OVERGLAD_DEPR compressed_tex_image( GLenum target, GLint level, GLenum internalformat,
        GLsizei width, GLsizei height, GLint border,
        GLsizei imageSize, GLvoid const *data )
    { glCompressedTexImage2D( target, level, internalformat, width, height, border, imageSize, data ); }
    SON8_OVERGLAD_DEPR compressed_tex_image( GLenum target, GLint level, GLenum internalformat,
        GLsizei width, GLint border,
        GLsizei imageSize, GLvoid const *data )
    { glCompressedTexImage1D( target, level, internalformat, width, border, imageSize, data ); }
    SON8_OVERGLAD_DEPR compressed_tex_sub_image( GLenum target, GLint level,
        GLint xoffset,
        GLsizei width,
        GLenum format, GLsizei imageSize, GLvoid const *data )
    { glCompressedTexSubImage1D( target, level, xoffset, width, format, imageSize, data ); }
    SON8_OVERGLAD_DEPR compressed_tex_sub_image( GLenum target, GLint level,
        GLint xoffset, GLint yoffset,
        GLsizei width, GLsizei height,
        GLenum format, GLsizei imageSize, GLvoid *data )
    { glCompressedTexSubImage2D( target, level, xoffset, yoffset, width, height, format, imageSize, data ); }
    SON8_OVERGLAD_DEPR compressed_tex_sub_image( GLenum target, GLint level,
        GLint xoffset, GLint yoffset, GLint zoffset,
        GLsizei width, GLsizei height, GLsizei depth,
        GLenum format, GLsizei imageSize, GLvoid *data )
    { glCompressedTexSubImage3D( target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data ); }

    // Chapter 4: Per-Fragment Operations and the Framebuffer

    SON8_OVERGLAD_DEPR begin_query( GLenum target, GLuint id )
    { glBeginQuery( target, id ); }
    SON8_OVERGLAD_DEPR end_query( GLenum target )
    { glEndQuery( target ); }
    SON8_OVERGLAD_DEPR gen_queries( GLsizei n, GLuint *ids )
    { glGenQueries( n, ids ); }
    SON8_OVERGLAD_DEPR delete_queries( GLsizei n, GLuint const *ids )
    { glDeleteQueries( n, ids ); }
    SON8_OVERGLAD_DEPR blend_equation( GLenum mode )
    { glBlendEquation( mode ); }
    SON8_OVERGLAD_DEPR blend_func_separate( GLenum srsRGB, GLenum dstRGB, GLenum srsAlpha, GLenum dstAlpha )
    { glBlendFuncSeparate( srsRGB, dstRGB, srsAlpha, dstAlpha ); }

    // Chapter 6: State and State Requests

    SON8_OVERGLAD_DEPR get_buffer_parameter( GLenum target, GLenum value, GLint *data )
    { glGetBufferParameteriv( target, value, data ); }
    SON8_OVERGLAD_DEPR get_compressed_tex_image( GLenum target, GLint level, GLvoid *pixels )
    { glGetCompressedTexImage( target, level, pixels ); }
    SON8_OVERGLAD_DEPR get_query( GLenum target, GLenum pname, GLint *params )
    { glGetQueryiv( target, pname, params ); }
    SON8_OVERGLAD_DEPR get_query_object( GLuint id, GLenum pname, GLint *params )
    { glGetQueryObjectiv( id, pname, params ); }
    SON8_OVERGLAD_DEPR get_query_object( GLuint id, GLenum pname, GLuint *params )
    { glGetQueryObjectuiv( id, pname, params ); }
    SON8_OVERGLAD_DEPR get_buffer_sub_data( GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data )
    { glGetBufferSubData( target, offset, size, data ); }
    SON8_OVERGLAD_DEPR get_buffer_pointer( GLenum target, GLenum pname, GLvoid **params )
    { glGetBufferPointerv( target, pname, params ); }
#endif // include deprecated functions
} // namespace son8::overglad

#endif // INCLUDE GUARD

// Apache License 2.0
// NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
// SPDX-License-Identifier: Apache-2.0
// lib: `overglad` C++17 Wrapper Over GLAD Loader
// Ⓒ Copyright (c) 2025-2026 Oleg'Ease'Kharchuk ᦒ
