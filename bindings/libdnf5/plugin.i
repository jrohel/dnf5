#if defined(SWIGPYTHON)
%module(package="libdnf5", directors="1") plugin
#elif defined(SWIGPERL)
%module "libdnf5::plugin"
#elif defined(SWIGRUBY)
%module "libdnf5/plugin"
#endif

%include <exception.i>
%include <stdint.i>
%include <std_common.i>

%include <shared.i>

%import "conf.i"

%{
    #include "libdnf/plugin/iplugin.hpp"
%}

#define CV __perl_CV

%ignore PluginError;
%ignore libdnf_plugin_get_api_version;
%ignore libdnf_plugin_get_name;
%ignore libdnf_plugin_get_version;
%ignore libdnf_plugin_new_instance;
%ignore libdnf_plugin_delete_instance;
%feature("director") IPlugin;
%include "libdnf/plugin/iplugin.hpp"

%extend libdnf::plugin::Version {
    Version(std::uint16_t major, std::uint16_t minor, std::uint16_t micro) {
        libdnf::plugin::Version * ver = new libdnf::plugin::Version({major, minor, micro});
        return ver;
    }
}
