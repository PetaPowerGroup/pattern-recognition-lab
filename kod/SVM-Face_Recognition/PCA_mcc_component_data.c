/*
 * MATLAB Compiler: 4.3 (R14SP3)
 * Date: Thu Jan 14 18:06:43 2010
 * Arguments: "-B" "macro_default" "-m" "-W" "main" "-T" "link:exe" "PCA.m" 
 */

#include "mclmcr.h"

#ifdef __cplusplus
extern "C" {
#endif
const unsigned char __MCC_PCA_session_key[] = {
        '9', 'A', 'D', 'D', 'F', 'E', 'E', '7', 'E', '3', 'B', '7', '9', '7',
        '7', '7', '1', '0', '5', 'C', '9', '7', '0', 'E', 'A', '9', '9', '6',
        '2', 'E', '9', '9', '9', '8', '0', '2', '4', '0', '3', 'C', '1', '4',
        '2', 'C', 'D', '3', '5', '1', '7', '7', 'C', '6', '7', '8', '4', '2',
        '9', 'C', 'B', 'E', '2', '7', 'A', '8', '9', 'E', 'B', 'A', 'B', '3',
        'B', '8', '3', 'F', 'C', '0', '2', '6', '2', '5', '7', '7', 'C', '0',
        'E', '0', '6', '3', '1', '5', 'E', '2', 'C', 'A', '9', 'A', 'F', '6',
        'B', '5', 'A', '5', '5', '4', '1', '7', 'B', '7', '0', '0', 'D', '4',
        'C', 'B', 'B', '4', 'F', '8', '9', '1', '1', '1', '4', 'F', 'B', 'A',
        'C', '4', 'C', '1', '8', '0', '6', '4', '8', '1', '5', '7', '4', 'F',
        'F', 'F', 'C', '0', '5', '3', '4', '5', '1', '3', '0', '7', '5', 'A',
        '9', '9', 'B', '5', '7', '8', '9', 'C', '9', 'A', '8', '6', '7', '3',
        '1', '4', '5', '1', 'E', '0', 'C', 'B', '9', '0', '3', 'A', '9', 'F',
        '6', 'B', '8', 'E', '2', '0', 'F', '2', '0', '9', '5', '4', '6', '5',
        '2', 'E', '6', 'B', '8', 'F', '4', 'E', '7', '7', 'A', '9', '0', 'E',
        '6', '2', '5', 'A', '0', '5', '6', 'C', '6', 'E', '3', '5', '7', '0',
        'D', '1', '2', '3', 'F', '3', '5', 'F', '7', '6', '1', 'B', 'A', '5',
        '1', '3', '9', '7', '0', '8', '8', '4', 'A', '9', '8', '1', 'E', '0',
        '6', '2', 'F', '1', '\0'};

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
    "PCA_CBF9D88A864323F8DD3833F96F2E142A",

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


