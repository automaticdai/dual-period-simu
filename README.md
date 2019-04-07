# Dual Period Task Scheduling

-------

Matlab Simulation of the paper 'A Dual-Mode Strategy for Performance-Maximization and Resource-Efficient CPS Design'.

## Requirements
1. Install MATLAB (c) R2017a or later
2. Install TDM-GCC MinGW-w64 compiler 4.9.2 (https://sourceforge.net/projects/tdm-gcc/files/TDM-GCC%20Installer/Previous/1.1309.0/). DO NOT include any space in the installation folder!


## Instructions
In MATLAB, config the mex compiler

```
setenv('MW_MINGW64_LOC',<MinGW installation folder>)
mex -setup C++
```


## Edit & Run The Program
In MATLAB, Home -> Open -> 'path-to-repository'/main.c, then click 'Run' on the top.


## Project Structure
- /afbs-kernel: the scheduler for Simulink
- /analysis: scripts for generating figures in reports
- /experiments: early experiments
- /result: save experiment result data
- main.m: program starting point
- main_cost_space.m: evaluate the cost space
- run_single_simulation: single run of one instance
- rta.py: response time analysis
- ga_main.m: functions related to genetic algorithms
- UUnifast.m: UUnifast synthetic task generator
- *.slx: Simulink models


## Known Issues
- switch back is not implemented