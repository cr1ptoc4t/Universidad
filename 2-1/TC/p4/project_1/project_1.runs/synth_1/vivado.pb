
�
Command: %s
1870*	planAhead2�
�read_checkpoint -auto_incremental -incremental C:/Users/Catalina/Documents/Universidad/2-1/TC/p4/project_1/project_1.srcs/utils_1/imports/synth_1/sintesis_div.dcp2default:defaultZ12-2866h px� 
�
;Read reference checkpoint from %s for incremental synthesis3154*	planAhead2�
sC:/Users/Catalina/Documents/Universidad/2-1/TC/p4/project_1/project_1.srcs/utils_1/imports/synth_1/sintesis_div.dcp2default:defaultZ12-5825h px� 
T
-Please ensure there are no constraint changes3725*	planAheadZ12-7989h px� 
y
Command: %s
53*	vivadotcl2H
4synth_design -top sintesis_div -part xc7a35tcpg236-12default:defaultZ4-113h px� 
:
Starting synth_design
149*	vivadotclZ4-321h px� 
�
@Attempting to get a license for feature '%s' and/or device '%s'
308*common2
	Synthesis2default:default2
xc7a35t2default:defaultZ17-347h px� 
�
0Got license for feature '%s' and/or device '%s'
310*common2
	Synthesis2default:default2
xc7a35t2default:defaultZ17-349h px� 
V
Loading part %s157*device2#
xc7a35tcpg236-12default:defaultZ21-403h px� 

VNo compile time benefit to using incremental synthesis; A full resynthesis will be run2353*designutilsZ20-5440h px� 
�
�Flow is switching to default flow due to incremental criteria not met. If you would like to alter this behaviour and have the flow terminate instead, please set the following parameter config_implementation {autoIncr.Synth.RejectBehavior Terminate}2229*designutilsZ20-4379h px� 
�
HMultithreading enabled for synth_design using a maximum of %s processes.4828*oasys2
22default:defaultZ8-7079h px� 
a
?Launching helper process for spawning children vivado processes4827*oasysZ8-7078h px� 
`
#Helper process launched with PID %s4824*oasys2
196482default:defaultZ8-7075h px� 
�
%s*synth2�
yStarting RTL Elaboration : Time (s): cpu = 00:00:04 ; elapsed = 00:00:04 . Memory (MB): peak = 1266.465 ; gain = 411.867
2default:defaulth px� 
�
synthesizing module '%s'638*oasys2 
sintesis_div2default:default2�
pC:/Users/Catalina/Documents/Universidad/2-1/TC/p4/project_1/project_1.srcs/sources_1/imports/p4/sintesis_div.vhd2default:default2
252default:default8@Z8-638h px� 
�
Hmodule '%s' declared at '%s:%s' bound to instance '%s' of component '%s'3392*oasys2
divisor_ent2default:default2|
hC:/Users/Catalina/Documents/Universidad/2-1/TC/p4/project_1/project_1.srcs/sources_1/new/divisor_ent.vhd2default:default2
52default:default2
divInstance2default:default2
divisor_ent2default:default2�
pC:/Users/Catalina/Documents/Universidad/2-1/TC/p4/project_1/project_1.srcs/sources_1/imports/p4/sintesis_div.vhd2default:default2
552default:default8@Z8-3491h px� 
�
Zmodule '%s' declared at '%s:%s' does not have matching formal port for component port '%s'3394*oasys2
divisor_ent2default:default2|
hC:/Users/Catalina/Documents/Universidad/2-1/TC/p4/project_1/project_1.srcs/sources_1/new/divisor_ent.vhd2default:default2
52default:default2
fin2default:default2�
pC:/Users/Catalina/Documents/Universidad/2-1/TC/p4/project_1/project_1.srcs/sources_1/imports/p4/sintesis_div.vhd2default:default2
552default:default8@Z8-3493h px� 
�
Zmodule '%s' declared at '%s:%s' does not have matching formal port for component port '%s'3394*oasys2
divisor_ent2default:default2|
hC:/Users/Catalina/Documents/Universidad/2-1/TC/p4/project_1/project_1.srcs/sources_1/new/divisor_ent.vhd2default:default2
52default:default2
cociente2default:default2�
pC:/Users/Catalina/Documents/Universidad/2-1/TC/p4/project_1/project_1.srcs/sources_1/imports/p4/sintesis_div.vhd2default:default2
552default:default8@Z8-3493h px� 
�
failed synthesizing module '%s'285*oasys2 
sintesis_div2default:default2�
pC:/Users/Catalina/Documents/Universidad/2-1/TC/p4/project_1/project_1.srcs/sources_1/imports/p4/sintesis_div.vhd2default:default2
252default:default8@Z8-285h px� 
�
%s*synth2�
yFinished RTL Elaboration : Time (s): cpu = 00:00:05 ; elapsed = 00:00:05 . Memory (MB): peak = 1356.168 ; gain = 501.570
2default:defaulth px� 
U
Releasing license: %s
83*common2
	Synthesis2default:defaultZ17-83h px� 
�
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
122default:default2
02default:default2
02default:default2
42default:defaultZ4-41h px� 
N

%s failed
30*	vivadotcl2 
synth_design2default:defaultZ4-43h px� 
�
Command failed: %s
69*common2Y
ESynthesis failed - please see the console or run log file for details2default:defaultZ17-69h px� 
�
Exiting %s at %s...
206*common2
Vivado2default:default2,
Sun Nov 19 23:09:02 20232default:defaultZ17-206h px� 


End Record