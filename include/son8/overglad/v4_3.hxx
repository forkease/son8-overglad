#ifndef SON8_OVERGLAD_V4_3_HXX
#define SON8_OVERGLAD_V4_3_HXX

#ifndef          SON8_OVERGLAD_DEFINED
#define          SON8_OVERGLAD_DEFINED
#define      SON8_OVERGLAD_VERSION_1_1
#define      SON8_OVERGLAD_VERSION_1_5
#define      SON8_OVERGLAD_VERSION_2_1
#define      SON8_OVERGLAD_VERSION_3_3
#define      SON8_OVERGLAD_VERSION_4_3
#define     SON8_OVERGLAD_PROFILE_CORE
#define SON8_OVERGLAD_VERSION 0x0403CE
#include      <son8/overglad/v1_1.hxx>
#include      <son8/overglad/v1_5.hxx>
#include      <son8/overglad/v2_1.hxx>
#include      <son8/overglad/v3_3.hxx>
#endif         //SON8_OVERGLAD_DEFINED

namespace son8::overglad {
    // CORE

    // Chapter 4: Event Model

    // TODO: BeginQueryIndexed,EndQueryIndexed,GetQueryIndexediv

    // Chapter 6: Buffer Objects

    // TODO: ClearBufferSubData,ClearBufferData,InvalidateBufferSubData,InvalidateBufferData

    // Chapter 7: Programs and Shaders

    SON8_OVERGLAD_PROC release_shader_compiler( )
    { glad_glReleaseShaderCompiler( ); }

    // TODO: ShaderBinary,ProgramParameteri,CreateShaderProgramv
    // ,GetProgramInterfaceiv,GetProgramResourceIndex,GetProgramResourceName,GetProgramResourceiv,GetProgramResourceLocation
    // ,GetProgramResourceLocationIndex

    SON8_OVERGLAD_FUNC is_pipeline( GLuint pipeline )
    { return glad_glIsProgramPipeline( pipeline ); }

    // TODO: UseProgramStages,ActiveShaderProgram,GetProgramBinary,ProgramBinary,GetActiveAtomicCounterBufferiv
    // ,Uniform*dv,UniformMatrix*dv,ProgramUniform*,ProgramUniformMatrix*,ShaderStorageBlockBinding
    // ,GetSubroutineIndex,GetActiveSubroutineName,GetSubroutineUniformLocation,GetActiveSubroutineUniformName
    // ,GetActiveSubroutineUniformiv,UniformSubroutinesuiv

    SON8_OVERGLAD_PROC memory_barrier( enums::Barrier barriers )
    { glad_glMemoryBarrier( static_cast< GLenum >( barriers ) ); }

    // TODO: GetProgramPipelineiv,GetProgramPipelineInfoLog,GetShaderPrecisionFormat,GetUniformdv,GetUniformSubroutineuiv,GetProgramStageiv

    // Chapter 8: Textures and Samplers

    // TODO: TexBufferRange,TextureView,TexStorage1D,TexStorage2D,TexStorage3D,TexStorage2DMultisample,TexStorage3DMultisample
    // ,InvalidateTexSubImage,InvalidateTexImage,BindImageTexture

    // Chapter 9: Framebuffers and Framebuffer Objects

    // TODO: FramebufferParameteri,GetFramebufferParameteriv

    // Chapter 10: Vertex Specification and Drawing Commands

    // TODO: PatchParameteri,VertexAttribL*dv,VertexAttrib*Format,BindVertexBuffer
    // ,VertexAttribBinding,VertexAttribLPointer,VertexBindingDivisor
    // ,DrawArraysInstancedBaseInstance,DrawArraysIndirect,MultiDrawArraysIndirect
    // ,DrawElementsInstancedBaseInstance,DrawElementsInstancedBaseVertexBaseInstance
    // ,DrawElementsIndirect,MultiDrawElementsIndirect,GetVertexAttribLdv

    // Chapter 11: Programmable Vertex Processing

    // TODO: ValidateProgramPipeline,PatchParameterfv

    // Chapter 13: Fixed-Function Vertex Post-Processing

    // TODO: GenTransformFeedbacks,DeleteTransformFeedbacks

    SON8_OVERGLAD_FUNC is_transform_feedback( GLuint id )
    { return glad_glIsTransformFeedback( id ); }

    // TODO: BindTransformFeedback,PauseTransformFeedback,ResumeTransformFeedback,DrawTransformFeedback
    // ,DrawTransformFeedbackInstanced,DrawTransformFeedbackStream,DrawTransformFeedbackStreamInstanced
    // ,DepthRangeArrayv,DepthRangeIndexed,DepthRangef,ViewportArrayv,ViewportIndexedf,ViewportIndexedfv

