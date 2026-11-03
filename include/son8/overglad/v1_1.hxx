#ifndef SON8_OVERGLAD_V1_1_HXX
#define SON8_OVERGLAD_V1_1_HXX

#ifndef          SON8_OVERGLAD_DEFINED
#define          SON8_OVERGLAD_DEFINED
#define      SON8_OVERGLAD_VERSION_1_1
#define     SON8_OVERGLAD_PROFILE_NONE
#define SON8_OVERGLAD_VERSION 0x010100
#endif         //SON8_OVERGLAD_DEFINED

#include <son8/overglad.hxx>

namespace son8::overglad {
    // Special, object type generation
    template< types::Object_::Type Type, bool Named >
    SON8_OVERGLAD_PROC gen( types::Object< Type, Named > &object )
    {
        using obj = types::Object_;
        static_assert( obj::validate( Type ), "Unsupported object type for generation");
        if constexpr ( Named ) {
            if/*_*/ constexpr ( obj::is_texture( Type ) ) glad_glCreateTextures( object.type( ), 1, object.data( ) );
            else if constexpr ( obj::is_buffer( Type ) ) glad_glGenBuffers( 1, object.data( ) );
            else if constexpr ( obj::is_vertex( Type ) ) glad_glGenVertexArrays( 1, object.data( ) );
            else if constexpr ( obj::is_pipeline( Type ) ) glad_glCreateProgramPipelines( 1, object.data( ) );
        } else {
            if/*_*/ constexpr ( obj::is_texture( Type ) ) glad_glGenTextures( 1, object.data( ) );
            else if constexpr ( obj::is_buffer( Type ) ) glad_glGenBuffers( 1, object.data( ) );
            else if constexpr ( obj::is_vertex( Type ) ) glad_glGenVertexArrays( 1, object.data( ) );
            else if constexpr ( obj::is_pipeline( Type ) ) glad_glGenProgramPipelines( 1, object.data( ) );
        }
    }

    template< types::Object_::Type Type, bool Named >
    SON8_OVERGLAD_PROC gen( types::Objects< Type, Named > &objects )
    {
        using obj = types::Object_;
        static_assert( obj::validate( Type ), "Unsupported object type for generation" );
        if constexpr ( Named ) {
            if/*_*/ constexpr ( obj::is_texture( Type ) ) glad_glCreateTextures( objects.type( ), objects.size( ), objects.data( ) );
            else if constexpr ( obj::is_buffer( Type ) ) glad_glGenBuffers( objects.size( ), objects.data( ) );
            else if constexpr ( obj::is_vertex( Type ) ) glad_glGenVertexArrays( objects.size( ), objects.data( ) );
            else if constexpr ( obj::is_pipeline( Type ) ) glad_glCreateProgramPipelines( objects.size( ), objects.data( ) );
        } else {
            if/*_*/ constexpr ( obj::is_texture( Type ) ) glad_glGenTextures( objects.size( ), objects.data( ) );
            else if constexpr ( obj::is_buffer( Type ) ) glad_glGenBuffers( objects.size( ), objects.data( ) );
            else if constexpr ( obj::is_vertex( Type ) ) glad_glGenVertexArrays( objects.size( ), objects.data( ) );
            else if constexpr ( obj::is_pipeline( Type ) ) glad_glGenProgramPipelines( objects.size( ), objects.data( ) );
        }
    }

    template< types::Object_::Type Type, bool Named >
    SON8_OVERGLAD_PROC del( types::Object< Type, Named > &object )
    {
        using obj = types::Object_;
        static_assert( obj::validate( Type ), "Unsupported object type for deletion" );
        if/*_*/ constexpr ( obj::is_texture( Type ) ) glad_glDeleteTextures( 1, object.data( ) );
        else if constexpr ( obj::is_buffer( Type ) ) glad_glDeleteBuffers( 1, object.data( ) );
        else if constexpr ( obj::is_vertex( Type ) ) glad_glDeleteVertexArrays( 1, object.data( ) );
        else if constexpr ( obj::is_pipeline( Type ) ) glad_glDeleteProgramPipelines( 1, object.data( ) );
        object.zero( );
    }

    template< types::Object_::Type Type, bool Named >
    SON8_OVERGLAD_PROC del( types::Objects< Type, Named > &objects )
    {
        using obj = types::Object_;
        static_assert( obj::validate( Type ), "Unsupported object type for deletion" );
        if/*_*/ constexpr ( obj::is_texture( Type ) ) glad_glDeleteTextures( objects.size( ), objects.data( ) );
        else if constexpr ( obj::is_buffer( Type ) ) glad_glDeleteBuffers( objects.size( ), objects.data( ) );
        else if constexpr ( obj::is_vertex( Type ) ) glad_glDeleteVertexArrays( objects.size( ), objects.data( ) );
        else if constexpr ( obj::is_pipeline( Type ) ) glad_glDeleteProgramPipelines( objects.size( ), objects.data( ) );
        objects.zero( );
    }

    template< types::Object_::Type Type, bool Named >
    SON8_OVERGLAD_PROC bind( types::Object< Type, Named > object )
    {
        assert( object.index( ) != 0 );
        using obj = types::Object_;
        static_assert( obj::validate( Type ), "Unsupported object type for binding" );
        if/*_*/ constexpr ( obj::is_texture( Type ) ) glad_glBindTexture( object.type( ), object );
        else if constexpr ( obj::is_buffer( Type ) ) glad_glBindBuffer( object.type( ), object );
        else if constexpr ( obj::is_vertex( Type ) ) glad_glBindVertexArray( object );
        else if constexpr ( obj::is_pipeline( Type ) ) glad_glBindProgramPipeline( object );
    }

    // Chapter 2: OpenGL Operation

    SON8_OVERGLAD_FUNC get( ) noexcept
    { return static_cast< enums::Error >( glad_glGetError( ) ); }

    // TODO: DrawArrays, DrawElements

    SON8_OVERGLAD_PROC depth_range( GLdouble n, GLdouble f ) noexcept
    { glad_glDepthRange( n, f ); }
    SON8_OVERGLAD_PROC viewport( ) noexcept
    { glad_glViewport( 0, 0, 640, 360 ); }
    SON8_OVERGLAD_PROC viewport( GLsizei wh ) noexcept
    { glad_glViewport( 0, 0, wh, wh ); }
    SON8_OVERGLAD_PROC viewport( GLsizei w, GLsizei h ) noexcept
    { glad_glViewport( 0, 0, w, h ); }
    SON8_OVERGLAD_PROC viewport( GLint x, GLint y, GLsizei w, GLsizei h ) noexcept
    { glad_glViewport( x, y, w, h ); }
    SON8_OVERGLAD_PROC enable( enums::Capability cap ) noexcept
    { glad_glEnable( static_cast< GLenum >( cap ) ); }
    SON8_OVERGLAD_PROC disable( enums::Capability cap ) noexcept
    { glad_glDisable( static_cast< GLenum >( cap ) ); }
    SON8_OVERGLAD_PROC front_face( enums::Dir dir ) noexcept
    { glad_glFrontFace( static_cast< GLenum >( dir ) ); }

    // Chapter 3: Rasterization

    SON8_OVERGLAD_PROC point_size( GLfloat size ) noexcept
    { glad_glPointSize( size ); }
    SON8_OVERGLAD_PROC line_width( GLfloat width ) noexcept
    { glad_glLineWidth( width ); }
    SON8_OVERGLAD_PROC cull( enums::Face face ) noexcept
    { glad_glCullFace( static_cast< GLenum >( face ) ); }
    // NOTE: in core profile face is always Front_Back, so use it by default
    SON8_OVERGLAD_PROC mode( enums::Polygon m ) noexcept
    { glad_glPolygonMode( static_cast< GLenum >( enums::Face::Front_Back ), static_cast< GLenum >( m ) ); }
    SON8_OVERGLAD_PROC polygon_offset( GLfloat factor, GLfloat units ) noexcept
    { glad_glPolygonOffset( factor, units ); }

    // TODO: PixelStore, TexImage, CopyTexImage, TexSubImage, CopyTexSubImage, TexParameter

    // Chapter 4: Per-Fragment Operations and the Framebuffer

    SON8_OVERGLAD_PROC scissor( GLint left, GLint bottom, GLsizei width, GLsizei height ) noexcept
    { glad_glScissor( left, bottom, width, height ); }

    // TODO: StencilFunc, StencilOp

    SON8_OVERGLAD_PROC depth( enums::Func func ) noexcept
    { glad_glDepthFunc( static_cast< GLenum >( func ) ); }

    // TODO: BlendFunc

    SON8_OVERGLAD_PROC logic( enums::Op op ) noexcept
    { glad_glLogicOp( static_cast< GLenum >( op ) ); }

    // TODO: DrawBuffer

