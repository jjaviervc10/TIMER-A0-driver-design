################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Drivers/%.obj: ../Drivers/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccs1011/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1011/ccs/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Javier/Desktop/9no.Semestre/Arq/Unidad_4/GUIA/TIMERSITO" --include_path="C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Drivers/$(basename $(<F)).d_raw" --obj_directory="Drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