    // Chapter 14: Fixed-Function Primitive Assembly and Rasterization

    // TODO: MinSampleShading

    // Chapter 17: Writing Fragments and Samples to the Framebuffer

    // TODO: ScissorArrayv,ScissorIndexed,ScissorIndexedv,BlendEquationi,BlendEquationSeparatei,BlendFunci,BlendFuncSeparatei

    SON8_OVERGLAD_PROC clear_depth( GLfloat depth )
    { glad_glClearDepthf( depth ); }

    // TODO: ,InvalidateSubFramebuffer,InvalidateFramebuffer

    // Chapter 18: Reading and Copying Pixels

    // TODO: CopyImageSubData

    // Chapter 19: Compute Shaders

    // TODO: DispatchCompute,DispatchComputeIndirect

    // Chapter 20: Debug Output

    // TODO: DebugMessageCallback,DebugMessageControl,DebugMessageInsert,PushDebugGroup,PopDebugGroup
    // ,ObjectLabel,ObjectPtrLabel,GetDebugMessageLog,GetObjectLabel,GetObjectPtrLabel

    // Chapter 22: Context State Queries

    // TODO: GetFloati_v,GetDoublei_v,GetInternalformat

    // COMPATIBILITY
#ifndef SON8_OVERGLAD_PROFILE_CORE
#endif // not core profile functions
    // DEPRECATED
#ifdef  SON8_OVERGLAD_INCLUDE_DEPRECATED

    // Chapter 4: Event Model

    SON8_OVERGLAD_DEPR begin_query( GLenum target, GLuint index, GLuint id )
    { glBeginQueryIndexed( target, index, id ); }
    SON8_OVERGLAD_DEPR end_query( GLenum target, GLuint index )
    { glEndQueryIndexed( target, index ); }
    SON8_OVERGLAD_DEPR get_query( GLenum target, GLuint index, GLenum pname, GLint *params )
    { glGetQueryIndexediv( target, index, pname, params ); }

    // Chapter 6: Buffer Objects

    SON8_OVERGLAD_DEPR clear_buffer_sub_data( GLenum target, GLenum internalformat,
        GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, GLvoid const *data )
    { glClearBufferSubData( target, internalformat, offset, size, format, type, data ); }
    SON8_OVERGLAD_DEPR clear_buffer_data( GLenum target, GLenum internalformat,
        GLenum format, GLenum type, GLvoid const *data )
    { glClearBufferData( target, internalformat, format, type, data ); }
    SON8_OVERGLAD_DEPR invalidate_buffer_sub_data( GLuint buffer, GLintptr offset, GLsizeiptr length )
    { glInvalidateBufferSubData( buffer, offset, length ); }
    SON8_OVERGLAD_DEPR invalidate_buffer_data( GLuint buffer )
    { glInvalidateBufferData( buffer ); }

    // Chapter 7: Programs and Shaders