    SON8_OVERGLAD_PROC color_mask( GLboolean r, GLboolean g, GLboolean b, GLboolean a ) noexcept
    { glad_glColorMask( r, g, b, a ); }
    SON8_OVERGLAD_PROC depth_mask( GLboolean mask ) noexcept
    { glad_glDepthMask( mask ); }
    SON8_OVERGLAD_PROC stencil_mask( GLuint mask ) noexcept
    { glad_glStencilMask( mask ); }
    SON8_OVERGLAD_PROC clear( enums::Clearbit mask ) noexcept
    { glad_glClear( static_cast< GLbitfield >( mask ) ); }
    SON8_OVERGLAD_PROC clear_color( ) noexcept
    { glad_glClearColor( 0.f, 0.f, 0.f, 0.f ); }
    SON8_OVERGLAD_PROC clear_color( GLfloat grey ) noexcept
    { glad_glClearColor( grey, grey, grey, 1.f ); }
    SON8_OVERGLAD_PROC clear_color( GLfloat grey, GLfloat alpha ) noexcept
    { glad_glClearColor( grey, grey, grey, alpha ); }
    SON8_OVERGLAD_PROC clear_color( GLfloat r, GLfloat g, GLfloat b ) noexcept
    { glad_glClearColor( r, g, b, 1.f ); }
    SON8_OVERGLAD_PROC clear_color( GLfloat r, GLfloat g, GLfloat b, GLfloat a ) noexcept
    { glad_glClearColor( r, g, b, a ); }
    SON8_OVERGLAD_PROC clear_depth( GLdouble d ) noexcept
    { glad_glClearDepth( d ); }
    SON8_OVERGLAD_PROC clear_stencil( GLint s ) noexcept
    { glad_glClearStencil( s ); }

    // TODO: ReadPixels, ReadBuffer

    // Chapter 5: Special Functions

    SON8_OVERGLAD_PROC flush( ) noexcept
    { glad_glFlush( ); }
    SON8_OVERGLAD_PROC finish( ) noexcept
    { glad_glFinish( ); }
    SON8_OVERGLAD_PROC mode( enums::Hint hint, enums::Care care ) noexcept
    { glad_glHint( static_cast< GLenum >( hint ), static_cast< GLenum >( care ) ); }

    // Chapter 6: State and State Requests

    // TODO: GetBooleanv, GetIntegerv, GetFloatv, GetDoublev

    SON8_OVERGLAD_FUNC get( enums::Capability cap ) noexcept
    { return static_cast< bool >( glad_glIsEnabled( static_cast< GLenum >( cap ) ) ); }

    // TODO: GetTexParameter*, GetTexLevelParameter*, GetTexImage

    SON8_OVERGLAD_FUNC is_texture( GLuint index ) noexcept
    { return glad_glIsTexture( index ); }

    // TODO: GetPointerv, GetString

#ifndef SON8_OVERGLAD_PROFILE_CORE

    // Chapter 2: OpenGL Operation

