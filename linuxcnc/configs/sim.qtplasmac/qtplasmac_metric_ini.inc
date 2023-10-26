
# this section required as is for removing z axis moves from the loaded gcode file
[FILTER]
PROGRAM_EXTENSION       = .ngc,.nc,.tap GCode File (*.ngc, *.nc, *.tap)
ngc                     = qtplasmac_gcode
nc                      = qtplasmac_gcode
tap                     = qtplasmac_gcode


[PYTHON]
# code specific for this configuration	
PATH_PREPEND = ./python
# generic support code
PATH_APPEND=../../nc_files/remap_lib/python-stdglue

# import the following Python module
TOPLEVEL=./python/toplevel.py

# the higher the more verbose tracing of the Python plugin
LOG_LEVEL = 10


[RS274NGC]
RS274NGC_STARTUP_CODE   = G21 G40 G49 G80 G90 G92.1 G94 G97 M52P1
PARAMETER_FILE          = metric_parameters.txt

SUBROUTINE_PATH         = ./:../../nc_files

# required for our material change
USER_M_PATH             = ./:../../nc_files


# A cycle in Python: M259 DEIJKPQR
# D = Pierce Type  (0=Normal, 1-Wiggle, 2=Ramp)
# E = Pierce Motion Delay  (Delay in Z motion to Pierce End Height expressed as a % of Pierce Delay)
# I = Cut Height Delay (At the end of transition to Pierce End Height wait x secs before transition to Cut Height)
# J = Pierce Ende Height (Target pierce height at end of Pierce Delay. Normally lower than Pierce Height)
# K = Gouge Speed (Speed in machine units/min)
# P = Gouge Distance (Distance of gouge to travel in machine units)
# Q = Creep Speed (Speed in machine units. Creep takes effect after gouge has finished)
# R = Creep Distance (Distance of creep to travel in machine units)
# M259 D2 E20 I3 J5 K325 P10 Q80 R10
REMAP=M259 argspec=DEIJKPQR python=m259 modalgroup=10


[HAL]
TWOPASS                 = ON
# the base machine
HALFILE                 = sim_no_stepgen.tcl
#HALFILE                 = sim_stepgen.tcl
# component connections
HALFILE                 = qtplasmac_comp.hal
# custom hal commands
HALFILE                 = custom.hal
# custom postgui hal
POSTGUI_HALFILE         = custom_postgui.hal
# sim postgui hal
POSTGUI_HALFILE         = sim_postgui.hal
# required
HALUI                   = halui

[EMC]
VERSION                 = 1.1
MACHINE                 = qtplasmac-metric
DEBUG                   = 0

[EMCIO]
EMCIO                   = io
CYCLE_TIME              = 0.100
TOOL_TABLE              = metric_tool.tbl

[TASK]
TASK                    = milltask
CYCLE_TIME              = 0.01

[EMCMOT]
EMCMOT                  = motmod
BASE_PERIOD             = 100000
SERVO_PERIOD            = 1000000

[KINS]
KINEMATICS              = trivkins coordinates=xyyz
JOINTS                  = 4
 
[TRAJ]
SPINDLES                = 3
COORDINATES             = XYYZ
LINEAR_UNITS            = mm
MAX_LINEAR_VELOCITY     = 350
DEFAULT_LINEAR_VELOCITY = 100
ANGULAR_UNITS           = degree
POSITION_FILE           = metric_position.txt

[AXIS_X]
MIN_LIMIT               = -0.001
MAX_LIMIT               = 612.001
# set to double the value in the corresponding joint
MAX_VELOCITY            = 500.0
# set to double the value in the corresponding joint
MAX_ACCELERATION        = 5000.0
# shares the above two equally between the joint and the offset
OFFSET_AV_RATIO         = 0.5

[JOINT_0]
MIN_LIMIT               = -0.001
MAX_LIMIT               = 612.001
MAX_VELOCITY            = 250
MAX_ACCELERATION        = 2500
TYPE                    = LINEAR
MIN_FERROR              = 5.0
FERROR                  = 10.0
HOME                    = 0.0
HOME_OFFSET             = 0.0
HOME_SEQUENCE           = 1
HOME_USE_INDEX          = NO
STEPGEN_MAXACCEL        = 5000
STEP_SCALE              = 1
STEPLEN                 = 1
STEPSPACE               = 0
DIRSETUP                = 8000
DIRHOLD                 = 5000

[AXIS_Y]
MIN_LIMIT               = -0.001
MAX_LIMIT               = 612.001
# set to double the value in the corresponding joint
MAX_VELOCITY            = 500.0
# set to double the value in the corresponding joint
MAX_ACCELERATION        = 5000.0
# shares the above two equally between the joint and the offset
OFFSET_AV_RATIO         = 0.5

[JOINT_1]
MIN_LIMIT               = -0.001
MAX_LIMIT               = 612.001
MAX_VELOCITY            = 250
MAX_ACCELERATION        = 2500
TYPE                    = LINEAR
MIN_FERROR              = 5.0
FERROR                  = 10.0
HOME                    = 0.0
HOME_OFFSET             = 0.0
HOME_SEQUENCE           = -2
HOME_USE_INDEX          = NO
STEPGEN_MAXACCEL        = 5000
STEP_SCALE              = 1
STEPLEN                 = 1
STEPSPACE               = 0
DIRSETUP                = 8000
DIRHOLD                 = 5000

[JOINT_2]
MIN_LIMIT               = -0.001
MAX_LIMIT               = 612.001
MAX_VELOCITY            = 250
MAX_ACCELERATION        = 2500
TYPE                    = LINEAR
MIN_FERROR              = 5.0
FERROR                  = 10.0
HOME                    = 0.0
HOME_OFFSET             = 0.0
HOME_SEQUENCE           = -2
HOME_USE_INDEX          = NO
STEPGEN_MAXACCEL        = 5000
STEP_SCALE              = 1
STEPLEN                 = 1
STEPSPACE               = 0
DIRSETUP                = 8000
DIRHOLD                 = 5000

[AXIS_Z]
#MIN_LIMIT               = -0.001
#MAX_LIMIT               = 70.001
MIN_LIMIT               = -150
MAX_LIMIT               = 15
# set to double the value in the corresponding joint
MAX_VELOCITY            = 120.0
# set to double the value in the corresponding joint
MAX_ACCELERATION        = 1200.0
# shares the above two equally between the joint and the offset
OFFSET_AV_RATIO         = 0.5

[JOINT_3]
# this should be the top of your slats
#MIN_LIMIT               = -0.001
#MAX_LIMIT               = 70.001
MIN_LIMIT               = -150
MAX_LIMIT               = 15
MAX_VELOCITY            = 60
MAX_ACCELERATION        = 600
TYPE                    = LINEAR
MIN_FERROR              = 5.0
FERROR                  = 10.0
#HOME                    = 65.0
#HOME_OFFSET             = 70.0
HOME                    = 0
HOME_OFFSET             = 0
HOME_SEQUENCE           = 0
HOME_USE_INDEX          = NO
STEPGEN_MAXACCEL        = 1200.0
STEP_SCALE              = 1
STEPLEN                 = 1
STEPSPACE               = 0
DIRSETUP                = 8000
DIRHOLD                 = 5000