    SON8_OVERGLAD_DEPR shader_binary( GLsizei count, GLuint const *shaders, GLenum binaryformat,
        GLvoid const *binary, GLsizei length )
    { glShaderBinary( count, shaders, binaryformat, binary, length ); }
    SON8_OVERGLAD_DEPR program_parameter( GLuint program, GLenum pname, GLint value )
    { glProgramParameteri( program, pname, value ); }
    SON8_OVERGLAD_DEPR create_shader_program( GLenum type, GLsizei count, GLchar const *const *strings )
    { return glCreateShaderProgramv( type, count, strings ); }
    SON8_OVERGLAD_DEPR get_program_interface( GLuint program, GLenum programInterface, GLenum pname, GLint *params )
    { glGetProgramInterfaceiv( program, programInterface, pname, params ); }
    SON8_OVERGLAD_DEPR get_program_resource_index( GLuint program, GLenum programInterface, GLchar const *name )
    { return glGetProgramResourceIndex( program, programInterface, name ); }
    SON8_OVERGLAD_DEPR get_program_resource_name( GLuint program, GLenum programInterface, GLuint index,
        GLsizei bufSize, GLsizei *length, GLchar *name )
    { glGetProgramResourceName( program, programInterface, index, bufSize, length, name ); }
    SON8_OVERGLAD_DEPR get_program_resourceiv( GLuint program, GLenum programInterface, GLuint index,
        GLsizei propCount, GLenum const *props, GLsizei bufSize, GLsizei *length, GLint *params )
    { glGetProgramResourceiv( program, programInterface, index, propCount, props, bufSize, length, params ); }
    SON8_OVERGLAD_DEPR get_program_resource_location( GLuint program, GLenum programInterface, GLchar const *name )
    { return glGetProgramResourceLocation( program, programInterface, name ); }
    SON8_OVERGLAD_DEPR get_program_resource_location_index( GLuint program, GLenum programInterface, GLchar const *name )
    { return glGetProgramResourceLocationIndex( program, programInterface, name ); }
    SON8_OVERGLAD_DEPR gen_pipelines( GLsizei n, GLuint *pipelines )
    { glGenProgramPipelines( n, pipelines ); }
    SON8_OVERGLAD_DEPR delete_pipelines( GLsizei n, GLuint const *pipelines )
    { glDeleteProgramPipelines( n, pipelines ); }
    SON8_OVERGLAD_DEPR bind_pipeline( GLuint pipeline )
    { glBindProgramPipeline( pipeline ); }
    SON8_OVERGLAD_DEPR use_program_stages( GLuint pipeline, GLenum stages, GLuint program )
    { glUseProgramStages( pipeline, stages, program ); }
    SON8_OVERGLAD_DEPR active_shader_program( GLuint pipeline, GLuint program )
    { glActiveShaderProgram( pipeline, program ); }
    SON8_OVERGLAD_DEPR get_program_binary( GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary )
    { glGetProgramBinary( program, bufSize, length, binaryFormat, binary ); }
    SON8_OVERGLAD_DEPR program_binary( GLuint program, GLenum binaryFormat, GLvoid const *binary, GLsizei length )
    { glProgramBinary( program, binaryFormat, binary, length ); }
    SON8_OVERGLAD_DEPR get_active_atomic_counter_buffer( GLuint program, GLuint bufferIndex, GLenum pname, GLint *params )
    { glGetActiveAtomicCounterBufferiv( program, bufferIndex, pname, params ); }
    SON8_OVERGLAD_DEPR uniform( GLint location, GLdouble x )
    { glUniform1d( location, x ); }
    SON8_OVERGLAD_DEPR uniform( GLint location, GLdouble x, GLdouble y )
    { glUniform2d( location, x, y ); }
    SON8_OVERGLAD_DEPR uniform( GLint location, GLdouble x, GLdouble y, GLdouble z )
    { glUniform3d( location, x, y, z ); }
    SON8_OVERGLAD_DEPR uniform( GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w )
    { glUniform4d( location, x, y, z, w ); }
    SON8_OVERGLAD_DEPR uniform_1( GLint location, GLsizei count, GLdouble const *value )
    { glUniform1dv( location, count, value ); }
    SON8_OVERGLAD_DEPR uniform_2( GLint location, GLsizei count, GLdouble const *value )
    { glUniform2dv( location, count, value ); }
    SON8_OVERGLAD_DEPR uniform_3( GLint location, GLsizei count, GLdouble const *value )
    { glUniform3dv( location, count, value ); }
    SON8_OVERGLAD_DEPR uniform_4( GLint location, GLsizei count, GLdouble const *value )
    { glUniform4dv( location, count, value ); }
    SON8_OVERGLAD_DEPR uniform_matrix_2( GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    { glUniformMatrix2dv( location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR uniform_matrix_3( GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    { glUniformMatrix3dv( location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR uniform_matrix_4( GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    { glUniformMatrix4dv( location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR uniform_matrix_2x3( GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    { glUniformMatrix2x3dv( location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR uniform_matrix_2x4( GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    { glUniformMatrix2x4dv( location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR uniform_matrix_3x2( GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    { glUniformMatrix3x2dv( location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR uniform_matrix_3x4( GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    { glUniformMatrix3x4dv( location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR uniform_matrix_4x2( GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    { glUniformMatrix4x2dv( location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR uniform_matrix_4x3( GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    { glUniformMatrix4x3dv( location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLint x )
    {  glProgramUniform1i( program, location, x ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLfloat x )
    {  glProgramUniform1f( program, location, x ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLdouble x )
    {  glProgramUniform1d( program, location, x ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLint x, GLint y )
    {  glProgramUniform2i( program, location, x, y ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLfloat x, GLfloat y )
    {  glProgramUniform2f( program, location, x, y ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLdouble x, GLdouble y )
    {  glProgramUniform2d( program, location, x, y ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLint x, GLint y, GLint z )
    {  glProgramUniform3i( program, location, x, y, z ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z )
    {  glProgramUniform3f( program, location, x, y, z ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z )
    {  glProgramUniform3d( program, location, x, y, z ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLint x, GLint y, GLint z, GLint w )
    {  glProgramUniform4i( program, location, x, y, z, w ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w )
    {  glProgramUniform4f( program, location, x, y, z, w ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w )
    {  glProgramUniform4d( program, location, x, y, z, w ); }
    SON8_OVERGLAD_DEPR program_uniform_1( GLuint program, GLint location, GLsizei count, GLint const *value )
    {  glProgramUniform1iv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform_1( GLuint program, GLint location, GLsizei count, GLfloat const *value )
    {  glProgramUniform1fv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform_1( GLuint program, GLint location, GLsizei count, GLdouble const *value )
    {  glProgramUniform1dv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform_2( GLuint program, GLint location, GLsizei count, GLint const *value )
    {  glProgramUniform2iv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform_2( GLuint program, GLint location, GLsizei count, GLfloat const *value )
    {  glProgramUniform2fv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform_2( GLuint program, GLint location, GLsizei count, GLdouble const *value )
    {  glProgramUniform2dv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform_3( GLuint program, GLint location, GLsizei count, GLint const *value )
    {  glProgramUniform3iv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform_3( GLuint program, GLint location, GLsizei count, GLfloat const *value )
    {  glProgramUniform3fv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform_3( GLuint program, GLint location, GLsizei count, GLdouble const *value )
    {  glProgramUniform3dv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform_4( GLuint program, GLint location, GLsizei count, GLint const *value )
    {  glProgramUniform4iv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform_4( GLuint program, GLint location, GLsizei count, GLfloat const *value )
    {  glProgramUniform4fv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform_4( GLuint program, GLint location, GLsizei count, GLdouble const *value )
    {  glProgramUniform4dv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLuint x )
    {  glProgramUniform1ui( program, location, x ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLuint x, GLuint y )
    {  glProgramUniform2ui( program, location, x, y ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLuint x, GLuint y, GLuint z )
    {  glProgramUniform3ui( program, location, x, y, z ); }
    SON8_OVERGLAD_DEPR program_uniform( GLuint program, GLint location, GLuint x, GLuint y, GLuint z, GLuint w )
    {  glProgramUniform4ui( program, location, x, y, z, w ); }
    SON8_OVERGLAD_DEPR program_uniform_1( GLuint program, GLint location, GLsizei count, GLuint const *value )
    {  glProgramUniform1uiv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform_2( GLuint program, GLint location, GLsizei count, GLuint const *value )
    {  glProgramUniform2uiv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform_3( GLuint program, GLint location, GLsizei count, GLuint const *value )
    {  glProgramUniform3uiv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform_4( GLuint program, GLint location, GLsizei count, GLuint const *value )
    {  glProgramUniform4uiv( program, location, count, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_2( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const *value )
    {  glProgramUniformMatrix2fv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_2( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    {  glProgramUniformMatrix2dv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_3( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const *value )
    {  glProgramUniformMatrix3fv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_3( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    {  glProgramUniformMatrix3dv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_4( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const *value )
    {  glProgramUniformMatrix4fv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_4( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    {  glProgramUniformMatrix4dv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_2x3( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const *value )
    {  glProgramUniformMatrix2x3fv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_2x3( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    {  glProgramUniformMatrix2x3dv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_2x4( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const *value )
    {  glProgramUniformMatrix2x4fv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_2x4( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    {  glProgramUniformMatrix2x4dv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_3x2( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const *value )
    {  glProgramUniformMatrix3x2fv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_3x2( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    {  glProgramUniformMatrix3x2dv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_3x4( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const *value )
    {  glProgramUniformMatrix3x4fv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_3x4( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    {  glProgramUniformMatrix3x4dv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_4x2( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const *value )
    {  glProgramUniformMatrix4x2fv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_4x2( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    {  glProgramUniformMatrix4x2dv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_4x3( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat const *value )
    {  glProgramUniformMatrix4x3fv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR program_uniform_matrix_4x3( GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble const *value )
    {  glProgramUniformMatrix4x3dv( program, location, count, transpose, value ); }
    SON8_OVERGLAD_DEPR shader_storage_block_binding( GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding )
    { glShaderStorageBlockBinding( program, storageBlockIndex, storageBlockBinding ); }
    SON8_OVERGLAD_DEPR get_subroutine_index( GLuint program, GLenum shadertype, GLchar const *name )
    { return glGetSubroutineIndex( program, shadertype, name ); }
    SON8_OVERGLAD_DEPR get_active_subroutine_name( GLuint program, GLenum shadertype, GLuint index,
        GLsizei bufSize, GLsizei *length, GLchar *name )
    { glGetActiveSubroutineName( program, shadertype, index, bufSize, length, name ); }
    SON8_OVERGLAD_DEPR get_subroutine_uniform_location( GLuint program, GLenum shadertype, GLchar const *name )
    { return glGetSubroutineUniformLocation( program, shadertype, name ); }
    SON8_OVERGLAD_DEPR get_active_subroutine_uniform_name( GLuint program, GLenum shadertype, GLuint index,
        GLsizei bufSize, GLsizei *length, GLchar *name )
    { glGetActiveSubroutineUniformName( program, shadertype, index, bufSize, length, name ); }
    SON8_OVERGLAD_DEPR get_active_subroutine_uniform( GLuint program, GLenum shadertype, GLuint index,
        GLenum pname, GLint *values )
    { glGetActiveSubroutineUniformiv( program, shadertype, index, pname, values ); }
    SON8_OVERGLAD_DEPR uniform_subroutine( GLenum shadertype, GLsizei count, GLuint const *indices )
    { glUniformSubroutinesuiv( shadertype, count, indices ); }
    SON8_OVERGLAD_DEPR memory_barrier( GLbitfield barriers )
    { glMemoryBarrier( barriers ); }
    SON8_OVERGLAD_DEPR get_pipeline( GLuint pipeline, GLenum pname, GLint *params )
    { glGetProgramPipelineiv( pipeline, pname, params ); }
    SON8_OVERGLAD_DEPR get_pipeline_info_log( GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog )
    { glGetProgramPipelineInfoLog( pipeline, bufSize, length, infoLog ); }
    SON8_OVERGLAD_DEPR get_shader_precision_format( GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision )
    { glGetShaderPrecisionFormat( shadertype, precisiontype, range, precision ); }
    SON8_OVERGLAD_DEPR get_uniform( GLuint program, GLint location, GLdouble *params )
    { glGetUniformdv( program, location, params ); }
    SON8_OVERGLAD_DEPR get_uniform_subroutine( GLenum shadertype, GLint location, GLuint *params )
    { glGetUniformSubroutineuiv( shadertype, location, params ); }
    SON8_OVERGLAD_DEPR get_program_stage( GLuint program, GLenum shadertype, GLenum pname, GLint *params )
    { glGetProgramStageiv( program, shadertype, pname, params ); }

    // Chapter 8: Textures and Samplers

    SON8_OVERGLAD_DEPR tex_buffer_range( GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size )
    { glTexBufferRange( target, internalformat, buffer, offset, size ); }
    SON8_OVERGLAD_DEPR texture_view( GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat,
        GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers )
    { glTextureView( texture, target, origtexture, internalformat, minlayer, numlayers, minlevel, numlevels ); }
    SON8_OVERGLAD_DEPR tex_storage( GLenum target, GLsizei levels, GLenum internalformat,
        GLsizei width )
    { glTexStorage1D( target, levels, internalformat, width ); }
    SON8_OVERGLAD_DEPR tex_storage( GLenum target, GLsizei levels, GLenum internalformat,
        GLsizei width, GLsizei height )
    { glTexStorage2D( target, levels, internalformat, width, height ); }
    SON8_OVERGLAD_DEPR tex_storage( GLenum target, GLsizei levels, GLenum internalformat,
        GLsizei width, GLsizei height, GLsizei depth )
    { glTexStorage3D( target, levels, internalformat, width, height, depth ); }
    SON8_OVERGLAD_DEPR tex_storage_multisample( GLenum target, GLsizei samples, GLenum internalformat,
        GLsizei width, GLsizei height, GLboolean fixedsamplelocations )
    { glTexStorage2DMultisample( target, samples, internalformat, width, height, fixedsamplelocations ); }
    SON8_OVERGLAD_DEPR tex_storage_multisample( GLenum target, GLsizei samples, GLenum internalformat,
        GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations )
    { glTexStorage3DMultisample( target, samples, internalformat, width, height, depth, fixedsamplelocations ); }
    SON8_OVERGLAD_DEPR invalidate_tex_sub_image( GLuint texture, GLint level,
        GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth )
    { glInvalidateTexSubImage( texture, level, xoffset, yoffset, zoffset, width, height, depth ); }
    SON8_OVERGLAD_DEPR invalidate_tex_image( GLuint texture, GLint level )
    { glInvalidateTexImage( texture, level ); }
    SON8_OVERGLAD_DEPR bind_image_texture( GLuint unit, GLuint texture, GLint level,
        GLboolean layered, GLint layer, GLenum access, GLenum format )
    { glBindImageTexture( unit, texture, level, layered, layer, access, format ); }

    // Chapter 9: Framebuffers and Framebuffer Objects

    SON8_OVERGLAD_DEPR framebuffer_parameter( GLenum target, GLenum pname, GLint param )
    { glFramebufferParameteri( target, pname, param ); }
    SON8_OVERGLAD_DEPR get_framebuffer_parameter( GLenum target, GLenum pname, GLint *params )
    { glGetFramebufferParameteriv( target, pname, params ); }

    // Chapter 10: Vertex Specification and Drawing Commands

    SON8_OVERGLAD_DEPR patch_parameter( GLenum pname, GLint value )
    { glPatchParameteri( pname, value ); }
    SON8_OVERGLAD_DEPR vertex_attrib_L( GLuint index, GLdouble x )
    { glVertexAttribL1d( index, x ); }
    SON8_OVERGLAD_DEPR vertex_attrib_L( GLuint index, GLdouble x, GLdouble y )
    { glVertexAttribL2d( index, x, y ); }
    SON8_OVERGLAD_DEPR vertex_attrib_L( GLuint index, GLdouble x, GLdouble y, GLdouble z )
    { glVertexAttribL3d( index, x, y, z ); }
    SON8_OVERGLAD_DEPR vertex_attrib_L( GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w )
    { glVertexAttribL4d( index, x, y, z, w ); }
    SON8_OVERGLAD_DEPR vertex_attrib_L_1( GLuint index, GLdouble const *v )
    { glVertexAttribL1dv( index, v ); }
    SON8_OVERGLAD_DEPR vertex_attrib_L_2( GLuint index, GLdouble const *v )
    { glVertexAttribL2dv( index, v ); }
    SON8_OVERGLAD_DEPR vertex_attrib_L_3( GLuint index, GLdouble const *v )
    { glVertexAttribL3dv( index, v ); }
    SON8_OVERGLAD_DEPR vertex_attrib_L_4( GLuint index, GLdouble const *v )
    { glVertexAttribL4dv( index, v ); }
    SON8_OVERGLAD_DEPR vertex_attrib_format( GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset )
    { glVertexAttribFormat( attribindex, size, type, normalized, relativeoffset ); }
    SON8_OVERGLAD_DEPR vertex_attrib_I_format( GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset )
    { glVertexAttribIFormat( attribindex, size, type, relativeoffset ); }
    SON8_OVERGLAD_DEPR vertex_attrib_L_format( GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset )
    { glVertexAttribLFormat( attribindex, size, type, relativeoffset ); }
    SON8_OVERGLAD_DEPR bind_vertex_buffer( GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride )
    { glBindVertexBuffer( bindingindex, buffer, offset, stride ); }
    SON8_OVERGLAD_DEPR vertex_attrib_binding( GLuint attribindex, GLuint bindingindex )
    { glVertexAttribBinding( attribindex, bindingindex ); }
    SON8_OVERGLAD_DEPR vertex_attrib_L_pointer( GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid const *pointer )
    { glVertexAttribLPointer( index, size, type, stride, pointer ); }
    SON8_OVERGLAD_DEPR vertex_binding_divisor( GLuint bindingindex, GLuint divisor )
    { glVertexBindingDivisor( bindingindex, divisor ); }
    SON8_OVERGLAD_DEPR draw_arrays_instanced_base_instance( GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance )
    { glDrawArraysInstancedBaseInstance( mode, first, count, instancecount, baseinstance ); }
    SON8_OVERGLAD_DEPR draw_arrays_indirect( GLenum mode, GLvoid const *indirect )
    { glDrawArraysIndirect( mode, indirect ); }
    SON8_OVERGLAD_DEPR multi_draw_arrays_indirect( GLenum mode, GLvoid const *indirect, GLsizei drawcount, GLsizei stride )
    { glMultiDrawArraysIndirect( mode, indirect, drawcount, stride ); }
    SON8_OVERGLAD_DEPR draw_elements_instanced_base_instance( GLenum mode, GLsizei count, GLenum type,
        GLvoid const *indices, GLsizei instancecount, GLuint baseinstance )
    { glDrawElementsInstancedBaseInstance( mode, count, type, indices, instancecount, baseinstance ); }
    SON8_OVERGLAD_DEPR draw_elements_instanced_base_vertex_base_instance( GLenum mode, GLsizei count, GLenum type,
        GLvoid const *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance )
    { glDrawElementsInstancedBaseVertexBaseInstance( mode, count, type, indices, instancecount, basevertex, baseinstance ); }
    SON8_OVERGLAD_DEPR draw_elements_indirect( GLenum mode, GLenum type, GLvoid const *indirect )
    { glDrawElementsIndirect( mode, type, indirect ); }
    SON8_OVERGLAD_DEPR multi_draw_elements_indirect( GLenum mode, GLenum type, GLvoid const *indirect,
        GLsizei drawcount, GLsizei stride )
    { glMultiDrawElementsIndirect( mode, type, indirect, drawcount, stride ); }
    SON8_OVERGLAD_DEPR get_vertex_attrib_L( GLuint index, GLenum pname, GLdouble *params )
    { glGetVertexAttribLdv( index, pname, params ); }

    // Chapter 11: Programmable Vertex Processing

    SON8_OVERGLAD_DEPR validate_pipeline( GLuint pipeline )
    { glValidateProgramPipeline( pipeline ); }
    SON8_OVERGLAD_DEPR patch_parameter( GLenum pname, GLfloat const *values )
    { glPatchParameterfv( pname, values ); }

    // Chapter 13: Fixed-Function Vertex Post-Processing

    SON8_OVERGLAD_DEPR gen_transform_feedbacks( GLsizei n, GLuint *ids )
    { glGenTransformFeedbacks( n, ids ); }
    SON8_OVERGLAD_DEPR delete_transform_feedbacks( GLsizei n, GLuint const *ids )
    { glDeleteTransformFeedbacks( n, ids ); }
    SON8_OVERGLAD_DEPR bind_transform_feedback( GLenum target, GLuint id )
    { glBindTransformFeedback( target, id ); }
    SON8_OVERGLAD_DEPR pause_transform_feedback( )
    { glPauseTransformFeedback( ); }
    SON8_OVERGLAD_DEPR resume_transform_feedback( )
    { glResumeTransformFeedback( ); }
    SON8_OVERGLAD_DEPR draw_transform_feedback( GLenum mode, GLuint id )
    { glDrawTransformFeedback( mode, id ); }
    SON8_OVERGLAD_DEPR draw_transform_feedback_instanced( GLenum mode, GLuint id, GLsizei instancecount )
    { glDrawTransformFeedbackInstanced( mode, id, instancecount ); }
    SON8_OVERGLAD_DEPR draw_transform_feedback_stream( GLenum mode, GLuint id, GLuint stream )
    { glDrawTransformFeedbackStream( mode, id, stream ); }
    SON8_OVERGLAD_DEPR draw_transform_feedback_stream_instanced( GLenum mode, GLuint id, GLuint stream, GLsizei instancecount )
    { glDrawTransformFeedbackStreamInstanced( mode, id, stream, instancecount ); }
    SON8_OVERGLAD_DEPR depth_range_array( GLuint first, GLsizei count, GLdouble const *v )
    { glDepthRangeArrayv( first, count, v ); }
    SON8_OVERGLAD_DEPR depth_range_indexed( GLuint index, GLdouble n, GLdouble f )
    { glDepthRangeIndexed( index, n, f ); }
    SON8_OVERGLAD_DEPR depth_range( GLfloat n, GLfloat f )
    { glDepthRangef( n, f ); }
    SON8_OVERGLAD_DEPR viewport_array( GLuint first, GLsizei count, GLfloat const *v )
    { glViewportArrayv( first, count, v ); }
    SON8_OVERGLAD_DEPR viewport_indexed( GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h )
    { glViewportIndexedf( index, x, y, w, h ); }
    SON8_OVERGLAD_DEPR viewport_indexed( GLuint index, GLfloat const *v )
    { glViewportIndexedfv( index, v ); }

    // Chapter 14: Fixed-Function Primitive Assembly and Rasterization

    SON8_OVERGLAD_DEPR min_sample_shading( GLfloat value )
    { glMinSampleShading( value ); }

    // Chapter 17: Writing Fragments and Samples to the Framebuffer

    SON8_OVERGLAD_DEPR scissor_array( GLuint first, GLsizei count, GLint const *v )
    { glScissorArrayv( first, count, v ); }
    SON8_OVERGLAD_DEPR scissor_indexed( GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height )
    { glScissorIndexed( index, left, bottom, width, height ); }
    SON8_OVERGLAD_DEPR scissor_indexed( GLuint index, GLint const *v )
    { glScissorIndexedv( index, v ); }
    SON8_OVERGLAD_DEPR blend_equation( GLuint buf, GLenum mode )
    { glBlendEquationi( buf, mode ); }
    SON8_OVERGLAD_DEPR blend_equation_separate( GLuint buf, GLenum modeRGB, GLenum modeAlpha )
    { glBlendEquationSeparatei( buf, modeRGB, modeAlpha ); }
    SON8_OVERGLAD_DEPR blend_func( GLuint buf, GLenum src, GLenum dst )
    { glBlendFunci( buf, src, dst ); }
    SON8_OVERGLAD_DEPR blend_func_separate( GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha )
    { glBlendFuncSeparatei( buf, srcRGB, dstRGB, srcAlpha, dstAlpha ); }
    SON8_OVERGLAD_DEPR invalidate_sub_framebuffer( GLenum target, GLsizei numAttachments, GLenum const *attachments,
        GLint x, GLint y, GLsizei width, GLsizei height )
    { glInvalidateSubFramebuffer( target, numAttachments, attachments, x, y, width, height ); }
    SON8_OVERGLAD_DEPR invalidate_framebuffer( GLenum target, GLsizei numAttachments, GLenum const *attachments )
    { glInvalidateFramebuffer( target, numAttachments, attachments ); }

    // Chapter 18: Reading and Copying Pixels

    SON8_OVERGLAD_DEPR copy_image_sub_data( GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ,
        GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ,
        GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth )
    { glCopyImageSubData( srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth ); }

    // Chapter 19: Compute Shaders

    SON8_OVERGLAD_DEPR dispatch_compute( GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z )
    { glDispatchCompute( num_groups_x, num_groups_y, num_groups_z ); }
    SON8_OVERGLAD_DEPR dispatch_compute_indirect( GLintptr indirect )
    { glDispatchComputeIndirect( indirect ); }

    // Chapter 20: Debug Output

    SON8_OVERGLAD_DEPR debug_message_callback( GLDEBUGPROC callback, GLvoid *userParam )
    { glDebugMessageCallback( callback, userParam ); }
    SON8_OVERGLAD_DEPR debug_message_control( GLenum source, GLenum type, GLenum severity, GLsizei count,
        GLuint const *ids, GLboolean enabled )
    { glDebugMessageControl( source, type, severity, count, ids, enabled ); }
    SON8_OVERGLAD_DEPR debug_message_insert( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar const *buf )
    { glDebugMessageInsert( source, type, id, severity, length, buf ); }
    SON8_OVERGLAD_DEPR push_debug_group( GLenum source, GLuint id, GLsizei length, GLchar const *message )
    { glPushDebugGroup( source, id, length, message ); }
    SON8_OVERGLAD_DEPR pop_debug_group( )
    { glPopDebugGroup( ); }
    SON8_OVERGLAD_DEPR object_label( GLenum identifier, GLuint name, GLsizei length, GLchar const *label )
    { glObjectLabel( identifier, name, length, label ); }
    SON8_OVERGLAD_DEPR object_ptr_label( GLvoid *ptr, GLsizei length, GLchar const *label )
    { glObjectPtrLabel( ptr, length, label ); }
    SON8_OVERGLAD_DEPR get_debug_message_log( GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types,
        GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog )
    { glGetDebugMessageLog( count, bufSize, sources, types, ids, severities, lengths, messageLog ); }
    SON8_OVERGLAD_DEPR get_object_label( GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label )
    { glGetObjectLabel( identifier, name, bufSize, length, label ); }
    SON8_OVERGLAD_DEPR get_object_ptr_label( GLvoid *ptr, GLsizei bufSize, GLsizei *length, GLchar *label )
    { glGetObjectPtrLabel( ptr, bufSize, length, label ); }

    // Chapter 22: Context State Queries

    SON8_OVERGLAD_DEPR get_float( GLenum target, GLuint index, GLfloat *data )
    { glGetFloati_v( target, index, data ); }
    SON8_OVERGLAD_DEPR get_double( GLenum target, GLuint index, GLdouble *data )
    { glGetDoublei_v( target, index, data ); }
    SON8_OVERGLAD_DEPR get_internal_format( GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params )
    { glGetInternalformativ( target, internalformat, pname, bufSize, params ); }
    SON8_OVERGLAD_DEPR get_internal_format( GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params )
    { glGetInternalformati64v( target, internalformat, pname, bufSize, params ); }
#endif// deprecated functions
} // namespace son8::overglad

#endif // INCLUDE GUARD

// Apache License 2.0
// NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
// SPDX-License-Identifier: Apache-2.0
// lib: `overglad` C++17 Wrapper Over GLAD Loader
// Ⓒ Copyright (c) 2025-2026 Oleg'Ease'Kharchuk ᦒ