    SON8_OVERGLAD_PROC begin( ) noexcept
    { glad_glBegin( static_cast< GLenum >( enums::Draw::Default ) ); }
    SON8_OVERGLAD_PROC begin( enums::Draw mode ) noexcept
    { glad_glBegin( static_cast< GLenum >( mode ) ); }
    SON8_OVERGLAD_PROC end( ) noexcept
    { glad_glEnd( ); }
    SON8_OVERGLAD_PROC edge_flag( GLboolean flag ) noexcept
    { glad_glEdgeFlag( flag ); }
    SON8_OVERGLAD_PROC edge_flag( types::array1bool const &flagv ) noexcept
    { glad_glEdgeFlagv( flagv.data( ) ); }
    SON8_OVERGLAD_PROC vertex( GLint x, GLint y ) noexcept
    { glad_glVertex2i( x, y ); }
    SON8_OVERGLAD_PROC vertex( GLshort x, GLshort y ) noexcept
    { glad_glVertex2s( x, y ); }
    SON8_OVERGLAD_PROC vertex( GLfloat x, GLfloat y ) noexcept
    { glad_glVertex2f( x, y ); }
    SON8_OVERGLAD_PROC vertex( GLdouble x, GLdouble y ) noexcept
    { glad_glVertex2d( x, y ); }
    SON8_OVERGLAD_PROC vertex( GLint x, GLint y, GLint z ) noexcept
    { glad_glVertex3i( x, y, z ); }
    SON8_OVERGLAD_PROC vertex( GLshort x, GLshort y, GLshort z ) noexcept
    { glad_glVertex3s( x, y, z ); }
    SON8_OVERGLAD_PROC vertex( GLfloat x, GLfloat y, GLfloat z ) noexcept
    { glad_glVertex3f( x, y, z ); }
    SON8_OVERGLAD_PROC vertex( GLdouble x, GLdouble y, GLdouble z ) noexcept
    { glad_glVertex3d( x, y, z ); }
    SON8_OVERGLAD_PROC vertex( GLint x, GLint y, GLint z, GLint w ) noexcept
    { glad_glVertex4i( x, y, z, w ); }
    SON8_OVERGLAD_PROC vertex( GLshort x, GLshort y, GLshort z, GLshort w ) noexcept
    { glad_glVertex4s( x, y, z, w ); }
    SON8_OVERGLAD_PROC vertex( GLfloat x, GLfloat y, GLfloat z, GLshort w ) noexcept
    { glad_glVertex4f( x, y, z, w ); }
    SON8_OVERGLAD_PROC vertex( GLdouble x, GLdouble y, GLdouble z, GLdouble w ) noexcept
    { glad_glVertex4d( x, y, z, w ); }
    SON8_OVERGLAD_PROC vertex( types::array2i const &coords ) noexcept
    { glad_glVertex2iv( coords.data( ) ); }
    SON8_OVERGLAD_PROC vertex( types::array2s const &coords ) noexcept
    { glad_glVertex2sv( coords.data( ) ); }
    SON8_OVERGLAD_PROC vertex( types::array2f const &coords ) noexcept
    { glad_glVertex2fv( coords.data( ) ); }
    SON8_OVERGLAD_PROC vertex( types::array2d const &coords ) noexcept
    { glad_glVertex2dv( coords.data( ) ); }
    SON8_OVERGLAD_PROC vertex( types::array3i const &coords ) noexcept
    { glad_glVertex3iv( coords.data( ) ); }
    SON8_OVERGLAD_PROC vertex( types::array3s const &coords ) noexcept
    { glad_glVertex3sv( coords.data( ) ); }
    SON8_OVERGLAD_PROC vertex( types::array3f const &coords ) noexcept
    { glad_glVertex3fv( coords.data( ) ); }
    SON8_OVERGLAD_PROC vertex( types::array3d const &coords ) noexcept
    { glad_glVertex3dv( coords.data( ) ); }
    SON8_OVERGLAD_PROC vertex( types::array4i const &coords ) noexcept
    { glad_glVertex4iv( coords.data( ) ); }
    SON8_OVERGLAD_PROC vertex( types::array4s const &coords ) noexcept
    { glad_glVertex4sv( coords.data( ) ); }
    SON8_OVERGLAD_PROC vertex( types::array4f const &coords ) noexcept
    { glad_glVertex4fv( coords.data( ) ); }
    SON8_OVERGLAD_PROC vertex( types::array4d const &coords ) noexcept
    { glad_glVertex4dv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( GLint s ) noexcept
    { glad_glTexCoord1i( s ); }
    SON8_OVERGLAD_PROC tex_coord( GLshort s ) noexcept
    { glad_glTexCoord1s( s ); }
    SON8_OVERGLAD_PROC tex_coord( GLfloat s ) noexcept
    { glad_glTexCoord1f( s ); }
    SON8_OVERGLAD_PROC tex_coord( GLdouble s ) noexcept
    { glad_glTexCoord1d( s ); }
    SON8_OVERGLAD_PROC tex_coord( GLint s, GLint t ) noexcept
    { glad_glTexCoord2i( s, t ); }
    SON8_OVERGLAD_PROC tex_coord( GLshort s, GLshort t ) noexcept
    { glad_glTexCoord2s( s, t ); }
    SON8_OVERGLAD_PROC tex_coord( GLfloat s, GLfloat t ) noexcept
    { glad_glTexCoord2f( s, t ); }
    SON8_OVERGLAD_PROC tex_coord( GLdouble s, GLdouble t ) noexcept
    { glad_glTexCoord2d( s, t ); }
    SON8_OVERGLAD_PROC tex_coord( GLint s, GLint t, GLint p ) noexcept
    { glad_glTexCoord3i( s, t, p ); }
    SON8_OVERGLAD_PROC tex_coord( GLshort s, GLshort t, GLshort p ) noexcept
    { glad_glTexCoord3s( s, t, p ); }
    SON8_OVERGLAD_PROC tex_coord( GLfloat s, GLfloat t, GLfloat p ) noexcept
    { glad_glTexCoord3f( s, t, p ); }
    SON8_OVERGLAD_PROC tex_coord( GLdouble s, GLdouble t, GLdouble p ) noexcept
    { glad_glTexCoord3d( s, t, p ); }
    SON8_OVERGLAD_PROC tex_coord( GLint s, GLint t, GLint p, GLint q ) noexcept
    { glad_glTexCoord4i( s, t, p, q ); }
    SON8_OVERGLAD_PROC tex_coord( GLshort s, GLshort t, GLshort p, GLshort q ) noexcept
    { glad_glTexCoord4s( s, t, p, q ); }
    SON8_OVERGLAD_PROC tex_coord( GLfloat s, GLfloat t, GLfloat p, GLfloat q ) noexcept
    { glad_glTexCoord4f( s, t, p, q ); }
    SON8_OVERGLAD_PROC tex_coord( GLdouble s, GLdouble t, GLdouble p, GLdouble q ) noexcept
    { glad_glTexCoord4d( s, t, p, q ); }
    SON8_OVERGLAD_PROC tex_coord( types::array1i const &coords ) noexcept
    { glad_glTexCoord1iv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( types::array1s const &coords ) noexcept
    { glad_glTexCoord1sv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( types::array1f const &coords ) noexcept
    { glad_glTexCoord1fv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( types::array1d const &coords ) noexcept
    { glad_glTexCoord1dv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( types::array2i const &coords ) noexcept
    { glad_glTexCoord2iv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( types::array2s const &coords ) noexcept
    { glad_glTexCoord2sv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( types::array2f const &coords ) noexcept
    { glad_glTexCoord2fv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( types::array2d const &coords ) noexcept
    { glad_glTexCoord2dv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( types::array3i const &coords ) noexcept
    { glad_glTexCoord3iv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( types::array3s const &coords ) noexcept
    { glad_glTexCoord3sv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( types::array3f const &coords ) noexcept
    { glad_glTexCoord3fv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( types::array3d const &coords ) noexcept
    { glad_glTexCoord3dv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( types::array4i const &coords ) noexcept
    { glad_glTexCoord4iv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( types::array4s const &coords ) noexcept
    { glad_glTexCoord4sv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( types::array4f const &coords ) noexcept
    { glad_glTexCoord4fv( coords.data( ) ); }
    SON8_OVERGLAD_PROC tex_coord( types::array4d const &coords ) noexcept
    { glad_glTexCoord4dv( coords.data( ) ); }
    SON8_OVERGLAD_PROC normal( GLbyte x, GLbyte y, GLbyte z ) noexcept
    { glad_glNormal3b( x, y, z ); }
    SON8_OVERGLAD_PROC normal( GLint x, GLint y, GLint z ) noexcept
    { glad_glNormal3i( x, y, z ); }
    SON8_OVERGLAD_PROC normal( GLshort x, GLshort y, GLshort z ) noexcept
    { glad_glNormal3s( x, y, z ); }
    SON8_OVERGLAD_PROC normal( GLfloat x, GLfloat y, GLfloat z ) noexcept
    { glad_glNormal3f( x, y, z ); }
    SON8_OVERGLAD_PROC normal( GLdouble x, GLdouble y, GLdouble z ) noexcept
    { glad_glNormal3d( x, y, z ); }
    SON8_OVERGLAD_PROC normal( types::array3i const &coords ) noexcept
    { glad_glNormal3iv( coords.data( ) ); }
    SON8_OVERGLAD_PROC normal( types::array3b const &coords ) noexcept
    { glad_glNormal3bv( coords.data( ) ); }
    SON8_OVERGLAD_PROC normal( types::array3s const &coords ) noexcept
    { glad_glNormal3sv( coords.data( ) ); }
    SON8_OVERGLAD_PROC normal( types::array3f const &coords ) noexcept
    { glad_glNormal3fv( coords.data( ) ); }
    SON8_OVERGLAD_PROC normal( types::array3d const &coords ) noexcept
    { glad_glNormal3dv( coords.data( ) ); }
    SON8_OVERGLAD_PROC color( GLint r, GLint g, GLint b ) noexcept
    { glad_glColor3i( r, g, b ); }
    SON8_OVERGLAD_PROC color( GLbyte r, GLbyte g, GLbyte b ) noexcept
    { glad_glColor3b( r, g, b ); }
    SON8_OVERGLAD_PROC color( GLuint r, GLuint g, GLuint b ) noexcept
    { glad_glColor3ui( r, g, b ); }
    SON8_OVERGLAD_PROC color( GLubyte r, GLubyte g, GLubyte b ) noexcept
    { glad_glColor3ub( r, g, b ); }
    SON8_OVERGLAD_PROC color( GLshort r, GLshort g, GLshort b ) noexcept
    { glad_glColor3s( r, g, b ); }
    SON8_OVERGLAD_PROC color( GLushort r, GLushort g, GLushort b ) noexcept
    { glad_glColor3us( r, g, b ); }
    SON8_OVERGLAD_PROC color( GLfloat r, GLfloat g, GLfloat b ) noexcept
    { glad_glColor3f( r, g, b ); }
    SON8_OVERGLAD_PROC color( GLdouble r, GLdouble g, GLdouble b ) noexcept
    { glad_glColor3d( r, g, b ); }
    SON8_OVERGLAD_PROC color( GLint r, GLint g, GLint b, GLint a ) noexcept
    { glad_glColor4i( r, g, b, a ); }
    SON8_OVERGLAD_PROC color( GLbyte r, GLbyte g, GLbyte b, GLbyte a ) noexcept
    { glad_glColor4b( r, g, b, a ); }
    SON8_OVERGLAD_PROC color( GLuint r, GLuint g, GLuint b, GLuint a ) noexcept
    { glad_glColor4ui( r, g, b, a ); }
    SON8_OVERGLAD_PROC color( GLubyte r, GLubyte g, GLubyte b, GLubyte a ) noexcept
    { glad_glColor4ub( r, g, b, a ); }
    SON8_OVERGLAD_PROC color( GLshort r, GLshort g, GLshort b, GLshort a ) noexcept
    { glad_glColor4s( r, g, b, a ); }
    SON8_OVERGLAD_PROC color( GLushort r, GLushort g, GLushort b, GLushort a ) noexcept
    { glad_glColor4us( r, g, b, a ); }
    SON8_OVERGLAD_PROC color( GLfloat r, GLfloat g, GLfloat b, GLfloat a ) noexcept
    { glad_glColor4f( r, g, b, a ); }
    SON8_OVERGLAD_PROC color( GLdouble r, GLdouble g, GLdouble b, GLdouble a ) noexcept
    { glad_glColor4d( r, g, b, a ); }
    SON8_OVERGLAD_PROC color( types::array3i const &components ) noexcept
    { glad_glColor3iv( components.data( ) ); }
    SON8_OVERGLAD_PROC color( types::array3b const &components ) noexcept
    { glad_glColor3bv( components.data( ) ); }
    SON8_OVERGLAD_PROC color( types::array3s const &components ) noexcept
    { glad_glColor3sv( components.data( ) ); }
    SON8_OVERGLAD_PROC color( types::array3f const &components ) noexcept
    { glad_glColor3fv( components.data( ) ); }
    SON8_OVERGLAD_PROC color( types::array3d const &components ) noexcept
    { glad_glColor3dv( components.data( ) ); }
    SON8_OVERGLAD_PROC color( types::array3ui const &components ) noexcept
    { glad_glColor3uiv( components.data( ) ); }
    SON8_OVERGLAD_PROC color( types::array3ub const &components ) noexcept
    { glad_glColor3ubv( components.data( ) ); }
    SON8_OVERGLAD_PROC color( types::array3us const &components ) noexcept
    { glad_glColor3usv( components.data( ) ); }
    SON8_OVERGLAD_PROC color( types::array4i const &components ) noexcept
    { glad_glColor4iv( components.data( ) ); }
    SON8_OVERGLAD_PROC color( types::array4b const &components ) noexcept
    { glad_glColor4bv( components.data( ) ); }
    SON8_OVERGLAD_PROC color( types::array4s const &components ) noexcept
    { glad_glColor4sv( components.data( ) ); }
    SON8_OVERGLAD_PROC color( types::array4f const &components ) noexcept
    { glad_glColor4fv( components.data( ) ); }
    SON8_OVERGLAD_PROC color( types::array4d const &components ) noexcept
    { glad_glColor4dv( components.data( ) ); }
    SON8_OVERGLAD_PROC color( types::array4ui const &components ) noexcept
    { glad_glColor4uiv( components.data( ) ); }
    SON8_OVERGLAD_PROC color( types::array4ub const &components ) noexcept
    { glad_glColor4ubv( components.data( ) ); }
    SON8_OVERGLAD_PROC color( types::array4us const &components ) noexcept
    { glad_glColor4usv( components.data( ) ); }
    SON8_OVERGLAD_PROC index( GLint i ) noexcept
    { glad_glIndexi( i ); }
    SON8_OVERGLAD_PROC index( GLshort i ) noexcept
    { glad_glIndexs( i ); }
    SON8_OVERGLAD_PROC index( GLubyte i ) noexcept
    { glad_glIndexub( i ); }
    SON8_OVERGLAD_PROC index( GLfloat i ) noexcept
    { glad_glIndexf( i ); }
    SON8_OVERGLAD_PROC index( GLdouble i ) noexcept
    { glad_glIndexd( i ); }
    SON8_OVERGLAD_PROC index( types::array1i const &index ) noexcept
    { glad_glIndexiv( index.data( ) ); }
    SON8_OVERGLAD_PROC index( types::array1s const &index ) noexcept
    { glad_glIndexsv( index.data( ) ); }
    SON8_OVERGLAD_PROC index( types::array1f const &index ) noexcept
    { glad_glIndexfv( index.data( ) ); }
    SON8_OVERGLAD_PROC index( types::array1d const &index ) noexcept
    { glad_glIndexdv( index.data( ) ); }
    SON8_OVERGLAD_PROC index( types::array1ub const &index ) noexcept
    { glad_glIndexubv( index.data( ) ); }

    // TODO: {EdgeFlag|TexCoord|Color|Index|Vertex}Pointer

    SON8_OVERGLAD_PROC enable( enums::ClientState array ) noexcept
    { glad_glEnableClientState( static_cast< GLenum >( array ) ); }
    SON8_OVERGLAD_PROC disable( enums::ClientState array ) noexcept
    { glad_glDisableClientState( static_cast< GLenum >( array ) ); }
    SON8_OVERGLAD_PROC array_element( GLint i ) noexcept
    { glad_glArrayElement( i ); }

    // TODO: InterleavedArrays

    SON8_OVERGLAD_PROC rect( GLint x1, GLint y1, GLint x2, GLint y2 ) noexcept
    { glad_glRecti( x1, y1, x2, y2 ); }
    SON8_OVERGLAD_PROC rect( GLshort x1, GLshort y1, GLshort x2, GLshort y2 ) noexcept
    { glad_glRects( x1, y1, x2, y2 ); }
    SON8_OVERGLAD_PROC rect( GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2 ) noexcept
    { glad_glRectf( x1, y1, x2, y2 ); }
    SON8_OVERGLAD_PROC rect( GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2 ) noexcept
    { glad_glRectd( x1, y1, x2, y2 ); }
    SON8_OVERGLAD_PROC rect( types::array2i const &v1, types::array2i const &v2 ) noexcept
    { glad_glRectiv( v1.data( ), v2.data( ) ); }
    SON8_OVERGLAD_PROC rect( types::array2s const &v1, types::array2s const &v2 ) noexcept
    { glad_glRectsv( v1.data( ), v2.data( ) ); }
    SON8_OVERGLAD_PROC rect( types::array2f const &v1, types::array2f const &v2 ) noexcept
    { glad_glRectfv( v1.data( ), v2.data( ) ); }
    SON8_OVERGLAD_PROC rect( types::array2d const &v1, types::array2d const &v2 ) noexcept
    { glad_glRectdv( v1.data( ), v2.data( ) ); }
    SON8_OVERGLAD_PROC load_identity( ) noexcept
    { glad_glLoadIdentity( ); }
    SON8_OVERGLAD_PROC mode( enums::Matrix mode ) noexcept
    { glad_glMatrixMode( static_cast< GLenum >( mode ) ); }
    SON8_OVERGLAD_PROC load_matrix( types::array16f const &m ) noexcept
    { glad_glLoadMatrixf( m.data( ) ); }
    SON8_OVERGLAD_PROC load_matrix( types::array16d const &m ) noexcept
    { glad_glLoadMatrixd( m.data( ) ); }
    SON8_OVERGLAD_PROC mult_matrix( types::array16f const &m ) noexcept
    { glad_glMultMatrixf( m.data( ) ); }
    SON8_OVERGLAD_PROC mult_matrix( types::array16d const &m ) noexcept
    { glad_glMultMatrixd( m.data( ) ); }
    SON8_OVERGLAD_PROC rotate( GLfloat degrees, GLfloat x, GLfloat y, GLfloat z ) noexcept
    { glad_glRotatef( degrees, x, y, z ); }
    SON8_OVERGLAD_PROC rotate( GLdouble degrees, GLdouble x, GLdouble y, GLdouble z ) noexcept
    { glad_glRotated( degrees, x, y, z ); }
    SON8_OVERGLAD_PROC translate( GLfloat x, GLfloat y, GLfloat z ) noexcept
    { glad_glTranslatef( x, y, z ); }
    SON8_OVERGLAD_PROC translate( GLdouble x, GLdouble y, GLdouble z ) noexcept
    { glad_glTranslated( x, y, z ); }
    SON8_OVERGLAD_PROC scale( GLfloat x, GLfloat y, GLfloat z ) noexcept
    { glad_glScalef( x, y, z ); }
    SON8_OVERGLAD_PROC scale( GLdouble x, GLdouble y, GLdouble z ) noexcept
    { glad_glScaled( x, y, z ); }
    SON8_OVERGLAD_PROC frustum( GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f ) noexcept
    { glad_glFrustum( l, r, b, t, n, f ); }
    SON8_OVERGLAD_PROC ortho( GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f ) noexcept
    { glad_glOrtho( l, r, b, t, n, f ); }
    SON8_OVERGLAD_PROC push_matrix( ) noexcept
    { glad_glPushMatrix( ); }
    SON8_OVERGLAD_PROC pop_matrix( ) noexcept
    { glad_glPopMatrix( ); }

    // TODO: TexGen

    SON8_OVERGLAD_PROC clip( enums::Plane plane, types::array4d const &eqn ) noexcept
    { glad_glClipPlane( static_cast< GLenum >( plane ), eqn.data( ) ); }
    SON8_OVERGLAD_PROC raster_pos( GLint x, GLint y ) noexcept
    { glad_glRasterPos2i( x, y ); }
    SON8_OVERGLAD_PROC raster_pos( GLshort x, GLshort y ) noexcept
    { glad_glRasterPos2s( x, y ); }
    SON8_OVERGLAD_PROC raster_pos( GLfloat x, GLfloat y ) noexcept
    { glad_glRasterPos2f( x, y ); }
    SON8_OVERGLAD_PROC raster_pos( GLdouble x, GLdouble y ) noexcept
    { glad_glRasterPos2d( x, y ); }
    SON8_OVERGLAD_PROC raster_pos( GLint x, GLint y, GLint z ) noexcept
    { glad_glRasterPos3i( x, y, z ); }
    SON8_OVERGLAD_PROC raster_pos( GLshort x, GLshort y, GLshort z ) noexcept
    { glad_glRasterPos3s( x, y, z ); }
    SON8_OVERGLAD_PROC raster_pos( GLfloat x, GLfloat y, GLfloat z ) noexcept
    { glad_glRasterPos3f( x, y, z ); }
    SON8_OVERGLAD_PROC raster_pos( GLdouble x, GLdouble y, GLdouble z ) noexcept
    { glad_glRasterPos3d( x, y, z ); }
    SON8_OVERGLAD_PROC raster_pos( GLint x, GLint y, GLint z, GLint w ) noexcept
    { glad_glRasterPos4i( x, y, z, w ); }
    SON8_OVERGLAD_PROC raster_pos( GLshort x, GLshort y, GLshort z, GLshort w ) noexcept
    { glad_glRasterPos4s( x, y, z, w ); }
    SON8_OVERGLAD_PROC raster_pos( GLfloat x, GLfloat y, GLfloat z, GLfloat w ) noexcept
    { glad_glRasterPos4f( x, y, z, w ); }
    SON8_OVERGLAD_PROC raster_pos( GLdouble x, GLdouble y, GLdouble z, GLdouble w ) noexcept
    { glad_glRasterPos4d( x, y, z, w ); }
    SON8_OVERGLAD_PROC raster_pos( types::array2i const &coords ) noexcept
    { glad_glRasterPos2iv( coords.data( ) ); }
    SON8_OVERGLAD_PROC raster_pos( types::array2s const &coords ) noexcept
    { glad_glRasterPos2sv( coords.data( ) ); }
    SON8_OVERGLAD_PROC raster_pos( types::array2f const &coords ) noexcept
    { glad_glRasterPos2fv( coords.data( ) ); }
    SON8_OVERGLAD_PROC raster_pos( types::array2d const &coords ) noexcept
    { glad_glRasterPos2dv( coords.data( ) ); }
    SON8_OVERGLAD_PROC raster_pos( types::array3i const &coords ) noexcept
    { glad_glRasterPos3iv( coords.data( ) ); }
    SON8_OVERGLAD_PROC raster_pos( types::array3s const &coords ) noexcept
    { glad_glRasterPos3sv( coords.data( ) ); }
    SON8_OVERGLAD_PROC raster_pos( types::array3f const &coords ) noexcept
    { glad_glRasterPos3fv( coords.data( ) ); }
    SON8_OVERGLAD_PROC raster_pos( types::array3d const &coords ) noexcept
    { glad_glRasterPos3dv( coords.data( ) ); }
    SON8_OVERGLAD_PROC raster_pos( types::array4i const &coords ) noexcept
    { glad_glRasterPos4iv( coords.data( ) ); }
    SON8_OVERGLAD_PROC raster_pos( types::array4s const &coords ) noexcept
    { glad_glRasterPos4sv( coords.data( ) ); }
    SON8_OVERGLAD_PROC raster_pos( types::array4f const &coords ) noexcept
    { glad_glRasterPos4fv( coords.data( ) ); }
    SON8_OVERGLAD_PROC raster_pos( types::array4d const &coords ) noexcept
    { glad_glRasterPos4dv( coords.data( ) ); }

    // TODO: Material, Light, LightModel, ColorMaterial, ShadeModel

    // Chapter 3: Rasterization

    SON8_OVERGLAD_PROC line_stipple( GLint factor, GLushort pattern ) noexcept
    { glad_glLineStipple( factor, pattern ); }

    // TODO: PolygonStipple

    SON8_OVERGLAD_PROC mode( enums::Face face, enums::Polygon m ) noexcept
    { glad_glPolygonMode( static_cast< GLenum >( face ), static_cast< GLenum >( m ) ); }

    // TODO: PixelTransfer*, PixelMap*, DrawPixels

    SON8_OVERGLAD_PROC pixel_zoom( GLfloat x, GLfloat y ) noexcept
    { glad_glPixelZoom( x, y ); }

    // TODO: Bitmap, AreTexturesResident, PrioritizeTextures, TexEnv, Fog

    // Chapter 4: Per-Fragment Operations and the Framebuffer

    // TODO: AlphaFunc

    SON8_OVERGLAD_PROC index_mask( GLuint mask ) noexcept
    { glad_glIndexMask( mask ); }
    SON8_OVERGLAD_PROC clear_index( GLuint index ) noexcept
    { glad_glClearIndex( index ); }
    SON8_OVERGLAD_PROC clear_accum( GLfloat r, GLfloat g, GLfloat b, GLfloat a ) noexcept
    { glad_glClearAccum( r, g, b, a ); }

    // TODO: Accum, CopyPixels

    // Chapter 5: Special Functions

    // TODO: Map+, EvalCoord+, MapGrid+, EvalMesh+, EvalPoint, InitNames, PopName, PushName, LoadName

    SON8_OVERGLAD_FUNC mode( enums::Render m ) noexcept
    { return glad_glRenderMode( static_cast< GLenum >( m ) ); }

    // TODO: SelectBuffer, FeedbackBuffer, Passthrough, NewList

    SON8_OVERGLAD_PROC end_list( ) noexcept
    { glad_glEndList( ); }

    // TODO: CallList, CallLists, ListBase, GenLists, IsList, DeleteLists

    // Chapter 6: State and State Requests

    // TODO: GetClipPlane, GetLight+, GetMaterial+, GetTexEnv+, GetTexGen+, GetPixelMap+, GetMap+, GetPolygonStipple

    SON8_OVERGLAD_PROC push_attrib( enums::Server bitfield ) noexcept
    { glad_glPushAttrib( static_cast< GLbitfield >( bitfield ) ); }
    SON8_OVERGLAD_PROC push_attrib( enums::Client bitfield ) noexcept
    { glad_glPushClientAttrib( static_cast< GLbitfield >( bitfield ) ); }
    SON8_OVERGLAD_PROC pop_server_attrib( ) noexcept
    { glad_glPopAttrib( ); }
    SON8_OVERGLAD_PROC pop_client_attrib( ) noexcept
    { glad_glPopClientAttrib( ); }
#endif // not core profile functions
    // DEPRECATED
#ifdef SON8_OVERGLAD_INCLUDE_DEPRECATED

    // Chapter 2: OpenGL Operation

    SON8_OVERGLAD_DEPR get_error( )
    { return glGetError( ); }
    SON8_OVERGLAD_DEPR begin( GLenum mode )
    { glBegin( mode ); }
    SON8_OVERGLAD_DEPR edge_flag( GLboolean const *flag )
    { glEdgeFlagv( flag ); }
    SON8_OVERGLAD_DEPR vertex_2( GLint const *v )
    { glVertex2iv( v ); }
    SON8_OVERGLAD_DEPR vertex_3( GLint const *v )
    { glVertex3iv( v ); }
    SON8_OVERGLAD_DEPR vertex_4( GLint const *v )
    { glVertex4iv( v ); }
    SON8_OVERGLAD_DEPR vertex_2( GLshort const *v )
    { glVertex2sv( v ); }
    SON8_OVERGLAD_DEPR vertex_3( GLshort const *v )
    { glVertex3sv( v ); }
    SON8_OVERGLAD_DEPR vertex_4( GLshort const *v )
    { glVertex4sv( v ); }
    SON8_OVERGLAD_DEPR vertex_2( GLfloat const *v )
    { glVertex2fv( v ); }
    SON8_OVERGLAD_DEPR vertex_3( GLfloat const *v )
    { glVertex3fv( v ); }
    SON8_OVERGLAD_DEPR vertex_4( GLfloat const *v )
    { glVertex4fv( v ); }
    SON8_OVERGLAD_DEPR vertex_2( GLdouble const *v )
    { glVertex2dv( v ); }
    SON8_OVERGLAD_DEPR vertex_3( GLdouble const *v )
    { glVertex3dv( v ); }
    SON8_OVERGLAD_DEPR vertex_4( GLdouble const *v )
    { glVertex4dv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_1( GLint const *v )
    { glTexCoord1iv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_1( GLshort const *v )
    { glTexCoord1sv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_1( GLfloat const *v )
    { glTexCoord1fv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_1( GLdouble const *v )
    { glTexCoord1dv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_2( GLint const *v )
    { glTexCoord2iv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_2( GLshort const *v )
    { glTexCoord2sv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_2( GLfloat const *v )
    { glTexCoord2fv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_2( GLdouble const *v )
    { glTexCoord2dv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_3( GLint const *v )
    { glTexCoord3iv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_3( GLshort const *v )
    { glTexCoord3sv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_3( GLfloat const *v )
    { glTexCoord3fv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_3( GLdouble const *v )
    { glTexCoord3dv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_4( GLint const *v )
    { glTexCoord4iv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_4( GLshort const *v )
    { glTexCoord4sv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_4( GLfloat const *v )
    { glTexCoord4fv( v ); }
    SON8_OVERGLAD_DEPR tex_coord_4( GLdouble const *v )
    { glTexCoord4dv( v ); }
    SON8_OVERGLAD_DEPR normal( GLbyte const *v )
    { glNormal3bv( v ); }
    SON8_OVERGLAD_DEPR normal( GLint const *v )
    { glNormal3iv( v ); }
    SON8_OVERGLAD_DEPR normal( GLshort const *v )
    { glNormal3sv( v ); }
    SON8_OVERGLAD_DEPR normal( GLfloat const *v )
    { glNormal3fv( v ); }
    SON8_OVERGLAD_DEPR normal( GLdouble const *v )
    { glNormal3dv( v ); }
    SON8_OVERGLAD_DEPR color_3( GLint const *v )
    { glColor3iv( v ); }
    SON8_OVERGLAD_DEPR color_3( GLbyte const *v )
    { glColor3bv( v ); }
    SON8_OVERGLAD_DEPR color_3( GLuint const *v )
    { glColor3uiv( v ); }
    SON8_OVERGLAD_DEPR color_3( GLubyte const *v )
    { glColor3ubv( v ); }
    SON8_OVERGLAD_DEPR color_3( GLshort const *v )
    { glColor3sv( v ); }
    SON8_OVERGLAD_DEPR color_3( GLushort const *v )
    { glColor3usv( v ); }
    SON8_OVERGLAD_DEPR color_3( GLfloat const *v )
    { glColor3fv( v ); }
    SON8_OVERGLAD_DEPR color_3( GLdouble const *v )
    { glColor3dv( v ); }
    SON8_OVERGLAD_DEPR color_4( GLint const *v )
    { glColor4iv( v ); }
    SON8_OVERGLAD_DEPR color_4( GLbyte const *v )
    { glColor4bv( v ); }
    SON8_OVERGLAD_DEPR color_4( GLuint const *v )
    { glColor4uiv( v ); }
    SON8_OVERGLAD_DEPR color_4( GLubyte const *v )
    { glColor4ubv( v ); }
    SON8_OVERGLAD_DEPR color_4( GLshort const *v )
    { glColor4sv( v ); }
    SON8_OVERGLAD_DEPR color_4( GLushort const *v )
    { glColor4usv( v ); }
    SON8_OVERGLAD_DEPR color_4( GLfloat const *v )
    { glColor4fv( v ); }
    SON8_OVERGLAD_DEPR color_4( GLdouble const *v )
    { glColor4dv( v ); }
    SON8_OVERGLAD_DEPR index( GLint const *v )
    { glIndexiv( v ); }
    SON8_OVERGLAD_DEPR index( GLshort const *v )
    { glIndexsv( v ); }
    SON8_OVERGLAD_DEPR index( GLubyte const *v )
    { glIndexubv( v ); }
    SON8_OVERGLAD_DEPR index( GLfloat const *v )
    { glIndexfv( v ); }
    SON8_OVERGLAD_DEPR index( GLdouble const *v )
    { glIndexdv( v ); }
    SON8_OVERGLAD_DEPR edge_flag_pointer( GLsizei stride, GLvoid const *pointer )
    { glEdgeFlagPointer( stride, pointer ); }
    SON8_OVERGLAD_DEPR tex_coord_pointer( GLint size, GLenum type, GLsizei stride, GLvoid const *pointer )
    { glTexCoordPointer( size, type, stride, pointer ); }
    SON8_OVERGLAD_DEPR color_pointer( GLint size, GLenum type, GLsizei stride, GLvoid const *pointer )
    { glColorPointer( size, type, stride, pointer ); }
    SON8_OVERGLAD_DEPR index_pointer( GLenum type, GLsizei stride, GLvoid const *pointer )
    { glIndexPointer( type, stride, pointer ); }
    SON8_OVERGLAD_DEPR normal_pointer( GLenum type, GLsizei stride, GLvoid const *pointer )
    { glNormalPointer( type, stride, pointer ); }
    SON8_OVERGLAD_DEPR vertex_pointer( GLint size, GLenum type, GLsizei stride, GLvoid const *pointer )
    { glVertexPointer( size, type, stride, pointer ); }
    SON8_OVERGLAD_DEPR enable_client_state( GLenum array )
    { glEnableClientState( array ); }
    SON8_OVERGLAD_DEPR disable_client_state( GLenum array )
    { glDisableClientState( array ); }
    SON8_OVERGLAD_DEPR draw_arrays( GLenum mode, GLint first, GLsizei count )
    { glDrawArrays( mode, first, count ); }
    SON8_OVERGLAD_DEPR draw_elements( GLenum mode, GLsizei count, GLenum type, GLvoid const *indices )
    { glDrawElements( mode, count, type, indices ); }
    SON8_OVERGLAD_DEPR interleaved_arrays( GLenum format, GLsizei stride, GLvoid const *pointer )
    { glInterleavedArrays( format, stride, pointer ); }
    SON8_OVERGLAD_DEPR rect( GLint const *v1, GLint const *v2 )
    { glRectiv( v1, v2 ); }
    SON8_OVERGLAD_DEPR rect( GLshort const *v1, GLshort const *v2 )
    { glRectsv( v1, v2 ); }
    SON8_OVERGLAD_DEPR rect( GLfloat const *v1, GLfloat const *v2 )
    { glRectfv( v1, v2 ); }
    SON8_OVERGLAD_DEPR rect( GLdouble const *v1, GLdouble const *v2 )
    { glRectdv( v1, v2 ); }
    SON8_OVERGLAD_DEPR matrix_mode( GLenum mode )
    { glMatrixMode( mode ); }
    SON8_OVERGLAD_DEPR load_matrix( GLfloat const *m )
    { glLoadMatrixf( m ); }
    SON8_OVERGLAD_DEPR load_matrix( GLdouble const *m )
    { glLoadMatrixd( m ); }
    SON8_OVERGLAD_DEPR mult_matrix( GLfloat const *m )
    { glMultMatrixf( m ); }
    SON8_OVERGLAD_DEPR mult_matrix( GLdouble const *m )
    { glMultMatrixd( m ); }
    SON8_OVERGLAD_DEPR enable( GLenum target )
    { glEnable( target ); }
    SON8_OVERGLAD_DEPR disable( GLenum target )
    { glDisable( target ); }
    SON8_OVERGLAD_DEPR tex_gen( GLenum coord, GLenum pname, GLint param )
    { glTexGeni( coord, pname, param ); }
    SON8_OVERGLAD_DEPR tex_gen( GLenum coord, GLenum pname, GLfloat param )
    { glTexGenf( coord, pname, param ); }
    SON8_OVERGLAD_DEPR tex_gen( GLenum coord, GLenum pname, GLdouble param )
    { glTexGend( coord, pname, param ); }
    SON8_OVERGLAD_DEPR tex_gen( GLenum coord, GLenum pname, GLint const *param )
    { glTexGeniv( coord, pname, param ); }
    SON8_OVERGLAD_DEPR tex_gen( GLenum coord, GLenum pname, GLfloat const *param )
    { glTexGenfv( coord, pname, param ); }
    SON8_OVERGLAD_DEPR tex_gen( GLenum coord, GLenum pname, GLdouble const *param )
    { glTexGendv( coord, pname, param ); }
    SON8_OVERGLAD_DEPR clip_plane( GLenum plane, GLdouble const *eqn )
    { glClipPlane( plane, eqn ); }
    SON8_OVERGLAD_DEPR raster_pos_2( GLint const *v )
    { glRasterPos2iv( v ); }
    SON8_OVERGLAD_DEPR raster_pos_2( GLshort const *v )
    { glRasterPos2sv( v ); }
    SON8_OVERGLAD_DEPR raster_pos_2( GLfloat const *v )
    { glRasterPos2fv( v ); }
    SON8_OVERGLAD_DEPR raster_pos_2( GLdouble const *v )
    { glRasterPos2dv( v ); }
    SON8_OVERGLAD_DEPR raster_pos_3( GLint const *v )
    { glRasterPos3iv( v ); }
    SON8_OVERGLAD_DEPR raster_pos_3( GLshort const *v )
    { glRasterPos3sv( v ); }
    SON8_OVERGLAD_DEPR raster_pos_3( GLfloat const *v )
    { glRasterPos3fv( v ); }
    SON8_OVERGLAD_DEPR raster_pos_3( GLdouble const *v )
    { glRasterPos3dv( v ); }
    SON8_OVERGLAD_DEPR raster_pos_4( GLint const *v )
    { glRasterPos4iv( v ); }
    SON8_OVERGLAD_DEPR raster_pos_4( GLshort const *v )
    { glRasterPos4sv( v ); }
    SON8_OVERGLAD_DEPR raster_pos_4( GLfloat const *v )
    { glRasterPos4fv( v ); }
    SON8_OVERGLAD_DEPR raster_pos_4( GLdouble const *v )
    { glRasterPos4dv( v ); }
    SON8_OVERGLAD_DEPR front_face( GLenum mode )
    { glFrontFace( mode ); }
    SON8_OVERGLAD_DEPR material( GLenum face, GLenum pname, GLint param )
    { glMateriali( face, pname, param ); }
    SON8_OVERGLAD_DEPR material( GLenum face, GLenum pname, GLfloat param )
    { glMaterialf( face, pname, param ); }
    SON8_OVERGLAD_DEPR material( GLenum face, GLenum pname, GLint const *params )
    { glMaterialiv( face, pname, params ); }
    SON8_OVERGLAD_DEPR material( GLenum face, GLenum pname, GLfloat const *params )
    { glMaterialfv( face, pname, params ); }
    SON8_OVERGLAD_DEPR light( GLenum light, GLenum pname, GLint param )
    { glLighti( light, pname, param ); }
    SON8_OVERGLAD_DEPR light( GLenum light, GLenum pname, GLfloat param )
    { glLightf( light, pname, param ); }
    SON8_OVERGLAD_DEPR light( GLenum light, GLenum pname, GLint const *params )
    { glLightiv( light, pname, params ); }
    SON8_OVERGLAD_DEPR light( GLenum light, GLenum pname, GLfloat const *params )
    { glLightfv( light, pname, params ); }
    SON8_OVERGLAD_DEPR light_model( GLenum pname, GLint param )
    { glLightModeli( pname, param ); }
    SON8_OVERGLAD_DEPR light_model( GLenum pname, GLfloat param )
    { glLightModelf( pname, param ); }
    SON8_OVERGLAD_DEPR light_model( GLenum pname, GLint const *params )
    { glLightModeliv( pname, params ); }
    SON8_OVERGLAD_DEPR light_model( GLenum pname, GLfloat const *params )
    { glLightModelfv( pname, params ); }
    SON8_OVERGLAD_DEPR color_material( GLenum face, GLenum mode )
    { glColorMaterial( face, mode ); }
    SON8_OVERGLAD_DEPR shade_model( GLenum mode )
    { glShadeModel( mode ); }

    // Chapter 3: Rasterization

    SON8_OVERGLAD_DEPR polygon_stipple( GLubyte const *pattern )
    { glPolygonStipple( pattern ); }
    SON8_OVERGLAD_DEPR cull_face( GLenum mode )
    { glCullFace( mode ); }
    SON8_OVERGLAD_DEPR polygon_mode( GLenum face, GLenum mode )
    { glPolygonMode( face, mode ); }
    SON8_OVERGLAD_DEPR pixel_store( GLenum pname, GLint param )
    { glPixelStorei( pname, param ); }
    SON8_OVERGLAD_DEPR pixel_store( GLenum pname, GLfloat param )
    { glPixelStoref( pname, param ); }
    SON8_OVERGLAD_DEPR pixel_transfer( GLenum pname, GLint param )
    { glPixelTransferi( pname, param ); }
    SON8_OVERGLAD_DEPR pixel_transfer( GLenum pname, GLfloat param )
    { glPixelTransferf( pname, param ); }
    SON8_OVERGLAD_DEPR pixel_map( GLenum map, GLsizei size, GLuint const *values )
    { glPixelMapuiv( map, size, values ); }
    SON8_OVERGLAD_DEPR pixel_map( GLenum map, GLsizei size, GLfloat const *values )
    { glPixelMapfv( map, size, values ); }
    SON8_OVERGLAD_DEPR pixel_map( GLenum map, GLsizei size, GLushort const *values )
    { glPixelMapusv( map, size, values ); }
    SON8_OVERGLAD_DEPR draw_pixels( GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid const *data )
    { glDrawPixels( width, height, format, type, data ); }
    SON8_OVERGLAD_DEPR bitmap( GLsizei w, GLsizei h, GLfloat xbo, GLfloat ybo, GLfloat xbi, GLfloat ybi, GLubyte const *data )
    { glBitmap( w, h, xbo, ybo, xbi, ybi, data ); }
    SON8_OVERGLAD_DEPR tex_image( GLenum target, GLint level, GLint internal, GLsizei w, GLsizei h, GLint border, GLenum format, GLenum type, GLvoid const *data )
    { glTexImage2D( target, level, internal, w, h, border, format, type, data ); }
    SON8_OVERGLAD_DEPR tex_image( GLenum target, GLint level, GLint internal, GLsizei w, GLint border, GLenum format, GLenum type, GLvoid const *data )
    { glTexImage1D( target, level, internal, w, border, format, type, data ); }
    SON8_OVERGLAD_DEPR copy_tex_image( GLenum target, GLint level, GLenum internal, GLint x, GLint y, GLsizei w, GLsizei h, GLint border )
    { glCopyTexImage2D( target, level, internal, x, y, w, h, border ); }
    SON8_OVERGLAD_DEPR copy_tex_image ( GLenum target, GLint level, GLenum internal, GLint x, GLint y, GLsizei w, GLint border )
    { glCopyTexImage1D( target, level, internal, x, y, w, border ); }
    SON8_OVERGLAD_DEPR tex_subimage( GLenum target, GLint level, GLint x, GLsizei w, GLenum format, GLenum type, GLvoid const *data )
    { glTexSubImage1D( target, level, x, w, format, type, data ); }
    SON8_OVERGLAD_DEPR tex_subimage( GLenum target, GLint level, GLint x, GLint y, GLsizei w, GLsizei h, GLenum format, GLenum type, GLvoid const *data )
    { glTexSubImage2D( target, level, x, y, w, h, format, type, data ); }
    SON8_OVERGLAD_DEPR copy_tex_subimage( GLenum target, GLint level, GLint xoffset, GLint y, GLint x, GLsizei w )
    { glCopyTexSubImage1D( target, level, xoffset, x, y, w ); }
    SON8_OVERGLAD_DEPR copy_tex_subimage( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei w, GLsizei h )
    { glCopyTexSubImage2D( target, level, xoffset, yoffset, x, y, w, h ); }
    SON8_OVERGLAD_DEPR tex_parameter( GLenum target, GLenum pname, GLint param )
    { glTexParameteri( target, pname, param ); }
    SON8_OVERGLAD_DEPR tex_parameter( GLenum target, GLenum pname, GLfloat param )
    { glTexParameterf( target, pname, param ); }
    SON8_OVERGLAD_DEPR tex_parameter( GLenum target, GLenum pname, GLint const *params )
    { glTexParameteriv( target, pname, params ); }
    SON8_OVERGLAD_DEPR tex_parameter( GLenum target, GLenum pname, GLfloat const *params )
    { glTexParameterfv( target, pname, params ); }
    SON8_OVERGLAD_DEPR bind_texture( GLenum target, GLuint texture )
    { glBindTexture( target, texture ); }
    SON8_OVERGLAD_DEPR delete_textures( GLsizei n, GLuint const *textures )
    { glDeleteTextures( n, textures ); }
    SON8_OVERGLAD_DEPR gen_textures( GLsizei n, GLuint *textures )
    { glGenTextures( n, textures ); }
    SON8_OVERGLAD_DEPR are_textures_resident( GLsizei n, GLuint const *textures, GLboolean *residences )
    { return glAreTexturesResident( n, textures, residences ); }
    SON8_OVERGLAD_DEPR prioritize_textures( GLsizei n, GLuint const *textures, GLclampf const *priorities )
    { glPrioritizeTextures( n, textures, priorities ); }
    SON8_OVERGLAD_DEPR tex_env( GLenum target, GLenum pname, GLint param )
    { glTexEnvi( target, pname, param ); }
    SON8_OVERGLAD_DEPR tex_env( GLenum target, GLenum pname, GLfloat param )
    { glTexEnvf( target, pname, param ); }
    SON8_OVERGLAD_DEPR tex_env( GLenum target, GLenum pname, GLint const *params )
    { glTexEnviv( target, pname, params ); }
    SON8_OVERGLAD_DEPR tex_env( GLenum target, GLenum pname, GLfloat const *params )
    { glTexEnvfv( target, pname, params ); }
    SON8_OVERGLAD_DEPR fog( GLenum pname, GLint param )
    { glFogi( pname, param ); }
    SON8_OVERGLAD_DEPR fog( GLenum pname, GLfloat param )
    { glFogf( pname, param ); }
    SON8_OVERGLAD_DEPR fog( GLenum pname, GLint const *params )
    { glFogiv( pname, params ); }
    SON8_OVERGLAD_DEPR fog( GLenum pname, GLfloat const *params )
    { glFogfv( pname, params ); }

    // Chapter 4: Per-Fragment Operations and the Framebuffer

    SON8_OVERGLAD_DEPR alpha_func( GLenum func, GLclampf ref )
    { glAlphaFunc( func, ref ); }
    SON8_OVERGLAD_DEPR stencil_func( GLenum func, GLint ref, GLuint mask )
    { glStencilFunc( func, ref, mask ); }
    SON8_OVERGLAD_DEPR stencil_op( GLenum fail, GLenum dpfail, GLenum dppass )
    { glStencilOp( fail, dpfail, dppass ); }
    SON8_OVERGLAD_DEPR depth_func( GLenum func )
    { glDepthFunc( func ); }
    SON8_OVERGLAD_DEPR blend_func( GLenum src, GLenum dst )
    { glBlendFunc( src, dst ); }
    SON8_OVERGLAD_DEPR logic_op( GLenum op )
    { glLogicOp( op ); }
    SON8_OVERGLAD_DEPR draw_buffer( GLenum buf )
    { glDrawBuffer( buf ); }
    SON8_OVERGLAD_DEPR clear( GLbitfield buf )
    { glClear( buf ); }
    SON8_OVERGLAD_DEPR clear_index( GLfloat index )
    { glClearIndex( index ); }
    SON8_OVERGLAD_DEPR accum( GLenum op, GLfloat value )
    { glAccum( op, value ); }
    SON8_OVERGLAD_DEPR read_pixels( GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *data )
    { glReadPixels( x, y, width, height, format, type, data ); }
    SON8_OVERGLAD_DEPR read_buffer( GLenum buf )
    { glReadBuffer( buf ); }
    SON8_OVERGLAD_DEPR copy_pixels( GLint x, GLint y, GLsizei width, GLsizei height, GLenum type )
    { glCopyPixels( x, y, width, height, type ); }

    // Chapter 5: Special Functions

    SON8_OVERGLAD_DEPR map( GLenum type, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat const *points )
    { glMap1f( type, u1, u2, stride, order, points ); }
    SON8_OVERGLAD_DEPR map( GLenum type, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble const *points )
    { glMap1d( type, u1, u2, stride, order, points ); }
    SON8_OVERGLAD_DEPR map( GLenum target
        , GLfloat u1, GLfloat u2, GLint ustride, GLint uorder
        , GLfloat v1, GLfloat v2, GLint vstride, GLint vorder
        , GLfloat const *points )
    { glMap2f( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points ); }
    SON8_OVERGLAD_DEPR map( GLenum target
        , GLdouble u1, GLdouble u2, GLint ustride, GLint uorder
        , GLdouble v1, GLdouble v2, GLint vstride, GLint vorder
        , GLdouble const *points )
    { glMap2d( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points ); }
    SON8_OVERGLAD_DEPR eval( GLfloat arg )
    { glEvalCoord1f( arg ); }
    SON8_OVERGLAD_DEPR eval( GLdouble arg )
    { glEvalCoord1d( arg ); }
    SON8_OVERGLAD_DEPR eval( GLfloat arg1, GLfloat arg2 )
    { glEvalCoord2f( arg1, arg2 ); }
    SON8_OVERGLAD_DEPR eval( GLdouble arg1, GLdouble arg2 )
    { glEvalCoord2d( arg1, arg2 ); }
    SON8_OVERGLAD_DEPR eval_1( GLfloat const *arg )
    { glEvalCoord1fv( arg ); }
    SON8_OVERGLAD_DEPR eval_1( GLdouble const *arg )
    { glEvalCoord1dv( arg ); }
    SON8_OVERGLAD_DEPR eval_2( GLfloat const *arg )
    { glEvalCoord2fv( arg ); }
    SON8_OVERGLAD_DEPR eval_2( GLdouble const *arg )
    { glEvalCoord2dv( arg ); }
    SON8_OVERGLAD_DEPR grid( GLint n, GLfloat u1, GLfloat u2 )
    { glMapGrid1f( n, u1, u2 ); }
    SON8_OVERGLAD_DEPR grid( GLint n, GLdouble u1, GLdouble u2 )
    { glMapGrid1d( n, u1, u2 ); }
    SON8_OVERGLAD_DEPR grid( GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2 )
    { glMapGrid2f( un, u1, u2, vn, v1, v2 ); }
    SON8_OVERGLAD_DEPR grid( GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2 )
    { glMapGrid2d( un, u1, u2, vn, v1, v2 ); }
    SON8_OVERGLAD_DEPR eval( GLenum mode, GLint p1, GLint p2 )
    { glEvalMesh1( mode, p1, p2 ); }
    SON8_OVERGLAD_DEPR eval( GLenum mode, GLint p1, GLint p2, GLint q1, GLint q2 )
    { glEvalMesh2( mode, p1, p2, q1, q2 ); }
    SON8_OVERGLAD_DEPR eval( GLint p )
    { glEvalPoint1( p ); }
    SON8_OVERGLAD_DEPR eval( GLint p, GLint q )
    { glEvalPoint2( p, q ); }
    SON8_OVERGLAD_DEPR init_names( )
    { glInitNames( ); }
    SON8_OVERGLAD_DEPR pop_name( )
    { glPopName( ); }
    SON8_OVERGLAD_DEPR push_name( GLuint name )
    { glPushName( name ); }
    SON8_OVERGLAD_DEPR load_name( GLuint name )
    { glLoadName( name ); }
    SON8_OVERGLAD_DEPR render_mode( GLenum mode )
    { return glRenderMode( mode ); }
    SON8_OVERGLAD_DEPR select_buffer( GLsizei n, GLuint *buffer )
    { glSelectBuffer( n, buffer ); }
    SON8_OVERGLAD_DEPR feedback_buffer( GLsizei n, GLenum type, GLfloat *buffer )
    { glFeedbackBuffer( n, type, buffer ); }
    SON8_OVERGLAD_DEPR pass_through( GLfloat token )
    { glPassThrough( token ); }
    SON8_OVERGLAD_DEPR new_list( GLuint n, GLenum mode )
    { glNewList( n, mode ); }
    SON8_OVERGLAD_DEPR call_list( GLuint n )
    { glCallList( n ); }
    SON8_OVERGLAD_DEPR call_lists( GLsizei n, GLenum type, GLvoid const *lists )
    { glCallLists( n, type, lists ); }
    SON8_OVERGLAD_DEPR list_base( GLuint base )
    { glListBase( base ); }
    SON8_OVERGLAD_DEPR gen_lists( GLsizei n )
    { return glGenLists( n ); }
    SON8_OVERGLAD_DEPR is_list( GLuint list )
    { return glIsList( list ); }
    SON8_OVERGLAD_DEPR delete_lists( GLuint list, GLsizei range )
    { glDeleteLists( list, range ); }
    SON8_OVERGLAD_DEPR hint( GLenum target, GLenum hint )
    { glHint( target, hint ); }

    // Chapter 6: State and State Requests

    SON8_OVERGLAD_DEPR get_boolean( GLenum value, GLboolean *data )
    { glGetBooleanv( value, data ); }
    SON8_OVERGLAD_DEPR get_integer( GLenum value, GLint *data )
    { glGetIntegerv( value, data ); }
    SON8_OVERGLAD_DEPR get_float( GLenum value, GLfloat *data )
    { glGetFloatv( value, data ); }
    SON8_OVERGLAD_DEPR get_double( GLenum value, GLdouble *data )
    { glGetDoublev( value, data ); }
    SON8_OVERGLAD_DEPR is_enabled( GLenum value )
    { return glIsEnabled( value ); }
    SON8_OVERGLAD_DEPR get_clip_plane( GLenum plane, GLdouble *eqn )
    { glGetClipPlane( plane, eqn ); }
    SON8_OVERGLAD_DEPR get_light( GLenum light, GLenum value, GLint *data )
    { glGetLightiv( light, value, data ); }
    SON8_OVERGLAD_DEPR get_light( GLenum light, GLenum value, GLfloat *data )
    { glGetLightfv( light, value, data ); }
    SON8_OVERGLAD_DEPR get_material( GLenum face, GLenum value, GLint *data )
    { glGetMaterialiv( face, value, data ); }
    SON8_OVERGLAD_DEPR get_material( GLenum face, GLenum value, GLfloat *data )
    { glGetMaterialfv( face, value, data ); }
    SON8_OVERGLAD_DEPR get_tex_env( GLenum env, GLenum value, GLint *data )
    { glGetTexEnviv( env, value, data ); }
    SON8_OVERGLAD_DEPR get_tex_env( GLenum env, GLenum value, GLfloat *data )
    { glGetTexEnvfv( env, value, data ); }
    SON8_OVERGLAD_DEPR get_tex_gen( GLenum coord, GLenum value, GLint *data )
    { glGetTexGeniv( coord, value, data ); }
    SON8_OVERGLAD_DEPR get_tex_gen( GLenum coord, GLenum value, GLfloat *data )
    { glGetTexGenfv( coord, value, data ); }
    SON8_OVERGLAD_DEPR get_tex_parameter( GLenum target, GLenum value, GLint *data )
    { glGetTexParameteriv( target, value, data ); }
    SON8_OVERGLAD_DEPR get_tex_parameter( GLenum target, GLenum value, GLfloat *data )
    { glGetTexParameterfv( target, value, data ); }
    SON8_OVERGLAD_DEPR get_tex_level_parameter( GLenum target, GLint lod, GLenum value, GLint *data )
    { glGetTexLevelParameteriv( target, lod, value, data ); }
    SON8_OVERGLAD_DEPR get_pixel_map( GLenum map, GLuint *data )
    { glGetPixelMapuiv( map, data ); }
    SON8_OVERGLAD_DEPR get_pixel_map( GLenum map, GLushort *data )
    { glGetPixelMapusv( map, data ); }
    SON8_OVERGLAD_DEPR get_pixel_map( GLenum map, GLfloat *data )
    { glGetPixelMapfv( map, data ); }
    SON8_OVERGLAD_DEPR get_map( GLenum map, GLenum value, GLint *data )
    { glGetMapiv( map, value, data ); }
    SON8_OVERGLAD_DEPR get_map( GLenum map, GLenum value, GLfloat *data )
    { glGetMapfv( map, value, data ); }
    SON8_OVERGLAD_DEPR get_map( GLenum map, GLenum value, GLdouble *data )
    { glGetMapdv( map, value, data ); }
    SON8_OVERGLAD_DEPR get_tex_image( GLenum tex, GLint lod, GLenum format, GLenum type, GLvoid *img )
    { glGetTexImage( tex, lod, format, type, img ); }
    SON8_OVERGLAD_DEPR get_polygon_stipple( GLubyte *pattern )
    { glGetPolygonStipple( pattern ); }
    SON8_OVERGLAD_DEPR get_pointer( GLenum pname, GLvoid **params )
    { glGetPointerv( pname, params ); }
    SON8_OVERGLAD_DEPR get_string( GLenum name )
    { return reinterpret_cast< char const * >( glGetString( name ) ); }
    SON8_OVERGLAD_DEPR push_attrib( GLbitfield mask )
    { glPushAttrib( mask ); }
    SON8_OVERGLAD_DEPR push_client_attrib( GLbitfield mask )
    { glPushClientAttrib( mask ); }
    SON8_OVERGLAD_DEPR pop_attrib( )
    { glPopAttrib( ); }
#endif // include deprecated functions
} // namespace son8::overglad

#endif // INCLUDE GUARD

// Apache License 2.0
// NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
// SPDX-License-Identifier: Apache-2.0
// lib: `overglad` C++17 Wrapper Over GLAD Loader
// Ⓒ Copyright (c) 2025-2026 Oleg'Ease'Kharchuk ᦒ
