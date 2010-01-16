/*
 * MATLAB Compiler: 4.3 (R14SP3)
 * Date: Sat Jan 16 10:30:06 2010
 * Arguments: "-B" "macro_default" "-m" "-W" "main" "-T" "link:exe" "PCA.m" 
 */

#include "mclmcr.h"

#ifdef __cplusplus
extern "C" {
#endif
const unsigned char __MCC_PCA_session_key[] = {
        '4', 'F', 'E', '2', '4', '9', '3', '4', '2', 'D', '5', '3', '5', 'C',
        '7', '0', 'C', '4', 'A', 'A', '0', '2', '4', 'E', 'D', '1', '0', '4',
        '5', 'B', '9', 'D', '0', 'F', '6', 'E', 'E', 'F', '8', '5', '0', '4',
        'B', '3', '8', 'B', '2', 'A', '6', 'D', '9', '6', 'C', 'C', '7', 'C',
        '4', '0', '3', 'F', '7', '6', 'A', '2', 'B', '6', 'A', 'A', '7', '0',
        '8', '0', '2', 'C', '2', 'F', '3', '2', 'F', '5', '5', 'E', '9', 'C',
        'E', '9', '6', '0', '7', '4', 'C', 'E', 'A', 'D', 'C', 'B', 'E', '0',
        'D', '3', 'F', '5', 'E', 'D', '7', 'C', '3', '0', 'A', '5', 'C', 'E',
        'E', 'F', 'F', '7', '5', 'B', '0', 'D', 'A', 'E', '8', '1', '4', 'A',
        'A', 'D', '7', '5', '5', '3', '5', '5', 'E', '7', '8', '0', '7', 'B',
        'B', '6', '9', '0', '3', '2', '2', '5', 'E', '6', 'F', '8', '5', 'C',
        'C', 'A', '8', '0', '1', '3', 'C', '7', '5', '6', '3', '6', 'F', '5',
        '8', '1', 'C', '4', '1', 'C', 'D', '6', '6', 'B', '2', 'A', '1', '9',
        '7', '2', 'C', '0', 'F', 'E', 'D', '6', '5', 'B', '8', 'C', '4', 'E',
        '7', 'C', '4', '4', '0', 'E', '7', '0', '1', 'E', '6', '8', '1', '1',
        'A', '1', 'F', '3', '9', '6', 'A', '7', 'A', '5', '7', '8', '4', '2',
        '2', '6', '2', 'C', '6', '3', '1', '2', '2', '5', 'E', '4', '8', '1',
        'B', '9', 'B', '4', 'E', '5', '6', '4', '1', '0', 'B', 'E', '4', '0',
        '6', '0', '5', '1', '\0'};

const unsigned char __MCC_PCA_public_key[] = {
        '3', '0', '8', '1', '9', 'D', '3', '0', '0', 'D', '0', '6', '0', '9',
        '2', 'A', '8', '6', '4', '8', '8', '6', 'F', '7', '0', 'D', '0', '1',
        '0', '1', '0', '1', '0', '5', '0', '0', '0', '3', '8', '1', '8', 'B',
        '0', '0', '3', '0', '8', '1', '8', '7', '0', '2', '8', '1', '8', '1',
        '0', '0', 'C', '4', '9', 'C', 'A', 'C', '3', '4', 'E', 'D', '1', '3',
        'A', '5', '2', '0', '6', '5', '8', 'F', '6', 'F', '8', 'E', '0', '1',
        '3', '8', 'C', '4', '3', '1', '5', 'B', '4', '3', '1', '5', '2', '7',
        '7', 'E', 'D', '3', 'F', '7', 'D', 'A', 'E', '5', '3', '0', '9', '9',
        'D', 'B', '0', '8', 'E', 'E', '5', '8', '9', 'F', '8', '0', '4', 'D',
        '4', 'B', '9', '8', '1', '3', '2', '6', 'A', '5', '2', 'C', 'C', 'E',
        '4', '3', '8', '2', 'E', '9', 'F', '2', 'B', '4', 'D', '0', '8', '5',
        'E', 'B', '9', '5', '0', 'C', '7', 'A', 'B', '1', '2', 'E', 'D', 'E',
        '2', 'D', '4', '1', '2', '9', '7', '8', '2', '0', 'E', '6', '3', '7',
        '7', 'A', '5', 'F', 'E', 'B', '5', '6', '8', '9', 'D', '4', 'E', '6',
        '0', '3', '2', 'F', '6', '0', 'C', '4', '3', '0', '7', '4', 'A', '0',
        '4', 'C', '2', '6', 'A', 'B', '7', '2', 'F', '5', '4', 'B', '5', '1',
        'B', 'B', '4', '6', '0', '5', '7', '8', '7', '8', '5', 'B', '1', '9',
        '9', '0', '1', '4', '3', '1', '4', 'A', '6', '5', 'F', '0', '9', '0',
        'B', '6', '1', 'F', 'C', '2', '0', '1', '6', '9', '4', '5', '3', 'B',
        '5', '8', 'F', 'C', '8', 'B', 'A', '4', '3', 'E', '6', '7', '7', '6',
        'E', 'B', '7', 'E', 'C', 'D', '3', '1', '7', '8', 'B', '5', '6', 'A',
        'B', '0', 'F', 'A', '0', '6', 'D', 'D', '6', '4', '9', '6', '7', 'C',
        'B', '1', '4', '9', 'E', '5', '0', '2', '0', '1', '1', '1', '\0'};

static const char * MCC_PCA_matlabpath_data[] = 
    { "PCA/", "toolbox/compiler/deploy/", "$TOOLBOXMATLABDIR/general/",
      "$TOOLBOXMATLABDIR/ops/", "$TOOLBOXMATLABDIR/lang/",
      "$TOOLBOXMATLABDIR/elmat/", "$TOOLBOXMATLABDIR/elfun/",
      "$TOOLBOXMATLABDIR/specfun/", "$TOOLBOXMATLABDIR/matfun/",
      "$TOOLBOXMATLABDIR/datafun/", "$TOOLBOXMATLABDIR/polyfun/",
      "$TOOLBOXMATLABDIR/funfun/", "$TOOLBOXMATLABDIR/sparfun/",
      "$TOOLBOXMATLABDIR/scribe/", "$TOOLBOXMATLABDIR/graph2d/",
      "$TOOLBOXMATLABDIR/graph3d/", "$TOOLBOXMATLABDIR/specgraph/",
      "$TOOLBOXMATLABDIR/graphics/", "$TOOLBOXMATLABDIR/uitools/",
      "$TOOLBOXMATLABDIR/strfun/", "$TOOLBOXMATLABDIR/imagesci/",
      "$TOOLBOXMATLABDIR/iofun/", "$TOOLBOXMATLABDIR/audiovideo/",
      "$TOOLBOXMATLABDIR/timefun/", "$TOOLBOXMATLABDIR/datatypes/",
      "$TOOLBOXMATLABDIR/verctrl/", "$TOOLBOXMATLABDIR/codetools/",
      "$TOOLBOXMATLABDIR/helptools/", "$TOOLBOXMATLABDIR/winfun/",
      "$TOOLBOXMATLABDIR/demos/", "$TOOLBOXMATLABDIR/timeseries/",
      "$TOOLBOXMATLABDIR/hds/", "toolbox/local/", "toolbox/compiler/" };

static const char * MCC_PCA_classpath_data[] = 
    { "" };

static const char * MCC_PCA_libpath_data[] = 
    { "" };

static const char * MCC_PCA_app_opts_data[] = 
    { "" };

static const char * MCC_PCA_run_opts_data[] = 
    { "" };

static const char * MCC_PCA_warning_state_data[] = 
    { "" };


mclComponentData __MCC_PCA_component_data = { 

    /* Public key data */
    __MCC_PCA_public_key,

    /* Component name */
    "PCA",

    /* Component Root */
    "",

    /* Application key data */
    __MCC_PCA_session_key,

    /* Component's MATLAB Path */
    MCC_PCA_matlabpath_data,

    /* Number of directories in the MATLAB Path */
    34,

    /* Component's Java class path */
    MCC_PCA_classpath_data,
    /* Number of directories in the Java class path */
    0,

    /* Component's load library path (for extra shared libraries) */
    MCC_PCA_libpath_data,
    /* Number of directories in the load library path */
    0,

    /* MCR instance-specific runtime options */
    MCC_PCA_app_opts_data,
    /* Number of MCR instance-specific runtime options */
    0,

    /* MCR global runtime options */
    MCC_PCA_run_opts_data,
    /* Number of MCR global runtime options */
    0,
    
    /* Component preferences directory */
    "PCA_216CA6F875DF44CC1F1C9B4F19859FC7",

    /* MCR warning status data */
    MCC_PCA_warning_state_data,
    /* Number of MCR warning status modifiers */
    0,

    /* Path to component - evaluated at runtime */
    NULL

};

#ifdef __cplusplus
}
#endif


