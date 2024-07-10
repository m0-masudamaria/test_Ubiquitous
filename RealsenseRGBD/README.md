# RealSense_RGBD_Camera

## Overview

Access to RealSense RGB-D Camera with librealsense2

## Description



### Input and Output



### Algorithm etc



### Basic Information

|  |  |
----|---- 
| Module Name | RealSense_RGBD_Camera |
| Description | Access to RealSense RGB-D Camera with librealsense2 |
| Version | 1.0.0 |
| Vendor | ha-ves |
| Category | Sensor |
| Comp. Type | COMMUTATIVE |
| Act. Type | PERIODIC |
| Kind | DataFlowComponent |
| MAX Inst. | 0 |

### Activity definition

<table>
  <tr>
    <td rowspan="4">on_initialize</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td>Check for librealsense2 availability.</td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td>librealsense2 binaries are available.</td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td>librealsense2 library is available for use.</td>
    </tr>
  </tr>
  <tr>
    <td>on_finalize</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td rowspan="4">on_startup</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td>Start camera configuration and system IO-related resources.</td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td>RealSense camera is available on the system (connected).</td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td>RealSense camera configuration applied and is available for operation.</td>
    </tr>
  </tr>
  <tr>
    <td rowspan="4">on_shutdown</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td>Release system IO-related resources.</td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td>RealSense Camera has stopped operation.</td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td>RealSense Camera connection closed successfully.</td>
    </tr>
  </tr>
  <tr>
    <td rowspan="4">on_activated</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td>Activate data acquiring.</td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td>RealSense Camera configured.</td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td>RealSense pipeline started and available for dataflow.</td>
    </tr>
  </tr>
  <tr>
    <td rowspan="4">on_deactivated</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td>Release periodic resources.</td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td>Dataflow has stopped.</td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td>RealSense Camera pipeline stopped and released it's resources.</td>
    </tr>
  </tr>
  <tr>
    <td rowspan="4">on_execute</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td>Acquire RGB and-or Depth frames.</td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td>RealSense Camera pipeline is available to fetch frames.</td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td>RGB and-or Depth frames dataflow.</td>
    </tr>
  </tr>
  <tr>
    <td>on_aborting</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>on_error</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>on_reset</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>on_state_update</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>on_rate_changed</td>
    <td colspan="2"></td>
  </tr>
</table>

### InPorts definition


### OutPorts definition

#### ColorFrame



<table>
  <tr>
    <td>DataType</td>
    <td>RTC::CameraImage</td>
    <td></td>
  </tr>
  <tr>
    <td>IDL file</td>
    <td colspan="2">InterfaceDataTypes.idl</td>
  </tr>
  <tr>
    <td>Number of Data</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Semantics</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Unit</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Occirrence frecency Period</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Operational frecency Period</td>
    <td colspan="2"></td>
  </tr>
</table>

#### PointCloud



<table>
  <tr>
    <td>DataType</td>
    <td>RTC::PointCloud</td>
    <td></td>
  </tr>
  <tr>
    <td>IDL file</td>
    <td colspan="2">InterfaceDataTypes.idl</td>
  </tr>
  <tr>
    <td>Number of Data</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Semantics</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Unit</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Occirrence frecency Period</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Operational frecency Period</td>
    <td colspan="2"></td>
  </tr>
</table>


### Service Port definition


### Configuration definition

#### ColorResolution




<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">rs_Resolution</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>w640h480</td>
    <td></td>
  </tr>
  <tr>
    <td>Unit</td>
    <td>pixels</td>
    <td></td>
  </tr>
  <tr>
    <td>Widget</td>
    <td colspan="2">radio</td>
  </tr>
  <tr>
    <td>Step</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Constraint</td>
    <td>(w1920h1080, w1280h720, w640h480)</td>
    <td></td>
  </tr>
  <tr>
    <td>Range</td>
    <td colspan="2"></td>
  </tr>
</table>

#### DepthResolution




<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">rs_Resolution</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>w640h480</td>
    <td></td>
  </tr>
  <tr>
    <td>Unit</td>
    <td>pixels</td>
    <td></td>
  </tr>
  <tr>
    <td>Widget</td>
    <td colspan="2">radio</td>
  </tr>
  <tr>
    <td>Step</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Constraint</td>
    <td>(w1920h1080, w1280h720, w640h480)</td>
    <td></td>
  </tr>
  <tr>
    <td>Range</td>
    <td colspan="2"></td>
  </tr>
</table>

#### Alignment




<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">rs_AlignTo</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>Color</td>
    <td></td>
  </tr>
  <tr>
    <td>Unit</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>Widget</td>
    <td colspan="2">radio</td>
  </tr>
  <tr>
    <td>Step</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Constraint</td>
    <td>(Color, Depth)</td>
    <td></td>
  </tr>
  <tr>
    <td>Range</td>
    <td colspan="2"></td>
  </tr>
</table>

#### RealSenseViewerCfgFile




<table>
  <tr>
    <td>DataType</td>
    <td colspan="2">string</td>
  </tr>
  <tr>
    <td>DefaultValue</td>
    <td>none</td>
    <td></td>
  </tr>
  <tr>
    <td>Unit</td>
    <td>.txt/.json</td>
    <td></td>
  </tr>
  <tr>
    <td>Widget</td>
    <td colspan="2">text</td>
  </tr>
  <tr>
    <td>Step</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Constraint</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>Range</td>
    <td colspan="2"></td>
  </tr>
</table>


## Demo

## Requirement

## Setup

### Windows

### Ubuntu

## Usage

## Running the tests

## LICENCE




## References




## Author


