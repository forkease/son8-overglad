#define SON8_OVERGLAD_INCLUDE_DEPRECATED
#include <son8/overglad/comp.hxx>
// dummy source to trigger cmake generation of compile commands json workaround
namespace son8::overglad::dummy_ {

    types::InfoTiny info;
    auto test = info.append( "fg" );
    types::BuffersArray bufferArray{ -8 };
    auto check = bufferArray.size( );
    auto ghgh = bufferArray[1];
}
